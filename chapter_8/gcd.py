def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
while 1:
    try:
        a, b = map(int, input("输入两个数：").split())
        print(f"{a}和{b}的最大公约数为：{gcd(a, b)}\n")
    except:
        print("Error.")