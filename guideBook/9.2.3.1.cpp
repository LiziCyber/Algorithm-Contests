#include<iostream>
#include<algorithm>
using namespace std;
int d[10005];
int V[105];
int S,n;
bool vis[10005];

int dp(int cur){
	if(cur==0)return 0;
	if(vis[cur])return d[cur];
	vis[cur]=1;

	d[cur]=-(1<<30);
	for(int i=0;i<n;i++)if(cur-V[i]>=0)
		d[cur]=max(d[cur],dp(cur-V[i])+1);

	return d[cur];
}

int main(){
	cin>>n>>S;
	for(int i=0;i<n;i++)
		cin>>V[i];
	dp(S);
	if(d[S]>=0)cout<<d[S];
	else cout<<"NO ANSWER";
}
