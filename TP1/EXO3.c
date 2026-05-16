#include<stdio.h>
#include<stdlib.h>


    // -------Q3--------
   void displayArray(int **tab , int A ,int B){
    for(int i = 0 ; i < A ; i++){
        for(int j = 0 ; j < B ;j++){
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
   }
   void displayArrayWithNoBracket(int ** tab , int A , int B){
    for(int i = 0 ; i < A ; i++){
        for(int j = 0 ; j < B ;j++){
            printf("%d\t", *(*(tab + i) + j));
        }
        printf("\n");
    }
   }

int main(){

   // --- Q1----
    int A , B ;
    printf(" lignes :  "); scanf("%d" , &A);
    printf(" colonnes :  "); scanf("%d" , &B);
    int **tab  = malloc(A * sizeof(int *));
    for(int i = 0 ; i < A ; i ++){
        tab[i] = malloc(B*sizeof(int));
    }

    // ----Q2--------
    for(int i = 0 ; i < A ; i++){
        for(int j = 0 ; j < B ;j++){
            tab[i][j] = (i + 1)*(j + 1);
        }
    }
    
    displayArray(tab , A , B);
    printf("\n");
    displayArrayWithNoBracket(tab , A , B);
    for(int i = 0 ; i < A ; i++){
        free(tab[i]);
    }
    free(tab);

}