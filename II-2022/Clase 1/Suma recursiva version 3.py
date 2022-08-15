import sys
 
 
 
def power_recursivo(a, b):
    if b == 0:
        return 1
     
    ans = power_recursivo(a * a, b // 2);
    if b % 2 == 1:
        ans *= a
     
    return ans
     
     
def power_lento(a, b):
    ans = 1
    for i in range(1, b + 1):
        ans = ans * a
     
    return ans
 
def power(a, b):
    ans = 1
    while b > 0:
         
        if b % 2 == 1:
            ans *= a
             
        a *= a
        b //= 2
 
    return ans
 
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
 
 
 
a = 1
b = 99123232343434
 
# print(power(a, b))
# print(power_lento(a, b))
 
 
# print(power(a, b))
# print(power_recursivo(a, b))
 
# principal
t = int(sys.stdin.readline())
for i in range(t):
    x, k = map(int, sys.stdin.readline().split())
    ans = power(x, k)
     
     
    # vamos a sumar mientras ans > 10
    resultado = 0
    while ans > 9:
        ans = suma(ans)
    # print(ans)
    sys.stdout.write( str(ans) + "\n")
