import math

def get_elem(n):
    if math.fabs(n) < 1:
        return math.log((1+n)/(1-n))
    else: return ""

def main():
    print("Введите значения")
    xb = float(input("Хнач = "))
    xe = float(input("Хкон = "))
    dx = float(input("Dx = "))
    print("Хнач={0: 7.2f} Хкон={1: 7.2f}".format(xb, xe))
    print("Dx={0: 7.2f}".format(dx))
    xt = xb
    print("+---------+-----------+")
    print("I    X    I Результат I")
    print("+---------+-----------+")
    while xt <= xe:
        y = get_elem(xt)
        print("{0: 0.2f}".format(xt), "     ", y)
        xt += dx
    print("+---------+-----------+")

main()
    
        
    
