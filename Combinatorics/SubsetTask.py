good = 0
A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
for i in range(0, 1 << 12):
    temp = []
    for j in range(0, 12):
        if i & (1 << j) != 0:
            temp.append(A[j])
    flag = True
    for j in temp:
        if (j - 3) in temp:
            flag = False
            break
    good += flag
print(good)
