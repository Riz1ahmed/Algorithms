/// Dijkstra Algorithm (single Shortest Path)
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,e,u,v,w,i,j,c;
	cin>>n>>e;
	int dis[n+2],cost[n+2][n+2];
	for (i=0; i<=n; i++){
		dis[i]=1e6;
		for (j=i; j<=n; j++)
			cost[i][j]=cost[j][i]=1e6;
		cost[i][i]=0;
	}
	vector<int> graph[n+5];
	for (i=0; i<e; i++){
		cin>>u>>v>>w;
		graph[u].push_back(v);
		graph[v].push_back(u);
		cost[u][v]=cost[v][u]=w;
	}
	queue<int> q;
	puts("All short path from node 0 is:");
	q.push(0), dis[0]=0;
	while (!q.empty()){
		u=q.front(), q.pop();
        for (auto v:graph[u])
			if (dis[u]+cost[u][v] < dis[v])
				dis[v]=dis[u]+cost[u][v], q.push(v);
	}
	for (i=0; i<=n; i++) cout<<dis[i]<<" "; puts("");
}
