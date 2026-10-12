a = float(input("a: "))
b = float(input("b: "))

def h(x, y, z):
    return (x + y + z) / (x ** 2 + y ** 2)

div = h(1, a*b, 1)
if div == 0:
    print("Gives no definition")
else:
    c = (h(a ** 2, 1, b) + h(b, 1, a ** 2)) / div
    print(round(c, 2))