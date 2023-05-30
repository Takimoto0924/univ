import math
import numpy as np
import pandas as pd

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\12\\mmse_kadai7.xls',header=None)

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

def theta2(N,M):
    a=np.linalg.inv(phi(0,N))+np.linalg.inv(phi(N,N+M))
    a=np.linalg.inv(a)

    b=np.dot(np.linalg.inv(phi(0,N)),theta(0,N))+np.dot(np.linalg.inv(phi(N,N+M)),theta(N,N+M))

    c=np.dot(a,b)

    return c

N=6000
M=4000
print('最初の6000組の最小二乗誤差推定量は\n',theta(0,N))
print('残りの4000組の最小二乗誤差推定量は\n',theta(N,N+M))
print('合成値は\n',theta2(N,M))

print('全データでは\n',theta(0,N+M))