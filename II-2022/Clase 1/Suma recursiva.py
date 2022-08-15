def f(x):
    if x == 0:
        return 0
    return f(x // 10) + x % 10
     
# x = input()
 
def suma(x):
    ans = 0
    while x > 0:
        ans += x % 10
        x //= 10
    return ans
 
 
 
 
# principal  (da TLE)
t = int(input())
for i in range(t):
    x, k = map(int, input().split())
    ans = x ** k
     
     
    # vamos a sumar mientras ans > 10
    resultado = 0
    while ans > 9:
        ans = suma(ans)
    print(ans)
