#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n;
int a[100005];
int sum[100005];
int start[100005];
int main(){
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		scanf("%d", &m);
		for(int l=0;l<m;l++){
			scanf("%d", &a[l]);
		}
		sum[0] = a[0];
		start[0] = 0;
		for(int i=0;i<m-1;i++){
			if(a[i+1]>sum[i]+a[i+1]){
				start[i+1]=i+1;
				sum[i+1]=a[i+1];
			}else{
				start[i+1]=start[i];
				sum[i+1]=sum[i]+a[i+1];
			}
		}
		int maxn=-2e9;
		int curi;
		for(int i=0;i<m;i++){
			if(maxn<sum[i]){
				maxn=sum[i];
				curi=i;
			}

		}
		printf("Case %d:\n", k+1);
		printf("%d %d %d\n",maxn , start[curi]+1, curi+1);
		if(k!=n-1) printf("\n");
	}
}
