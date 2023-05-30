import numpy as np
import pandas as pd

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\7\\mmse_kadai2.xls',header=None)

x=df.iloc[:,0:1].to_numpy()
y=df.iloc[:,1:2].to_numpy()

def X(i):
    a=np.array([[1,x[i][0],x[i][0]**2,x[i][0]**3]])
    return a

def Y(i):
    a=np.array([y[i]])
    return a

def phi(N):
    a=0
    for i in range(N):
        a+=np.dot(X(i).T,X(i))
    a=np.linalg.inv(a)
    return a

def theta(N):
    a=phi(N)

    b=0
    for j in range(N):
        b+=np.dot(X(j).T,Y(j))

    c=np.dot(a,b)

    return c
    
def C(N):
    a=theta(N)

    b=0
    for i in range(N):
        b+=Y(i)
    b/=N

    c=0
    for i in range(N):
        c0=np.dot(X(i),a)-b
        c+=np.dot(c0,c0)
    
    d=0
    for i in range(N):
        d0=Y(i)-b
        d+=np.dot(d0,d0)
    
    e=c/d

    return e

N=10000
print('決定変数は',C(N))