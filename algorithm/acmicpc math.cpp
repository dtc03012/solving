#include <iostream>
using namespace std;
unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
	if(b>a){
		unsigned long long int tmp=a;
		a=b;
		b=tmp;
	}
	while(b!=0){
		unsigned long long int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
unsigned long long int aa[77];
int main(void){
	int t;
	cin >> t;
	aa[0]=1;
	aa[1]=1;
	for(int e=2;e<77;e++) aa[e]=aa[e-1]+aa[e-2];
	for(int e=1;e<=t;e++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		unsigned long long int ff=aa[b+1],ss=aa[b];
		cout << "Case "<<e<<": "<<gcd(ff*a+c,ss*a+c) << "\n";
	}
}
