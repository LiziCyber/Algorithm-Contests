#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(1<<30);
int M1,M2,T,n,c,kase=0;
bool has_train[205][55][2];
int t[55],dp[205][55];

void solve(){
	for(int i=1;i<n;i++)dp[T][i]=INF;
	dp[T][n]=0;

	for(int i=T-1;i>=0;i--){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i+1][j]+1;
			if(j<n&&has_train[i][j][0]&&i+t[j]<=T)
				dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
			if(j>1&&has_train[i][j][1]&&i+t[j-1]<=T)
				dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
		}
	}
}

int main(){
	while(true){
		cin>>n;
		if(n==0)break;
		memset(has_train,0,sizeof(has_train));
		memset(dp,0,sizeof(dp));
		cin>>T;
		for(int i=1;i<n;i++)
			cin>>t[i];

		cin>>M1;
		for(int i=0;i<M1;i++){
			cin>>c;
			for(int j=1;c<=T&&j<=n;j++){
				has_train[c][j][0]=1;
				c=c+t[j];
			}
		}

		cin>>M2;
		for(int i=0;i<M2;i++){
				cin>>c;
			for(int j=n;c<=T&&j>=1;j--){
				has_train[c][j][1]=1;
				c=c+t[j-1];
			}
		}

		solve();

		cout<<"Case Number "<<++kase<<": ";
		if(dp[0][1]>=INF) cout<<"impossible\n";
		else cout<<dp[0][1]<<"\n";
	}
	return 0;
}
