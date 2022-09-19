# f si puedo hacer x trabajos en tiempo mid
def f(arr, mid, trabajos):
    cantidad = 0
    for i in arr:
        # print(trabajos, i, trabajos // i)
        cantidad += mid // i
 
    # print(mid, trabajos, cantidad)
    return cantidad >= trabajos
 
n = int(input())
arr = list(map(int, input().split()))
q = int(input())
 
 
while q > 0:
    q -= 1
 
    trabajos = int(input())
 
    # print(f(arr, 1999999, trabajos))
 
    a = 0
    b = 10**9
    while b - a > 1:
        mid = (a + b) // 2
        if f(arr, mid, trabajos):      # true
            b = mid
        else:
            a = mid
    # la respuesta deberia en b
    print("Tiempo minimo para {} trabajos es: {}".format(trabajos, b))
