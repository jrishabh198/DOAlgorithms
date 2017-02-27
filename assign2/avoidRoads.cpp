#include <bits/stdc++.h>
using namespace std;
int main(){
	int wid,heit;
	cin>>wid>>heit;
	int k;//number of bad streets
	cin>>k;
	map<pair<pair<int,int>,pair<int,int>>,int> mp;
	for(int i =0;i<k;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		mp[make_pair(make_pair(a,b),make_pair(c,d))]=1;
	}
	long long int ans[wid+1][heit+1];
	for(int i =0;i<=wid;i++){
		for(int j =0;j<=heit;j++){
			long long int l =0;
			long long int d =0;
			if(i==0&&j==0){ans[i][j]=1;continue;}
			else if(i==0){l= ans[i][j-1];d=0;}
			else if(j==0){d=ans[i-1][j];l =0;}
			else {l = ans[i][j-1];d = ans[i-1][j];}
			if(mp[make_pair(make_pair(i-1,j),make_pair(i,j))]==1)d =0;
			if(mp[make_pair(make_pair(i,j-1),make_pair(i,j))]==1)l =0;
			if(mp[make_pair(make_pair(i,j),make_pair(i,j-1))]==1)l =0;
			if(mp[make_pair(make_pair(i,j),make_pair(i-1,j))]==1)d =0;
			ans[i][j]= l+d;

		}
	}
	cout<<ans[wid][heit];
}