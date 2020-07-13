#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10000;
int a[maxn][maxn],d[maxn][maxn];
int n;

void solve(){
	int i,j;
	for(j=1;j<=n;j++)d[n][j]=a[n][j];
	for(i=n-1;i>=1;i--)
		for(j=1;j<=i;j++)
			d[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
}

int solve(int i,int j){
	if(d[i][j]>=0)return d[i][j];
	return d[i][j]=a[i][j]+(i==n?0:max(solve(i+1,j),solve(i+1,j+1)));
}

int main(){
	cin>>n;
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];

}
