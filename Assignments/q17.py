#program to print fibonacci series using recursion upto n terms
def fibonacci(n):
    if n<=1:
        return n
    else:
        return(fibonacci(n-1)+fibonacci(n-2))
n=int(input("Enter the number of terms:"))
if n<=0:
    print("Enter a positive integer")
else:
    print("Fibonacci series:")
    for i in range(n):
        print(fibonacci(i))
        