//Huffman
#include<iostream>
#include<queue>
using namespace std;
int n;

struct node{
	char c;
	int w;
	node* left;
	node* right;
	bool operator < (const node &b)const{
		return this->w<b.w;
	}
};

node build_tree(){
	priority_queue<node>q;
	for(int i=0;i<n;i++){
		node A;
		cin>>A.c>>A.w;
		q.push(A);
	}
	while(true){
		if(q.size()==1)break;
		node A=q.top();q.pop();
		node B=q.top();q.pop();
		node C;
		C.left=&A;
		C.right=&B;
		C.w=A.w+B.w;
		q.push(C);
	}
	return q.top();
}

print_tree(node n){
	if(n.left!=NULL)print_tree(*n.left);
	if(n.right!=NULL)print_tree(*n.right);
	if(n.left==NULL&&n.right==NULL) cout<<n.c;
}

int main(){
	print_tree(build_tree());
	return 0;
}
