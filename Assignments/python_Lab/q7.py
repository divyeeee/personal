num=[]
print("Enter 5 numbers")
for _ in range(5):
    num.append(int(input()))
def max_num(num):
    max=num[0]
    for i in num:
        if i>max:
            max=i
    return max
def min_num(num):
    min=num[0]
    for i in num:
        if i<min:
            min=i
    return min
print("Max number is",max_num(num))
print("Min number is",min_num(num))
    
    