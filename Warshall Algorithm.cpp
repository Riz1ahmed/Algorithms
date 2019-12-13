#include <cstdio>
#define inf 1e7
#define boom(a) memset(a,0,sizeof(a))
using namespace std;
int main() {
	//freopen("Warshal.txt","r",stdin);
	int n,e,u,v,w,i,j,k,ans=0;
	scanf("%d %d",&n,&e);
	int mat[n+2][n+2];
	for (i=0; i<=n; i++)
		for (j=i; j<=n; j++)
			mat[i][j]=mat[j][i]=inf;
	while (e--){
		scanf("%d %d %d",&u,&v,&w);
		mat[v][u]=mat[u][v]=w;
	}
	printf("\nThe matrix is\n");
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++)
			printf(mat[i][j]==inf ? " -1 ":"%3d ",mat[i][j]);
		puts("");
	}
	for (k=1; k<=n; k++) ///Warshall ALGO
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if ( i!=j && mat[i][k]+mat[k][j] < mat[i][j])
					mat[i][j] = mat[j][i] = mat[i][k] + mat[k][j];
	printf("\nNow the matrix is\n");
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++)
			printf(mat[i][j]==inf ? " -1 ":"%3d ",mat[i][j]);
		puts("");
	}
	return 0;
}
