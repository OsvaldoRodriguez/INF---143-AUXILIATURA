n, q = map(int, input().split())
zeus = [0] * (n + 2)
 
for i in range(q):
    L, R = map(int, input().split())
    zeus[L] += 1
    zeus[R + 1] -= 1
     
# generando la acumulada del vector zeus
 
acc = [0] * (n + 2)
 
acc[1] = zeus[1]
for i in range(2, n + 2, 1):
    acc[i] = acc[i - 1] + zeus[i]
     
# print(acc)
 
for i in range(1, n + 1):
     
    if acc[i] % 2 == 0:
        print('Z', end = '')
    else:
        print('R', end = '')
    if i + 1 < n + 1:
        print(end = " ")
