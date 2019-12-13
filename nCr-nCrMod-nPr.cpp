#include<stdio.h>
#include <string.h>
#define ll long long int
ll fact[1000000],M=1e9+7;
ll nCr(ll n,ll r){
	if (n<r) return 0;
	return fact[n]/(fact[r]*fact[n-r]);
}
ll nPr(ll n,ll r){
	if (n<r) return 0;
	return fact[n]/fact[n-r];
}

ll PowerMod(ll a,ll n,ll M){
	if (!n) return 1;
	ll x=PowerMod(a,n/2,M);
	x=(x*x)%M;
    return (n&1)? (x*a)%M : x;
}
///n^(-1) mod M
ll modInverse(ll n,ll M){
	return PowerMod(n,M-2,M);
}

ll nCrMod(ll n,ll r,ll p){
    if (!r) return 1;
	fact[0]=1;
	return (fact[n]*modInverse(fact[r],p)%p*
			modInverse(fact[n-r],p)%p)%p;
}

int main(){
	ll n,r;
	fact[0]=1;
	for (int i=1;i<=100000;i++)
		fact[i]=(fact[i-1]*i)%M;
	while (~scanf("%lld %lld",&n,&r)){
		printf("nCr=%lld, nPr=%lld\n",
			nCr(n,r),nPr(n,r));
	}
}
