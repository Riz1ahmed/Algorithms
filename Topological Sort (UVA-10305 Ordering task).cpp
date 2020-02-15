/** Topological Sort (UVA-10305 Ordering task) ***
You are given N task. You must complete task U before V.
Print the Possible order of task. */
#include <bits/stdc++.h>
using namespace std;
vector<int> vc;
void DFS(int x, vector<int> *g, int *done){
    for (int i=0; i<g[x].size(); i++)
        if (!done[g[x][i]])
			DFS(g[x][i],g,done);
	vc.push_back(x);
	done[x]=1;
	return;
}
int main(){
	int n,e,u,v,i;
	while (~scanf("%d %d",&n,&e)){
		int c=0, done[n+5];
		memset(done,0,sizeof(done));
		vector<int> g[n+5];
		vc.clear();
		for (i=0; i<e; i++){
			cin>>u>>v, g[v].push_back(u);
		}
		for (i=1; i<=n; i++)
			if (!done[i])
				DFS(i,g,done);
		for (i=0; i<vc.size(); i++)
			printf(i!=vc.size()-1 ? "%d ":"%d\n",vc[i]);
	}
	return 0;
}/*
3 3
1 2
1 3
3 2
Ans=1 3 2
*/
