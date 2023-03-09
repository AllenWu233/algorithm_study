from random import *
import sys

sys.stdout = open("number_triangle.in", "w")

MAXN = 100  # 数组组数
MAXM = 100  # 数据范围（上界）

for _ in range(MAXN):
    n = randint(1, MAXM)
    print(n)
    for i in range(1, n+1):
        for _ in range(1, i+1):
            print(randint(1, 1e5), end=" ")
        print()
