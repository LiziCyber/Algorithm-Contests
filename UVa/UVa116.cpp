#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,A[11][101],nexti[11][101];
int d[11][101],t[3];

int main(){
	while(scanf("%d%d",&m,&n)==2){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&A[i][j]);

		for(int i=1;i<=m;i++)
			d[i][n]=A[i][n];

		for(int j=n-1;j>=1;j--){
			for(int i=1;i<=m;i++){
				for(int k=-1;k<=1;k++)
					if(i+k==0)t[k+1]=m;
					else if(i+k==m+1)t[k+1]=1;
					else t[k+1]=i+k;
				sort(t,t+3);
				d[i][j]=d[t[0]][j+1]+A[i][j];
				nexti[i][j]=t[0];
				for(int k=1;k<=2;k++){
					if(d[i][j]>d[t[k]][j+1]+A[i][j]){
						d[i][j]=d[t[k]][j+1]+A[i][j];
						nexti[i][j]=t[k];
					}
				}
			}
		}
		int ans=1<<30,v;
		for(int i=1;i<=m;i++)if(ans>d[i][1]){
			ans=d[i][1];
			v=i;
		}
        for(int i=1;i<=n;i++){
			if(i!=n)printf("%d ",v);
			else printf("%d",v);
			v=nexti[v][i];
        }
		printf("\n%d\n",ans);
	}
}
