import math
#x = float(input("Enter the number: "))
x = -15.246
y = 4.642 * math.pow(10, -2)
z = 20.001 * math.pow(10, 2)
x1 = math.log(math.pow(y, -math.sqrt(abs(x))))
x2 = x - (y / 2)
x3 = math.pow(2, math.sin(math.atan(z)))
result = (x1 * x2) + x3
print("%.3f" % result)
