way1, way2 = 0, 0
num = input().split()

for i in range(len(num)):
    curString = input()
    
    number = ''
    dot = False
    for char in curString:
        if char.isdigit():
            number += char
        elif char == '.' and not dot:
            number += char
            dot = True
        elif number:
            break

    if number:
        curNum = float(number) if '.' in number else int(number)
    else:
        curNum = 0 
    
    if "higher than in-store" in curString:
        way1 += (100 + curNum) * float(num[i]) / 100

    if "lower than in-store" in curString:
        way2 += (100 - curNum) * float(num[i]) / 100


# print(way1, way2)
curMoney = float(input())

if way1 <= curMoney or way2 <= curMoney:
    print("true")
else:
    print("false")
