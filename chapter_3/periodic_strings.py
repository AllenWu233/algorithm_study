n = int(input())
while n:
    n -= 1
    s = input()
    for k in range(1, len(s)):
        if len(s) % k != 0:
            continue
        for i in range(1, len(s)//k):
            if s[k*i : k*(i+1)] == s[:k]:
                flag = True
                continue
            else:
                flag = False
                break
        if flag:
            print(k)
            break
        else:
            continue
    if flag == False:
        print(len(s))