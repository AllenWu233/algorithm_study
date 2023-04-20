from random import *
import sys

sys.stdout = open("coins.in", "w")

T = 100
MAXN = 100
MAXS = 10000


print(T)
for _ in range(T):
    n = randint(1, MAXN)
    s = randint(1, MAXS)
    print(n)
    lis = []
    while len(lis) < n:
        v = randint(1, s)
        if v == 1 and random() < 0.6:
            continue
        if v not in lis:
            lis.append(v)
    lis = sorted(lis)
    for i in lis:
        print(i, end=" ")
    print()
    print(s)

