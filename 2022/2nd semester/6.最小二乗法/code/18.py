import numpy as np
import pandas as pd

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\18\\mmse_kadai13.xls',header=None)

x=df.iloc[:,0:1].to_numpy()
y=df.iloc[:,1:2].to_numpy()

theta_a=np.array([[100,100]])
theta_b=np.array([[0.5,-1,2]])

def XA(i,j):
    a=np.array([[1,x[i][0],x[i][0]**2],[x[i][0],x[i][0]**2,x[i][0]**3]])
    a=np.dot(np.reshape(theta_a[j],(1,2)),a)
    return a

def XB(i,j):
    a=np.array([[1,x[i][0],x[i][0]**2],[x[i][0],x[i][0]**2,x[i][0]**3]])
    a=np.dot(np.reshape(theta_b[j],(1,3)),a.T)
    return a

def Y(i):
    a=np.array([y[i]])
    return a

def phiA(j):
    a=0
    for i in range(N):
        a+=np.dot(XA(i,j).T,XA(i,j))
    a=np.linalg.inv(a)
    return a

def phiB(j):
    a=0
    for i in range(N):
        a+=np.dot(XB(i,j).T,XB(i,j))
    a=np.linalg.inv(a)
    return a

def A(j):
    a=phiB(j-1)

    b=0
    for i in range(N):
        b+=np.dot(XB(i,j-1).T,Y(i))

    c=np.dot(a,b)

    global theta_a
    theta_a=np.append(theta_a,np.reshape(c,(1,2)),axis=0)

def B(j):
    a=phiA(j)

    b=0
    for i in range(N):
        b+=np.dot(XA(i,j).T,Y(i))

    c=np.dot(a,b)

    global theta_b
    theta_b=np.append(theta_b,np.reshape(c,(1,3)),axis=0)

N=10000
e=10**-10
j=1
while True:
    A(j)
    B(j)
    if np.linalg.norm(theta_a[j-1]-theta_a[j])**2+np.linalg.norm(theta_b[j-1]-theta_b[j])**2<e:
        print(theta_b[0],theta_a[j],theta_b[j])
        break
    else:
        j+=1