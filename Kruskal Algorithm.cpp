/***** Minimum Spanning Tree (Kruskal) Algorithm ******
Given a wighted graph with N node & E e edges.
Find Minimum Spanning Tree. Traverse all Node with minCost.*/
#include <bits/stdc++.h>
using namespace std;
struct eg{ int u,v; };
int par[80000];
int findP(int x) {
    return par[x] == x ? x : (par[x]=findP(par[x]));
}
int main(){
    int n,e,i,j,k,f;
    map<int,eg>mp;
	cin>>n>>e;
	int ans=0,u,v,w[n+2];
	for (i=0; i<=n; i++) par[i]=i;
	for (i=0; i<e; i++)
		cin>>u>>v>>w[i],
		mp[w[i]]={u,v};

	sort(w,w+e);
	for (i=0; i<e; i++){
		cout<<w[i]<<" "<<mp[w[i]].u<<" "<<mp[w[i]].v<<" ";
		u=mp[w[i]].u, v=mp[w[i]].v;
		u=findP(u), v=findP(v);
		if (u==v) puts("= Already Connected");
		else{
			puts("= Connected OK");
			par[u]=v, ans+=w[i];
		}
	}
	printf("\nMinimum Spanning Tree with Kruskal is %d\n",ans);
    return 0;
}
