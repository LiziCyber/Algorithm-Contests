#include<cstdio>
#include<cmath>

double sum,d,wsm,wsh,wmh;

int main(){
	wsm=59/10.0,wsh=719/120.0,wmh=11/120.0;
	double l,r,l2,r2,l3,r3;
	int i,j,k;
	while(scanf("%lf",&d),d>-0.5){
		for(sum=0,i=1;;i++){
			l=(360*i-360+d)/wsm;
			r=(360*i-d)/wsm;
			if(l>12*60*60)break;

			j=(int)((l*wsh+d)/360);
			if((360*j-d)/wsh<=l)j++;
			for(;;j++){
				l2=(360*j-360+d)/wsh;
				r2=(360*j-d)/wsh;
				if(l2<l)l2=l;
				if(r2>r)r2=r;
				if(l2>=r2)break;
				k=(int)((l2*wmh+d)/360);
				if((360*k-d)/wmh<=l2)k++;
				for(;;k++){
					l3=(360*k-360+d)/wmh;
					r3=(360*k-d)/wmh;
					if(l3<l2)l3=l2;
					if(r3>r2)r3=r2;
					if(l3>=r3)break;
					sum+=r3-l3;
				}
		    }
        }
      printf("%.3lf\n",sum/(12*60*60)*100);
    }
  return 0;
}
