void DFS(int x, vector<int> *graph, int *visit){
    visit[x]=1,c++;
    for (int i=0; i<graph[x].size(); i++)
        if (!visit[graph[x][i]])
			DFS(graph[x][i],graph,visit);
}
