import math as m


def A(a, n, x):
    R = x * x * (2*n - 1) / (2*n + 1)
    a *= R
    return a


def Sum(x, eps):
    n = 0
    a = x
    s = 0
    while True:
        n += 1
        if abs(a) >= eps:
            s += a
            a = A(a, n, x)
        if abs(a) <= eps:
            break
    return 2 * s, n


def main():
    xp = float(input("xp: "))
    while not (-1 < xp < 1):
        xp = float(input("xp: "))

    xk = float(input("xk: "))
    while not (-1 < xk < 1):
        xk = float(input("xk: "))

    dx = float(input("dx: "))
    eps = float(input("eps: "))

    print(f"{'X':>7} | {'n':>4} | {'S':>7} | {'ln':>7}")
    x = xp
    while x <= xk:
        s, n = Sum(x, eps)
        ln = m.log((1 + x) / (1 - x))
        print(f"{x:7.4f} | {n:4d} | {s:7.4f} | {ln:7.4f}")
        x += dx


if __name__ == "__main__":
    main()