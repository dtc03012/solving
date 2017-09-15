#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
int arr[222222];
set<int> f,s;

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<222222;e++) arr[e]=e;
	if(n%2){
		for(int e=1;e<(n/2)+1;e++) f.insert(e);
		for(int e=(n/2)+2;e<=n;e++) s.insert(e);
	}
	else{
		for(int e=1;e<=(n/2);e++) f.insert(e);
		for(int e=(n/2)+1;e<=n;e++) s.insert(e);
	}
	int kk=0,type=0;
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==2){
			if(b%2)
			{
				
			}else{
				if(b<=(n/2)){
					if(binary_search(f.begin(),f.end(),b)==0)
					{
						printf("0\n");
					}else{
						printf("%d",f.find(b));
					}
				}
			}
		}
		if(a==1){
			if(n%2==1&&kk==0){
				kk++;
				if(b==(n/2)+1) continue;
				else{
					if(b<=(n/2)){
						f.erase(b);
						f.insert((n/2)+1);
						type=1;
					}
					if(b>=(n/2)+2){
						s.erase(b);
						s.insert((n/2)+1);
						type=2;
					}
				}
			}
			else{
				if(n%2){
					if(b==(n/2)+1){
						if(type==0){
							f.erase(b);		
						}
						else{
							s.erase(b);
						}
					}
					else{
						if(b<=(n/2)){
							f.erase(b);
						}
						if(b>=(n/2)+2){
							s.erase(b);
						}
					}
				}else{
					if(b<=(n/2)){
						f.erase(b);
					}
					if(b>(n/2)){
						s.erase(b);
					}
				}
			}
		}
	}
}
