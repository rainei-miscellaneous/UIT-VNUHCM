import sys
import matplotlib.pyplot as plt

"""Bai lam co tham khao cach bien doi cong thuc tu MSE sang OLS cua GPT"""

data = sys.stdin.readlines()

points = []
for l in data:
    x, y = map(float, l.split(','))
    points.append((x, y))

n = len(points)
xSum, ySum, xySum, xSquaredSum = 0, 0, 0, 0
for x, y in points:
    xSum += x
    ySum += y
    xySum += x * y
    xSquaredSum += x * x

a = (n * xySum - xSum * ySum) / (n * xSquaredSum - xSum * xSum)
b = (ySum - a * xSum) / n

sys.stdout.write(f"{a:.8e} {b:.8e}\n")

#########################################################

x_vals = [x for x, y in points]
y_vals = [y for x, y in points]

# Tạo dữ liệu cho đường thẳng hồi quy
x_line = [min(x_vals), max(x_vals)]
y_line = [a * x + b for x in x_line]

# Vẽ điểm dữ liệu
plt.scatter(x_vals, y_vals, color='blue', label='Dữ liệu')

# Thêm tiêu đề và nhãn
plt.title('Biểu đồ hồi quy tuyến tính')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.grid(True)

# Hiển thị biểu đồ
plt.show()