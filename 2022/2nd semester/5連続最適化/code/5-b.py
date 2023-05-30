import numpy as np

def evalfi(x,i):
    fi=y[i]-x[0]*(1-x[1]**(i+1))
    return fi

def evalf(x):
    f=0
    for i in range(3):
        f+=evalfi(x,i)**2
    return f

def evalgi(x,i):
    gi=np.array([-(1-x[1]**(i+1)),(i+1)*x[0]*x[1]**i])
    return gi

def evalg(x):
    g=0
    for i in range(3):
        g+=2*evalfi(x,i)*evalgi(x,i)
    return g


def evalhi(x,i):
    if i==0:
        hi=np.array([[0,1],[1,0]])    
    else:
        hi=np.array([[0,(i+1)*x[1]**i],[(i+1)*x[1]**i,(i+1)*i*x[0]*x[1]**(i-1)]])
    return hi

def evalh(x):
    h=0
    for i in range(3):
        h+=2*(evalfi(x,i)*evalhi(x,i)+np.dot(np.reshape(evalgi(x,i),(2,1)),np.reshape(evalgi(x,i),(1,2))))
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

x=np.array([2.0,0.0])
e=10**-6
k=0
y=[1.5,2.25,2.625]

while np.linalg.norm(evalg(x),ord=2)>e:
    x+=t(x)*d(x)
    k+=1

    if k==10**7:
        print('最適解は存在しない')
        break

    else:
        continue

else:
    print('最適解 x={}\n最適値 f(x)={}\n反復回数 {}回'.format(x,evalf(x),k))