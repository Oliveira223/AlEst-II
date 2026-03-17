
def func1(n):
    global op  # acessa a variável op definida no programa principal
    op += 1    # cada chamada conta UMA operação
    if n <= 1:
        return 1
    return func1(n-1) + func1(n-2)

for n in range(1,40): # conta de 1 a 39 - não dá para fazer muito mais que isso... demora demais!
    op = 0
    func1(n)
    print(n,op) # gera uma tabela com o n e a quantidade de operações correspondente
