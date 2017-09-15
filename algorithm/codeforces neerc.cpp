#include <iostream>
#include <fstream>
using namespace std;
long long int arr[111111],tot=0,wh,rr=0;
int main(void){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	long long int n,k;
	in >> n >> k;
	for(int e=0;e<n;e++) {
		in >> arr[e];
		if(arr[e]>rr){
			rr=arr[e];
			wh=e;
		}
		tot+=arr[e];
	}
	long long int f=wh,s=0,p=n+rr-1,q=tot;
	for(int e=0;e<wh;e++) s+=arr[e];
	long long int ttt=0,qqq=0;
	while(k>=f+p*qqq){
		if(k>=f+p*qqq&&k<=s+q*qqq){
			ttt++;
			break;
		}
		qqq++;
	}
	if(ttt){
		out << "YES";
	}else{
		out << "KEK";
	}
}
