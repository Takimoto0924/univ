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

def d(x):
    d=-evalg(x)
    return d

def t(x):
    t=1
    xi=10**-4
    rho=0.5
    while evalf(x+t*d(x))>evalf(x)+xi*t*np.inner(d(x),evalg(x)):
        t*=rho
    
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