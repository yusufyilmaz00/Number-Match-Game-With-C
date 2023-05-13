#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
void drawBoard(int matris[][MAX], int N);
void createBoard(int matrix[][MAX],int N);
void drawPath(int matris[][MAX],int N);

int main(){
	int i,j,N=5,matrix[MAX][MAX];
	int moveHistory[10][4];
	
	createBoard(matrix,N);
	drawBoard(matrix,N);
	
	int totalMove;
	int a=2;
	while(a>0){
		drawPath(matrix,N);
		drawBoard(matrix,N);
		--a;
	}
	
	return 0;
}
void createBoard(int matrix[][MAX],int N){
	int i,j,numberRow,numberColumn;
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
			matrix[numberRow][numberColumn]=i;
		}
	}	
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
    printf("\n\n");
}

void drawPath(int matris[][MAX],int N){
	int i,j,k,r1,c1,r2,c2,is_true;
	// **fonk içine bir de eslesen sayýlarýn counterini koy.
	
	do{
	is_true=1;
	printf("Yalnizca bir eksende hareket edebilirsiniz\n\n");
	printf("Source-Row:");
	scanf(" %d",&r1);
	printf("Source-Column:");
	scanf(" %d",&c1);
	printf("Destination-Row:");
	scanf(" %d",&r2);
	printf("Destination-Column:");
	scanf(" %d",&c2);
	if(r1>=N || r2>=N || c1>=N ||c2>=N || r1<0 || r2<0 || c1<0 || c2<0){
		printf("\nKoordinatlar 0 ile (N-1) arasinda olmalidir !\n");
		is_true =0;
	}	
	}while( r1-r2 !=0 && c1-c2 !=0  || r1==r2 && c1==c2 || is_true ==0 );
	
	printf("\nSource: (%d,%d) ---> Destination: (%d,%d)\n",r1,c1,r2,c2);
	/*/hamle kaydedilecek
	matrix[index][0] = r1;
	matrix[index][1] = c1;
	matrix[index][2] = r2;
	matrix[index][3] = c2;
	*/
	
	if(r1-r2 !=0){
		// Yukarý-asagi yonde hareket
		k= 1;
		if(r1-r2>0)
			k= -1;
		//process
		i= r1+k;
		
		while(i != r2+k){
			
			if(matris[i][c1] == matris[r1][c1]){
				printf("Sayilar eslesti!\n");
				// eslesen_Sayilar_counter -= 1;
				return; // sayilar eslestiyse duracak 
			}
			else if(matris[i][c1]==0){
				matris[i][c1]= matris[r1][c1]; // bu adimda kaynaktaki sayiyi bu hucreye yerlestiriyoruz
			}
			else{
				printf("Wrong Path, auto-undo running...");
				//counter = undo(koordinatlar);
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
				// eslesen_Sayilar_counter -= 1;
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

