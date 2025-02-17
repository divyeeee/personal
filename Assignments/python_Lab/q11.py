#program to multiply two matrices
def input_matrix(r,c):
    
    matrix = []
    for i in range(r):
        row = []
        for j in range(c):
            row.append(int(input("Enter the element: ")))
        matrix.append(row)
    return matrix
r1= int(input("Enter the number of rows: "))
c1= int(input("Enter the number of columns: "))
matrix1 = input_matrix(r1,c1)
r2= int(input("Enter the number of rows: "))
c2= int(input("Enter the number of columns: "))
matrix2 = input_matrix(r2,c2)
if c1==r2:
    result = [[0 for j in range(c2)] for i in range(r1)] #initializing the result matrix, it will have r1 rows and c2 columns, all elements will be 0, this is a nested list comprehension, it is equivalent to:, result = [] for i in range(r1): a = [] for j in range(c2): a.append(0) result.append(a), this is a more compact way of writing the same thing,
    for i in range(r1):
        for j in range(c2):
            for k in range(r2):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    print("The product of the two matrices is: ")
    for i in range(r1):
        for j in range(c2):
            print(result[i][j], end=" ")
        print()
