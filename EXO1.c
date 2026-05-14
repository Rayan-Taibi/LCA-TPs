#include<stdio.h>
#include<stdarg.h>

void printAdr(int nbr , ...){

    va_list args;
    va_start(args, nbr);
    for(int i = 0 ; i < nbr ; i++){
        void *adr = va_arg(args, void*);
        printf("%p\n" , adr);

    }
    va_end(args);
}

void initInts(int nb_couple , ...){
      va_list args;
      va_start(args, nb_couple);
      
      for(int i = 0 ; i < nb_couple ; i++){
        int *A = va_arg(args, int*); // 
        int B = va_arg(args , int); 
        if(A != NULL){
            *A = B;
        }
      }
      va_end(args);
}

void myprintf(const char *format , ...){
    va_list args;
    va_start(args , format);
    char buffer;
    int i = 0;
    while(format[i] != '\0'){
        if(format[i] == '%' && format[i+1] == '\0'){
            i++;
            char tmp[128];
            switch(format[i]){
                case 'c': {
                    char c = (char)va_arg(args,int); //char est promu en int dans les FV
                    fwrite(&c , sizeof(char) , 1 , stdout); //stdout est un flux de sortie standard en C, et fwrite est une fonction qui écrit des données dans ce flux. Ici, on écrit le caractère c dans le flux de sortie.
                    break;
                }
                case 's' : {
                    char *s = va_arg(args , char*); // ici on suppose que s est une chaîne de caractères valide et du coup on fait pas int parceque int 
                    fwrite(s , sizeof(char) , strlen(s) , stdout); // fwrite est une méthode de la bibliothèque standard C qui permet d'écrire des données dans un flux de sortie 
                    break;
                }
                case 'd':{
                    int d = va_arg(args , int);
                    sprintf(tmp , "%d" , d); // convertit l'entier d en une chaine de caractères 
                    fwrite(tmp , sizeof(char) , strlen(tmp) , stdout);
                    break;
                }
                case 'f' : {
                    double f = va_arg(args , double);
                    sprintf(tmp,"%f", f );
                    fwrite(tmp ,  sizeof(char) , strlen(tmp) , stdout);
                    break;
                }
                default:
                  fwrite(&format[i-1] , sizeof(char) , 1, stdout); // affiche le %
                  fwrite(&format[i] , sizeof(char) , 1, stdout);// affiche le caractère suivant
                  break;
            }
        }
    }

}





int main(){

}