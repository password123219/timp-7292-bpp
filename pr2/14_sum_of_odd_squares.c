#include <stdio.h>
int main()
{
	int posl = 0,n = 0,razn = 0,i = 0,itog = 0;
	if (scanf("%d", &n) == 1){
		for (i = 1;i <= n;i++){
				if (scanf("%d", &posl) == 1){
					razn = i % 2;
					itog += razn * posl*posl;
		}
	}
	}
	printf("%d",itog);
	return 0;
}