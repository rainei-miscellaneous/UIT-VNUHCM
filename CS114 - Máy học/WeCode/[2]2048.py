import sys

arr = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
letter = sys.stdin.readline().strip()
newArr = [[0 for _ in range(4)] for _ in range(4)]

def solveLeft():
    # Each row
    for row in range(4):
        nonZero = [num for num in arr[row] if num]
        merged = []
        skip = False
        for i in range(len(nonZero)):
            if skip:
                skip = False
                continue
            if i < len(nonZero)-1 and nonZero[i] == nonZero[i+1]:
                merged.append(2*nonZero[i])
                skip = True
            else:
                merged.append(nonZero[i])

        while len(merged) < 4:
            merged.append(0)

        newArr[row] = merged
    for row in newArr:
        print(" ".join(map(str, row)))

def solveRight(): 
    # Each row
    for row in range(4):
        nonZero = [num for num in arr[row] if num]
        # print(nonZero)
        merged = []
        skip = False
        
        i = len(nonZero) - 1
        while i >= 0:
            if skip:
                skip = False
                i -= 1
                continue
            if i > 0 and nonZero[i] == nonZero[i-1]:
                merged.insert(0, 2 * nonZero[i])
                skip = True
            else:
                merged.insert(0, nonZero[i])
            i -= 1

        while len(merged) < 4:
            merged.insert(0, 0)

        newArr[row] = merged
    for row in newArr:
        print(" ".join(map(str, row)))

def solveUp(): 
    # Each col
    for col in range(4):
        nonZero = [arr[row][col] for row in range(4) if arr[row][col]]
        merged = []
        skip = False
        for i in range(len(nonZero)):
            if skip:
                skip = False
                continue
            if i < len(nonZero)-1 and nonZero[i] == nonZero[i+1]:
                merged.append(2*nonZero[i])
                skip = True
            else:
                merged.append(nonZero[i])

        while len(merged) < 4:
            merged.append(0)

        for row in range(4):
            newArr[row][col] = merged[row]
    for row in newArr:
        print(" ".join(map(str, row)))

def solveDown(): 
    for col in range(4):
        nonZero = [arr[row][col] for row in range(4) if arr[row][col]]
        merged = []
        skip = False
        
        i = len(nonZero) - 1
        while i >= 0:
            if skip:
                skip = False
                i -= 1
                continue
            if i > 0 and nonZero[i] == nonZero[i-1]:
                merged.insert(0, 2 * nonZero[i])
                skip = True
            else:
                merged.insert(0, nonZero[i])
            i -= 1

        while len(merged) < 4:
            merged.insert(0, 0)

        print(merged)

        for row in range(4):
            newArr[row][col] = merged[row]
    for row in newArr:
        print(" ".join(map(str, row)))

if letter == "L":
    solveLeft()
elif letter == "R":
    solveRight()
elif letter == "U":
    solveUp()
elif letter == "D":
    solveDown()
