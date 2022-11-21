import random

D = 20
I = 1<<20
file = 'data.in'
with open(file, 'w') as f:
    for _ in range(100):
        f.write(f"{random.randint(1, D)} {random.randint(1, I)}\n")

