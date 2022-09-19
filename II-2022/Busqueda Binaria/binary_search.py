# # https://www.educative.io/answers/how-to-copy-a-list-in-python


# import random


# n = random.randint(20, 20)
# arreglo = [i for i in range(n)]
# for i in range(n):
#     arreglo[i] = random.randint(1, 90)
# print(*arreglo)

import sys
#Complexity: O(n)
def buscar_x(arreglo, x):
    cnt = 0
    for i in arreglo:
        cnt += 1
        if i == x:
            return {True, cnt}
    return {False, cnt}

def f(arreglo, m, x):
    if arreglo[m] <= x:
        return True
    return False


#log n
def busqueda_binaria(arreglo, x):
    cnt = 0
    a = 0
    b = len(arreglo)
    while b - a > 1:

        cnt += 1
        mid = (a + b) // 2
        if f(arreglo, mid, x):  # true
            a = mid
        else:
            b = mid

    # print(a, b, arreglo[a])
    return (arreglo[a] == x, cnt)
    # la respuesta deberia estar en a

arreglo = [5, 10, 4, 6, 11, 0, -10, 22, 30]

arreglo = list(map(int, input().split()))
# print(*arreglo)
# pos = [i for i in range(len(arreglo))]
arreglo.sort(reverse = False)
# encontrar el elemento x en el arreglo
print(arreglo)




#Biblioteca -> prestarnos un libro

for line in sys.stdin:
    x = int(line)
    for i in range(len(arreglo)):
        print(i, arreglo[i], f(arreglo, i, x))
    print(x, "busqueda lineal ", buscar_x(arreglo, x))
    print(x, "busqueda_binaria ", busqueda_binaria(arreglo, x))
