#include<stdio.h>
#include<stdarg.h>
#include<string.h>
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
    int i = 0;
    while(format[i] != '\0'){
        if(format[i] == '%' && format[i+1] != '\0'){
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
                case 'x' : {
                    int x = va_arg(args , int);
                    sprintf(tmp , "%x" , x); // convertit l'entier x en une chaine de caractères hexadécimale
                    fwrite(tmp , sizeof(char) , strlen(tmp) , stdout);
                    break;
                }
                case 'o':{
                    int o = va_arg(args , int);
                    sprintf(tmp , "%o" , o); // convertit l'entier o en une chaine de caractères octale
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
            // après le switch, on continue à la prochaine itération de la boucle while, ce qui permet de traiter le caractère suivant dans la chaîne de format.
        } else {
            fwrite(&format[i] , sizeof(char) , 1, stdout);
        }
       i++;
    }
    va_end(args);

}





int main(){

    int a = 5;
    int b = 10;
    int c = 15;
    printAdr(3 , &a , &b , &c);
    initInts(3 , &a , 20 , &b , 30 , &c , 40);
    printf("a = %d , b = %d , c = %d\n" , a , b , c);
    myprintf("Hello %s , a = %d , b = %x , c = %o , f = %f\n" , "world" , a , b , c , 3.14);

}