
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
 
n = 100000

print(divisores(n))
print(divisores_raiz(n))
