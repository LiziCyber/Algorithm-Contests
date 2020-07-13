#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int k;
	string name;
	while(~scanf("%d",&k)){
		map<string, int> bol;
		if(k==0)break;
		for(int i=0; i<k; i++){
			cin>>name;
			if(bol.count(name)>0){
				bol[name]++;
			}else{
				bol[name]=1;
			}
		}
		map<string, int>::iterator iter;
		iter = bol.begin();
		string maxname;
		int maxn=0;
		while(iter!=bol.end()){
			if(maxn<(iter->second)){
				maxn=iter->second;
				maxname=iter->first;
			}
			iter++;
		}
		cout<<maxname<<endl;
	}
}
