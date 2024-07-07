# input boolean function number

print("How you want to insert boolean function? \n"
      "1. By boolean function number \n"
      "2. By min terms \n"
      "3. By XOR of two boolean function numbers \n"
      "4. By the values of the function in the truth table\n")

key = int(input())

f_value = ""

if key == 1:
    print("Enter Boolean function number")

    data = int(input())
    f_value = bin(data)[2::]
else:
    if key == 2:
        print("Enter min terms")

        data = list(map(int, input().split(' ')))
        now = 0
        for i in range(0, 2 ** 4):
            if now < len(data) and data[now] == i:
                f_value += '1'
                now += 1
            else:
                f_value += '0'
    else:
        if key == 3:
            print("Enter first boolean function number")
            first = int(input())
            print("Enter second boolean function number")
            second = int(input())

            f_value = bin(first ^ second)[2::]
        else:
            if key == 4:
                f_value = input()
            else:
                print("Invalid request")
                exit(1)

while len(f_value) < 2 ** 4:
    f_value = '0' + f_value
print(f_value)

# combination of values A, B
height_values = ['00', '01', '11', '10']
# combination of values C, D, E
width_values = ['00', '01', '11', '10']

k_map = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

# print K - map
print("The Karnaugh map")
print("       ", end="")

for CD in width_values:
    print(CD, end="    ")

print()
print("   " + "-" * 24)

for AB in height_values:
    print(f"{AB} |", end="    ")
    for CD in width_values:
        index = int('0b' + AB + CD, 2)
        k_map[index] = int(f_value[index])
        print(k_map[index], end="     ")
    print()
print()

order = ['0000', '1000', '0100', '0010', '0001', '1100', '1010', '1001',
         '0110', '0101', '0011', '1110', '1101', '1011', '0111', '1111']

# construct ANF (Zhegalkin polynomial) using Karnaugh map

ANF = []

for now in range(0, len(order)):
    index = int('0b' + order[now], 2)
    if k_map[index] == 1:
        if index == 0:
            ANF.append('1')
            for i in range(0, len(k_map)):
                k_map[i] = (1 - k_map[i])
        else:
            s = ''
            if order[now][0] == '1':
                s += 'A'
            if order[now][1] == '1':
                s += 'B'
            if order[now][2] == '1':
                s += 'C'
            if order[now][3] == '1':
                s += 'D'
            ANF.append(s)
            for i in range(0, len(order)):
                ind = int('0b' + order[i], 2)
                flag = True
                if order[now][0] == '1':
                    flag = (flag and (order[i][0] == '1'))
                if order[now][1] == '1':
                    flag = (flag and (order[i][1] == '1'))
                if order[now][2] == '1':
                    flag = (flag and (order[i][2] == '1'))
                if order[now][3] == '1':
                    flag = (flag and (order[i][3] == '1'))
                if flag:
                    k_map[ind] = (1 - k_map[ind])

print("Zhegalkin polynomial")
for i in range(0, len(ANF)):
    if i == len(ANF) - 1:
        print(ANF[i])
    else:
        print(ANF[i], end=" xor ")
