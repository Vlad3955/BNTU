import random
n = int(input("Введите размер матрицы (NxN): "))
A = []
for i in range(n):
    B = []
    for j in range(n):
        k = float(input("Введите число: "))
        B.append(k)
    A.append(B)

print("Сформированная матрица размером 4x4")
for i in range(n):
    for j in range(n):
        print(A[i][j], end = '  ')
    print()
print()

o = 0
for i in range(n):
    nonzero = True
    for j in range(n):
        if A[i][j]==0: nonzero = False
    if nonzero: o+=1
print("Количество строк без нулевых элементов: ", o)

C = []
for i in range(n):
    for j in range(n):
        C.append(A[i][j])

D = []
l = len(C)
for i in range(l):
    for j in range(i+1,l):
        if(C[i]==C[j]):
            D.append(C[i])
E = set(D)
m = max(E)
print("Наибольшее число из встречающихся более  раза: ",m)
