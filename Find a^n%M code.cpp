#include<bits/stdc++.h>
using ll=long long int;
using namespace std;
ll gcd(ll a,ll b) {return !(a%b)? b:gcd(b,a%b);}
ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll PowerMod(ll a,ll n,ll M){
	if (n<2) return n? a:1;
	ll x=PowerMod(a,n/2,M);
    return (n&1)? ((x*x)%M*a)%M:(x*x)%M;
}
ll LogInt(ll n,ll base){
    ll p=1,i;
    for(i=1;; i++,p*=base)
		if (p*base>n) break;
    return i-1;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	return 0;
}
