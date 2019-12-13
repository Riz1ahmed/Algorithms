#include <cstdio>
using namespace std;
int r[100005], p[100005]; //r=Child,p=Parent
int findp(int x) {
    return p[x] == x ? x : (p[x]=findp(p[x]));
}
int main() {
    int n,e,u,v,i,ans;
	scanf("%d %d", &n,&e);
	int size=0;
	for (i=0; i<=n; i++) r[i]=1, p[i]=i; ///Itself p.
	while (e--) {
		scanf("%d %d",&u,&v);
		int pu=findp(u), pv=findp(v);
		if (pu!=pv) r[pu]+=r[pv], p[pv]=pu;
		ans=r[pu];
		printf("Total Connected Node of %d is %d.\n",u,ans);
	}
    return 0;
}
