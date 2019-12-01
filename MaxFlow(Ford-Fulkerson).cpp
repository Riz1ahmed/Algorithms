#include <bits/stdc++.h>
using namespace std;
#define V 6 ///No of Vertices
bool bfs(int rGraph[V][V],int s,int t,int parent[]){
	bool visited[V];
	memset(visited,0,sizeof(visited));
	queue <int> q;
	q.push(s), visited[s]=true, parent[s]=-1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v=0; v<V; v++)
			if (visited[v]==false && rGraph[u][v]>0)
				q.push(v),parent[v]=u,visited[v]=true;
	}
	return (visited[t]==true); ///If a path Existed.
}
int fordFulkerson(int graph[V][V],int s,int t){
///parent=for store path. rGraph=Just a Copy of graph
	int u,v,mxflow=0,rGraph[V][V],parent[V];
	for (u=0; u<V; u++) for (v=0; v<V; v++)
		rGraph[u][v]=graph[u][v];
	///BFS=If there have a path
	while (bfs(rGraph, s, t, parent)){
		int path=INT_MAX;
		/// Find Min weight(Max Flow)
		for (v=t; v!=s; v=parent[v])
			u=parent[v], path=min(path,rGraph[u][v]);

		///Update the paths
		for (v=t; v != s; v=parent[v])
			u=parent[v],
			rGraph[u][v]-=path,
			rGraph[v][u]+=path;
		mxflow+=path;
	}
	return mxflow;
}
int main(){
	int graph[V][V]={ {0,16, 13,  0,  0, 0},
					  {0, 0, 10, 12,  0, 0},
					  {0, 4,  0,  0, 14, 0},
					  {0, 0,  9,  0,  0,20},
					  {0, 0,  0,  7,  0, 4},
					  {0, 0,  0,  0,  0, 0} };
	printf("The maximum flow is %d\n",fordFulkerson(graph, 0, 5));
	return 0;
}
