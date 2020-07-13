#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
double d[1005][1005];

struct point{
	int x,y;
}p[1005];

double dis(point a,point b){
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

double solve(){
	double dis1=dis(p[n-1],p[n]);
	for(int i=1;i<n-1;i++)
		d[n-1][i]=dis1+dis(p[i],p[n]);
	for(int i=n-2;i>1;i--){
		for(int j=1;j<i;j++){
			d[i][j]=min(d[i+1][j]+dis(p[i],p[i+1]),
						d[i+1][i]+dis(p[j],p[i+1]));
		}
	}

	return d[2][1]+dis(p[2],p[1]);
}

int main(){
	while(scanf("%d",&n)==1){
		memset(d,0,sizeof(d));

		for(int i=1;i<=n;i++)
			scanf("%d %d",&p[i].x,&p[i].y);

		printf("%.2f\n",solve());

	}
	return 0;
}
