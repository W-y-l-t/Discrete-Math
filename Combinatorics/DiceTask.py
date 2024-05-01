good = 0
bad = 0
for i in range(1, 5):
    for j in range(1, 7):
        for k in range(1, 9):
            if i + j + k == 12:
                good += 1
            else:
                bad += 1
print(good / (good + bad))
