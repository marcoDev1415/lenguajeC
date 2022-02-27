#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct video{

  char  nombre[15];
  int   visitas;

};



void menu();
void busqueda_nombre(struct video *);
void imprimir(struct video *);
void busqueda_visitas(struct video *);
void Quicksort(int *, int, int);
int pivot(int *, int, int );
void binario(int *,struct video *);





int main()
{
    menu();
    return 0;
}



/***********************************************************************************************/
int pivot(int *unarray, int izq, int der)
{
    int i;
    int pivote, valor_pivote;
    int aux;

    pivote = izq;
    valor_pivote = unarray[pivote];
    for (i=izq+1; i<=der; i++){
        if (unarray[i] < valor_pivote){
                pivote++;
                aux=unarray[i];
                unarray[i]=unarray[pivote];
                unarray[pivote]=aux;

        }
    }
    aux=unarray[izq];
    unarray[izq]=unarray[pivote];
    unarray[pivote]=aux;
    return pivote;
}

void Quicksort(int *unarray, int izq, int der)
{
     int pivote;
     if(izq < der){
        pivote=pivot(unarray, izq, der);
        Quicksort(unarray, izq, pivote-1);
        Quicksort(unarray, pivote+1, der);
     }




}






/**********************************************************************************************/
void busqueda_nombre(struct video *videoptr){

   int encontrado, i ,result;
   char Encontrar[20] ,aux[20];
                                      /*video ptr*/
    printf("Escriba el nombre del video por favor:");
    scanf("%s",&Encontrar);
    printf("Usted ingreo %s\n",Encontrar);
    encontrado = 0;



    for (i=0;i<5;i++){


        strcpy(aux,(videoptr+i)->nombre);

        result =strncmp(aux,Encontrar,50);


        if (result == 0){
            encontrado =1;
        }
    }
    if(encontrado==1){

        printf("Video encontrado!\n");
        printf("%s\n",(videoptr+i)->nombre );
    }else{
        printf("Video no encontrado!\n");

            imprimir(videoptr);

    }




}

void imprimir(struct video * videoptr){

   int i;

    for(i=0;i<5;i++){

          printf("Video :%s\n",(videoptr+i)->nombre);
           printf("Video :%d\n",(videoptr+i)->visitas);

    }



}
/******************************************************************************************************/
void binario(int *miarray ,struct video *videoptr){

    int limsup,liminf,centro,bandera=0 ,buscar;
    limsup=5-1;
    liminf=0;


    printf(" ingresa numero buscar \n");
    scanf("%d",&buscar);

  

    while(liminf<=limsup){
        if(bandera==0){
            centro=(liminf+limsup)/2;
            if(buscar==miarray[centro]){
                printf("---------\nEl videos que busco con las visitas %d se encontro \n",miarray[centro]);
                printf("Es:%s\n",(videoptr+centro)->nombre );
                bandera=1;
            }
            else{
                if(miarray[centro]>buscar){
                    limsup=centro-1;
                }
                else{
                    liminf=centro+1;
                }


            }
        }
        else{

        	printf("NO se encontro\n");
            break;
        }
    }
}



/********************************************************************************************************/
void menu(){


   int seleccion , i, bandera=1 , miarray[5];
   struct video videoVar[5] , *videoptr;

   videoptr=videoVar;
do{
   

   system("cls");
   printf("\n");
   printf("\t**********************************************\n");
   printf("\tMenu\n");
   printf("\t1.- Registrar videos\n");
   printf("\t2.- Busqueda por nombre\n");
   printf("\t3.- Busqueda por numero de visitas \n");
   printf("\t4.- Imprimir\n");
   printf("\t Ingres opcion\n");
   printf("\t");scanf("%d",&seleccion);
   printf("\t*********************************************\n");

   switch(seleccion){



     case 1:

             for(i=0;i<5;i++){
                printf("\t**********************************\n");
                printf("\tIngresa nombre del video %d \n",i+1);
                printf("\t");scanf("%s",(videoptr+i)->nombre);
                printf("\tIngresa numero de visitas %d \n",i+1);
                printf("\t");scanf("%d",&(videoptr+i)->visitas);
                fflush(stdin);
                printf("\t**********************************\n");
                 system("cls");
             }


                for(i=0;i<5;i++){                  /*copia para metodo de ordenamiento*/
                  miarray[i]=(videoptr+i)->visitas;
               }



           break;



     case 2:

              busqueda_nombre(videoptr);


           break;




     case 3:

            Quicksort(miarray, 0, 5-1);
            printf("Datos de las reproducciones ordenados \n");
            for(i=0;i<5;i++){

                printf("[%d]",miarray[i]);
            }

            printf("\n");

            binario(miarray,videoptr);
           break;

     case 4:

            imprimir(videoptr);

          break;



   }

}while(bandera!=0);



}
