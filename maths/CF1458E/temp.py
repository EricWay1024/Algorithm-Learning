# lose_states = [(0, 0), (3, 0), (2, 1)]
lose_states = [(0, 0), (3, 0), (0, 1)]

def check(x, y):
    if (x, y) in lose_states:
        return False
    
    for i in range(x):
        if not check(i, y):
            return True
    
    for j in range(y):
        if not check(x, j):
            return True
    
    return False

for x in range(0, 10):
    for y in range(0, 10):
        res = check(x, y)
        if not res:
            print(x, y, check(x, y))