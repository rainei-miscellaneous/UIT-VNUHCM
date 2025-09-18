import re, sys, math

n = int(sys.stdin.readline())

def isPrime(n):
    for i in range(2, math.isqrt(n) + 1):
        if not (n % i): return False
    return True

ans = 0

for i in range(2, n//2 + 1):
    ans += (isPrime(i) and isPrime(n-i))

print(ans)