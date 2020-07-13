#include <cstdio>

long long gcd(long long a, long long b){
    return b!=0 ? gcd(b, a%b) : a;
}

int main(){
    int n;
    scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		long long answer = 1;
		for(int j=0;j<m;j++){
			int temp;
			scanf("%d", &temp);
			answer = answer*temp/gcd(answer, temp);
		}
		printf("%lld\n", answer);
	}
    return 0;
}
