#include <stdio.h>
int a,b,c;
void recur(int n,int tot,int x,int y)
{
	if(n==1)
	{
		if(x==c&&y==b) printf("%d",tot);
		return;
	}
	if(c<x+(n/2)&&b<y+(n/2))recur(n/2,tot,x,y);
	if(c>=x+(n/2)&&b<y+(n/2))recur(n/2,tot+(n/2)*(n/2),x+(n/2),y);
	if(c<x+(n/2)&&b>=y+(n/2))recur(n/2,tot+2*(n/2)*(n/2),x,y+(n/2));
	if(c>=x+(n/2)&&b>=y+(n/2))recur(n/2,tot+3*(n/2)*(n/2),x+(n/2),y+(n/2));
}
int main(void)
{
	scanf("%d%d%d",&a,&b,&c);
	int kk=1;
	for(int e=0;e<a;e++) kk*=2;
	recur(kk,0,0,0);
}
