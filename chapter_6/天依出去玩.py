pre_order, in_order, post_order = [], '', ''
cnt = 0
def read_list():
    global pre_order, in_order, post_order
    in_order = input()
    post_order = input()
    pre_order = []
    in_order = list(map(int, in_order.split()))
    post_order = list(map(int, post_order.split()))


def build_pre(in_order, post_order, k):
    global pre_order, cnt
    root = post_order[-1]
    cnt += 1
    if cnt == k:
        print(root)
        return
    root_in_order = in_order.index(root)
    in_left = in_order[:root_in_order]
    in_right = in_order[root_in_order+1 : len(in_order)]
    post_left = post_order[:len(in_left)]
    post_right = post_order[len(in_left) : -1]
    if len(post_left):
        build_pre(in_left, post_left, k)
    if len(post_right):
        build_pre(in_right, post_right, k)


while 1:
    try:
        n, k = map(int, input().split())
        read_list()
    except:
        break
    build_pre(in_order, post_order, k)
    cnt = 0