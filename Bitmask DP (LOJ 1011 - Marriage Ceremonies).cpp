/** Bitmask DP (LOJ 1011 - Marriage Ceremonies)
Given boys & Girls Chosen priority
(as ith boy & jth girl priority is prio[i][j]).
Match the Boy and Girl such that Prority is Maximum.
Must one boy choise only one girl.
1 2 3         1 5
6 5 4         2 1
8 1 2         Ans=7
Ans=16                                     */
#include<bits/stdc++.h>
using namespace std;
int prio[20][20],n, dp[17][1<<17];
bool maried(int mask,int p){return mask&(1<<p);}
int Set(int mask,int p){    return mask|(1<<p);}
int best(int boy,int girl){
    if (boy==n) return 0;
    int &res=dp[boy][girl];
    if (res) return res;
    for (int i=0; i<n; i++)
        if (!maried(girl,i))
            res=max(res, best(boy+1,Set(girl,i)) + prio[boy][i]);
    return res;
}
int main(){
    int cs=1;
    scanf("%*d");
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof dp);
        for (int i=0; i<n; i++) for (int j=0; j<n; j++)
            scanf("%d",&prio[i][j]);
        printf("Case %d: %d\n",cs++,best(0,0));
    }
    return 0;
}
