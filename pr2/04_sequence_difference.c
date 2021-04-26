#include <stdio.h>
int main()
{
	int posl = 0,n = 0,razn = 0,i = 0;
	if (scanf("%d", &n) == 1){
		for (i = 0;i < n;i++){
				if (scanf("%d", &posl) == 1){
					razn = razn - posl;
		}
	}
	}
	printf("%d",razn);
	return 0;
}