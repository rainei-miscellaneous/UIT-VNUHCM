# a = []
# for i in range(3):
#     for j in range(3):

arr = []
for i in range(3):
    a = input()
    arr.extend(int(num) for num in a.split())

# print(arr)

n = int(input())

calledNum = []
for i in range(n):
    calledNum.append(int(input()))

isRow = 0
for row in range(3):
    cnt = 0
    for col in range(3):
        cnt += ((arr[row * 3 + col]) in calledNum)

    if cnt == 3: isRow = 1

isCol = 0
for col in range(3):
    cnt = 0
    for row in range(3):
        cnt += ((arr[row * 3 + col]) in calledNum)

    if cnt == 3: isCol = 1

isDiag = (arr[0] in calledNum and arr[4] in calledNum and arr[8] in calledNum) or (arr[2] in calledNum and arr[4] in calledNum and arr[6] in calledNum)

if isRow or isCol or isDiag:
    print("Yes")
else:
    print("No")