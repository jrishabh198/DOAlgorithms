#include <bits/stdc++.h>
using namespace std;
struct node{
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
};
bool findOverlap(int l1,int r1,int l2,int r2){
	if(l1>=l2&&l1<=r2)return true;
	if(l2>=l1&&l2<=r1)return true;
	if(r1>=l2&&r1<=r2)return true;
	if(r2>=l1&&r2<=r1)return true;
	return false;
}

pair<int,int> search(node* root,int l,int r){
	if(root==NULL)return make_pair(-1,-1);
	if(findOverlap(root->interval_low,root->interval_high,l,r))return make_pair(root->interval_low,root->interval_high);
	if(root->left!=NULL){
		if(l<=root->left->max)return search(root->left,l,r);
		else return search(root->right,l,r);
	}
	return search(root->right,l,r);
}

void insert(node* &root,int l,int r){
	if(root==NULL){
		root = new node();
		root->interval_low = l;
		root->interval_high = r;
		root->max = r;
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

node* next_succ(node* root){
	while(root->left!=NULL){
		root= root->left;
	}
	return root;
}


void delete1(node* &root,int l,int r,node* &parent){
	if(root==NULL)return;
	if(l<root->interval_low){
		delete1(root->left,l,r,root);
	}
	else if(l>root->interval_low){
		delete1(root->right,l,r,root);
	}
	else if(r==root->interval_high){
		if(root->left==NULL){
			if(parent->left==root)parent->left = root->right;
			else parent->right = root->right;
		}
		else if(root->right ==NULL){
			if(parent->left ==root)parent->left = root->left;
			else parent->right = root->left;
		}
		else{
			node* temp = next_succ(root->right);
			root->interval_low = temp->interval_low;
			root->interval_high = temp->interval_high;
			root->max = temp->max;
			delete1(root->right,temp->interval_low,temp->interval_high,root);
		}
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
	int l,r;
	cin>>l>>r;
	pair<int,int> x = search(root,l,r);
	cout<<x.first<<" "<<x.second<<endl;
	


}