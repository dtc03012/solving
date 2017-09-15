#include <iostream>
using namespace std;
pair<unsigned long long int,unsigned long long int> af[111111],bf[111111];
long long int gcd(long long int a,long long int b){
	if(b>a){
		long long int tmp=a;
		a=b;
		b=tmp;
	}
	while(b!=0){
		long long int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
int main(void)
{
	af[0]=make_pair(1,0);
	bf[0]=make_pair(0,1);
	for(int e=1;e<111111;e++){
		if(e%2) af[e]=af[e-1];
		else {
			af[e].second=af[e-1].first+af[e-1].second;
			af[e].first=af[e].second+af[e-1].first;
		}
		if(e%2==0) bf[e]=bf[e-1];
		else {
			bf[e].second=bf[e-1].first+bf[e-1].second;
			bf[e].first=bf[e].second+bf[e-1].first;
		}
	}
	cout << af[100000].first << endl;
	int t;
	cin >> t;
	for(int ee=1;ee<=t;ee++){
		long long int a,b,c,d,f,s,k;
		cin >> a >> b >> c >> d;
		if(b==0){
			a+=c;
		}
		f=a;
		s=0;
		for(int e=1;e<=b;e++){
			f=af[e].first*a;
			s=bf[e].first*a;
		}
		if(b){
			if(f>=s) f+=c;
			else s+=c;
		}
		if(s>f){
			long long int tmp=f;
			f=s;
			s=tmp;
		}
		a=f;
		k=s;
		for(int e=1;e<=d-b;e++){
			f=af[e].first*a+af[e].second*k;
			s=bf[e].first*a+bf[e].second*k;
		}
		cout << "Case "<<ee<<": " << gcd(f,s) << "\n";
	}
}
