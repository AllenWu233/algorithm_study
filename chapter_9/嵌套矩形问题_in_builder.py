from random import *
import sys

sys.stdout = open("nested_rectangle.in", "w")

MAXN = 100
MAXM = 100


print(MAXN)
for _ in range(MAXN):
    n = randint(1, MAXM)
    print(n)
    for _ in range(n):
        print(randint(1, MAXM), randint(1, MAXM))

