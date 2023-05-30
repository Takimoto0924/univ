import math
import numpy as np

def evalg(x):
    g=np.array([2*x[0]+math.exp(x[0])-2*x[1],4*x[1]**3+2*x[1]-2*x[0]])
    print('f={}'.format(g))