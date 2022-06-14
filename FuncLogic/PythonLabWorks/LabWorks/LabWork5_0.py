def get_fibonacci_elem(n):
    fib1 = 0
    fib = 0
    fib2 = 1
    i = 0
    while i < n:
        fib = fib1
        fib1 = fib2
        fib2 += fib
        i = i+1
    return fib

def main():
    print("Программа вывода значений ряда Фиббоначи \n")
    print("Варианты вывода:")
    print("1. Вывод конкретного элемента последовательности:")
    print("2. Вывод всех элементов последовательности до указанного:")
    print("3. Вывод части последовательности, значение последнего элемента которой не превосходит введённое значение:")
    answ = int(input())
    n = int(input("Введите число больше 0: "))+1
    if answ == 1:
        res = 0
        for i in range(1,n):
            res = get_fibonacci_elem(i)
        print(res)
    elif answ == 2:
        for i in range(1,n):
            print(get_fibonacci_elem(i),end=' ')
    elif answ == 3:
        i = 1
        while get_fibonacci_elem(i)< n:
            print(get_fibonacci_elem(i),end=' ')
            i+=1
    else:
        print("К сожалению, такого варианта нет")

main()
