#program to find transpose of any matrix
r=int(input("Enter the number of rows: "))
c=int(input("Enter the number of columns: "))
matrix=[]
for i in range(r):
    a=[]
    for j in range(c):
        a.append(int(input()))
    matrix.append(a)
for i in range(c):
    for j in range(r):
        print(matrix[j][i],end=" ")
    print()
