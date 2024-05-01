count = 0
for i in range(-5, 6):
    for j in range(i, 6):
        for k in range(j, 6):
            if i + j + k == 5:
                count += 1
print(count)

