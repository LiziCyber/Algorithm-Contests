#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int G[95][95],n,kase,d[95];

struct rectangle{
	int a,b,h;

	void set_rec(int a,int b,int h){
		this->a=max(a,b);
		this->b=min(a,b);
		this->h=h;
	}

	bool operator<(rectangle& R)const{
		return (this->a)<R.a&&(this->b)<R.b;
	}
}R[95];

int dp(int i){
	if(d[i]>0)return d[i];
	d[i]=R[i].h;
	for(int j=0;j<3*n;j++)
		if(G[i][j])d[i]=max(d[i],dp(j)+R[i].h);
	return d[i];
}

int solve(){
	int ans=0;
	for(int i=0;i<n*3;i++){
		ans=max(ans,dp(i));
	}
	return ans;
}

int main(){

	while(true){
		memset(G,0,sizeof(G));
		memset(d,0,sizeof(d));
		memset(R,0,sizeof(R));

		cin>>n;
		if(n==0)break;
		int a,b,c;
		for(int i=0;i<n*3;i+=3){
			cin>>a>>b>>c;
			R[i].set_rec(a,b,c);
			R[i+1].set_rec(a,c,b);
			R[i+2].set_rec(b,c,a);
		}

		for(int i=0;i<n*3;i++){
			for(int j=0;j<n*3;j++){
				if(R[j]<R[i]){
					G[i][j]=1;
				}
			}
		}

		cout<<"Case "<<++kase<<": maximum height = "<<solve()<<endl;

	}

	return 0;
}
