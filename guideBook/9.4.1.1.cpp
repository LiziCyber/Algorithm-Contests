#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005;
int a[maxn],d[maxn];
int n;

void solve1(){
	d[1]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
	if(a[j]<a[i]&&d[j]+1>d[i]){
		d[i]=d[j]+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,d[i]);
	cout<<ans;
}

void solve2(){
	int len=1;
	d[1]=a[1];
	for(int i=2;i<=n;i++){
		int* it=lower_bound(d+1,d+len+1,a[i]);
		if(it==d+len+1)
			d[++len]=a[i];
		else
			*it=a[i];
	}
	cout<<len;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//solve1();
	solve2();
	return 0;
}
