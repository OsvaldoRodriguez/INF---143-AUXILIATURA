#Complexity O(n)
def divisores(n):
    div = 0
    for i in range(1, n + 1):
        if n % i == 0:
            div += 1
    return div
 
#Complexity O(sqrt(n))             
def divisores_raiz(n):
    i = 1
    div = 0
    # i <= sqrt(n)
    while i * i <= n:
        if n % i == 0:
            if n // i == i:
                div += 1
            else:
                div += 2
        i += 1
    return div
 
 
#Complexity O(sqrt(n)) 
def primo(n):
    if divisores_raiz(n) == 2:
        return True
    return False
     

#Complexity O(n * sqrt(n))     
def primos_1_n(n):
    counter = 0
    for i in range(1, n + 1):
        if primo(i) == True:
            counter += 1
             
    return counter
     
# O(n log log n)  -> O(n)
def criba1(n):
    # asumimos que todos los numeros son primos
    criba = [1] * (n + 1)
    # print(criba)
    # el 0 y el 1 no son primos
    criba[0] = criba[1] = 0
     
    i = 2
    while i * i <= n:
        if criba[i] == 1:
            for j in range(i * i, n + 1, i):
                criba[j] = 0 # no es primo
        i += 1
 
    # print(criba)
     
    contador = 0
    for i in range(n + 1):
        if criba[i] == 1:
            contador += 1
             
    return contador
 
n = 2147483647
print(primo(n))
 
m = 10000000
 
m = 10000000
print(primos_1_n(m))
 
print(criba1(m))
