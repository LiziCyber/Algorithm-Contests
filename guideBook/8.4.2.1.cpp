#include<algorithm>
#include<iostream>
using namespace std;
int ans[100000];

struct section{
	int id,a,b;
}A[100000];

bool cmp(section& p,section& q){
	return p.b!=q.b ? p.b<q.b : p.a>q.a;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i].a>>A[i].b;
		A[i].id=i;
	}
	sort(A,A+n,cmp);
	int cur=0;
	for(int i=1;i<n;i++){
		if(A[ans[cur]].b<=A[i].a){
			ans[++cur]=i;
		}
	}
	for(int i=0;i<=cur;i++)
		cout<<A[ans[i]].id<<' ';
	cout<<endl;
	cout<<cur+1;
	return 0;
}
