#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
int A[35];

void getmax(int& r,int& m,int len){
	m=A[0];r=0;
	for(int i=0;i<len;i++){
		if(A[i]>A[r]){
			r=i;
			m=A[i];
		}
	}
}

void inv(int ed){
	int i=0;
	while(i<ed){
		swap(A[i],A[ed]);
		i++;
		ed--;
	}
}

int main(){
	string s;
	while(getline(cin,s)){
		memset(A,0,sizeof(A));
		stringstream ss(s);
		int len=0;
		while(ss>>A[len])len++;
		int r=0,m=0;
		int l=len;
		for(int i=0;i<l;i++)
			cout<<A[i]<<" ";
		cout<<endl;
		while(len>1){
			getmax(r,m,len);
			if(r!=len-1){
				if(r!=0){
					inv(r);
					cout<<l-r<<" ";
				}
				inv(len-1);
				cout<<l-len+1<<" ";
			}
			len--;
		}
		cout<<"0"<<endl;
	}
}
