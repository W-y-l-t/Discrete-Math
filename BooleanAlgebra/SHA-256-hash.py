import hashlib

# Hash calculation
text = "DM Fall 2023 HW3"
my_hash = hashlib.sha256(text.encode("UTF-8"))
my_hash_binary = bin(int(my_hash.hexdigest(), 16))[2:].zfill(256)

print("HEX SHA-256 hash")
print(my_hash.hexdigest())
print()

print("BINARY SHA-256 hash")
print(my_hash_binary)
print()

# Slice hash to 32-bit length parts
hash_slices = []
for i in range(1, (256 // 32) + 1):
    hash_slices.append(('0b' + my_hash_binary[32 * (i - 1): 32 * i]))

print("Sliced hash")
for i in range(0, len(hash_slices)):
    print(hash_slices[i][2::])
print()

# XOR calculation
xor = 0
for i in range(0, len(hash_slices)):
    xor ^= int(hash_slices[i], 2)
xor ^= 0x24d03294

xor = bin(xor)[2:]
while len(xor) != 32:
    xor = '0' + xor

print("XOR")
print(xor)
print()

# combination of values A, B
height_values = ['00', '01', '11', '10']
# combination of values C, D, E
width_values = ['000', '001', '011', '010', '110', '111', '101', '100']

# print K - map
print("The Karnaugh map")
print("       ", end="")

for CDE in width_values:
    print(CDE, end="   ")

print()
print("   " + "-" * 49)

for AB in height_values:
    print(f"{AB} |", end="    ")
    for CDE in width_values:
        index = '0b' + AB + CDE
        print(xor[int(index, 2)], end="     ")
    print()
print()
