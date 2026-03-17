import math

import matplotlib.pyplot as plt
import matplotlib
matplotlib.use("TkAgg")

import matplotlib.pyplot as plt

def func1(n):
    global op  # acessa a variável op definida no programa principal
    op += 1    # cada chamada conta UMA operação
    if n <= 1:
        return 1
    return func1(n-1) + func1(n-2)

x = []
y = []
for n in range(1,31):
    op = 0
    func1(n)
    x.append(n)
    y.append(op)
plt.style.use('fivethirtyeight')
plt.plot(x,y,'r-')
plt.show()
print(x)
print(y)


# Se for exponencial:

# Calcula o valor de dois pontos da função
a = 4
b = 20

op=0
res=f5(a)
fa = res

op=0
res=f5(b)
fb = res

print(a,fa)
print(b,fb)
# Inclinação da reta (r) será aprox. (log(fb)-log(fa))/(b-a)
r = (math.log10(fb) - math.log10(fa))/ (b-a)
# E o expoente é exp(r)
base = math.exp(r)
print(50,  base**50)
print(100, base**100)
print(200, base**200)
print("Base aproximada da função exponencial:", base)