class environment():
    def __init__(self):
      self.states_dim = 2
      self.n_actions = 27
      self.possible_actions_orig = [(i, j, k) for i in range(-1,2) for j in range(-1,2) for k in range(-1,2)]
      self.mapping_actions = [i for i in range(27)]
      self.possible_actions = dict(zip(self.mapping_actions, self.possible_actions_orig))
      self.state = None
      self.X_faces = None
      self.Y_faces = None
      self.X_faces_norm = None
      self.Y_faces_norm = None
      self.n_faces = 0
      self.frame_width = 400
      self.frame_height = 400
      self.pixel_to_mm = 0.2645833333   #	0.2645833333 mm = 1 pixel 
      self.delta_thetaX = 0.9*1600    # X Stepper Motor Rotation (CW), 0.9 is the stepper motor step angle
      self.delta_thetaRo = 0.9*5    # Y Stepper Motor Rotation (CW)
      self.delta_thetaPhi = 0.9*7   # Z Stepper Motor Rotation (CW)
      self.shaft_diameter = 5        # Stepper Motor Shaft Diameter
      self.delta_x = (self.delta_thetaX/360) * math.pi * self.shaft_diameter    # sliding DOF ()
      self.steps = 0
    def reset(self):
      n = np.random.randint(1, 11)
      self.n_faces = n
      self.X_faces = np.random.randint(100, self.frame_width-100, size = n).astype("float64")
      self.Y_faces = np.random.randint(100, self.frame_height-100, size = n).astype("float64")
      self.X_faces_norm = self.X_faces/self.frame_width
      self.Y_faces_norm = self.Y_faces/self.frame_height
      self.state = (np.std(abs(self.X_faces_norm - 0.5)), np.std(abs(self.Y_faces_norm - 0.5)))
      self.steps = 0
      return np.array(self.state), self.X_faces, self.Y_faces
    def custom_reset(self, n, faces_X, faces_Y):
      self.n_faces = n
      self.X_faces = faces_X.astype("float64")
      self.Y_faces = faces_Y.astype("float64")
      self.X_faces_norm = self.X_faces/self.frame_width
      self.Y_faces_norm = self.Y_faces/self.frame_height
      self.state = (np.std(abs(self.X_faces_norm - 0.5)), np.std(abs(self.Y_faces_norm - 0.5)))
      self.steps = 0
      return np.array(self.state), self.X_faces, self.Y_faces

    def step(self, action):
      new_x = self.X_faces + (- self.delta_x*action[0]*self.pixel_to_mm - (math.sin(self.delta_thetaRo*math.pi/180)*self.frame_width/2*action[1]))
      new_y = self.Y_faces + (+(math.sin(self.delta_thetaPhi*math.pi/180)) * self.frame_height/2 * action[2])
      new_x_norm = new_x/self.frame_width
      new_y_norm = new_y/self.frame_height
      new_std_x = np.std(abs(self.X_faces_norm - 0.5))
      new_std_y = np.std(abs(self.Y_faces_norm - 0.5))
      out_of_frame = False
      done = False
      if any(x<0.02 for x in new_x_norm) or any(x>0.98 for x in new_x_norm) or any(y<0.02 for y in new_y_norm) or any(y>0.98 for y in new_y_norm):
        out_of_frame = True
        done = True
      else:
        if new_std_x < 0.075 and new_std_y < 0.075:
          done = True
      self.steps += 1
      if not done:
        reward = 1 + 10*(self.state[0]-new_std_y) + 10*(self.state[1]-new_std_y)
      else:
        if not out_of_frame:
          reward = +100 - self.steps/10
        else:
          reward = -100 - self.steps/10
      self.state = (new_std_x, new_std_y)
      self.X_faces = new_x
      self.Y_faces = new_y
      return np.array(self.state), reward, done, self.X_faces, self.Y_faces
    def action_space_Sample(self):
      return np.random.choice(self.possible_actions)
