import math

def evalf(x):
    f=x[0]**2+math.exp(x[0])+x[1]**4+x[1]**2-2*x[0]*x[1]+3
    print('f={}'.format(f))