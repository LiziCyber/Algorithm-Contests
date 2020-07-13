#include<algorithm>
#include<iostream>
using namespace std;
struct th{
	int w,v;
	int q;
}A[100000];
int n,C;

bool cmp(th &a,th &b){
	return a.q>b.q;
}

int solve(int C){
	sort(A,A+n,cmp);
	int sum=0,ans=0,i;
	for(i=0;i<n;i++){
		if((sum+A[i].w)<=C){
			ans+=A[i].v;
			sum+=A[i].w;
		}else break;
	}
	if(sum<C)ans+=A[i].q*(C-sum);
	return ans;
}

int main(){
	cin>>n>>C;
	int w,v;
	for(int i=0;i<n;i++){
		cin>>A[i].w>>A[i].v;
		A[i].q=v/w;
	}
	cout<<solve(C);
	return 0;
}
