from cs50 import get_int

def main():
    n=get_int("Number: ")
    if card(n):
        while n>99:
            n//=10
        if n==51 or n==52 or n==53 or n==54 or n==55:
            print("MASTERCARD")
        elif n==34 or n==37:
            print("AMEX")
        elif n // 10 == 4 or n == 4:
            print("VISA")
        else:
            print("INVALID")

    else:
        print("INVALID")






def card(n):
    if n<=999999999999:
       return False
    poz=0
    sum1=0
    sum2=0
    while n!=0:
        if poz%2==0:
            sum1+=n%10
        else:
            sum2+=(((n%10)*2)%10+((n%10)*2)//10)
        n//=10
        poz+=1
    if (sum1+sum2)%10==0:
        return True
    else:
        return False

main()
