#include <iostream>
#include <math.h>
using namespace std;

int main(void){
	int n,pp=0;
	cin >> n;
	for(int e=2;e<=n;e++)
	{
		if(n%e==0){
			int tt=0;
			for(int q=2;q<=sqrt(e);q++){
				if(e%q==0) tt++;
			}
			if(tt==0){
				pp++;
				n/=e;
			}
		}
	}
	if(pp==3) {
		cout << "YES";
	}else{
		cout << "NO";
	}
}
