///Owelar Tocient (Find Divisors)
#include <stdio.h>
#define lim 100
#include <vector>
#define iclear(x) memset(x,0,sizeof(x))
#define sclear(x) memset(x,0,strlen(x))
using namespace std;
int i,j,k;
vector<int>div[lim+1],total(lim+1);
void prime(){
	total[0]=total[1]=1;
	div[0].push_back(0);
	div[1].push_back(1);
	for (i=2; i<=lim; i++)
		if (!total[i])
			for (j=i+i; j<=lim; j+=i) {
				total[j]++;
				div[j].push_back(i);
			}
	printf("১০০ পর্যন্ত ভাজক সমূহ\n");
	for (i=0; i<=lim; i++){
		printf("%d এর %d টা =",i,total[i]);
		for (j=0; j<div[i].size(); j++)
			printf(" %d",div[i][j]);
		puts("");
	}
}
int main(){ prime(); }
