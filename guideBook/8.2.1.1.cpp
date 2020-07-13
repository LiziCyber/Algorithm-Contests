#include<iostream>
using namespace std;
int A[5000],T[5000];
void merge_sort(int *A,int x,int y,int *T){
	if(y-x>1){
		int m=x+(y-x)/2;
		int p=x,q=m,i=x;
		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);
		while(p<m||q<y){
			if( p>=m || q<y&&A[p]>A[q] )T[i++]=A[q++];
			else T[i++]=A[p++];
		}
		for(int i=x;i<y;i++)A[i]=T[i];
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	merge_sort(A,0,n,T);
	for(int i=0;i<n;i++)
		cout<<A[i];
	return 0;
}
