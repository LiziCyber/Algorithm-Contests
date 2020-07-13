#include<iostream>
using namespace std;
const int maxn=105,maxc=10005;
int d[maxc],v[maxn],w[maxn];
int c,n;
bool vis[maxc];

int solve(int cur){
	if(vis[cur])return d[cur];
	vis[cur]=1;

	for(int i=0;i<n;i++)if(cur>=v[i])
			d[cur]=max(d[cur],solve(cur-v[i])+w[i]);

	return d[cur];
}

int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++)
		cin>>v[i]>>w[i];
	cout<<solve(c);
}
