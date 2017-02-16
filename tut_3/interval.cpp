#include <bits/stdc++.h>
using namespace std;
class node{
	int interval_low;
	int interval_high;
	int max;
	node* left;
	node* right;

	node(){
		interval_low =0;
		interval_high =0;
		max =0;
		left =NULL;
		right = NULL;

	}
}
void insert(node* root,int l,int r){
	if(root==NULL){
		root = new node();
		root->interval_low = l;
		root->interval_high = r;
		root->max = interval_high;
		return;
	}
	if(l<=root->interval_low){
		insert(root->left,l,r);
	}
	else{
		insert(root->right,l,r);
	}
	if(r>root->max)root->max = r;
}
void delete(node* root,int l,int r){
	if(root==NULL)return;
	if(l==root->interval_low&&r==interval_high){
		
	}
	if(l<root->interval_low){

	}
}
int main(){
	int n;
	cin>>n;
	node* root = NULL;
	for(int i =0;i<n;i++){
		int l,r;
		cin>>l>>r;
		insert(root,l,r);
	}


}