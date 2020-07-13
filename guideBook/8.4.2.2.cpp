#include<algorithm>
#include<iostream>
using namespace std;

struct section{
	int a,b;
}A[100000];

bool cmp(section& p,section& q){
	return p.b!=q.b ? p.b<q.b : p.a>q.a;
}

int main(){
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i].a>>A[i].b;
	sort(A,A+n,cmp);
	for(int i=1;i<n;i++){
		int cnt=1;
		for(int j=i+1;A[j].a<=A[i].b&&j<n;j++)
			cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
