def f(x):
    return x**3+2*x**2-5*x-6

def df(x):
    return 3*x**2+4*x-5

def nibun(i):
    e=10**-100
    a=float(input("x0="))

    while abs(f(a))>e:
        a-=f(a)/df(a)

    else:
        print('x={}\n'.format(a))

for i in range(3):
    nibun(i)