#include <iostream>
#include <string>
using namespace std;
string aa[8],kk[8];
int main(void){
	aa[1]="Yakk";
	aa[2]="Doh";
	aa[3]="Seh";
	aa[4]="Ghar";
	aa[5]="Bang";
	aa[6]="Sheesh";
	kk[1]="Habb Yakk";
	kk[2]="Dobara";
	kk[3]="Dousa";
	kk[4]="Dorgy";
	kk[5]="Dabash";
	kk[6]="Dosh";
	int n;
	cin >> n;
	for(int e=1;e<=n;e++){
		int a,b;
		cin >> a >> b;
		if(a==b){
			cout << "Case "<<e<<": "<<kk[a] << "\n";
		}else{
			if((a==6&&b==5)||(a==5&&b==6)) cout << "Case "<<e<<": "<< "Sheesh Beesh" << "\n";
			else cout << "Case "<<e<<": "<<aa[max(a,b)] <<" " <<aa[min(a,b)] << "\n";
		}
	}
}
