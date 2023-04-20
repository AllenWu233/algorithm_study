import sys
from random import *

sys.stdout = open('LIS.in', 'w')


T = 100
print(T)
for _ in range(T):
    n = randint(1, 1000)
    print(n)
    for _ in range(n):
        print(randint(1, 1e9 + 7), end=" ")
    print()