#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int v,e;
		cin>>v>>e;
		vector<pair<pair<int,int >, int> >  edg;
		for(int j =0;j<e;j++){
			int l,r,w;
			cin>>l>>r>>w;
			edg.push_back(make_pair(make_pair(l,r),w));
			edg.push_back(make_pair(make_pair(r,l),w));
		}
		int src;
		cin>>src;
		clock_t clockSt = clock();
		long long int arr[v+1];
		
		for(int k =0;k<v+1;k++)arr[k]= INT_MAX;
        arr[src]=0;
		for(int i1 =0;i1<v;i1++){
			for(int j =0;j<edg.size();j++){
				int l1 = edg[j].F.F;
				int r1 = edg[j].F.S;
				int w1 = edg[j].S;
				if(arr[r1]>arr[l1]+w1){
					if(i1==v-1){
						cout<<"Negative weight cycle present";
						break;}
					arr[r1]= arr[l1]+w1;

				}
			}
		}
		// for(int k=1;k<=v;k++){
		// 	if(arr[k]==INT_MAX)cout<<-1<<" ";
		// 	else if(k==src)continue;
		// 	else cout<<arr[k]<<" ";
		// }
		// cout<<endl;

		double time1= ((double)(clock() - clockSt)/CLOCKS_PER_SEC)*1000;
        cout<<fixed<<setprecision(6)<<time1<<" "<<v<<" "<<e<<" "<<v*e<<endl;
	
	}
}

