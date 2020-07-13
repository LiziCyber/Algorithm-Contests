//¶ş·Ö²éÕÒ
int bsearch(int* A,int x,int y,int v){
	int m;
	while(x<y){
		m=x+(y-x)/2;
		if(A[m]==v)return m;
		else if(A[m]<v)y=m;
		else x=m+1;
	}
	return -1;
}

int lower_bound(int *A,int x,int y,int v){
	int m;
	while(x<y){
		m=x+(y-x)/2;
		if(A[m]>=v)y=m;
		else x=m+1;
	}
	return x;
}
