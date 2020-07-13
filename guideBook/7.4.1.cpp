//eight queens
#include<cstdio>
int ans,n;
int vis[3][100];
void solve(int cur){
	if(cur==n)ans++;
	else for(int i=0;i<n;i++){
		if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]){
			vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
			solve(cur+1);
			vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	solve(0);
	printf("%d",ans);
}
