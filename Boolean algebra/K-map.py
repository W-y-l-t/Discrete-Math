# input boolean function number
print("Enter Boolean function number")
data = int(input())
f_value = bin(data)[2::]
while len(f_value) < 2 ^ 4:
    f_value = '0' + f_value

# combination of values A, B
height_values = ['00', '01', '11', '10']
# combination of values C, D, E
width_values = ['00', '01', '11', '10']

# print K - map
print("The Karnaugh map")
print("       ", end="")

for CD in width_values:
    print(CD, end="    ")

print()
print("   " + "-" * 24)

for AB in height_values:
    print(f"{AB} |", end="    ")
    for CDE in width_values:
        index = '0b' + AB + CDE
        print(f_value[int(index, 2)], end="     ")
    print()
print()
