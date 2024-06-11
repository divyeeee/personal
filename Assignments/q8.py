#program  to make a simple calculator

flag=True
while flag :
    a=int(input("Enter the first number: "))
    b=int(input("Enter the second number: "))
    op=input("Enter the operator: ")
    
    if op=="+":
        print(a+b)
            
    elif op=="-":
        print(a-b)
            
    elif op=="*":
        print(a*b)
        
    elif op=="/":
        print(a/b)
            
    else:
        print("Invalid operator")
            
    q=input("Do you want to continue? (y/n): ")
    if q=="n":
        flag=False