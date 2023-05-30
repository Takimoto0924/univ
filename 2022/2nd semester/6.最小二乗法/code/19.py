import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys

df=pd.read_excel('C:\\Users\\Takimoto\\Desktop\\kadai\\19\\mmse_kadai14.xls',header=None)

x=df.iloc[:,0:2].to_numpy()

mu=np.array([[2.0,0.0],[1.0,-2.0],[-5.0,0.0]])
N=1000
e=10**-6

while True:
    mu0=mu
    r=np.ones((N,3))
    for l in range(3):
        a=0
        b=0
        for i in range(N):
            for k in range(3):
                if np.linalg.norm(x[i]-mu[l])<=np.linalg.norm(x[i]-mu[k]):
                    continue
                else:
                    r[i][l]=0
                    break
            a+=r[i][l]
            b+=r[i][l]*x[i]
        mu[l]=b/a

    c=1
    for k in range(3):
        if np.linalg.norm(mu0[k]-mu[k])**2<e:
            continue
        else:
            c=0
            break

    if c==1:
        x1_0=[]
        x1_1=[]
        x2_0=[]
        x2_1=[]
        x3_0=[]
        x3_1=[]
        for i in range(N):
            if r[i][0]==1:
                x1_0.append(x[i][0])
                x1_1.append(x[i][1])
            elif r[i][1]==1:
                x2_0.append(x[i][0])
                x2_1.append(x[i][1])
            elif r[i][2]==1:
                x3_0.append(x[i][0])
                x3_1.append(x[i][1]) 
    else:
        continue

    break

print(len(x1_0),len(x2_0),len(x3_0))

plt.scatter(x1_0,x1_1,label='$\mu$1')
plt.scatter(x2_0,x2_1,label='$\mu$2')
plt.scatter(x3_0,x3_1,label='$\mu$3')
plt.legend()
plt.show()