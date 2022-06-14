import math

print("Программа вычисляет значение y = a * ф(x) - ln(x + 2.5) + b(e^x - e^-x), если z<-1, то x=z/3, иначе x=|z|")

a = float(input("введите a: "))
z = float(input("введите z: "))
b = float(input("введите b: "))
print("Варианты функции Ф(x): ")
print("1. 2x")
print("2. x**2")
print("3. x/3")
f=int(input("Выберите функцию Ф(x): "))

if(f == 1 or f == 2 or f == 3): 
    if z < -1:
        x = -z / 3;
    else:
        x = math.fabs(z)
        
    if x > -1:
        print("Условия вычисления: ")
        print("a:", a)
        print("z:", z)
        print("x:", x)
        print("b:", b)
        if(f==1):
            print("функция: 2x")
            y = a * (2 * x) - math.log(x + 2,5) + b * (math.exp(x) - math.exp(-x))
        elif(f==2):
            print("функция: x**2")
            y = a * (x**2) - math.log(x + 2,5) + b * (math.exp(x) - math.exp(-x))
        elif(f==3):
            print("функция: x/3")
            y = a * (x / 3) - math.log(x + 2,5) + b * (math.exp(x) - math.exp(-x))

        print("Результат: ", "{0:.2f}".format(y)) 
    else:
        print("Ошибка: невозможно получить натуральный логарифм")    
                
else:
    print("\nОшибка ввода: такой функции нет!")

input("\nДля выхода нажмите Enter...")
