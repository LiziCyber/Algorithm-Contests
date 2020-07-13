#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005;
int a[maxn],b[maxn];
int d[maxn][maxn];
int m,n;

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}
	cout<<d[m][n];
}
