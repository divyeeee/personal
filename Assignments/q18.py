#program to swap two numbers
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))
print("Before swapping: a = ", a, "b = ", b)
a = a + b
b = a - b
a = a - b
print("After swapping: a = ", a, "b = ", b)