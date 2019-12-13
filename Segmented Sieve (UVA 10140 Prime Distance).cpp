/***(Segmented Sieve)**(Prime<=1e18,range[l:r]<=1e6)**(UVA 10140 Prime Distance)***
Given l,r (1<=l,r<=1e18, r-l<=1e6). You have to print 2 min & 2 max distance prime number.
Input: 1 17.   Output: 2,3 are closest, 7,11 are most distant. ***/
#include<cstdio>
#include <vector>
using ll=long long int;
using namespace std;
const ll sz=1e6;
ll fl[sz+5];
vector<ll> primes,NewP;

void sieve(){
	for (ll i=3; i*i<=sz; i+=2)
		if (!fl[i])
			for (ll j=i+i; j<=sz; j+=i)
				fl[j]=1;
	primes.push_back(2);
	for (ll i=3; i<=sz; i+=2)
		if (!fl[i]) primes.push_back(i);
}
/*All prime in [l:r]. 1<=l,r<=1e18. r-l<=1e6.*/
void SegSieve(ll l,ll r){
	memset(fl,0,sizeof fl);
	for (ll i=0; primes[i]*primes[i]<=r; i++){
        ll st=l/primes[i];
        if (st*primes[i]<l) st++;
        if (st==1) st++;
		for (ll j=st*primes[i]; j<=r; j+=primes[i])
			fl[j-l]=1;
	}
	for (ll i=l; i<=r; i++)
		if (!fl[i-l]) NewP.push_back(i);
}
int main(){
	sieve();
	ll l,r;
	while(~scanf("%lld %lld",&l,&r)){
		if (l<2) l=2;
		NewP.clear(), SegSieve(l,r);
		if(NewP.size()<2){
			puts("There are no adjacent primes.");
			continue;
		}
		ll mnl=NewP[0],mnr=NewP[1];
		ll mxl=NewP[0],mxr=NewP[1];
		for (ll i=1; i<NewP.size(); i++){
			if (mnr-mnl>NewP[i]-NewP[i-1])
				mnl=NewP[i-1],mnr=NewP[i];
			if (mxr-mxl<NewP[i]-NewP[i-1])
				mxl=NewP[i-1],mxr=NewP[i];
		}
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mnl,mnr,mxl,mxr);
	}
}
