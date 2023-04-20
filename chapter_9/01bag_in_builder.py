from random import *
import sys

sys.stdout = open("01bag.in", "w")

T = 10
MAXN = 100
MAXC = 10000


print(T)
for _ in range(T):
    n = randint(1, MAXN)
    print(n)
    c = randint(1, MAXC)
    print(c)
    vw = []
    while len(vw) < n:
        v = randint(1, c)
        w = randint(1, c)
        if (v, w) not in vw:
            vw.append((v, w))
    vw.sort()
    for i in vw:
        print(i[0], i[1])