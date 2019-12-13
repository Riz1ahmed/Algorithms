#include <cstdio>
int main(){
	int n;
	printf("Input array size: ");
	scanf("%d",&n);
	int a[n],f;
	printf("Input the array values 1 by 1:\n");
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	printf("Input the Search value: ");
	scanf("%d",&f);
	///Binary search start.
	int l=0,r=n-1,m;
	while(l<=r){
		m=l+(r-1/2);
		if (a[m]==f)
			return!printf("Found at %d no index\n",m);
		else if (a[m]>n) r=m-1;
		else l=m+1;
	}
	printf("The value not found\n");
	return 0;
}
