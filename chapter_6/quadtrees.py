length = 32
maxn = 1024 + 10
buf = []
cnt = 0


def draw(s, p, r, c, w):
    global cnt, buf
    ch = s[p]
    p += 1
    if ch == 'p':
        draw(s, p, r,      c+w//2, w//2)  # 1
        draw(s, p, r,      c,      w//2)  # 2
        draw(s, p, r+w//2, c,      w//2)  # 3
        draw(s, p, r+w//2, c+w//2, w//2)  # 4
    elif ch == 'f':
        for i in range(r, r+w):
            for j in range(c, c+w):
                if buf[i][j] == 0:
                    buf[i][j] = 1
                    cnt += 1
    else:
        pass


T = int(input())
while T:
    T -= 1
    buf = [[0]*length for _ in range(length)]
    cnt = 0
    for _ in range(2):
        s = input()
        p = 0
        draw(s, p, 0, 0, length)
    print(f"There are {cnt} black pixels.")