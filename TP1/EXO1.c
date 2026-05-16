#include<stdio.h>

typedef struct {
    char *nom;
    int age;
} Personne;


void reverseArrayGeneric(void *array , size_t n , size_t size){
   char tmp[size];// la taille d'un élément
   char *debut = (char*)array;
   char *fin = (char * )array + (n-1)*size; // on pointe sur le dernier element du tableau , cette ligne équivaut a array[n-1]
   while(debut < fin){
     
    for (int i = 0 ; i < size ; i++){
        tmp[i] = debut[i];
        debut[i] = fin[i];
        fin[i] = tmp[i];
    }
    debut += size;
    fin -= size;
      
   }
}

int main(){

    int arr[] = {1,2,3,4,5};
    double arr2[] = {1.1,2.2,3.3,4.4,5.5};
    Personne arr3[] = {{"Alice",30},{"Bob",25},{"Charlie",35}};
    reverseArrayGeneric(arr , 5 , sizeof(int));
    reverseArrayGeneric(arr2 , 5 , sizeof(double));
    reverseArrayGeneric(arr3 , 3 , sizeof(Personne));
    for (int i = 0 ; i < 5 ; i++){
        printf("%d ",arr[i]);  
    }
    printf("\n");
    for (int i = 0 ; i < 5 ; i++){
        printf("%.1f ",arr2[i]);
    }
    printf("\n");
    for (int i = 0 ; i < 3 ; i++){
        printf("%s %d\n",arr3[i].nom , arr3[i].age);
        
    }

}