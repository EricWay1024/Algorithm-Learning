def f(n):
    ans = 0
    for i in range(n + 1):
        ans ^= i
    return ans

for n in range(1, 25):
    print(n, f(n))

print(2 ^ 3 ^4)