#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ans[1000];

struct Node{
	bool is_giant;
	int x,y,id;
	double ang;
}A[1000],v;

bool cmp1(Node &a,Node &b){
	return a.ang==b.ang?a.x<b.x:a.y<b.y;
}

bool cmp2(Node &a,Node &b){
	return atan2(a.y-v.y,a.x-v.x)<atan2(b.y-v.y,b.x-v.x);
}

void solve(int l,int r){//[l,r)
	if(l+1>=r)return;

	sort(A+l,A+r,cmp1);
	v=A[l];

	sort(A+1+l,A+r,cmp2);
	int c1=0,c2=0;
	int i;
	for(i=r-1;i>l;i--){
		if(c1==c2&&A[i].is_giant!=v.is_giant)break;
		if(v.is_giant==A[i].is_giant)c1++;
		else c2++;
	}
	ans[A[i].id]=v.id;
	ans[v.id]=A[i].id;
	solve(l+1,i);
	solve(i+1,r);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i].x>>A[i].y>>A[i].is_giant;
		A[i].id=i;
	}
	solve(0,n);
	for(int i=0;i<n;i++){
		cout<<i<<" "<<ans[i]<<endl;
	}
}
/*
4
0 0 1
2 1 1
2 2 0
0 3 0
*/
