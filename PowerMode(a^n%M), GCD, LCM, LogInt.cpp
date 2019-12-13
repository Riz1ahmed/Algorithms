/*****************
Given a,n,M. Find a^n%M.
******************/
#include<cstdio>
#define ll long long int
ll gcd(ll a,ll b) {return !(a%b)?b:gcd(b,a%b);}
ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll gcdExtended(ll a, ll b, ll &x, ll &y){
    if (!a){x=0, y=1; return b;}
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1-(b/a)*x1;
    y = x1;
    return gcd;
}
ll PowerMod(ll a,ll n,ll M){
	if (!n) return 1;
	ll x=PowerMod(a,n/2,M);
	x=(x*x)%M;
   	return (n&1)? (x*a)%M : x;
}
ll LogInt(ll n,ll base){
    ll p=1,i;
    for(i=1;; i++,p*=base)
		if (p*base>n) break;
    return i-1;
}
int main(){
	ll a,n,M=1e9+7;
	scanf("%lld %lld",&a,&n);
	printf("%lld\n",PowerMode(a,n,M);
}
