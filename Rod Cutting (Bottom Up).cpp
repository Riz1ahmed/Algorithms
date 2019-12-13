#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
	int len[]={0,1,2,3,4,5,6,7,8,9,10};
	int p[]={0,1,5,8,9,10,16,17,20,24,30};
	int n=sizeof(p)/sizeof(p[0]);
	int i,j,r[n+1];
	r[0]=0;
	for (i=1; i<n; i++){
		r[i]=p[i];
		for (j=1; j<=i; j++)
			r[i]=max(r[i],r[j]+r[i-j]);
	}
	for (i=1; i<n; i++)
		printf("%d ",r[i]);
}
