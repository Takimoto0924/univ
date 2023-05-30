import math
import numpy as np
import pandas as pd

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\13\\mmse_kadai8.xls',header=None)

x=df.iloc[:,0:1].to_numpy()
y=df.iloc[:,1:2].to_numpy()

def X(i):
    a=np.array([[1,math.exp(-(x[i][0]-1)**2/2),math.exp(-(x[i][0]+1)**2)]])
    return a

def Y(i):
    a=np.array([y[i]])
    return a

def phi(N,M):
    a=0
    for i in range(N,M):
        a+=np.dot(X(i).T,X(i))
    a=np.linalg.inv(a)
    return a

def theta(N,M):
    a=phi(N,M)

    b=0
    for j in range(N,M):
        b+=np.dot(X(j).T,Y(j))

    c=np.dot(a,b)

    return c

def V(N,M):
    a=theta(N,M)

    b=0
    for i in range(N,M):
        c=Y(i)-np.dot(X(i),a)
        b+=np.dot(c,c.T)
    
    d=b/(N-n)

    return d

def phi2(N,M):
    a=1/V(N,M)

    b=0
    for i in range(N,M):
        b+=np.dot(np.dot(X(i).T,a),X(i))
    b=np.linalg.inv(b)
    return b

def theta2(N,M):
    a=np.linalg.inv(phi2(0,N))+np.linalg.inv(phi2(N,N+M))
    a=np.linalg.inv(a)

    b=np.dot(np.linalg.inv(phi2(0,N)),theta(0,N))+np.dot(np.linalg.inv(phi2(N,N+M)),theta(N,N+M))

    c=np.dot(a,b)

    return c

N=6000
M=4000
n=3
print('最初の6000組の最小二乗誤差推定量は\n',theta(0,N),'\n偶然誤差の共分散行列の推定値は',V(0,N))
print('残りの4000組の最小二乗誤差推定量は\n',theta(N,N+M),'\n偶然誤差の共分散行列の推定値は',V(N,N+M))
print('合成値は\n',theta2(N,M))

print('全データでは\n',theta(0,N+M))