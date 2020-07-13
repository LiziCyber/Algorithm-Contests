#include<iostream>
#include<algorithm>
using namespace std;
int G[1000][1000];
int n,d[1000];

struct ju{
	int a,b;//³¤¿í
	void ini(int a,int b){
		this->a=max(a,b);
		this->b=min(a,b);
	}
	bool operator<(const ju& j)const{
		return a<j.a&&b<j.b;
	}
}A[1000];

int dp(int i){
	int& ans=d[i];
	if(ans>0)return ans;
	ans=1;
	for(int j=0;j<n;j++)if(G[i][j])
		ans=max(ans,dp(j)+1);
	return ans;
}

void print_ans(int i){
	cout<<i+1;
	for(int j=0;j<n;j++)if(G[i][j]&&d[i]==d[j]+1){
		print_ans(j);
		break;
	}
}

int main(){
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		A[i].ini(a,b);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i]<A[j])G[i][j]=1;
	for(int i=0;i<n;i++)
		dp(i);
	int mini=0;
	for(int i=1;i<n;i++)
		if(d[i]>d[mini])
			mini=i;
	print_ans(mini);
	//for(int i=0;i<n;i++)cout<<d[i]<<" ";
	return 0;
}
