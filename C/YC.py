def f():
    return f


U = lambda u: lambda x: lambda y: x(u(u)(x))(y)
Y = U(U)
fac = Y(lambda f: lambda n: 1 if n == 0 else n * f(n - 1))

print(fac(100))
