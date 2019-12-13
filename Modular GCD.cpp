#include <iostream>
#define ll long long
ll M,mod=1e9+7;
///Modular Exponentiation.
/// Return (x^y)%m. where 0<x,y,M<1e9;
ll powxy(ll x, ll y) {
	if (!y) return 1;
	if (y&1) return (x*powxy(x, y-1))%M;
	ll t = powxy(x, y/2);
	return (t*t)%M;
} ///D&C Alcorithm
ll gcd(ll a,ll b){
	return (a%b ? gcd(b, a%b) : b);
}
int main() {
	int t;
	scanf("%d",&t);
	while (t--){
		ll a,b,n,ans;
		scanf("%lld %lld %lld",&a,&b,&n);
		ll ab=abs(a-b);
		if (a==b){
			M=mod;
			ans=(powxy(a,n)+powxy(b,n))%M;
			printf("%lld\n",ans);
		}else{
			M=ab;
			ans=(powxy(a,n)+powxy(b,n))%M;
			ans=(gcd(ans,ab))%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
