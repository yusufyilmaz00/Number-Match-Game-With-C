#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
void drawBoard(int matris[][MAX], int N);
int createRandomBoard(int matris[][MAX],int N);
void drawPath(int matris[][MAX]);
int main(){
	
	
	int i,j,numberRow,numberColumn,N=3,matrix[MAX][MAX];
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	// þuanda rastgele yerleþtiriyor
	// fakat bazen çok yakýn olabiliyor
	// bazen de yol olmayabiliyor.
	
	
	for(i=1;i<=N;i++){
		for(j=0;j<2;j++){
			numberRow= rand() % N;
			numberColumn = rand() % N;
			while(matrix[numberRow][numberColumn] !=0){
				numberRow= rand() % N;
				numberColumn = rand() % N;
			}
			matrix[numberRow][numberColumn]=i;
		}
	}
	
	
	// ekrana bastýr
	drawBoard(matrix,N);
	
	drawPath(matrix);
	return 0;
}

void drawBoard(int matris[][MAX], int N){
    int i,j,k;
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n");
        for(j=0;j<N;j++)
            if (matris[i][j]!=0)
                printf("  %d   |",matris[i][j]);
            else
                 printf("      |",matris[i][j]);
    }
    printf("\n\n");
}

void drawPath(int matris[][MAX]){
	int i,j,k,x1,y1,x2,y2;
	printf("X1:");
	scanf(" %d",&x1);
	printf("Y1:");
	scanf(" %d",&y1);
	printf("X2:");
	scanf(" %d",&x2);
	printf("Y2:");
	scanf(" %d",&y2);
		
	while(x1-x2 !=0 && y1-y2 !=0 || x1==x2 && y1==y2){
		printf("Yalnizca bir eksende hareket edebilirsiniz\n");
		printf("X1: ");
		scanf("%d\n",&x1);
		printf("Y1: ");
		scanf("%d\n",&y1);
		printf("X2: ");
		scanf("%d\n",&x2);
		printf("Y2: ");
		scanf("%d\n",&y2);
	}
	
	printf("\nSource: (%d,%d) ---> Destination: (%d,%d)\n",x1,y1,x2,y2);
	
	if(x1-x2 !=0){
		k= 1;
		if(x1-x2>0)
			k= -1;
		//process
	}
	elif(y1-y2 !=0){
		k= 1;
		if(y1-y2>0)
			k= -1;
		//process
	}
	/*
	for(i=x1;i=x2;i+k){
		for(j=y1;j=y2;j+k){
			printf("%d,%d",i,j);
			//matris[i][j] = matris[x1][y1];
			// baþlangýç noktasýndaki sayý ile yolu dolduracaðýz  
		}
	}
	*/
}
