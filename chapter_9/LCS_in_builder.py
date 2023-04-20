import sys
from random import *

sys.stdout = open('LCS.in', 'w')


T = 1000
print(T)
for _ in range(T):
    n = randint(1, 1000)
    print(n)
    m = randint(1, 1000)
    print(m)

    for _ in range(n):
        print(randint(1, 1e9 + 7), end=" ")
    print()
    for _ in range(m):
        print(randint(1, 1e9 + 7), end=" ")
    print()

    # for i in range(1, n+1):
    #     print(i, end=" ")
    # print()
    # for i in range(1, m+1):
    #     print(i, end=" ")
    # print()