import sys, math

n = int(sys.stdin.readline().strip())
n_squared = n * n
# n = math.sqrt(n)

ans, lim = 0, int(n/math.sqrt(2))

for i in range(1, lim):
    other_squared = n_squared - i*i
    ans += (math.sqrt(other_squared).is_integer())

print(ans)