#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int r[10000];
int RodCut(int p[],int n){
	if (r[n]) return r[n];
	r[n]=p[n];
	for (int i=1; i<n; i++)
		r[n]=max(r[n],RodCut(p,i)+RodCut(p,n-i));
	return r[n];
}
using namespace std;
int main(){
	int len[]={0,1,2,3,4,5,6,7,8,9,10};
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	int n=sizeof(p)/sizeof(p[0])-1;
	r[n]=p[n];
	r[n]=max(r[n],RodCut(p,1)+RodCut(p,n-1));
	for(int i=1; i<n; i++)
		printf("%d ",r[i]);
}
