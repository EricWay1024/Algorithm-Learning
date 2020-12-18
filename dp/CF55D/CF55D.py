def judge(n):
    nn = n
    while n:
        k = (n % 10)
        if k >= 2 and (nn % k) != 0:
            return False
        n //= 10
    
    return True

def count(l, r):
    s = 0
    for n in range(l, r + 1):
        j = judge(n)
        # if j:
        #     print("n =", n)
        s += j
    return s



t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    print(count(l, r))