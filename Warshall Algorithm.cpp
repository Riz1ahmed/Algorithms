/***********  Warshall Algorithm  *************
Given a wighted graph with N node & E e edges.
Find all possible shortest path.    **********/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,e,u,v,w,i,j,k,ans=0;
	cin>>n>>e;
	int mat[n+2][n+2];
	for (i=0; i<=n; i++) for (j=i; j<=n; j++)
        mat[i][j]=mat[j][i]=1e7;
	while (e--) cin>>u>>v>>w, mat[v][u]=mat[u][v]=w;

	puts("\nThe matrix is");
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++)
			printf(mat[i][j]==1e7 ? " -1 ":"%3d ",mat[i][j]);
		puts("");
	}
	for (k=1; k<=n; k++) ///Warshall ALGO
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if ( i!=j && mat[i][k]+mat[k][j] < mat[i][j])
					mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];
	puts("\nNow the matrix is");
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++)
			printf(mat[i][j]==1e7 ? " -1 ":"%3d ",mat[i][j]);
		puts("");
	}
	return 0;
}
