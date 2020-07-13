#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int now[10];
int ans[10];
int pic[10];
int pos[26];
int G[30][30];
int vis[26];
int n,k,m,ch;
string s;
void dfs(int cur,int cnt){
	if(cur==n){
		if(cnt==k){
			int ok=0;
			for(int i=0;i<n;i++){
				if(ans[i]>now[i]){
					ok=1;break;
				}else if(ans[i]==now[i])continue;
				else break;
			}
			if(ok)for(int i=0;i<n;i++){
				ans[i]=now[i];
			}
		}else if(cnt<k){
			k=cnt;
			for(int i=0;i<n;i++){
				ans[i]=now[i];
			}
		}
	}else{
		for(int i=0;i<n;i++){
			int ok=1;
			for(int j=0;j<cur;j++)
				if(now[j]==pic[i]){ok=0;break;}
			if( !cur || ok ){
				now[cur]=pic[i];
				for(int j=0;j<cur;j++){
					if(G[ now[j]-'A' ][ now[cur]-'A' ]){
						if(cur-j>k)return;
						if(cnt<=cur-j)cnt=cur-j;
					}
				}
				dfs(cur+1,cnt);
			}
		}
	}
}

int main(){
	for(;;){
		n=0;k=8;s="",m=0;
		memset(pic,0,sizeof(pic));
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		memset(pos,0,sizeof(pos));
		getline(cin,s);
		if(s[0]=='#')break;
		for(int i=0;i<s.length();i++){
			if(!i||s[i-1]==';'){
				ch=s[i];
				if(!vis[s[i]-'A']){
					pos[s[i]-'A']=n;
					pic[n++]=s[i];
					vis[s[i]-'A']=1;
				}
			}else if(s[i]==':'||s[i]==';'){
				continue;
			}else{
				G[ch-'A'][s[i]-'A']=1;
				G[s[i]-'A'][ch-'A']=1;
				if(!vis[s[i]-'A']){
					pos[s[i]-'A']=n;
					pic[n++]=s[i];
					vis[s[i]-'A']=1;
				}
			}
		}
		dfs(0,1);
		for(int i=0;i<n;i++)
			printf("%c ",ans[i]);
		printf("-> %d\n",k);
	}
	return 0;

}
//A B C F G D H E -> 3
/*
A:FB;B:GC;D:GC;F:AGH;E:HD
#
*/
