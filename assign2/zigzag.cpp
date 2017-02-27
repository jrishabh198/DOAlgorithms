#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	int ans[n][2];
	for(int i =0;i<n;i++){
		cin>>arr[i];
		ans[i][0]=0;
		ans[i][1]=0;
	}
	
	ans[0][0]=1;
	ans[0][1]=1;
	int max1 =1;
	for(int i =1;i<n;i++){

		for(int j =0;j<i;j++){
			if((arr[i]-arr[j])>0){
				ans[i][0]= max(ans[i][0],ans[j][1]+1);
				if(ans[i][0]>max1)max1 = ans[i][0];
			}
			else if((arr[i]-arr[j])<0){
				ans[i][1]= max(ans[i][1],ans[j][0]+1);
				if(ans[i][1]>max1)max1 = ans[i][1]; 
			}
		}
		if(ans[i][0]==0)ans[i][0]=1;
		if(ans[i][1]==0)ans[i][1]=1;
	}
	cout<<max1<<endl;

}