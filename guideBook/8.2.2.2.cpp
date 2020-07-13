//¿ìËÙÑ¡ÔñO(n)
#include<iostream>
#include<algorithm>
using namespace std;
int A[5000];
int m,ans;
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
	if(A[i]>m) quick_sort(A,x,i);
	else quick_sort(A,i,y);
}

int main(){
	int m,n;
	cin>>m>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	quick_sort(A,0,n);
	for(int i=0;i<n;i++)
		if(A[i]==m){
			cout<<(i+1);
			return 0;
		}
	return 0;
}
