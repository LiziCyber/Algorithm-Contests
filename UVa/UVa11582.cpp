#include<iostream>
#include<vector>
using namespace std;
const int maxn=1005;
vector<int> F[maxn];

int pow_mod(int a,unsigned long long b,int n){
	if(b==0)return 1;
	int x=pow_mod(a,b/2,n);
	long long ans=(long long)x*x%n;
	if(b%2==1)ans=(ans*(a%n))%n;
	return (int)ans;
}

int main(){
	unsigned long long a=0,b=0;
	int n,t,n1;
	for(int i=1;i<=1000;i++){
		F[i].push_back(0);
		F[i].push_back(1);
		for(int j=2;j<=1000*1000;j++){
			n1=(F[i][j-1]+F[i][j-2])%i;
			if(n1==1&&F[i][j-1]==0){
				F[i].pop_back();
				break;
			}
			F[i].push_back(n1);
		}
	}
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		if(n==1){
			cout<<"0"<<endl;
			continue;
		}
		n1=F[n].size();
		cout<<F[n][pow_mod(a%n1,b,n1)]<<endl;
	}
	return 0;
}
