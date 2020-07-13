#include<iostream>
#include<algorithm>
using namespace std;
int A[5000];

void quick_sort(int *A,int x,int y){
	if(x+1>=y)return;
	int m=A[x];
	int i=x+1,j=y-1;
	while(i!=j){
		for(i;i!=j;i++)
			if(A[i]>m)break;
		for(j;j!=i;j--)
			if(A[j]<m)break;
		if(i!=j)swap(A[i],A[j]);
	}
	if(A[x]>A[i])swap(A[x],A[i]);
	quick_sort(A,x,i);
	quick_sort(A,i,y);
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	quick_sort(A,0,n);
	for(int i=0;i<n;i++)
		cout<<A[i];
	return 0;
}
