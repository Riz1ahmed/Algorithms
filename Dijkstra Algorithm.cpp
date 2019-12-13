#include <cstdio>
#include <queue>
#define SZ 1000000
using namespace std;
int main(){
	freopen("Dijkstra.txt","r",stdin);
	int n,e,u,v,w,i,j,c;
	scanf("%d %d",&n,&e);
	int dis[n+2],cost[n+2][n+2];
	for (i=0; i<=n; i++){
		dis[i]=SZ;
		for (j=i; j<=n; j++)
			cost[i][j]=cost[j][i]=SZ;
		cost[i][i]=0;
	}
	vector<int> graph[n+5];
	for (i=0; i<e; i++){
		scanf("%d %d %d",&u,&v,&w);
		graph[u].push_back(v);
		graph[v].push_back(u);
		cost[u][v]=cost[v][u]=w;
	}
	queue<int> q;
	printf("All short path from node 0 is:\n");
	q.push(0); ///ASP from 1.
	dis[0]=0;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (i=0; i<graph[u].size(); i++){
			v=graph[u][i];
			if (dis[u]+cost[u][v]<dis[v]){
				dis[v]=dis[u]+cost[u][v];
				q.push(v);
			}
		}
	}
	for (i=0; i<=n; i++) printf("%d ",dis[i]); puts("");
	return 0;
}
