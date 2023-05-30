import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-10,10,0.1)
y = x**3+2*x**2-5*x-6
plt.plot(x, y)
plt.xlim(-10,10)
plt.ylim(-10,10)
plt.axhline(0, c='black')
plt.axvline(0, c='black')
plt.xlabel('x')
plt.ylabel('y')
plt.show()