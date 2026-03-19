from cs50 import get_float
while True:
    change=get_float("Change: ")
    if change>=0:
      break
contor=0
while change!=0:
   if change>=0.25:
      change-=0.25
      contor+=1
   elif change>=0.10:
      change-=0.10
      contor+=1
   elif change>=0.05:
      change-=0.05
      contor+=1
   elif change>=0.01:
      change-=0.01
      contor+=1
   change=round(change,2)
print(contor)
