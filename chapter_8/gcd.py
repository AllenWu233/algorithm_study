def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
try:
    a, b = map(int, input().split())
    print(gcd(a, b))
except:
    print("Error.")