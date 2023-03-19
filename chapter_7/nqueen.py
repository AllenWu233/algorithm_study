import time


def print_solve():
    global tot, n, C
    print(f"解：{tot}")
    for i in range(n):
        print(f"({i},{C[i]})", end=" ")
    print()


def search(cur):
    global C, vis, tot, n, nc
    nc += 1
    if cur == n:
        tot += 1
        # if cur == n:
        #     print_solve()
    else:
        for i in range(n):
            if vis[0][i] == 0 and vis[1][cur+i] == 0 and vis[2][cur-i+n] == 0:
                C[cur] = i
                vis[0][i] = 1
                vis[1][cur+i] = 1
                vis[2][cur-i+n] = 1
                search(cur+1)
                vis[0][i] = 0
                vis[1][cur+i] = 0
                vis[2][cur-i+n] = 0


while 1:
    start = time.time()

    C = [0]*30
    vis = [[0]*30 for _ in range(3)]
    tot = 0
    n = 0
    nc = 0
    try:
        n = int(input())
    except:
        print("error.")
    search(0)
    print(f"解的个数：{tot}")
    print(f"递归次数：{nc}")

    end = time.time()
    print('程序执行时间: ', end - start)
