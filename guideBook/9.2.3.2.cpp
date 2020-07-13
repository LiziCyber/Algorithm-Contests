#include<iostream>
#include<algorithm>
using namespace std;
int maxv[10005],minv[10005];
int V[105];
int S,n;

int main(){
	cin>>n>>S;
	for(int i=0;i<n;i++)
		cin>>V[i];
	minv[0]=maxv[0]=0;
	//*
	for(int i=1;i<=S;i++){
		minv[i]=1<<30;
		maxv[i]=-(1<<30);
	}
	for(int i=1;i<=S;i++){
		for(int j=0;j<n;j++){
			if(i>=V[j]){
				minv[i]=min(minv[i],minv[i-V[j] ]+1);
				maxv[i]=max(maxv[i],maxv[i-V[j] ]+1);
			}
		}
	}
	cout<<minv[S]<<" "<<maxv[S];
}
