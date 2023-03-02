#!/usr/bin/python3
import sys
from random import randint

sys.stdout = open(r"paintball.in", "w")

for _ in range(1000):
    n = randint(1, 1000)
    print(n)
    for _ in range(n):
        print(f"{randint(0, 1000)} {randint(0, 1000)} {randint(0, 100)}")

