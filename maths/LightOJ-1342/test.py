from random import randrange
def test(m):
    taken = set()
    cnt = 0
    while len(taken) < m:
        r = randrange(0, m)
        taken.add(r)
        cnt += 1
    return cnt

def repeated_test(m):
    T = 100000
    return sum(test(m) for _ in range(T)) / T

for m in range(1, 30):
    ret = repeated_test(m)
    print(m, ret, ret/m, sum(1/i for i in range(1, m+1)))