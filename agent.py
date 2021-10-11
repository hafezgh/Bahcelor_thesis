
import torch.nn as nn
import torch.nn.functional as F
from datetime import timedelta
from datetime import datetime


state_dim = 2
n_actions = 27

class DQN(nn.Module):
    def __init__(self, act=F.relu):
        super(DQN, self).__init__()

        self.layer1 = nn.Linear(state_dim, 128)
        self.act1 = act

        self.layer2 = nn.Linear(128, 256) 
        self.act2 = act

        self.layer3 = nn.Linear(256, 256) 
        self.act3 = act

        self.layer4 = nn.Linear(256, 128) 
        self.act4 = act

        self.layer5 = nn.Linear(128, n_actions) 
        
    def forward(self, x):
        x = self.layer1(x)
        x = self.act1(x)

        x = self.layer2(x)
        x = self.act2(x)

        x = self.layer3(x)
        x = self.act3(x)
        
        x = self.layer4(x)
        x = self.act4(x)

        x = self.layer5(x)
        return x