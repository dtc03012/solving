#include <stdio.h>

int gcd(int a,int b)
{
	if(b>a)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
	while(b!=0)
	{
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
int main(void)
{
 	int a, b;
	 printf("�� �� a�� b �Է�");
 	scanf("%d %d", &a, &b);
 	printf("%d",gcd(a,b));
 return 0;
}
