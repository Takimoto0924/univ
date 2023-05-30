import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\10\\mmse_kadai5.xls',header=None)

x=df.iloc[:,0:1].to_numpy()
y=df.iloc[:,1:3].to_numpy()

def X(i):
    a=np.array([[1,x[i][0]],[1,x[i][0]**2]])
    return a

def Y(i):
    a=np.array([[y[i][0]],[y[i][1]]])
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

def V(N):
    a=theta(N)

    b=0
    for i in range(N):
        c=Y(i)-np.dot(X(i),a)
        b+=np.dot(c,c.T)
    
    d=b/(N-n)

    return d

def E(N):
    a=V(N)

    b=0
    for i in range(N):
        b+=np.dot(np.dot(X(i).T,a),X(i))
    
    c=np.dot(np.dot(phi(N),b),phi(N))

    return c

N=1000
n=2
print('最小二乗誤差推定量は\n',theta(N))
print('推定誤差共分散行列は\n',E(N))

n=[]
a1=[]
a2=[]
for i in range(1,N):
    n.append(i)

    a=theta(i)
    a1.append(a[0])
    a2.append(a[1])

plt.plot(n,a1)
plt.axhline(y=2.99456713,linestyle='--',color='red')
plt.xscale('log')
plt.xlabel('N')
plt.ylabel(r'$\theta$[0]')
plt.show()