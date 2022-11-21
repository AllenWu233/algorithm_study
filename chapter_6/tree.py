in_order, post_order = [], []
lch, rch = [0]*10010, [0]*10010
n = 0


def read_list(a):
    global n
    line = list(map(int, input().split()))
    if line == []:
        return False
    a += line
    n = len(a)
    return n


def build(L1, R1, L2, R2):
    global lch, rch
    if L1 > R1:
        return 0
    root = post_order[R2]
    p = L1
    while in_order[p] != root:
        p += 1
    cnt = p - L1
    lch[root] = build(L1, p-1, L2, L2+cnt-1)
    rch[root] = build(p+1, R1, L2+cnt, R2-1)
    return root


best, best_sum = 0, 0
def dfs(u, sum):
    global best, best_sum, lch, rch
    sum += u
    if lch[u] == 0 and rch[u] == 0:
        if sum < best_sum or (sum == best_sum and u < best):
            best = u
            best_sum = sum
    if lch[u]: dfs(lch[u], sum)
    if rch[u]: dfs(rch[u], sum)


while read_list(in_order):
    read_list(post_order)
    build(0, n-1, 0, n-1)
    best_sum = 1000000000
    dfs(post_order[n-1], 0)
    print(best)
    in_order, post_order = [], []  # 清空列表