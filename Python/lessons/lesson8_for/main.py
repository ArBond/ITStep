word = 'word'
for i in word:
    print(i)


print("\nCounting:")
for i in range(10):
    print(i)

print("\nCounting:")
for i in range(0, 21, 2):
    print(i, end=" ")


print("\n")
i = 1
for color in 'yellow', 'orange', 'red', 'green', 'blue':
    print("#", i, "color of rainbow is", color, sep=" ")
    i += 1


message = input("\nEnter a message: ")
new_message = ""
VOWELS = "aeiouy"
print()
for letter in message:
    if letter.lower() not in VOWELS:
        new_message += letter
        print("A new string:", new_message)
print("\nYour message without vowels is:", new_message)