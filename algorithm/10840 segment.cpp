#include <iostream>
#include <string>

using namespace std;
string a,b;
int arr1[1555][26],arr2[1555][26],ma;
bool poss(int st,int fi,int length)
{
	for(int e=0;e<=b.size()-length;e++)
	{
		int pp=0;
		for(int q=0;q<26;q++) if(arr1[fi][q]-(st==0?0:arr1[st-1][q])!=arr2[e+length-1][q]-(e==0?0:arr2[e-1][q])) pp++;
		if(pp==0) return true;
	}
	return false;
}
int main(void)
{
	cin >> a >> b;
	arr1[0][a[0]-'a']=1;
	for(int e=1;e<a.size();e++) 
	{
		for(int q=0;q<26;q++) arr1[e][q]=arr1[e-1][q];
		arr1[e][a[e]-'a']++;
	}
	arr2[0][b[0]-'a']=1;
	for(int e=1;e<b.size();e++)
	{
		for(int q=0;q<26;q++) arr2[e][q]=arr2[e-1][q];
		arr2[e][b[e]-'a']++;
	}
	for(int e=0;e<a.size();e++)
	{
		for(int p=e;p<a.size();p++) if(p-e+1<=b.size()) if(poss(e,p,p-e+1)) ma=max(ma,p-e+1);
	}
	cout << ma;
}
