import math
num = int(input('Введите чило- '))
base = int(input("Основание (2-9): "))
if not(2 <= base <= 9):
    quit()

new_num = ''

while num > 0:
    new_num = str(num % base) + new_num
    num //= base

print(new_num)
