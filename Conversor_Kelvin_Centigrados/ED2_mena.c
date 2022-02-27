#include <stdio.h>
#include <stdlib.h>


void menu();
float centigrados_a_faren(float);
float Faren_a_centigrados(float);
float kelvin_a_centrigrados(float);
float kelvin_a_faren(float);
void imprimir(float);


int main()
{
    int bandera;
    do{
        menu();



        printf("\n");
        printf("\************************************************************************\a\a\a\n");
        printf("Salir del programa ingresa el numero 1 sino ingrese cualquier otro numero\t");
        scanf("%d",&bandera);
        printf("*************************************************************************\n");
        printf("\t\tGood bye\a\a");

     }while(bandera!=1);

    return 0;
}




void menu(){

    int selec ;
    float dato , res ,aux;



    printf("****************************************************************\n");
    printf("\t\tConversor de temperaturas\n");
    printf("****************************************************************\n");
    printf("      1.- De grados centigrados a grados farenheit\n");
    printf("      2.- De grados farenhei a grados centigrados\n");
    printf("      3.- De grados kelvin a grados centrigados\n");
    printf("      4.- De grados kelvin a grados farenheit\n");
    printf("----------------------------------------------------------------\n");
    printf("ingresa una opcion\n");
    scanf("%d",&selec);


    switch(selec){


       case 1:


               printf("Ingresa el valor de grados Centigrados\n");
               scanf("%f",&dato);

               aux=centigrados_a_faren(dato);
               system("cls");
               printf("1.- De grados centigrados a grados farenheit\n");
               imprimir(aux);

              break;

       case 2:

               printf("Ingresa el valor de grados Farenheit\n");
               scanf("%f",&dato);

               aux=Faren_a_centigrados(dato);
               system("cls");
               printf("2.- De grados farenhei a grados centigrados\n");
               imprimir(aux);

              break;

       case 3:

               printf("Ingresa el valor de kelvin\n");
               scanf("%f",&dato);

               aux=kelvin_a_centrigrados(dato);
               system("cls");
               printf("3.- De grados kelvin a grados centrigados\n");
               imprimir(aux);

              break;



       case 4:


               printf("Ingresa el valor kelvin\n");
               scanf("%f",&dato);

               aux=kelvin_a_faren(dato);
               system("cls");
               printf("4.- De grados kelvin a grados farenheit\n");
               imprimir(aux);


              break;




          default :

               printf("no existe la opcion \n");
    }






}




float centigrados_a_faren(float dato){

    float res;

     res=((dato*1.8)+32);


   return res;
}


float Faren_a_centigrados(float dato){

    float res;

   res=(dato-32)/1.8;

   return res;

}


float kelvin_a_centrigrados(float dato){

 float res;

  res=dato-273.15;


  return res;

}



float kelvin_a_faren(float dato){

 float res;

  res=((9*(dato-273.5))/5)+32;


  return res;

}


void imprimir(float aux){

      printf("--------------\n");
      printf("Resultado es: ");
      printf("%.2f\n",aux);
      printf("--------------\n");

}
