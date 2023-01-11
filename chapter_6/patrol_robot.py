# 重定向
# import sys
# sys.stdin = open(r'patrol_robot.in', 'r') 
# sys.stdout = open(r'patrol_robot.out', 'w')

def read_lines(m):
    pic = []
    for _ in range(m):
        pic.append(list(map(int, input().split())))
    return pic

def check(x, y, m, n):
    if (x < 0 or y < 0 or x > m or y > n):
        return True
    return False

def bfs(x, y, m, n, k):
    global pic, vis
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    q = [[x, y, 0, 0]]  # 利用列表[x, y, step, cnt]存储状态，q为队列
    while len(q):
        t = q[0]
        if t[0] == m and t[1] == n:
            return t[2]
        for i in range(4):
            px = t[0] + dx[i]
            py = t[1] + dy[i]
            if check(px, py, m, n):
                continue
            tmp = [px, py, t[2], t[3]]
            if pic[px][py]:
                tmp[3] += 1
            else:
                tmp[3] = 0
            if tmp[3] <= k and vis[px][py][tmp[3]] == False:
                tmp[2] += 1
                vis[px][py][tmp[3]] = True
                q.append(tmp)
        q.pop(0)
    return -1


for _ in range(int(input())):
    m, n = map(int, input().split())
    k = int(input())
    pic = read_lines(m)
    vis = [[[False]*21 for _ in range(n)] for _ in range(m)]
    print(bfs(0, 0, m-1, n-1, k))