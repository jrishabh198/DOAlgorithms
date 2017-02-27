#include <bits/stdc++.h>
using namespace std;
int findlis(int ind,int arr[],int n){
	int t1[20004];
	int ans =0;
	for(int i = ind;i<=ind+n;i++){
		int f=lower_bound(t1+1,t1+ans+1,arr[i])-t1;
		ans=max(ans,f);
		t1[f]=arr[i];
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	for(int test =0;test<t;test++){
		int n;
		cin>>n;
		int arr[n+n];
		for(int i =0;i<n;i++){
			cin>>arr[i];
			arr[i+n]=arr[i];
		}
		int ans =0;
		for(int i =0;i<n;i++)ans = max(ans,findlis(i,arr,n));
		cout<<ans<<endl;
	}
}