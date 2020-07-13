#include<iostream>
#include<algorithm>
using namespace std;
int n,d[1005],s[1005];

struct bulb{
	int V,K,C,L;
}B[1005];

bool cmp(bulb &a,bulb &b){
	return a.V<b.V;
}

int main(){
	while(true){
		cin>>n;
		if(n==0)break;
		for(int i=0;i<n;i++)
			cin>>B[i].V>>B[i].K>>B[i].C>>B[i].L;
		sort(B,B+n,cmp);
		s[0]=B[0].L;
		for(int i=1;i<n;i++)
			s[i]=s[i-1]+B[i].L;

		for(int i=0;i<n;i++){
			d[i]=s[i]*B[i].C+B[i].K;
			for(int j=1;j<i;j++)
				d[i]=min(d[i],d[j]+(s[i]-s[j])*B[i].C+B[i].K);
		}

		cout<<d[n-1]<<endl;
	}
	return 0;
}
