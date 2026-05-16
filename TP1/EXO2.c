#include<stdio.h>
#include<stdlib.h>

void displayArray(int * tab , int n){
    for (int i = 0 ; i < n ; i++){
        printf("%d " , *(tab+i));
    }
    printf("\n");
}
int sum(int *tab , int n){
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum+= *(tab+i);
    }
    return sum;
}


int main(){
    int n; 
    printf("Entrez la taille du tableau que vous voulez crée : ");
    scanf("%d" , &n);

    int *tab = malloc(n*sizeof(int));
    for(int i = 0 ;i <n ; i++){
        *(tab + i ) = i+1; // tab[i] = i+1
    }
    displayArray(tab , n);
    printf("somme =  %d " , sum(tab , n));
    free(tab);
}