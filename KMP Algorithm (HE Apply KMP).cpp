/*******Statement********
Given 2 strings, 1≤P,T≤10⁵,
	find occurrenced time of P in T.
	
°Sample Input: sds sasdsdssagsdsad
°Sample Output: 3
Problem Link: http://bit.ly/applyKMP
*************************/
#include <cstdio>
#include <cstring>
#define sz 100010
char P[sz], T[sz];
int b[sz], Plen, Tlen;
void FailureTable(){
	int i=0, j=-1;
	b[0] = -1;
	while (i<Plen){
		while (j>=0 && P[i]!=P[j]) j=b[j];
		i++, j++, b[i]=j;
	}
}
int KMP(){
	int i=0, j=0, ans=0;
	while (i<Tlen){
		while (j>=0 && T[i]!=P[j]) j=b[j];
		i++, j++;
		if (j==Plen) ans++, j=b[j];
	}
	return ans;
}
int main(){
	scanf("%s %s",P,T);
	Plen=strlen(P), Tlen=strlen(T);
	FailureTable();
	//for (int i=0; i<Plen; i++)
		//printf("%d ",b[i]); puts("");
	printf("%d\n",KMP());
	return 0;
}
