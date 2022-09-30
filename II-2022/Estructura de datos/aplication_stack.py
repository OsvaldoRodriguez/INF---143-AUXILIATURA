# your code goes here
 
def reconstruir(arreglo):
    cadena = ""
    for i in range(len(arreglo)):
        if i < arreglo[i]:
            cadena += "("
        else:
            cadena += ")"
    return cadena
 
cad = input()
 
#pila
pila = []
 
pareja = [-1] * len(cad)
 
flag = True
 
for i in range(len(cad)):
    if cad[i] == '(':
        pila.append(i)
    else:
        if len(pila) > 0:
            # x es la posicion de apertura
            x = pila.pop()
            # la pos del vector pareja denota quien le cieera / abre
            pareja[i] = x #  cierre
             
            pareja[x] = i #
        else:
            flag = False
print(pareja)
 
if len(pila) > 0:
    flag = False
print(flag)
print(reconstruir(pareja))
