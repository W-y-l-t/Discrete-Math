from itertools import permutations

good = 0
A = [1, 2, 3, 4, 5]

perms = permutations(A)

for perm in perms:
    if ((perm[0] < perm[1] and perm[1] < perm[2]) or
        (perm[1] < perm[2] and perm[2] < perm[3]) or
        (perm[2] < perm[3] and perm[3] < perm[4]) or
        (perm[0] > perm[1] and perm[1] > perm[2]) or
        (perm[1] > perm[2] and perm[2] > perm[3]) or
        (perm[2] > perm[3] and perm[3] > perm[4])):
        continue
    good += 1

print(good)
