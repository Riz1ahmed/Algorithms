///Fast Custom Sentence and Integer Input.
#include<stdio.h>
#include<string.h>
void Sentence(char s[]){
	char c; int i=0;
	while((c=getchar())!='\n')
		s[i++]=c;
	s[i]='\0';
}

int Read(int &n){
    int sign=1; char c=getchar(); n=0;
    for(; c<48 || 87<c; c=getchar())
        if(c=='-') sign=-1;
    for(; 47<c && c<58; c=getchar())
        n=n*10+c-48;
    n*=sign;
}

int main(){
	int n;
	char s[1000];
	Sentence(s);
	Read(n);
	printf("%s %d\n",s,n);
}
