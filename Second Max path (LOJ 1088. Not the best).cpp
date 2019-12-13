/******************
Find Second Maximum path (LOJ 1088)
******************/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct R{int n,w;};
int main(){
	int t,n,m,i,u,v,w,w1,mn1,mn2,cs=1;
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&n,&m);
		vector<R> g[n+2];
		for (i=0; i<m; i++){
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		queue<R> q;
		q.push({1,0});
		mn1=mn2=1e9;
		while (q.size()){
			u=q.front().n, w=q.front().w, q.pop();
			for (i=0; i<g[u].size(); i++){
				v=g[u][i].n, w1=w+g[u][i].w;
				if (w1<mn1 || w1<mn2){
					q.push({v,w1});
					if (v==n){
						if (w1<mn1) mn2=mn1, mn1=w1;
						else if (w1!=mn1) mn2=w1;
					}
				}
			}
		}
		printf("Case %d: %d\n",cs++,mn2);
	} return 0; 
}
