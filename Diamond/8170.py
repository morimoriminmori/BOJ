for i in range(int(input())):
  a=int(input())
  l=list(map(int,input().split()))
  res=0
  if~a&1:
    for i in range(a//2):res^=(l[2*i+1]-l[2*i])
  else:
    res^=l[0]
    for i in range(a//2):res^=(l[2*i+2]-l[2*i+1])
  if res==0:print("NIE")
  else:print("TAK")
