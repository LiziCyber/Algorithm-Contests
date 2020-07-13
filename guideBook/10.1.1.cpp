#include<iostream>
#include<algorithm>
using namespace std;
int X[10005];

int gcd(int a,int b){
	if(a>b)
		return b==0?a:gcd(b,a%b);
	else return gcd(b,a);
}

int judge(){
	X[2]/=gcd(X[2],X[1]);
	for(int i=3;i<=k;i++)X[2]/=gcd(X[2],X[i]);
	return X[i]==1;
}

int main(){
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)cin>>X[i];
	if(judge())cout<<"True";
	else cout<<"False";
	return 0;
}
