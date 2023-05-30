def f(x):
    return 1/3*x**3-x**2-3*x+5/3

def g(x):
    return x**2-2*x-3

def h(x):
    return 2*x-2

def d(x):
    return -h(x)**-1*g(x)

def t(k):
    return 1/(k+1)

x=5
e=10**-6
k=0

while abs(g(x))>e:
    x+=t(k)*d(x)
    k+=1

    if k==10**7:
        print('停留点は存在しない')
        break

    else:
        continue

else:
    print('停留点はx={}'.format(x))