#include <cstdio>
#include <cstring>
#include <vector>
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
	for (i=0; i<e; i++){
		scanf("%d %d %d",&u,&v,&w);
		cost[u][v]=cost[v][u]=w;
	}
	printf("All short path from node 0 is:\n",n);
	dis[0]=0;
	for (i=0; i<=n; i++){
		for (j=0; j<=n; j++){
			if (dis[i]+cost[i][j]<dis[j]){
				dis[j]=dis[i]+cost[i][j];
			}
		}
	}
	for (i=0; i<=n; i++) printf("%d ",dis[i]); puts("");
	return 0;
}
