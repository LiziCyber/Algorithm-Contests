#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1005],b[1005],c[1005];
int n;
int flag=0;

int main(){
	//freopen("2.in","r",stdin);
	scanf("%d", &n);
	for(int k=0;k<n;k++){
		int flag0=0;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		memset(c,'\0',sizeof(c));
		scanf("%s", a);
		scanf("%s", b);
		if(a==""){
			printf("%s", b);
		}else if(b==""){
			printf("%s", a);
		}else{
			int la=strlen(a)-1,lb=strlen(b)-1;
			if(la<lb){
				flag0=1;
				swap(a,b);
				swap(la,lb);
			}
			for(int i=la;i>=0;i--){
				int j=lb-(la-i);
				int cura=a[i]-'0';
				int curb=0;
				if(j>=0){
					curb=b[j]-'0';
				}
				c[i]=(cura+curb+flag)%10+'0';
				flag=(cura+curb+flag)/10;
			}
		}
		printf("Case %d:\n", k+1);
		if(flag0)swap(a,b);
		if(flag!=0){
			printf("%s + %s = %d%s\n", a,b,flag,c);
			if(k<n-1) printf("\n");
		}
		else{
			printf("%s + %s = %s\n", a,b,c);
			if(k<n-1) printf("\n");
		}

	}
}

