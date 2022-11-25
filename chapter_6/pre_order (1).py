pre_order, in_order, post_order = [], '', ''
def read_list():
    global pre_order, in_order, post_order
    in_order = input()
    if in_order == '': return
    post_order = input()
    if post_order == '': return
    pre_order = []
    in_order = list(map(int, in_order.split()))
    post_order = list(map(int, post_order.split()))

    print(in_order)
    print(post_order)


class Node(object):
    """节点类"""
    def __init__(self, data=None, l=None, r=None):
        self.data = data
        self.l = l
        self.r = r


class Tree(object):
    def __init__(self):
        self.root = Node()


    def build(self, root, L1, R1, L2, R2):
        if L1 > R1: return None
        self.root = Node(post_order[R2])
        p = in_order.index(post_order[R2])
        cnt = p - L1
        root.l = build(self.root.l, L1, p-1, L2, L2+cnt-1)
        root.r = build(self.root.r, p+1, R1, L2+cnt, R2-1)
        return self.root


    # def build(self, in_order, post_order):
    #     self.root = Node(post_order[-1])
    #     return build(self.root.l, in_order[:in_order.index(post_order[-1])], )
    #     return build(self.root.r, in_order[in_order.index(post_order[-1]) + 1:], )

    def rec_pre_order(self, node=None):
        global pre_order
        if node:
            pre_order.append(node.data)
            self.rec_pre_order(node.l)
            self.rec_pre_order(node.r)

while 1:
    if read_list() == False: break
    tree = Tree()
    tree.build(tree.root, 0, 0, len(in_order)-1, len(post_order)-1)
    tree.rec_pre_order(tree.root)
    print(pre_order)