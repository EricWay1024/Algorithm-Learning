import random
def test(n, k):
    lights = [0 for _ in range(n)]
    for _ in range(k):
        x1 = random.randrange(0, n)
        x2 = random.randrange(0, n)
        if x1 > x2:
            x2, x1 = x1, x2
        for i in range(x1, x2 + 1):
            lights[i] = 1 - lights[i]
    return sum(lights)

def repeated_test(n, k, T):
    return sum(test(n, k) for _ in range(T)) / T

T = 1000000

for k in range(1, 11):
    ans = repeated_test(4, k, T)
    print(k, ans, 1/(ans - 2))