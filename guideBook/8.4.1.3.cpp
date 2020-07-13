#include<algorithm>
#include<iostream>
using namespace std;
int ans,n,C;
int A[1000000];
int main(){
	cin>>n>>C;
	for(int i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);
	int i=0,j=n-1;
	while(i<j){
		if(A[i]+A[j]>C){
			ans++;
			j--;
		}else{
			ans++;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
