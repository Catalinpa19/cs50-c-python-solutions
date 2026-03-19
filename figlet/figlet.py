from pyfiglet import Figlet
import sys
import random

figlet=Figlet()
fontlist=figlet.getFonts()


if len(sys.argv)==3:
    if sys.argv[1] not in ["-f", "-font"]:
        sys.exit("Invalid usage")
    if sys.argv[2] not in fontlist:
        sys.exit("Invalid usage")
    fontfig = sys.argv[2]
elif len(sys.argv)==1:
    index=random.randrange(len(fontlist))
    fontfig=fontlist[index]
else:
    sys.exit("Invalid usage")
text=input("Input: ")
figlet.setFont(font=fontfig)
print("Output: ")
print(figlet.renderText(text))




