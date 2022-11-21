# 1/n**2 + 1/(n+1)**2 + ... + 1/m**2
while 1:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    sum = 0;
    for i in range(n, m+1):
        sum += 1 / (i*i)
    print('%.6f' % sum)