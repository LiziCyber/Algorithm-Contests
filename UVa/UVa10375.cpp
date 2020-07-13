#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
vector<int> primes;
const int maxn=10000+5;
int vis[maxn],e[maxn];
int p,q,r,s,len;

void solve0(int n,int d){
	for(int i=0;i<len;i++){
		while(n%primes[i]==0){
			n/=primes[i];
			e[i]+=d;
		}
		if(n==1)break;
	}
}

void solve(int n,int d){
	for(int i=1;i<=n;i++)
		solve0(i,d);
}

int main(){
	for(int i=2;i<=100;i++)if(!vis[i])
		for(int j=i*i;j<=10000;j+=i)
			vis[j]=1;

	for(int i=2;i<=10000;i++)if(!vis[i])
		primes.push_back(i);
	len=primes.size();

	while(cin>>p>>q>>r>>s){
		memset(e,0,sizeof(e));
		solve(p,1);
		solve(q,-1);
		solve(p-q,-1);
		solve(r,-1);
		solve(s,1);
		solve(r-s,1);
		double ans=1;
		for(int i=0;i<len;i++)
			ans*=pow(primes[i],e[i]);
		printf("%.5lf\n",ans);

	}
	return 0;
}
