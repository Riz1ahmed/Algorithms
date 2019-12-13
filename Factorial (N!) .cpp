#include <cstdio>
#define u64 unsigned long long int
u64 n=6;
u64 fac(u64 n) {
	if (n==1) return 1;
	n*=fac(n-1);
}
int main(){
	n*=fac(n-1);
	printf("%llu\n",n);
	return 0;
}
