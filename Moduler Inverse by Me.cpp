/********************
Riz1 Ahmed, CSE, LU.
********************/
#include<bits/stdc++.h>
/**
Problem: (A/B)*C mod P.
Constraint: 0< A,B,C,P <=1e8;

Here you will get WA if apply this formula
normally like (((A/B)%P)*C)%P

See,
(A/B)*C = A*(1/B)*C = A*(B^-1)*C.

Here B^-1 we say 'Inverse of B' or 'B Inverse'.
And that is called Modular Inverse :).
B^-1=modInverse(B,P).

So have to apply like (A*modInverse(B,P)%P)*C)%P
---------------------------------------------**/

///a^n mod M
ll PowerMod(ll a,ll n,ll M){
	if (!n) return 1;
	ll x=PowerMod(a,n/2,M);
	x=(x*x)%M;
    return (n&1)? (x*a)%M : x;
}
ll modInverseByPw(ll n,ll M){
    /// return n^(-1) mod M
	return PowerMod(n,M-2,M);
}

ll gcdExtended(ll a, ll b, ll &x, ll &y){
    if (!a){x=0, y=1; return b;}
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1-(b/a)*x1;
    y = x1;
    return gcd;
}
ll modInverseByGCD(ll a) {
    ll x,y;///if a=0 not exist
    ll g = gcdExtended(a,M,x,y);
    if (g==1) return (x%M+M)%M;
	printf("%d=ModInv not exist\n",a);
}
int main(){
	ll A,B,C,P;
	A=123, B=23, C=23, P=1e9+7;
    cout<< (A*modInverseByPw(B,P)%P)*C)%P<<endl;
	return 0;
}
