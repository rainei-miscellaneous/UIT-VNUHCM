import sys

"""Bai lam co ap dung kien thuc DSTT, co tham khao cach code cua GPT, va co ap dung cac bai hoc ve chuan hoa tren coursera (nhung sai), co tham khao nguon: https://stackoverflow.com/questions/63766815/determinate-of-a-singular-4x4-matrix-is-non-zero-using-numpy-det
"""
"""https://drive.google.com/file/d/11OLV4QSfCjeGKwa-cQjDLf9gyJ2igsDA/view?usp=sharing"""

### Input
data = sys.stdin.readlines()

points = []
for l in data:
    x, y = map(float, l.split(','))
    points.append((x, y))
m = len(points)

# ### Chuan hoa
# x_vals = [x for x, y in points]
# xMax, xMin = max(x_vals), min(x_vals)
# normalizedPoints = [((x - xMin) / (xMax - xMin), y) for x, y in points]  # MinMax Scaler

def matmul(A, B): # -> Done
    result = [[sum(A[i][k] * B[k][j] for k in range(len(B))) for j in range(len(B[0]))] for i in range(len(A))]
    return result

def dot(A, v): # -> Done
    return [sum(A[i][j] * v[j] for j in range(len(v))) for i in range(len(A))]

def transpose(A): # -> Done
    return [[A[j][i] for j in range(len(A))] for i in range(len(A[0]))]

def determinant(m1): 
    if (len(m1)!=len(m1[0])): 
        return "Error this is not a square matrix"
    elif (len(m1) == 2):
        return (m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0])
    elif (len(m1) == 3):
      # | m00 m01 m02|          
      # | m10 m11 m12 | 
      # | m20 m21 m22 |
          a = m1[0][0] * (m1[1][1]* m1[2][2] - m1[2][1] * m1[1][2]) 
          b = m1[0][1] * (m1[1][0]* m1[2][2] - m1[2][0] * m1[1][2])
          c = m1[0][2] * (m1[1][0]* m1[2][1] - m1[2][0] * m1[1][1])                     
          return(a-b+c)     
    elif (len(m1) == 4):
     # |m00 m01 m02 m03|          
     # |m10 m11 m12 m13| 
     # |m20 m21 m22 m23|
     #| m30 m31 m32 m33|
        a1 = 0
        a2 = 0
        a3 = 0 
        a4 = 0   
        a1 = m1[0][0] * (m1[1][1] * (m1[2][2] * m1[3][3] - m1[3][2] * m1[2][3]) - m1[1][2] * (m1[2][1] * m1[3][3] - m1[3][1] * m1[2][3]) + m1[1][3] * (m1[2][1] * m1[3][2] - m1[3][1] * m1[2][2]))
        a2 = m1[0][1] * (m1[1][0] * (m1[2][2] * m1[3][3] - m1[3][2] * m1[2][3]) - m1[1][2] * (m1[2][0] * m1[3][3] - m1[3][0] * m1[2][3]) + m1[1][3] * (m1[2][0] * m1[3][2] - m1[3][0] * m1[2][2])) 
        a3 = m1[0][2] * (m1[1][0] * (m1[2][1] * m1[3][3] - m1[3][1] * m1[2][3]) - m1[1][1] * (m1[2][0] * m1[3][3] - m1[3][0] * m1[2][3]) + m1[1][3] * (m1[2][0] * m1[3][1] - m1[3][0] * m1[2][1])) 
        a4 = m1[0][3] * (m1[1][0] * (m1[2][1] * m1[3][2] - m1[3][1] * m1[2][2]) - m1[1][1] * (m1[2][0] * m1[3][2] - m1[3][0] * m1[2][2]) + m1[1][2] * (m1[2][0] * m1[3][1] - m1[3][0] * m1[2][1]))
    return a1-a2+a3-a4   

def transpose(matrix):
    return [[matrix[j][i] for j in range(4)] for i in range(4)]

def cofactor(matrix):
    cofMat = [[0, 0, 0, 0] for _ in range(4)]
    for i in range(4):
        for j in range(4):
            minor = [[matrix[x][y] for y in range(4) if y != j] for x in range(4) if x != i]
            cofMat[i][j] = determinant(minor)
            if (i + j) % 2 != 0:
                cofMat[i][j] = -cofMat[i][j]
    return cofMat

def inverse(matrix):
    det = determinant(matrix)

    cofactorMat = cofactor(matrix)
    adjMat = transpose(cofactorMat)
    invMat = [[adjMat[i][j] / det for j in range(4)] for i in range(4)]

    return invMat

def solveLinear(X, Y):
    n = len(X)

    X_tmp = [[0] * 4 for i in range(4)]
    Y_tmp = [0] * 4

    for i in range(n):
        xi = X[i]
        yi = Y[i]

        X_tmp[0][0] += xi ** 8
        X_tmp[0][1] += xi ** 6
        X_tmp[0][2] += xi ** 5
        X_tmp[0][3] += xi ** 4

        X_tmp[1][0] += xi ** 6
        X_tmp[1][1] += xi ** 4
        X_tmp[1][2] += xi ** 3
        X_tmp[1][3] += xi ** 2

        X_tmp[2][0] += xi ** 5
        X_tmp[2][1] += xi ** 3
        X_tmp[2][2] += xi ** 2
        X_tmp[2][3] += xi

        X_tmp[3][0] += xi ** 4
        X_tmp[3][1] += xi ** 2
        X_tmp[3][2] += xi
        X_tmp[3][3] += 1

        Y_tmp[0] += yi * xi ** 4
        Y_tmp[1] += yi * xi ** 2
        Y_tmp[2] += yi * xi
        Y_tmp[3] += yi

    xinv = inverse(X_tmp)
    sol = tuple(dot(xinv, Y_tmp))

    return sol

X = [x for x, _ in points]
Y = [y for _, y in points]

coeffs = solveLinear(X, Y)

terms = [
    f"{coeffs[0]}*x**4",
    f"{coeffs[1]}*x**2",
    f"{coeffs[2]}*x",
    f"{coeffs[3]}"
]
equation = " + ".join(terms)
sys.stdout.write(f"{equation}\n")

# ### Test MSE
# mse = sum((y - (coeffs[0] * (x ** 4) + coeffs[1] * (x ** 2) + coeffs[2] * x + coeffs[3])) ** 2 for x, y in points) / m
# sys.stdout.write(f"MSE = {mse}")

# ########################################################
# ### Plotting
# import matplotlib.pyplot as plt
# x_vals = [x for x, y in points]
# y_vals = [y for x, y in points]

# plt.scatter(x_vals, y_vals, color='blue', label='Data')

# x_range = sorted(x_vals)
# y_preds = [coeffs[0] * (x ** 4) + coeffs[1] * (x ** 2) + coeffs[2] * x + coeffs[3] for x in x_range]

# plt.plot(x_range, y_preds, color='red', label=f'Polynomial Fit')

# plt.title('Polynomial Regression Fit')
# plt.xlabel('X')
# plt.ylabel('Y')
# plt.legend()
# plt.grid(True)

# plt.show()