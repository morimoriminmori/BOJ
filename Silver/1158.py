n,k=map(int,input().split())
a=list(range(1,n+1));r=[];i=0
while a:
    i=(i+k-1)%len(a)
    r.append(str(a.pop(i)))
print(f"<{', '.join(r)}>")
