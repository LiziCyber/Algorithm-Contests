#include<cstdio>
int S[100];
int n,L,cnt=0;
int dfs(int cur){
	if(cnt++ == n){
		for(int i=0;i<cur;i++){
			if(i==64)printf("\n");
			printf("%c",'A'+S[i]);
			if(i%4==3&&i!=cur-1&&i%64!=63)printf(" ");
		}
		printf("\n%d",cur);
		return 0;
	}
	for(int i=0;i<L;i++){
		S[cur]=i;
		int ok=1;
		for(int j=1;j*2<=cur+1;j++){
			int equal=1;
			for(int k=0;k<j;k++)
				if(S[cur-k]!=S[cur-k-j]){
					equal=0;
					break;
				}
			if(equal){ok=0;break;}
		}
		if(ok) if(!dfs(cur+1))return 0;
	}
	return 1;
}

int main(){
	//freopen("ans.txt","w",stdout);
	int i=0;
	while(scanf("%d%d",&n,&L)){
		if(i!=0)printf("\n");
		if(n==0&L==0)break;
		cnt=0;
		dfs(0);
		i++;
	}
	return 0;
}
