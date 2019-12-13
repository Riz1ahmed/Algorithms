#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> vc;
void DFS(int x, vector<int> *graph, int *done){
    for (int i=0; i<graph[x].size(); i++)
        if (!done[graph[x][i]])
			DFS(graph[x][i],graph,done);
	vc.push_back(x);
	done[x]=1;
	return;
}
int main(){
	int n,e,u,v,i;
	while (~scanf("%d %d",&n,&e)){
		int c=0;
		int done[n+5];
		memset(done,0,sizeof(done));
		vector<int> graph[n+5];vc.clear();
		for (i=0; i<e; i++){
			scanf("%d %d",&u,&v);
			graph[v].push_back(u);
		}
		for (i=1; i<=n; i++)
			if (!done[i])
				DFS(i,graph,done);
		for (i=0; i<vc.size(); i++)
			printf(i!=vc.size()-1 ? "%d ":"%d\n",vc[i]);
	}
	return 0;
}/*
5 4
1 2
1 3
3 2
3 5
5 2
Ans=1,3,5,2,4,
*/
