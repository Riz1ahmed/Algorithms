/**Bit Sieve && BIT/Frenwick Tree Algorithm (toph.co/p/easy-prime)**\
Given a N size array & Q query.
Every Query 2 type:
1 l r: print total print in range[l:r]
2 p v: update the value of array[p] to v.
Note: 1-Based Indexed.  **/
#include<bits/stdc++.h>
using namespace std;
const int MX=1e7;
/// Bitwise Sieve
int bitPrime[MX/32+5];
bool PrimeNot(int x){ return bitPrime[x/32] & (1<<(x%32));}
bool IsPrime(int x){ return !PrimeNot(x);}
void mark(int x){bitPrime[x/32] |= (1<<(x%32));}
void bitSieve(){
    memset(bitPrime,0,sizeof bitPrime);
    mark(1);
    for (int i=2; i*i<=MX; i++)
        if (IsPrime(i))
            for (int j=i*i; j<=MX; j+=i)
                mark(j);
}
/// BIT/Frenwick Tree
int tree[MX+5];
void update(int idx,int val,int n){
    while(idx<=n)
        tree[idx]+=val,
        idx+=(idx & -idx);
}
int query(int idx){
    int sum=0;
    while(idx>0)
        sum+=tree[idx],
        idx-=(idx & -idx);
    return sum;
}
int main(){
    bitSieve();
    int n,q,tp,pos,val;
    while (~scanf("%d",&n)){
        int ar[n+5];
        for (int i=1; i<=n; i++){
            scanf("%d",&ar[i]);
            if (IsPrime(ar[i])) update(i,1,n);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d",&tp,&pos,&val);
            if (tp==1) //Here pos=l, val=r.
                printf("%d\n",query(val)-query(pos-1));
            else if (tp==2 && IsPrime(val)!=IsPrime(ar[pos])){
                ar[pos]=val;
                IsPrime(ar[pos]) ? update(pos,1,n) : update(pos,-1,n);
}   }   }   }
