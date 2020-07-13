#include<algorithm>
#include<iostream>
using namespace std;
int A[100000];
int n,C;

int solve(int C){
	sort(A,A+n);
	int sum=0,ans=0;
	for(int i=0;i<n;i++){
		if((sum+=A[i])<=C)
			ans++;
	}
	return ans;
}

int main(){
	cin>>n>>C;
	for(int i=0;i<n;i++)
		cin>>A[i];
	cout<<solve(C);
	return 0;
}
