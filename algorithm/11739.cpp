#include<stdio.h>
#include<vector>
using namespace std;

int n,k;
vector<vector<int> > v;
vector<int> c;

int main(){
	scanf("%d%d",&n,&k);
	v.resize(n);	c.resize(n,0);
	for(int i=0;i<n;i++){
		int a;	scanf("%d",&a);
		for(int j=0;j<a;j++){
			int t;	scanf("%d",&t);
			v[i].push_back(t);
		}
	}
	
	int cnt=0, s = 0, t = 0;
	while(cnt<k){
		if(c[t]==v[t].size()){
			cnt++;	s+=50;
		}
		else if(s>v[t][c[t]]){
			c[t]++;
		}
		else{
			cnt++;	s+=v[t][c[t]];	c[t]++;
		}
		t=(t+1)%n;
	}
	printf("%d\n",s);
	
	return 0;
}
