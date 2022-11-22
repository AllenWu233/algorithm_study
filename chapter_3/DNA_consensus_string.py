# UVa1368
T = int(input())
while T:
    T -= 1
    m, n = map(int, input().split())
    DNAs, hammings = [], []
    for _ in range(m):
        DNAs.append(input())

    # print(DNAs)

    for i in range(m):
        hamming = 0
        for j in range(m):
            if i == j:
                continue
            for k in range(n):
                if DNAs[i][k] != DNAs[j][k]:
                    hamming += 1
        hammings.append(hamming)

    # print(hammings)

    min_dna = ''
    for i in range(m):
        if hammings[i] == min(hammings):
            if min_dna == '':
                min_dna = DNAs[i]
            else:
                if min_dna > DNAs[i]:
                    min_dna = DNAs[i]

    print(min_dna)
    print(hammings[DNAs.index(min_dna)])