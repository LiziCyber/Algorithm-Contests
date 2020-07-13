#include<iostream>
using namespace std;
int A[10000][10000];
void fl(int cur){
	if(cur==0)return;
	fl(cur-1);
	int v=1<<(cur-1);
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			A[i][j+v]=A[i][j]+v;
			A[i+v][j]=A[i][j]+v;
			A[i+v][j+v]=A[i][j];
		}
	}
}

int main(){
	int k;
	cin>>k;A[0][0]=1;
	fl(k);
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<(1<<k);j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
