/**BIT/Frenwick Tree Algorithm (LOJ 1080 - Binary Simulation)**\
Given a binary string S & Q query.
Every Query 2 type:
I i j: Invert the bit in range[i:j]
Q i: Print the Bit of S[i] 0 or 1.
Note: 1-Based Indexed.  **/
#include<bits/stdc++.h>
using namespace std;
int tree[100009];
void update(int idx,int v,int n){
    while(idx<=n)
        tree[idx]+=v,
        idx+=(idx& -idx);
}
int query(int idx){
    int sum=0;
    while(idx>0)
        sum+=tree[idx],
        idx-= (idx& -idx);
    return sum;
}
int main(){
    char s[100005],tp[2];
    int n,q,p,i,j,cs=1;
    scanf("%*d");
    while(~scanf("%s",s)){
        int n=strlen(s), ar[n+5];
        memset(tree,0,sizeof (int)*(n+5));
        for (i=0; i<n; i++) ar[i+1]=s[i]-'0';
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%s %d",tp,&i);
            if (tp[0]=='I'){
                scanf("%d",&j);
                update(i,1,n), update(j+1,-1,n);
            }else printf("%d\n",ar[i]^(query(i)&1));
        }
    }
    return 0;
}
