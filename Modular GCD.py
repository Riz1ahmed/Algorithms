import math
t=int(input())
for cs in range(t):
    a, b, n = map(int,input().split())
    ab=a-b
    M=(int)(1e9+7)
    if (ab==0):
    	ans=pow(a,n)+pow(b,n)%M
    	print(ans)
    else:
    	ans=pow(a,n,ab)+pow(b,n,ab)%ab
    	ans=math.gcd(ans,ab)%M
    	print(ans)
