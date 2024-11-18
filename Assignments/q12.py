#program to print the elements of a list in reverse order
ls=[]
n=int(input("Enter the number of elements in the list: "))
for i in range(n):
    ls.append(input("Enter the element: "))
print("The elements of the list in reverse order are: ")
for i in range(n-1,-1,-1):
    print(ls[i])