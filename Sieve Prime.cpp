#include<bits/stdc++.h>
using ll=long long int;
using namespace std;
int mx=1e7,i,j,n;
int fl[10000005];
int pri[10000005];
void sieve(){
	for (i=2; i*i<mx; i++)
		if (!fl[i])
			for (j=i+i; j<mx; j+=i)
				fl[j]=1;
	for (i=2,j=1; i<=mx; i++)
		if (!fl[i]) pri[j++]=i;
}
int main(){
	sieve();
	printf("Total %d prime from 1 to %d\nn = ",j,mx);
	scanf("%d",&n);
	printf("the %dth no prime is %d\n",n, pri[n]);
	return 0;
}
