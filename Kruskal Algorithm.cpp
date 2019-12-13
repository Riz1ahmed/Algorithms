#include <cstdio>
#include <map>
#include <algorithm>
#define SZ 80000
using namespace std;
struct eg{ int u,v; };
int parent[SZ];
int findp(int x) {
    if (parent[x]==x) return x;
    return parent[x]=findp(parent[x]);
}
int main() {
	freopen("Prims.txt","r",stdin);
    int n,e,i,j,k,f;
    map<int,eg>mp;
	scanf("%d %d",&n,&e);
	int ans=0,u,v,w[n+2];
	for (i=0; i<=n; i++) parent[i]=i;
	for (i=0; i<e; i++){
		scanf("%d %d %d",&u,&v,&w[i]);
		eg x; x.u=u,x.v=v;
		mp[w[i]]=x;
	}
	sort(w,w+e);
	for (i=0; i<e; i++){
		printf("%d %d %d ", w[i], mp[w[i]].u, mp[w[i]].v);
		u=mp[w[i]].u,v=mp[w[i]].v;
		u=findp(u),v=findp(v);
		if (u!=v){
			printf("= Taken");
			parent[u]=v;
			ans+=w[i];
		} else printf("= Not taken");
	puts("");
	}
	printf("\nMinimum Spening Tree with Kruskal is %d\n",ans);
    return 0;
}
