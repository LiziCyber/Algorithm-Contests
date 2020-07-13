#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=110;
int G[maxn][maxn];
int vis[maxn];
int m,n,a,b;
stack<int> s;

void DFS(int u){
	for(int v=1;v<=n;v++)
		if(G[u][v]&&(!vis[v]))
			DFS(v);
	vis[u]=1;
	s.push(u);
}

int main(){
	for(;;){
		scanf("%d%d",&n,&m);
		if( !(m||n) )break;
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			G[a][b]=1;
		}
		for(int u=1;u<=n;u++){
			if(!vis[u])
				DFS(u);
		}
		while(!s.empty()){
			printf("%d ", s.top() );
			s.pop();
		}
		printf("\n");
	}
}
