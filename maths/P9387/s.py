MOD = int(1e9+7)

def solve(n, mem):
    if n == 0:
        return 0
    if mem[n] > -1:
        return mem[n]
    st = set()
    for b in range(1, n + 1):
        r = n - b
        for a in range(r + 1):
            c = r - a
            i = a ^ c
            st.add(solve(i, mem))
    i = 0
    while True:
        if i not in st:
            mem[n] = i
            return i
        i += 1

def f2(y, x):
    ans = 0
    for s in range(x):
        for a in range(s + 1):
            c = s - a
            if (a ^ c ^ x) == y:
                ans += 1
    return ans

def quick_pow(a, b):
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % MOD
        a = a * a % MOD
        b >>= 1
    return ans

def f(s, x, i):
    p = 1 << i
    if p == 2:
        return 1 if x == 1 and s == 1 else 0
    q = 1 << (i - 1)
    if s < q:
        if x < q:
            return f(s, x, i - 1)
        else:
            return (2 * f(s, x - q, i - 1)) % MOD
    else:
        if x < q:
            return 0
        else:
            return (q - f(p - 1 - s, p - 1 - x, i - 1)) % MOD

def g(s, i):
    p = 1 << i
    if p == 2:
        return 1 if s == 1 else 0
    if s < p // 2:
        return 3 * g(s, i - 1) % MOD
    else:
        return (quick_pow(2, 2 * i - 2) - g(p - 1 - s, i - 1)) % MOD

def h(s, x, i):
    p = 1 << i
    if p == 2:
        return 1 if x == 1 and s == 1 else 0
    if x == p - 1:
        return g(s, i)
    q = 1 << (i - 1)
    if s < q:
        if x < q:
            return h(s, x, i - 1)
        else:
            return (g(s, i - 1) + 2 * h(s, x - q, i - 1) % MOD) % MOD
    else:
        if x < q:
            return 0
        else:
            return ((g(s, i) - ((p - 1 - x) * q % MOD)) + h(p - 1 - s, p - 2 - x, i - 1)) % MOD

def calc(n):
    j = n % 4
    if j == 0:
        return n
    elif j == 1:
        return 1
    elif j == 2:
        return n + 1
    else:
        return 0

if __name__ == "__main__":
    # Uncomment and use these lines for debugging or specific functionality
    # mem = [-1] * 100
    # for i in range(1, 31):
    #     print(i, solve(i, mem))
    
    # n = 6
    # for i in range(1 << n):
    #     ans = 0
    #     for j in range(1 << n):
    #         ans += f2(i, j)
    #         assert f2(i, j) == f(i, j, 61)
    #         assert ans == h(i, j, 61), f"{i}, {j}, {ans}, {h(i, j, 61)}"
    #     assert ans == g(i, n)
    #     print(i)
    
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        s = calc(n) ^ m
        ans = (f(s, m, 61) + h(s, n, 61)) % MOD
        ans = (ans + MOD) % MOD
        print(ans)
