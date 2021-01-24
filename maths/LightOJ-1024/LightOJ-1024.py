def gcd(a, b):
    return gcd(b, a % b) if b != 0 else a

def lcm(a, b):
    return a // gcd(a, b) * b

from functools import reduce
t=int(input())
for i in range(1, t+1):
    n=int(input())
    l=list(map(int, input().split(' ')))
    ans = reduce(lcm, l, 1)
    print('Case %d: %d' % (i, ans))