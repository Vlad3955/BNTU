import math

print("Программа решает квадратное уравнение: ax2 + bx + c = 0")

a = float(input("введите a: "))
b = float(input("введите b: "))
c = float(input("введите c: "))

if a != 0:
    D = b**2 - 4 * a * c
    
    if D > 0:
        x1 = (-b + math.sqrt(D)) / (2 * a)
        x2 = (-b - math.sqrt(D)) / (2 * a)
        print("\nДва корня уравнения:")
        #print("x1 = " + "{0:.2f}".format(str(x1)))
        print("x2 = " + str(x1))
        print("x2 = " + str(x2))
    else:
        if D == 0:
            x = -b / 2 / a
            print("\nОдин корень уравнения:")
            print("x = " + str(x))
        else:
            print("\nУравнение не имеет корней!")
            
else:
    print("\nОшибка ввода: коэффициент а должен быть ненулевым!")

input("\nДля выхода нажмите Enter...")
