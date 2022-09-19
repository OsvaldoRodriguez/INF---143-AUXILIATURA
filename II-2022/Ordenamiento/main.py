#O(n^2)
def burbuja(lista):
    for i in range(len(lista)):
        for j in range(i + 1, len(lista), 1):
            if lista[j] < lista[i]:
                aux = lista[j]
                lista[j] = lista[i]
                lista[i] = aux
    return lista
 
 
def check(arreglo):
    for i in range(1, len(arreglo), 1):
        if arreglo[i] < arreglo[i - 1]:
            return False
    return True
 
def merge_sort(l, r):
    # el arreglo de tamano 1 ya esta ordenado
    if l == r:
        return
     
    m = (l + r) // 2
    #hijo izquierdo
    #print("izquieda", l, m)
    merge_sort(l, m)
    #hijo derecho
    #print("derecho", m + 1, r)
    merge_sort(m + 1, r)
     
     
    # construyendo el hijo izquierdo
    L = []
    for i in range(l, m + 1, 1):
        L.append(cms[i])
     
    #print("izquierda")
    #print(L)
     
    R = []
    for i in range(m + 1, r + 1, 1):
        R.append(cms[i])
         
    #print("derecha")
    #print(R)
    # puntero para el hijo izquierdo
    pl = 0
     
    #puntero para el hijo derecho
    pd = 0
     
    #construyenco al padre de L y R
    for i in range(l, r + 1, 1):
        # si el hijo izquierdo esta vacio
        if pl >= len(L):
            cms[i] = R[pd]
            pd += 1
        elif pd >= len(R):
            # el hijo derecho esta vacio
            cms[i] = L[pl]
            pl += 1
        else:
            if L[pl] <= R[pd]:
                cms[i] = L[pl]
                pl += 1
            else:
                cms[i] = R[pd]
                pd += 1
         
     
     
n = int(input())
lista = list(map(int, input().split()))
 
copia = lista.copy()
cms = lista.copy()
#copia = lista.copy()
print(check(copia))
#ordenado = burbuja(copia)
 
#print(ordenado)
print(check(copia))
print("orenando con merge sort")
print(check(cms))
#print(cms)
merge_sort(0, len(cms) - 1)
print(" despues de ordenar")
print(check(cms))
