#include<cstdio>
//枚举数组P中所有元素的排列（包含重复）
void print_permutation(int n,int* P,int* A,int cur){
	if(cur==n){
		for(int i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
	else for(int i=0;i<n;i++)
	if(!i||P[i]!=P[i-1]){
		int c1=0,c2=0;
		for(int j=0;j<cur;j++)if(A[j]==P[i])c1++;
		for(int j=0;j<n;j++)if(P[j]==P[i])c2++;
		if(c1<c2){
			A[cur]=P[i];
			print_permutation(n,P,A,cur+1);
		}
	}
}
	int A[50],P[50];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&P[i]);
	print_permutation(n,P,A,0);
}
