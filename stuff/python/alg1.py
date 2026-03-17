import matplotlib.pyplot as plt # pacote gráfico
import math
plt.style.use('fivethirtyeight') # estilo dos gráficos

def f1(n):
  res = 0
  for i in range(n-1, n*n+1):    # conta de n-1 até n*n
    for j in range(i, n*n+1, i): # conta de i até n*n, de i em i
      for k in range(0, n+1, i): # conta de 0 até n, de i em i
        res += 1
  return res


x = [] # lista vazia: coordenadas x
y = [] # lista vazia: coordenadas y
for n in range(2,200):
  op=0
  res=f1(n)
  x.append(n)     # acrescenta o valor atual de n no final da lista x
  y.append(op) # acrescenta o valor da função no fina da lista y
  #y.append(f5(n)) # acrescenta o valor da função no fina da lista y

# Desenha o gráfico com linhas vermelhas
# (para usar escala logarítmica, descomente uma ou ambas linhas abaixo)
#plt.yscale("log") # usa escala log para y (precisa ser feito a CADA novo gráfico)
#plt.xscale("log") # idem, para x
plt.plot(x,y,'r-')
plt.show()



# Programa principal
for n in range(2,100):
  print(n,f1(n))
