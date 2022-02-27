#include <stdio.h>
#include <stdlib.h>



void capturar();
void burbuja(float vector[] );
void media(float vector[]);
void mediana(float vector[]);
void moda(float vector[]);
void resultados(float);



int main()
{
     capturar();
    return 0;
}





void capturar(){

  int i ,j ,aux ,selec ,bandera=1;
  float  vector3[10];



do{
   printf("Bienvendio al programa de media , moda y mediana \n");


  for(i=0;i<10;i++){
   printf("Ingresa dato %d \n",i+1);
   scanf("%f",&vector3[i]);

  }

   printf("Datos ordenados \n");
   burbuja(vector3);
   printf("\n");
/****************************************** Funciones ********************************/



  printf("**************************************************************\n");
  printf("Ingresa una opcion \n");
   printf("1.- MEDIA \n");
  printf("2.- MEDIANA \n");
  printf("3.- MODA \n");
  scanf("%d",&selec);

  switch(selec){



   case 1:
        system("cls");
        media(vector3);

   case 2:
         system("cls");
         mediana(vector3);
         break;

  case 3:

       system("cls");
       moda(vector3);
       break;

  }
}while(bandera!=0);



}


void burbuja(float vector3[]){


  int j,i;
  float aux;


    for (i=1; i<10; i++)
    {
        for (j=0; j<10-i; j ++)
        {
            if (vector3[j]>vector3[j+1])
            {
                aux=vector3[j];
                vector3[j]=vector3[j+1];
                vector3[j+1]=aux;
            }

        }

    }


   for(i=0;i<10;i++){

     printf("[%.2f]",vector3[i]);


   }


   printf("\n");

}

void media(float vector3[]){

   float acum;
   int i;


   for(i=0;i<10;i++){


    acum=acum+vector3[i];

   }


   acum=acum/10;

   resultados(acum);
}


void mediana(float vector3[]){

   int i;
   float acum , acum1;



    acum1=vector3[4]+vector3[5];

    acum=acum1/2;


  resultados(acum);



}


void moda(float vector3[]){


   register int t, w;
	float md, AnteriorModa;
	int cont, antcont,acum;

	AnteriorModa=0;
	antcont=0;
	for (t=0; t< 10; ++t) {
		md = vector3[t];
		cont = 1;
		for(w=t+1; w < 10; ++w)
			if(md == vector3[w])
				cont++;
		if(cont > antcont) {
			AnteriorModa = md;
			antcont = cont;
		}
	}


    acum=AnteriorModa;




   resultados(acum);

}


void resultados(float acum){

   printf("resultado :%.2f",acum);
   printf("\n");

}
