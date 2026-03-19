from cs50 import get_int
while True:
    number=get_int("Your number is: ")
    if number<=8 and number>=1:
        break
for i in range(number+1):
    if i!=0:
        print(" "*number-i,end="")
        print("#"*i,end="")
        print()




