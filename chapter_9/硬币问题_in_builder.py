from random import *
import sys

sys.stdout = open("coins.in", "w")

MAXN = 1
MAXV = 100
MAXS = 10000


print(MAXN)
for _ in range(MAXN):
    n = randint(1, MAXV)
    print(n)
    lis = []
    while len(lis) < n:
        v = randint(1, MAXV)
        if v == 1:
            continue
            if random() < 0.6:
                continue
        if v not in lis:
            lis.append(v)
        lis = sorted(lis)
    for i in lis:
        print(i, end=" ")
    print()
    print(randint(1, MAXS))

