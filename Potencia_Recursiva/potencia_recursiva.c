#include <stdio.h>
#include <stdlib.h>


/*
  Alumno mena landa marco antonio
  Grupo: 3 c
  Profesora : Maria Guadalupe
*/

int potencia(int ,int);  /*prototipo de la funcion*/



int main()
{
    /*Variables*/
    int base ,exponente ,memo;


    printf("ingrsa base\n");
    scanf("%d",&base);
    printf("ingresa exponente\n");
    scanf("%d",&exponente);


     memo=potencia(base,exponente);  /*Se le asigna el resultado de la funcion potencia a la variable memo*/


    printf("Resultado :%d",memo);   /* Imprime el resultado*/
    return 0;
}

 /*Funcion potencia recursiva  que resive valores de base y exponente*/


int potencia(int base , int exponente){


   if(exponente==0){          /*caso base para mayore a cero*/

    return 1;

    }else{

     return base*potencia(base,exponente-1);  /*Aplicacion de la recursividad */

   }



}
