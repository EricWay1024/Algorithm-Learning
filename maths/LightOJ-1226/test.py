def solve(l):
    from math import factorial
    ans = factorial(sum(l))
    for i in l:
        ans //= factorial(i)
    # ans //= factorial(len(l))
    return ans

print(solve([2, 2, 3]))