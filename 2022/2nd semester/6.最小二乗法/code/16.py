import numpy as np
import matplotlib.pyplot as plt

N=100
ak=0.9
ck=2
sigma_v=1
sigma_w=1
mean=3
sigma=2

theta0=[np.random.normal(loc=3,scale=np.sqrt(2),size=None)]
y=[0]
for k in range(N):
    theta_k1 = ak*theta0[k]+np.random.randn()
    theta0.append(theta_k1)
    
    y_k = ck*theta0[k+1]+np.random.randn()
    y.append(y_k)

theta=[mean]
X=[0]
V=[sigma]
F=[0]
for k in range(N):
    X_k=ak**2*V[k]+sigma_v
    X.append(X_k)

    V_k=(sigma_w*X[k+1])/(ck**2*X[k+1]+sigma_w)
    V.append(V_k)

    F_k=(ck*X[k+1])/(ck**2*X[k+1]+sigma_w)
    F.append(F_k)

    theta_k=ak*theta[k]+F[k+1]*(y[k+1]-ck*ak*theta[k])
    theta.append(theta_k)

k=[]
for i in range(N+1):
    k.append(i)

plt.scatter(k,theta)
plt.scatter(k,theta0)
plt.legend()
plt.xlabel('k')
plt.ylabel(r'$\theta$')
plt.show()