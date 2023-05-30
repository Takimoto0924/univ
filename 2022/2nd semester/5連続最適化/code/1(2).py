def f(x):
    return x**3+2*x**2-5*x-6

def nibun(i):
    e=10**-6
    a=float(input("a="))
    b=float(input("b="))

    if f(a)<0 and f(b)>=0:
        pass
    elif f(a)>=0 and f(b)<0:
        a,b=b,a
    else:
        print('初期値を再入力してください。')
        return nibun(i)

    c=(a+b)/2
    while abs(f(c))>e:
        if f(c)<0:
            a=c
        elif f(c)>=0:
            b=c
        c=(a+b)/2

    else:
        print('x={}\n'.format(c))

for i in range(3):
    nibun(i)