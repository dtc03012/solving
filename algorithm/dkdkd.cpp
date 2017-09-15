#include <stdio.h>
#include <string.h>
char S[111111],P[111111];
int main(void)
{
	scanf("\n%[^\n]s", S+1);
    scanf("\n%[^\n]s", P+1);
    printf("%d",strlen(S+1));
}
