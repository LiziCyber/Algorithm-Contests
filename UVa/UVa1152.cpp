#include<cstdio>
#include<cmath>
#include<cstdlib>
int n,m;
const int p=4000000;
int A[4005],B[4005],C[4005],D[4005];
struct node{
	int num=0;
	int fre=0;
	node* son=NULL;
}L[p][2];

void setvalue(int c,int q){
	int pos=abs(q%p);
	if(L[pos][c].fre){
		node* cur=&L[pos][c];
		if(q==cur->num){
			cur->fre++;
			return;
		}
		while(cur->son!=NULL){
			cur=cur->son;
			if(q==cur->num){
				cur->fre++;
				break;
			}
		}
		node *No=new node();
		No->num=q;
		No->fre=1;
		cur->son=No;

	}else{
		L[pos][c].fre++;
		L[pos][c].num=q;
	}
}

int main(){
	scanf("%d",&m);
	for(int cases=0;cases<m;cases++){
		int ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){//读取数据
			scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
		}
		int cur;
		for(int i=0;i<n;i++){//储存进hash表
			for(int j=0;j<n;j++){
				cur=A[i]+B[j];
				setvalue(0,cur);
				cur=C[i]+D[j];
				setvalue(1,cur);
			}
		}
		for(int i=0;i<p;i++){//check哈希表
			if(!(L[i][0].fre&&L[i][1].fre))continue;
			node* cur0=&L[i][0];
			while(cur0!=NULL){
				node* cur1=&L[i][1];
				while(cur1!=NULL){
					if(cur1->num+cur0->num==0){
						ans+=(cur1->fre)*(cur0->fre);
						break;
					}
					cur1=cur1->son;
				}
				cur0=cur0->son;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}






