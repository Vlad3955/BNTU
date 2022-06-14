years = int(input("Please, enter a year: "))
if(years % 4 == 0 and years % 100 != 0) or (years % 400 == 0):
    print("Leap year")
else:
    print("Not leap")
