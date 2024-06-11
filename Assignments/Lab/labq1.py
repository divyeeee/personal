import sys
a=1234567891234567891
b=69.98758
c="helloworld"
d=[23,"HEY THERE",69.6969]
e={"Divye":1,"Vaibhav":2,"Mishra":3}
f={112,'s',45.98}
g=tuple(("Divye","Vaibhav","Mishra","will","be"))
for i in [a,b,c,d,e,f,g]:
    print(sys.getsizeof(i))


for i in range(1,10):
    print(i)