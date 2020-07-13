#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char s[1005];
    int a[1005];
    int i,len,sum,n;
    while(scanf("%s",s)!=EOF){
        n=0;
        sum=0;
        len=strlen(s);
        s[len]='5';
        i=0;
        while(s[i]=='5')i++;//Ìø¹ýÇ°×º
        for(i;i<=len;i++){
            if(i>0&&s[i]=='5'&&s[i-1]=='5')
                continue;

            if(s[i]!='5')
                sum=sum*10+s[i]-'0';
            else{
                a[n++]=sum;
                sum=0;
            }
        }
        sort(a,a+n);
        printf("%d",a[0]);
        for(i=1;i<n;++i)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
