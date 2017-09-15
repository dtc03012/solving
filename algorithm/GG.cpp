#include<stdio.h>

int main(){
	int t;	scanf("%d",&t);
	while(t-->0){
		int n, index;	scanf("%d",&n);
		double m=0;
		for(int i=0;i<n;i++){
			double a,b,c,ans;	scanf("%lf%lf%lf",&a,&b,&c);
			ans = (b*b)/(4*a)+c;
			if(ans>m){
				m=ans;
				index=i+1;
			}
		}
		printf("%d\n",index);
	}
	
	return 0;
}
