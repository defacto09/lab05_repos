import math as m

def z(x):
    if abs(x) >= 1:
        return (1 - m.sin(x)) / ((m.exp(x)) + (m.cos(x) ** 2))
    if abs(x) < 1:
        return 1/(m.exp(-x)) * summary(x)
    
def summary(x, j_max = 7):
    a = 1
    j = 1
    S = 1
    while j <= 7:
        R = - x / (((2*j)- 1) * (2*j))
        a *= R
        S += a
        j += 1
    return S

def main():
    kp = float(input("kp: "))
    kk = float(input("kk: "))
    n = int(input("n: "))
    dk = (kk - kp) / n
    k = kp
    print(f"{'K':>6} | {'Y':>6}")
    while k <= kk:
        y = z(1 - k ** 2) + (z(1 + z(k)))** 2
        print(f"{k:4.4f} | {y:4.4f}")
        k += dk

if __name__ == "__main__":
    main()

