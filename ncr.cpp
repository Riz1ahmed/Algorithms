#include <cstdio>
#define ll long long int
#define S (int)1e6
ll ncr[S][10];
ll nCr(ll n,ll r){
	if (!r || n==r) return 1;
	if (ncr[n][r]) return ncr[n][r];
	return ncr[n][r]=nCr(n-1,r-1)+nCr(n-1,r);
}
int main(){
	int n=100,m=5;
	scanf("%d %d",&n,&m);
	printf("%lld\n",nCr(n,m));
}
