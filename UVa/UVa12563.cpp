#include<iostream>
#include<cstring>
using namespace std;
int d[15000],f[15000];
int n,t,ans_n,v,T,kase;

int main(){
	cin>>T;
	while(T--){
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		cin>>n>>t;
		for(int i=1;i<=n;i++){
			cin>>v;
			for(int j=t-1;j>=0;j--)if(j>=v)
			if(d[j-v]+1>d[j]||(d[j-v]+1==d[j]&&f[j]<f[j-v]+v)){
				d[j]=d[j-v]+1;
				f[j]=f[j-v]+v;
			}
		}
		cout<<"Case "<<++kase<<": "<<d[t-1]+1<<" "<<f[t-1]+678<<"\n";
	}
	return 0;
}
