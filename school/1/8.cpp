#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

// 4个方向BFS找联通
// 1上2下3左4右
int di[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int bl[11][4]={
	{1,0,1,0},
	{1,0,0,1},
	{0,1,1,0},
	{0,1,0,1},
	{1,1,0,0},
	{0,0,1,1},
	{1,0,1,1},
	{1,1,1,0},
	{0,1,1,1},
	{1,1,0,1},
	{1,1,1,1}
};
int off[4]={1,0,3,2};
int a[55][55];
int vis[55][55];


struct node{
	int x;
	int y;
	node(int x, int y) :x(x), y(y){}
};

queue<node> q;
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m<0||n<0)break;

		memset(vis,0,sizeof(vis));

		char c;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%c", &c);
				a[i][j]=c-'A';
			}
			getchar();
		}

		int curnum=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(vis[i][j]==0){
					q.push(node(i,j));
					vis[i][j]=curnum;
					while(!q.empty()){
						node curnode=q.front();
						q.pop();
						for(int k=0;k<4;k++){
							if(bl[a[i][j]][k]){
								int x=curnode.x+di[k][0];
								int y=curnode.y+di[k][1];
								if(x>=0 && x<m && y>=0 && y<n &&
								   bl[a[x][y]][off[k]] && vis[x][y]==0){
									q.push(node(x,y));
									vis[x][y]=curnum;
								}
							}
						}

					}
					curnum++;
				}
			}
		}
		printf("%d\n",curnum-1);
	}
}

