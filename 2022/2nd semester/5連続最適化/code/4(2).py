import math
import numpy as np

def evalf(x):
    f=x[0]**2+math.exp(x[0])+x[1]**4+x[1]**2-2*x[0]*x[1]+3
    return f

def evalg(x):
    g=np.array([2*x[0]+math.exp(x[0])-2*x[1],4*x[1]**3+2*x[1]-2*x[0]])
    return g

def evalh(x):
    h=np.array([[2+math.exp(x[0]),-2], [-2,12*x[1]**2+2]])
    return h

def d(x):
    d=-np.dot(np.linalg.inv(evalh(x)),evalg(x))
    return d

def t(x):
    t=1
    xi=10**-4
    rho=0.5
    while evalf(x+t*d(x))>evalf(x)+xi*t*np.inner(d(x),evalg(x)):
        t=rho*t
    
    else:
        return t

x=np.array([1,1])
e=10**-6
k=0

while np.linalg.norm(evalg(x),ord=2)>e:
    x=x+t(x)*d(x)
    k+=1

    if k==10**7:
        print('最適解は存在しない')
        break

    else:
        continue

else:
    print('最適解 x={}\n最適値 f(x)={}\n反復回数 {}回'.format(x,evalf(x),k))