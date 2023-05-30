import math
import numpy as np

def evalh(x):
    H=np.array([[2+math.exp(x[0]),-2], [-2,12*x[1]**2+2]])
    print('H=\n{}'.format(H))