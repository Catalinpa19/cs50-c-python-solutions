greeting=input("Greeting: ")
greeting=greeting.split()
copy=greeting[0]
copy=copy[0:5].lower()

if copy=="hello":
    print("$0")
elif copy[0]=="h":
    print("$20")
else:
    print("$100")
