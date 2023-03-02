from random import *
import sys

sys.stdout = open("test.in", "w")

for _ in range(100):
    n = randint(1, 100)
    print(n)
    for i in range(1, n+1):
        for _ in range(1, i+1):
            print(randint(1, 1e5), end=" ")
        print()
