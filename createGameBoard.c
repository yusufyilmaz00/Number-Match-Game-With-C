#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int i,j,numberRow,numberColumn,N=5,matrix[10][10];
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	
	
	
	for(i=1;i<=N;i++){
		for(j=0;j<2;j++){
			numberRow= rand() % N;
			numberColumn = rand() % N;
			while(matrix[numberRow][numberColumn] !=0){
				numberRow= rand() % N;
				numberColumn = rand() % N;
				
			}
		}
	}
	
	// ekrana bastýr
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d|",matrix[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
