pre_order, in_order, post_order = [], '', ''
def read_list():
    global pre_order, in_order, post_order
    in_order = input()
    post_order = input()
    pre_order = []
    in_order = list(map(int, in_order.split()))
    post_order = list(map(int, post_order.split()))


def build_pre(in_order, post_order):
    """递归构建二叉树的先序遍历"""
    global pre_order

    # 直观地看到递归的步骤
    print("in_order   = ", in_order)
    print("post_order = ", post_order)
    print("pre_order  = ", pre_order, "\n")

    root = post_order[-1]
    pre_order.append(root)  # 所谓先序遍历，只需在构建子树时记录下根节点即可

    root_in_order = in_order.index(root)
    in_left = in_order[:root_in_order]
    in_right = in_order[root_in_order+1 : len(in_order)]
    post_left = post_order[:len(in_left)]
    post_right = post_order[len(in_left) : -1]
    if len(post_left):
        build_pre(in_left, post_left)
    if len(post_right):
        build_pre(in_right, post_right)


while 1:
    try:
        read_list()
    except:
        break
    build_pre(in_order, post_order)
    print("PreOrder: ", end='')
    for i in pre_order:
        print(i, end=' ')
    print("\n")