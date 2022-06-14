import random

print ("Игра 'Угадай число'\n")
print ("Компьютер задумал число от 1 до 100") 
print  ("Твоя задача: угадать это число за меньшее число шагов.")
print ("Каждый раз компьютер будет говорить") 
print  (" больше или меньше указанное тобой число.\n")

while True:
    n = int(input("Введите начальное число диапазона: "))
    m = int(input("Введите конечное число диапазона: "))
    k = int(input("Введите максимальное количество попыток: "))
    kol = 0
    ch = -1
    currentNum = random.randint(n,m)
    while True:
        ch = int(input("Введите число: "))
        if(ch != currentNum):
            kol+=1
            print("Неверно!")
            print("Ваше число", end=' ')
            if ch > currentNum:
                print("больше")
            else:
                print("меньше")
            if kol == k:
                print("Загаданное число:", currentNum)
                print("Game Over")
                break 
        else:
           print("Поздравляем!")
           print("Количество затраченных попыток:", kol)
           print("Загаданное число:", currentNum)
           break
    print("Хотите сыграть ещё раз? ")
    print("1. Да")
    print("2. Нет")
    answ = int(input())
    if answ == 2:
        print("До встречи!")
        break



