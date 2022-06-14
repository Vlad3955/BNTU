import random, math
n = int(input("Введите размер массива(N<=30) N: "))
Amax = float(input("Введите пороговое значение A: "))
if n > 30: n = 30
elif n < 5: n = 5
arr = []
print("Исходный одномерный список: ")
for i in range(n):
    arr.append(random.uniform(-5,5))
    print("{0:>8.4f}".format(arr[i]))
    
#1. Первый и второй максимальные по модулю элементы списка.
max1 = math.fabs(arr[0])
max2 = math.fabs(arr[0])
for i in range(1,n):
    if max1 < math.fabs(arr[i]):
        max2 = max1
        max1 = math.fabs(arr[i])
    else:
        if max2 < math.fabs(arr[i]):
            max2 = math.fabs(arr[i])
print("Наибольшие по модулю элементы: ","{0:>8.4f} {1:>8.4f}".format(max1,max2))

#2. Сумму элементов, модуль которых меньше единицы.
sum = 0
for i in range(n):
    if math.fabs(arr[i]) < 1:
        sum+=arr[i]
print("Сумма элементов, модуль которых меньше 1: ","{0:>8.4f}".format(sum))

#3. Все элементы, модуль которых превышает Amax обнулить.
for i in range(n):
    if math.fabs(arr[i]) > Amax:
        arr[i] = 0
print("Список с обнулёнными элементами: ")
for i in range(n):
    print("{0:>8.4f}".format(arr[i]))

#4. Отсортировать список, сохраняя порядок ненулевых элементов. Равные нулю
j = 0
for i in range(n):
    if math.fabs(arr[i]) > 0.00001:
        arr[j] = arr[i]
        j = j+1
for i in range(j,n):
    arr[i] = 0.0
print("Список после сортировки: ")
for i in range(n):
    print("{0:>8.4f}".format(arr[i]))
