#include <stdio.h>
#include <unistd.h>

int main(){
	int x = 10;
	int i=0,j=0;
	for(i=1;i<=9;i++){
		for(j=1;j<=i;j++){
			sleep(1);
			printf ("%d*%d=%d\t",j,i,i*j);
			fflush(stdout);
		}
		printf("\n");
	}
	return 0;
}
