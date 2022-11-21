import random


def oil(m, n, file):
    with open(file, 'a') as f:
        f.write(f"{m} {n}\n")
        for _ in range(m):
            for _ in range(n):
                if random.randint(0,1):
                    f.write("*")
                else:
                    f.write("@")
            f.write("\n")


if __name__ == '__main__':
    file = 'data_oil.in'
    with open(file, 'w') as f:
        f.write("")
    for _ in range(100):
        m = random.randint(1, 100)
        n = random.randint(1, 100)
        oil(m, n, file)