import numpy as np
import math

def X(i):
    a=np.array([[y[i+1],y[i],F(i-2)]])
    return a

def Y(i):
    a=np.array([y[i+2]])
    return a

def theta(N):
    theta=np.array([[0],[0],[0]])
    phi=np.identity(n)/e

    for i in range(N+1):
        k=np.dot(np.dot(phi,X(i).T),1/(np.identity(m)+np.dot(np.dot(X(i),phi),X(i).T)))
        phi=phi-np.dot(np.dot(k,X(i)),phi)
        theta=theta+np.dot(k,Y(i)-np.dot(X(i),theta))
    
    return theta

M=2
D=1
K=3
dt=0.01
e=10**-6
n=3
m=1

N=10000
y=[0,0]

def F(k):
    a=math.sin(math.pi*k/5)
    return a

for k in range(N+1):
    y_k=(2-(D/M)*dt)*y[k+1]+(-1+(D/M)*dt-(K/M)*dt**2)*y[k]+(dt**2/M)*F(k-2)+np.random.uniform(-1,1)
    y.append(y_k)
    
print(theta(N))