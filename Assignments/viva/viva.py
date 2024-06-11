#program to calculate sum of a list of number using recursion
n=int(input("Enter the number of elements in the list: "))
l=[]
for i in range(n):
    l.append(int(input("Enter the element: ")))
def sum_list(l,n):
    if n==0:
        return 0
    else:
        return l[n-1]+sum_list(l,n-1)
print("The sum of the list is: ",sum_list(l,n))
