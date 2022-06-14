import math
x = float(input("Введите значение аргумента:"))

if x < -5:
    y = 1
elif x >= -5 and x < 0:
    y = (-3 / (5 * x))-2
elif x >= 0 and x < 2:
    y = -math.sqrt(4 - x**2)
elif x >= 2 and x < 4:
    y = x - 2
elif x >= 4 and x < 8:
    y = 2 + math.sqrt(4 - (x - 6)**2)
elif x >= 8:
    y = 2

print("X={0:.2F} Y={1:.2f}".format(x,y))

input("Для выхода надмите Enter...")
