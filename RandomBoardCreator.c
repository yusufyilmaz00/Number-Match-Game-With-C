#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
void drawBoard(int matris[][MAX], int N);
int createRandomBoard(int matris[][MAX],int N);
void drawPath(int matris[][MAX]);
int main(){
	
	
	int i,j,numberRow,numberColumn,N=5,matrix[MAX][MAX];
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	// suanda rastgele yerlestiriyor
	// fakat bazen cok yakin olabiliyor
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
	
	
	// ekrana bastir
	drawBoard(matrix,N);
	
	drawPath(matrix);
	drawBoard(matrix,N);
	
	return 0;
}

void drawBoard(int matris[][MAX], int N){
    int i,j,k;
    printf("\n      |");
    for(j=0;j<N;j++)
			printf("  c%d  |",j);
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<=N;k++)
            printf("------|");
        printf("\n");
        printf("  r%d  |",i);
        for(j=0;j<N;j++)
            if (matris[i][j]!=0)
                printf("  %d   |",matris[i][j]);
            else
                 printf("      |",matris[i][j]);
    }
    printf("\n");
}

void drawPath(int matris[][MAX]){
	int i,j,k,r1,c1,r2,c2;
	do{
	printf("\nYalnizca bir eksende hareket edebilirsiniz\n\n");
	printf("Source-Row:");
	scanf(" %d",&r1);
	printf("Source-Column:");
	scanf(" %d",&c1);
	printf("Destination-Row:");
	scanf(" %d",&r2);
	printf("Destination-Column:");
	scanf(" %d",&c2);
	}while(r1-r2 !=0 && c1-c2 !=0 || r1==r2 && c1==c2);
	
	printf("\nSource: (%d,%d) ---> Destination: (%d,%d)\n",r1,c1,r2,c2);
	
	if(r1-r2 !=0){
		// Yukarý-asagi yonde hareket
		k= 1;
		if(r1-r2>0)
			k= -1;
		//process
		i= r1+k;
		
		while(i != r2+k){
			
			if(matris[i][c1] == matris[r1][c1]){
				printf("Sayýlar eslesti!\n");
				return; // sayilar eslestiyse duracak 
			}
			else if(matris[i][c1]==0){
				matris[i][c1]= matris[r1][c1]; // bu adimda kaynaktaki sayiyi bu hucreye yerlestiriyoruz
			}
			else{
				printf("Wrong Path, auto-undo running...");
				//undo(koordinatlar);
				return;
			}
			i += k;
		}
	}
	
	else if(c1-c2 !=0){
		// sag-sol yonunde hareket
		k= 1;
		if(c1-c2>0)
			k= -1;
		//process
		j=c1+k;
		while(j != c2+k){
			if(matris[r1][j]== matris[r1][c1]){
				printf("Sayilar eslesti!\n");
				return; // bu adimda sayilar eslestigi icin fonksiyon duracak
			}
			else if(matris[r1][j]== 0){
				matris[r1][j] = matris[r1][c1]; // bu adimda kaynaktaki sayiyi bu hucreye yerlestiriyoruz
			}
			else{
				printf("Wrong Path, auto-undo running...");
				//undo(koordinatlar);
				return;
			}
			j += k;
		}
	}
}
