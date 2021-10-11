
import torch
import numpy as np

def get_action(s, agent, env, epsilon=0):
    dqn = agent
    state = torch.tensor(s[None], dtype=torch.float32)
    q_values = dqn(state).detach().numpy()
    possible_actions = env.mapping_actions
    num = np.random.uniform(low = 0, high = 1)
    if num <= epsilon:
      chosen_action = possible_actions[np.random.choice(len(possible_actions))]
    else:
      chosen_action = possible_actions[np.argmax(q_values)]
    return chosen_action

def compute_td_loss(states, actions, rewards, next_states, is_done, dqn, gamma=0.99):
    states = torch.tensor(
        states, dtype=torch.float32)   
    actions = torch.tensor(actions, dtype=torch.long)   
    rewards = torch.tensor(rewards, dtype=torch.float32)  
    next_states = torch.tensor(next_states, dtype=torch.float32)
    is_done = torch.tensor(is_done, dtype=torch.uint8)
    predicted_qvalues = dqn(states)

    predicted_qvalues_for_actions = predicted_qvalues[
      range(states.shape[0]), actions
    ]
    predicted_next_qvalues = dqn(next_states)

    temp = [max(predicted_next_qvalues[i]) for i in range(len(next_states))]
    next_state_values = torch.tensor(temp, dtype=torch.float32)

    target_qvalues_for_actions = rewards + gamma * next_state_values

    target_qvalues_for_actions = torch.where(
        is_done, rewards, target_qvalues_for_actions)

    loss = torch.mean((predicted_qvalues_for_actions -
                       target_qvalues_for_actions.detach()) ** 2)
    return loss

def generate_session(env, opt, t_max=1000, epsilon=0, train=False):
    total_reward = 0
    s, _, _ = env.reset()
    for t in range(t_max):
        a = get_action(s, epsilon=epsilon)
        next_s, r, done, _, _ = env.step(env.possible_actions[a])
        if train:
            opt.zero_grad()
            loss = compute_td_loss([s], [a], [r], [next_s], [done]).backward()

            opt.step()
        total_reward += r
        s = next_s
        if done:
          break
    return total_reward