#include<algorithm>
#include<iostream>
using namespace std;

struct section{
	int a,b;
}A[10000];

bool cmp(section& p,section& q){
	return p.a<q.a;
}

int main(){
	int n,s,t;
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
		cin>>A[i].a>>A[i].b;
	sort(A,A+n,cmp);

	int i=0,cnt,ans=0;
	while(s!=t&&i<n){
		if(A[i].a<=s){
			cnt=A[i].b;
			while(A[++i].a<=s&&i<n){
				cnt=max(A[i].b,cnt);
			}
			s=cnt;
			ans++;
		}else{
			cout<<"NO ANSWER";
			break;
		}
	}

	if(cnt<t)
		cout<<"NO ANSWER";
	else
		cout<<ans;

	return 0;
}
