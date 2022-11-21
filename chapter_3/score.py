n, score = 1, 0
for i in input():
    if i == 'O':
        score += n
        n += 1
    else:
        n = 1
print(score)