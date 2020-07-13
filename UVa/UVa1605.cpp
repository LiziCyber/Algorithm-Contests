#include<cstdio>
int A[55];
int n;
int main(){
	for(int i=0;i<26;i++){
		A[i]='a'+i;
		A[i+26]='A'+i;
	}
	while(scanf("%d",&n)){
		printf("2 %d %d\n",n,n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c ",A[i]);
			}
			printf("\n");
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c ",A[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
