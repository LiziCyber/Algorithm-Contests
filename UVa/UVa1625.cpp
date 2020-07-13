#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=5005;
const int INF = 1000000000;

int T,la,lb,t;
char a[maxn],b[maxn];
int sa[26],ea[26];
int sb[26],eb[26];
int d[maxn][2],c[maxn][2];

void fir_se(){
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
}

void set_be(){
		for(int i=0;i<26;i++){
			sa[i]=sb[i]=INF;
			ea[i]=eb[i]=0;
		}
		for(int i=1;i<=la;i++){
			sa[a[i]]=min(sa[a[i]],i);
			ea[a[i]]=i;
		}
		for(int i=1;i<=lb;i++){
			sb[b[i]]=min(sb[b[i]],i);
			eb[b[i]]=i;
		}
}

void read(){
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1);lb=strlen(b+1);
	for(int i=1;i<=la;i++)a[i]-='A';
	for(int i=1;i<=lb;i++)b[i]-='A';
}

int main(){
	scanf("%d",&T);
	while(T--){
		read();

		set_be();

		t=0;
		fir_se();
		for(int i=0;i<=la;i++){
			for(int j=0;j<=lb;j++){
				if(!i&!j)continue;

				int v1=INF,v2=INF;
				if(i)v1=d[j][t^1]+c[j][t^1];
				if(j)v2=d[j-1][t]+c[j-1][t];
				d[j][t]=min(v1,v2);

				if(i){
					c[j][t]=c[j][t^1];
					if(sa[a[i]]==i&&sb[a[i]]>j)c[j][t]++;
					if(ea[a[i]]==i&&eb[a[i]]<=j)c[j][t]--;
				}else if(j){
					c[j][t]=c[j-1][t];
					if(sb[b[j]]==j&&sa[b[j]]>i)c[j][t]++;
					if(eb[b[j]]==j&&ea[b[j]]<=i)c[j][t]--;
				}
			}
			t^=1;
		}
		printf("%d\n",d[lb][t^1]);
	}
	return 0;
}
/*
Sample Input
2
AAABBCY
ABBBCDEEY
GBBY
YRRGB
Sample Output
10
12
*/
