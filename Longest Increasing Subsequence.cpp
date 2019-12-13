#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int ar[]={2,3,1,4,7,8,10,2,3,9};
	int n=sizeof(ar)/sizeof(ar[0]);
	int i,c=1,mx=-1;
	for(i=1; i<n; i++){
		if (ar[i-1]<ar[i]) c++;
		else mx=max(mx,c),c=1;
	}
	mx=max(mx,c);
	printf("%d\n",mx);
}
