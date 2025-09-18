import re, sys, math

def valid_ip(n: str) -> bool:
    index = [i for i, c in enumerate(n) if c == '.'] 

    if len(index) != 3:
        return False

    index.insert(0, -1) 
    index.append(len(n))  

    for j in range(len(index) - 1):
        id1 = index[j]
        id2 = index[j + 1]

        if id2 - id1 == 1:
            return False

        if id2 - id1 > 2 and n[id1 + 1] == '0':
            return False

        num = int(n[id1 + 1:id2])
        if num > 255:
            return False

    return True

def ip(cur_length: int, ans: str, check: list, last_dot_pos: int):
    for i in range(last_dot_pos + 1, len(ans)):
        if cur_length < 4:
            if not check[i]:
                check[i] = True
                ans = ans[:i] + '.' + ans[i:]

                ip(cur_length + 1, ans, check, i)

                ans = ans[:i] + ans[i + 1:]
                check[i] = False
        else:
            if valid_ip(ans):
                print(ans)
            return

n = sys.stdin.readline().strip()

if len(n) < 4 or len(n) > 12:
    print("")
else:
    check = [False] * (len(n) + 3)
    ip(1, n, check, 0)