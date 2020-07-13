//O(n) 求最大连续和
#include<iostream>
#include<algorithm>
using namespace std;
int S[100],T[100];
int maxsum(int* S,int n,int* T){
	for(int i=1;i<=n;i++){
		T[i]=min(T[i-1],S[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(S[i]-T[i-1],ans);
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cin>>S[1];
	for(int i=2;i<=n;i++){
		cin>>S[i];
		S[i]=S[i]+S[i-1];
	}
	cout<<maxsum(S,n,T);
	return 0;
}
