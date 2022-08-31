# import timeit
import sys
 
# prox O(2^n)  1.5^n
def f(n):
    if n <= 1:
        return n
    return f(n - 1) + f(n - 2)
 
# O(n)
def g(n):
    global dp
    if n <= 1:
        return n 
    if dp[n] != -1:
        return dp[n]
    dp[n] = g(n - 1) + g(n - 2)
    return dp[n]
# x = int(input())
 
 
def multiplicar_matrix(A, B):
    global mod
    # C[0][0] = C[0][1] = C[1][0] = C[1][1] = 0
    C = [[0, 0], [0, 0]]
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0]
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1]
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0]
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1]
 
    C[0][0] %= mod
    C[0][1] %= mod
    C[1][0] %= mod
    C[1][1] %= mod
    return C
 
 
def fast_pow(A, n):
    ans = [[1, 0], [0, 1]]
    while n > 0:
        if n & 1:
            ans = multiplicar_matrix(ans, A)
        n >>= 1
        A = multiplicar_matrix(A, A)
    return ans
 
 
 
# dp = [-1] * 10**5
mod = 10**9 + 7
# start = timeit.default_timer()
# print(f(x))
# print(g(x))
# stop = timeit.default_timer()
# print('Time: ', stop - start) 
#con programacion dinamica -> O(n)
 
 
# C = [[0] * 2 for i in range(2)]
 
A = [[1, 1], [1, 0]]
 
t = int(sys.stdin.readline())
while t > 0:
    y = int(sys.stdin.readline())
    ANS = fast_pow(A, y)
    # sys.stdout.write(str(ANS[0][0]) + "\n")
    print(ANS[0][0])
    t -= 1
 
