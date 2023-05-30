import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

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

n=[]
a1=[]
a2=[]
a3=[]
a4=[]
for i in range(2,14):
    N=2**i
    n.append(N)

    a=theta(N)
    a1.append(a[0])
    a2.append(a[1])
    a3.append(a[2])
    a4.append(a[3])

plt.plot(n,a1,marker='o')
plt.axhline(y=-0.50902942,linestyle='--',color='red')
plt.xscale('log',base=2)
plt.xlabel('N')
plt.ylabel(r'$\theta$[0]')
plt.show() 