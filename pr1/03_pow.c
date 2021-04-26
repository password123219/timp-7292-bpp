#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c;
	if (scanf("%lf",&a) == 1){
		if (scanf("%lf",&b) == 1){
			c = pow(a,b);
			printf("%lf",c);
			}
			else{printf("OShibka");
			}
	}
	else{
		printf("OShibka");
	}
	return 0;
}