#program to find lcm and gcd of two numbers
a=int(input("Enter first number: "))
b=int(input("Enter second number: "))
for i in range(min(a,b),1,-1):
    if a%i==0 and b%i==0:
        gcd=i
        break
lcm=a*b/gcd
print("GCD of",a,"and",b,"is",gcd)
print("LCM of",a,"and",b,"is",lcm)
