/* ******Trie ALGO Problem (LOJ 1224)*******
Given N string (Contain only 'A', 'C', 'G', 'T').
Find a Substring which is Maximum len*t.
	(Here len=Substring size, t=Occurrence time).
°°°°°°°°°°°Input°°°°°°°°°°°
1 4
ACGT ACGTGCGT ACCGTGC ACGCCGT
°°°°°°°°°Output°°°°°°°°°°°
Case 1: 9
*/
#include <bits/stdc++.h>
using namespace std; 
int ans;
struct trie{
	trie *eg[5]; int c=0;
	trie(){eg[1]=eg[2]=eg[3]=eg[4]=NULL;}
};
int max(int a,int b){return a>b?a:b;};
int idx(char c){
	if (c=='A') return 1; if (c=='C') return 2;
	if (c=='G') return 3; if (c=='T') return 4;
}
void insert(char s[],trie *r){
	trie *t=r; int l=strlen(s);
	for (int i=0; i<l; i++){
		int x=idx(s[i]);
		if (!t->eg[x]) t->eg[x]=new trie();
		t=t->eg[x], t->c++;
	}
}
void dfs(int p,trie *r){
	ans=max(ans,p*r->c);
	for (int i=1; i<5; i++)
		if (r->eg[i]) dfs(p+1, r->eg[i]);
}
void clean(trie *t){
	for (int i=1; i<5; i++)
		if (t->eg[i]) clean(t->eg[i]);
	free(t);
}
int main(){
	int t,cs=1,n;
	char s[60];
	scanf("%d",&t);
	while (t--){
		trie *r=new trie();
		scanf("%d",&n);
		while (n--) scanf("%s",s), insert(s,r);
		ans=0, dfs(0,r);
		printf("Case %d: %d\n",cs++,ans);
		clean(r);
	} return 0;
}
