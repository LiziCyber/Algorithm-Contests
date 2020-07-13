#include<iostream>
using namespace std;
int A[10000][10000];
int ans;

void fi(int cur,int x,int y,int cx,int cy){
	int v=(1<<cur);
	if(cur==1){
		ans++;
	}else{
		ans++;
		if(x>=cx&&x<cx+v&&y>=cy&&y<cy+v){//左上
			fi(cur-1,x,y,cx,cy);
			fi(cur-1,cx+v,cy+v-1,cx+v,cy);
			fi(cur-1,cx+v-1,cy+v,cx,cy+v);
			fi(cur-1,cx+v,cy+v,cx+v,cy+v);
		}else if(x>=cx+v&&x<cx+2*v&&y>=cy&&y<cy+v){//左下
			fi(cur-1,cx+v-1,cy+v-1,cx,cy);
			fi(cur-1,x,y,cx+v,cy);
			fi(cur-1,cx+v-1,cy+v,cx,cy+v);
			fi(cur-1,cx+v,cy+v,cx+v,cy+v);
		}else if(x>=cx&&x<cx+v&&y>=cy+v&&y<cy+2*v){//右上
			fi(cur-1,cx+v-1,cy+v-1,cx,cy);
			fi(cur-1,cx+v,cy+v-1,cx+v,cy);
			fi(cur-1,x,y,cx,cy+v);
			fi(cur-1,cx+v,cy+v,cx+v,cy+v);
		}else{//右下
			fi(cur-1,cx+v-1,cy+v-1,cx,cy);
			fi(cur-1,cx+v,cy+v-1,cx+v,cy);
			fi(cur-1,cx+v-1,cy+v,cx,cy+v);
			fi(cur-1,x,y,cx+v,cy+v);
		}
	}
}

int main(){
	int k,x,y;
	cin>>k>>x>>y;
	A[x][y]=1;
	fi(k,x,y,0,0);
	cout<<ans;
	return 0;
}
