t = int(input())
 
for _ in range(t):
    secuencia = input()
    pila = [] # pila vacia
     
    flag = True
    for i in range(len(secuencia)):
        if secuencia[i] == ' ':
            flag = False
            continue
         
        if secuencia[i] == '(':
            pila.append(')')
        if secuencia[i] == '[':
            pila.append(']')
             
        if secuencia[i] == ')' or secuencia[i] == ']':
            if len(pila) > 0:
                x = pila.pop()
                if secuencia[i] != x:
                    flag = False
            else:
                flag = False
                 
    if len(pila)> 0:
        flag = False
         
    if flag == True :
        print("Yes")
    else:
        print("No")
