import random, math
n = int(input("Введите размер массива N: "))
arr = []
print("Исходный одномерный список: ")
for i in range(n):
    arr.append(random.uniform(-100,100))
    print("{0:>8.4f}".format(arr[i]))

#1. Сумму отрицательных элементов.
sum = 0
for i in arr:
    if i < 0:
        sum+=i
print("Сумма отрицательных элементов: ","{0:>8.4f}".format(sum))

    
#2. Произведение элементов, расположенных между максимальным и минимальным элементами.
maxi = 0
mini = 0
for i in range(1,n):
    if arr[i] > arr[maxi]:
        maxi = i
    if arr[i] < arr[mini]:
        mini = i
if maxi > mini:
    n = mini
    m = maxi
else:
    n = maxi
    m = mini
    
res = 1
for i in range(n,m):
    res *=arr[i]
print("Произведение элементов, расположенных между максимальным и минимальным: ","{0:>8.4f}".format(res))

#Сортировка
arr.sort()
print("Отсортированный одномерный список: ")
for i in arr:
    print("{0:>8.4f}".format(i))
