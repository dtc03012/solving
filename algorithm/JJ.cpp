#include<stdio.h>
#include<iostream>
#include <string.h>
#include<string>
#include<vector>
using namespace std;

int main(){
	int t;	scanf("%d",&t);
	printf("%d\n",t);
	while(t-->0){
		string s;	cin>>s;
		vector< pair<int,int> > v;
		int x=0,y=0,dic[4][2]={0,1,1,0,0,-1,-1,0},index=0;
		int min_x=1000,min_y=1000,n=0,m=0;
		char map[105][105];
		memset(map,0,sizeof(map));
		
		for(int i=0;i<s.length();i++){
			v.push_back(make_pair(x,y));
			if(s[i]=='R') index++;
			else if(s[i]=='L') index+=3;
			else if(s[i]=='B') index+=2;
			index%=4;
			x+=dic[index][0], y+=dic[index][1];
			if(min_x>x) min_x=x;
			if(min_y>y) min_y=y;
		}
		min_x--;
		min_x*=-1,min_y*=-1;
		for(int i=0;i<s.length();i++){
			v[i].first+=min_x, v[i].second+=min_y;
			n = (n>v[i].first)?n:v[i].first;
			m = (m>v[i].second)?m:v[i].second;
		}
		n+=2,m+=2;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) map[i][j]='#';
		for(int i=0;i<s.length();i++) map[v[i].first][v[i].second]='.';
		printf("%d %d\n",n,m);
		for(int i=0;i<n;i++) printf("%s\n",map[i]);
	}
	
	return 0;
}
