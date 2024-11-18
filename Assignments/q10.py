#program to add two matrices
r1 = int(input("Enter the number of rows for first matrix: "))
c1 = int(input("Enter the number of columns for first matrix: "))
r2 = int(input("Enter the number of rows for second matrix: "))
c2 = int(input("Enter the number of columns for second matrix: "))
if r1 != r2 or c1 != c2:
    print("Matrices cannot be added")
    exit()
else:
    print("Enter the elements of first matrix: ")
    matrix1 = []
    for i in range(r1):
        a = []
        for j in range(c1):
            a.append(int(input()))
        matrix1.append(a)
    print("Enter the elements of second matrix: ")
    matrix2 = []
    for i in range(r2):
        a = []
        for j in range(c2):
            a.append(int(input()))
        matrix2.append(a)
    result = []
    for i in range(r1):
        a = []
        for j in range(c1):
            a.append(matrix1[i][j] + matrix2[i][j])
        result.append(a)
    print("The sum of the two matrices is: ")
    for i in range(r1):
        for j in range(c1):
            print(result[i][j], end = " ")
        print()    