#include<cstdio>
#include<cstring>
int n,p[40],ans[40],vis[40];

int is_prime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}

void solve(int cur){
	if(cur==n&&p[ ans[0]+ans[n-1] ]){
		for(int i=0;i<n-1;i++)
			printf("%d ",ans[i]);
		printf("%d",ans[n-1]);
		printf("\n");
	}else for(int i=2;i<=n;i++){
		if(p[ans[cur-1]+i]&&!vis[i]){
			ans[cur]=i;
			vis[i]=1;
			solve(cur+1);
			vis[i]=0;
		}
	}
}

int main(){
	for(int i=2;i<40;i++) p[i]=is_prime(i);
	int c=0;
	while(scanf("%d",&n)==1){
		if(c>0) printf("\n");
		c++;
		printf("Case %d:\n",c);
		memset(ans,0,sizeof(ans));
		ans[0]=1;
		solve(1);
	}
	return 0;
}
