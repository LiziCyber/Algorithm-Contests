#include<iostream>
using namespace std;
int d[10005];
int n,c,v,w;

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>v>>w;
		for(int j=c;j>=0;j--)
		if(j>=v)d[j]=max(d[j],d[j-v]+w);
	}
	cout<<d[c];
}
