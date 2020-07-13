//分治法求最大连续和
int maxsum(int x,int y,int *a){
	int v,L,R,maxs;
	if(y-x==1)return a[x];
	int m=x+(y-x)/2;
	int maxs=max(maxsum(x,m,a),maxsum(m,y,a));
	v=0;L=A[m-1];
	for(int i=m-1;i>=x;i--){
		L=max(L,v+=a[i]);
	}
	v=0;R=A[m];
	for(int i=m;i<y;i++){
		R=max(R,v+=a[i]);
	}
	return max(maxs,L+R);
}
