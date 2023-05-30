import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\6\\mmse_kadai1.xls',header=None)

x=df.iloc[:,0:2].to_numpy()
y=df.iloc[:,2:3].to_numpy()

def X(i):
    a=np.array([x[i]])
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
for i in range(1,14):
    N=2**i
    n.append(N)

    a=theta(N)
    a1.append(a[0])
    a2.append(a[1])

plt.plot(n,a1,marker='o')
plt.axhline(y=1.50655081,linestyle='--',color='red')
plt.xscale('log',base=2)
plt.xlabel('N')
plt.ylabel(r'$\theta$[0]')
plt.show()