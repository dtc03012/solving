#include <stdio.h>
#define INF 987654321
int n,w[20][20],ma=INF,s[22][77777];
int min(int a,int b)
{
	return a>b?b:a;
}
int tsp(int now,int check,int wei)
{
    if(s[now][check]) return s[now][check];
	if(check==(1<<n)-1) 
    {
        if(w[now][0]) if(ma>wei+w[now][0]) ma=wei+w[now][0];
		return wei+w[now][0];
	}
	for(int e=0;e<n;e++)
	{
		if(check&(1<<e)) continue;
		if(w[now][e]==0) continue;
        if(wei+w[now][e]>s[e][check|(1<<e)]) continue;
		s[now][check]=min(s[now][check],tsp(e,check|(1<<e),wei+w[now][e]));
	}
	return s[now][check];
}
int main(void)
{
	scanf("%d",&n);
	for(int e=0;e<n;e++) for(int p=0;p<n;p++) scanf("%d",&w[e][p]);
	for(int e=0;e<22;e++) for(int p=0;p<77777;p++) s[e][p]=INF;
	tsp(0,1,0);
	printf("%d",ma);
}
