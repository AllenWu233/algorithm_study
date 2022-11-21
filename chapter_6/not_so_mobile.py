def solve(W):
    b1, b2 = True, True
    W1, D1, W2, D2 = map(int, input().split())
    if W1 == 0: b1 = solve(W1)
    if W2 == 0: b2 = solve(W2)
    W = W1 + W2
    return b1 and b2 and (W1*D1 == W2*D2)


W = 0
T = int(input())
while T > 0:
    T -= 1
    print("YES") if solve(W) else print("No")
    if T: print("\n")