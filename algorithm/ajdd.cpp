#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#define mod 1000000000
using namespace std;
vector<pair<int,int> > arr[111];
pair<int,int> a[111],b[111];
int vis[111];
pair<int,int> ff[111],ss[111];
string fk[111],sk[111];
bool dfs(int now){
	vis[now]=1;
	for(int e=0;e<arr[now].size();e++){
		int next=arr[now][e].first;
		if(b[next].first==-1||vis[b[next].first]==0&&dfs(b[next].first)){
			b[next].first=now;
			a[now].first=next;
			a[now].second=arr[now][e].second;
			return true;
		}
	}
	return false;
}
int main(void){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int n,m;
	cin >> n >> m;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(int e=0;e<n;e++){
		string kk;
		cin >> kk;
		int aa=0,bb=0;
		fk[e]=kk;
		for(int ee=0;ee<3;ee++) aa+=kk[ee]-'0';
		for(int ee=kk.size()-1;ee>=kk.size()-3;ee--) bb+=kk[ee]-'0';
		ff[e]=make_pair(aa,bb);
	}
	for(int e=0;e<m;e++){
		string kk;
		cin >> kk;
		int aa=0,bb=0;
		sk[e]=kk;
		for(int ee=0;ee<3;ee++) aa+=kk[ee]-'0';
		for(int ee=kk.size()-1;ee>=kk.size()-3;ee--) bb+=kk[ee]-'0';
		ss[e]=make_pair(aa,bb);
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			if(ff[e].first==ss[p].second){
				arr[e].push_back(make_pair(p,0));
			}
			if(ff[e].second==ss[p].first){
				arr[e].push_back(make_pair(p,1));
			}
		}
	}
	int tt=0;
	for(int e=0;e<n;e++){
		memset(vis,0,sizeof(vis));
		if(dfs(e)){
			tt++;
		}
	}
	cout << tt<<"\n";
	for(int e=0;e<n;e++){
		if(a[e].second!=-1){
			if(a[e].second==0){
				cout << "AT" << " " << fk[e] << " " << sk[a[e].first] << "\n";
			}
			if(a[e].second==1){
				cout << "TA" << " " <<sk[a[e].first] <<  " " << fk[e] << "\n";
			}
		}
	}
}
