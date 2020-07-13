#include<cstdio>
#include<cmath>

const int maxn=1000005;
const int maxm=10000005;
int vis[maxn];
int d[maxm];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int v=sqrt(m)+1;
	for(int i=2;i<=v;i++)if(!vis[i])
		for(int j=i*i;j<=m;j+=i)
			vis[j]=1;
	for(int i=2;i<=v;i++)if(!vis[i])
		for(int j=n;j<=m;j+=i*i)
			d[j-n]=1;
	for(int i=0;i<=m-n;i++)if(!d[i])
		printf("%d\n",i);
}
