import sys, time
from decimal import Decimal, getcontext

"""Bai lam co tham khao GPT cach xu ly so lon (Thu vien Decimal) va Wikipedia de tim ra upper_bound cua viec so sanh Palindrome"""

getcontext().prec = 15_001
def isPalindrome(s):
    s = str(s)
    return s == s[::-1]

s = Decimal(sys.stdin.readline().strip())
repi = 0
maxIter = 10001
arr = [None] * maxIter

while len(str(s)) <= 15000 and repi < maxIter:
    sRev = Decimal(str(s)[::-1])
    s = s + sRev
    arr[repi] = s

    if repi < 293:
        if isPalindrome(s): break

    repi += 1

output = []
if isPalindrome(s):
    output.append("NO")
    output.extend(map(str, arr[:repi + 1]))
else:
    output.append("YES")
    output.append(f"{repi} {s}")

sys.stdout.write('\n'.join(output) + '\n')