///My Custom Sentence Input.
#include<stdio.h>
#include<string.h>
void Scan(char s[]){
	char c; int i=0;
	while((c=getchar())!='\n')
		s[i++]=c;
	s[i]='\0';
}
int main(){
	char s[1000];
	Scan(s);
	printf("%s\n",s);
}
