import math
print("Введите Хнач, Хкон и Dx")
xb = float(input("Хнач = "))
xe = float(input("Хкон = "))
dx = float(input("Dx = "))
arr = []
print("Хнач={0: 7.2f} Хкон={1: 7.2f}".format(xb, xe))
print("Dx={0: 7.2f}".format(dx))
xt2 = xb

while xt2 <= xe:
    arr.append(xt2)
    xt2 += dx
    #print(arr)

print("+--------+--------+")
print("I X      I Y      I")
print("+--------+--------+")
for i in arr:
    if i < -5:
        y = 1
    else:
        if i >= -5 and i < 0:
            y = (-3 / (5 * i)) -2
        else:
            if i >= 0 and i < 2:
                y = -math.sqrt(4 - i**2)
            else:
                if i >= 2 and i < 4:
                    y = i - 2
                else:
                    if i >= 4 and i < 8:
                        y = 2 + math.sqrt(4 - (i - 6)**2)
                    else:
                        y = 2
    print("I {0: 7.2f} I {1: 7.2f}".format(i,y))
        
    
print("+--------+--------+")

                    
