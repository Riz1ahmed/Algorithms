///Given a graph. Count the Articulation points
#include <bits/stdc++.h>
using namespace std;
int dis[110],point[110],c;//dis=vis
vector<int> adj[110];

int ArtPoint(int p,int u){
	if (dis[u]) return dis[u];
	int mn=dis[u]=c++,i;
	for (i=0; i<adj[u].size(); i++){
		int v=adj[u][i];
		if (v==p) continue;
		if (dis[v]) {mn=min(mn,dis[v]);continue;}
		int x=ArtPoint(u,v);
		if (x>=dis[u]) point[u]++;
		mn=min(mn,x);
	}
	return mn;
}
int main(){
	int n,e,u,v,i,j,f;
	for (i=0; i<110; i++) adj[i].clear();
	memset(dis,0,sizeof dis),
	memset(point,0,sizeof point);

	puts("Input how many node and edge:");
	scanf("%d %d",&n,&e);

	puts("Input the edges one by one:");
	for (i=0; i<e; i++){
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (i=c=1; i<=n; i++) ///Finding Articulation Point
		if (!dis[i]){
			dis[i]=c++;
			for (j=f=0; j<adj[i].size(); j++)
				if (!dis[adj[i][j]])
					f++, ArtPoint(i,adj[i][j]);
			if (f>1) point[i]=f;
		}
	puts("The Articulation poin(s) are:");
	for (i=1; i<=n; i++) if (point[i]) printf("%d ",i);
	return 0;
}
