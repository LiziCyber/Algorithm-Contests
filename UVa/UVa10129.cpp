/*
The door cannot be opened.
Ordering is possible.
*/
#include<cstdio>
#include<cstring>
char s[1005];
int in[26];
int out[26];
int G[26][26];
int vis[26];
void dfs(int u){
	vis[u]=1;
	for(int v=0;v<26;v++)
		if( vis[v]==-1&&G[u][v] )
			dfs(v);
}

int main(){
	int T,N;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&N);

		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));

		for(int j=0;j<N;j++){
			memset(s,0,sizeof(s));
			scanf("%s",s);
			out[s[0]-'a']++;
			in[s[strlen(s)-1]-'a']++;
			G[s[0]-'a'][s[strlen(s)-1]-'a']=1;
			G[s[strlen(s)-1]-'a'][s[0]-'a']=1;
			vis[s[0]-'a']=-1;
			vis[s[strlen(s)-1]-'a']=-1;
		}

		int flag=0,num1=0,num2=0;
		for(int j=0;j<26;j++){
			if(in[j]==out[j]){
				continue;
			}else if(in[j]==out[j]+1){
				num1++;
			}else if(in[j]+1==out[j]){
				num2++;
			}else{
				flag=1;
				break;
			}
		}
		if(flag||num1>1||num2>1){
			printf("The door cannot be opened.\n");
			continue;
		}
		dfs(s[strlen(s)-1]-'a');
		int flag2=0;
		for(int j=0;j<26;j++){
			if(vis[j]==-1){
				flag2=1;
				break;
			}
		}
		if(flag2){
			printf("The door cannot be opened.\n");
			continue;
		}
		printf("Ordering is possible.\n");
	}
}
