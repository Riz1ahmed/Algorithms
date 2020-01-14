#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
#define Fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define for0(n) for(int i=0;i<n;i++)
#define for1(n) for(int i=1;i<=n;i++)
#define for1LR(l,r) for(int i=l;i<=r;i++)
#define ll long long int
const ll M=1e9+7;
using namespace std;
int dx[]={0, 0,1,-1,1, 1,-1,-1};
int dy[]={1,-1,0, 0,1,-1, 1,-1};
int inner(int x,int n,int y,int m){
    return -1<x&&x<n && -1<y&&y<m;}

ll gcd(ll a,ll b) {return !(a%b)? b:gcd(b,a%b);}
ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
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
ll gcdExtended(ll a, ll b, ll &x, ll &y){
    if (!a){x=0, y=1; return b;}
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1-(b/a)*x1;
    y = x1;
    return gcd;
}
ll modInvByPw(ll n,ll Mod){
    /// return n^(-1) mod Mod
    return PowerMod(n,Mod-2,Mod);
}
ll modInv(ll a) {
    ll x,y;///if a=0 not exist
    ll g = gcdExtended(a,M,x,y);
    if (g==1) return (x%M+M)%M;
    printf("ModInv not exist for %d\n",a);
}

bool fl[int(1e7+5)];
vector<int> prime;
void sieve(){
    for (int i=3; i*i<=1e7; i+=2)
        if (!fl[i])
            for (int j=i+i; j<=1e7; j+=i)
                fl[j]=1;
    prime.push_back(2);
    for (int i=3; i<=1e7; i+=2)
        if (!fl[i]) prime.push_back(i);
}

int main(){
    sieve();
    int n=5,m=6;
    scanf("%d",&n);
    printf("%d\n",n);
    return 0;
}
