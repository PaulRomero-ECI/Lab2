//Escuela colombiana de ingenieria Julio Garavito
//lab2 ALSE-2
//Nombres: Sergio Fernando Quiroga, Paul Romero
//en este programa en C implementa el problema planteado en el ejercicio #2 de la guia propuesta por el profesor.

#include <stdio.h>                                                                               //inclusion librerias y definicion constantes
#include <string.h>
#define MAX 11
#define MIN 4
#define MAX_2 22

//definicion prototipo
int mostrar_menu();
void ingresar_palabras(char pal_1[MAX], char pal_2[MAX], char pal_3[MAX], int *ban_1);
void comparar_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ]);
void invierte_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ]);
void concatena_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ]);
void longitud_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ]);
void suma_decimal(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ]);
int largo_palabra(char palabra[MAX]);

//definicion main
void main (void)
{
	int opcion = 0;                                                    //opcion ingresada por el usuario
	char palabra_1[MAX] = {'\0'};                                      //palabras ingresadas por el usuario
	char palabra_2[MAX] = {'\0'};
	char palabra_3[MAX] = {'\0'};
	int bandera_1 = 0;                                                 //bandera que indica si se ingresaron datos o no
	
	printf("\n\n\t\t\t\t\t¡¡¡Hola!!!\nEste programa compara, invierte, concatena, halla la longitud y muestra la suma decimal de los caracteres\nsegun la opcion indicada, de tres palabras ingresadas por usted.\n\n");
	do{
		opcion = mostrar_menu();
		switch (opcion)
		{
			case 1 :
			    ingresar_palabras(palabra_1, palabra_2, palabra_3, &bandera_1);
				break;
			case 2 :
			    comparar_palabras(bandera_1, palabra_1, palabra_2, palabra_3);
				break;
			case 3 : 
			    invierte_palabras(bandera_1, palabra_1, palabra_2, palabra_3);
				break;
			case 4 : 
			    concatena_palabras(bandera_1, palabra_1, palabra_2, palabra_3);
				break;
			case 5 : 
			    longitud_palabras(bandera_1, palabra_1, palabra_2, palabra_3);
				break;
			case 6 : 
			    suma_decimal(bandera_1, palabra_1, palabra_2, palabra_3);
				break;
		}
	  }
	while(opcion != 7);
	

}

//definicion funciones

int mostrar_menu()
{
    int opc = 0;      
    
    printf ("\n\nEscoja la opcion que quiera realizar:\n");
	printf ("\t1. Ingresar palabras.\n");
	printf ("\t2. Comparar palabras.\n");
	printf ("\t3. Mostrar palabras al reves.\n");
	printf ("\t4. Concatenar las palabras.\n");
	printf ("\t5. Longitud de cada palabra.\n");
	printf ("\t6. Mostrar la suma decimal de los caracteres de cada palabra.\n");
	printf ("\t7. Salir del programa.\n");
    scanf("%d", &opc);
	if ( opc !=1 && opc !=2 && opc !=3 && opc !=4 && opc !=5 && opc !=6 && opc !=7)              //valida si se ingreso un numero diferente del 1 al 7
		printf("\n\t\t¡¡ERROR!!\nPor favor ingrese de nuevo un numero entre el 1 y el 7.\n");
    return opc;
}

void ingresar_palabras(char pal_1[MAX], char pal_2[MAX], char pal_3[MAX], int *ban_1)
{
	int longitud = 0;
	*ban_1 = 1;
	
	printf("\n\nIngrese las tres palabras, recuerde que deben tener un minimo de 3 caracteres y un maximo de 10 caracteres\n");
	do{
		printf("\n\tPrimer palabra:\n");
	    scanf("%s", pal_1);
	    longitud = largo_palabra(pal_1);
	    if (longitud<3||longitud>10)                              //valida el tamaño de las palabras ingresadas
		    printf("¡¡¡OJO!!! Recuerde el minimo y maximo de caracteres(min 3; max 10), ingrese de nuevo la palabra\n");
	  }
	while(longitud<3||longitud>10);
	do{
		printf("\n\tSegunda palabra:\n");
	    scanf("%s", pal_2);
	    longitud = largo_palabra(pal_2);
	    if (longitud<3||longitud>10)
		    printf("¡¡¡OJO!!! Recuerde el minimo y maximo de caracteres(min 3; max 10), ingrese de nuevo la palabra\n");
	  }
	while(longitud<3||longitud>10);
	do{
		printf("\n\tTercer palabra:\n");
	    scanf("%s", pal_3);
	    longitud = largo_palabra(pal_3);
	    if (longitud<3||longitud>10)
		    printf("¡¡¡OJO!!! Recuerde el minimo y maximo de caracteres(min 3; max 10), ingrese de nuevo la palabra\n");
	  }
	while(longitud<3||longitud>10);
}

void comparar_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ])
{
	if (ban_1 == 1)                                                              //strcmp devuelve 0 solo si las palabras son iguales, de lo contrario son diferentes
	{
	    if(strcmp(pal_1,pal_2)==0)
	    	printf("\n\nLas palabras 1 y 2 son iguales.");
	    else 
	    	printf("\n\nLas palabras 1 y 2 son diferentes.");
	    if(strcmp(pal_2,pal_3)==0)
	    	printf("\n\nLas palabras 2 y 3 son iguales.");
	    else 
	    	printf("\n\nLas palabras 2 y 3 son diferentes.");
	    if(strcmp(pal_1,pal_3)==0)
	    	printf("\n\nLas palabras 1 y 3 son iguales.");
	    else 
	    	printf("\n\nLas palabras 1 y 3 son diferentes\n.");
	}
	else
    printf("\n\nUsted no ha ingresado ningun dato, por favor vuelva al menu e ingrese las palabras\n\n");
}

void invierte_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ])
{
	int pos_fin ,aux_1 = 0, aux_2 = 0, aux_3 = 0;                              //aux: variables auxiliares
	aux_1=largo_palabra(pal_1);
	aux_2=largo_palabra(pal_2);
	aux_3=largo_palabra(pal_3);
	
    if (ban_1 == 1)
	{
	printf("\n\nLas palabras ingresadas pero mostradas al reves son: \n");
    printf("\n\t1. ");	
	for(pos_fin=aux_1;pos_fin>=0;pos_fin--)
	{
		printf("%c", pal_1[pos_fin]);
	}
	printf("\n\t2. ");	
	for(pos_fin=aux_2;pos_fin>=0;pos_fin--)
	{
		printf("%c", pal_2[pos_fin]);
	}
	printf("\n\t3. ");	
	for(pos_fin=aux_3;pos_fin>=0;pos_fin--)
	{
		printf("%c", pal_3[pos_fin]);
	}
	}
	else
    printf("\n\nUsted no ha ingresado ningun dato, por favor vuelva al menu e ingrese las palabras\n\n");
}

void concatena_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ])
{
	char cat1[MAX_2] = {'\0'};                                                 //muestra todas las opciones para concatenar las palabras ingresadas
	char cat2[MAX_2] = {'\0'};
	char cat3[MAX_2] = {'\0'};
	char cat4[MAX_2] = {'\0'};
	char cat5[MAX_2] = {'\0'};
	char cat6[MAX_2] = {'\0'};
	 if (ban_1 == 1)
	{
	stpcpy(cat1,pal_1);
	strcat(cat1, pal_2);
	printf("\n\nLa palabra 1 concatenada con la palabra 2 es: %s", cat1);
	stpcpy(cat2,pal_2);
	strcat(cat2, pal_1);
	printf("\n\nLa palabra 2 concatenada con la palabra 1 es: %s", cat2);
	stpcpy(cat3,pal_2);
	strcat(cat3, pal_3);
	printf("\n\nLa palabra 2 concatenada con la palabra 3 es: %s", cat3);
	stpcpy(cat4,pal_3);
	strcat(cat4, pal_2);
	printf("\n\nLa palabra 3 concatenada con la palabra 2 es: %s", cat4);
	stpcpy(cat5,pal_1);
	strcat(cat5, pal_3);
	printf("\n\nLa palabra 1 concatenada con la palabra 3 es: %s", cat5);
	stpcpy(cat6,pal_3);
	strcat(cat6, pal_1);
	printf("\n\nLa palabra 3 concatenada con la palabra 1 es: %s", cat6);
	}
	else
    printf("\n\nUsted no ha ingresado ningun dato, por favor vuelva al menu e ingrese las palabras\n\n");
}

void longitud_palabras(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ])
{
	int lon_1 = 0;                                           //variables locales que su valor es la longitud de cada palabra
	int lon_2 = 0; 
	int lon_3 = 0;
	if (ban_1 == 1)
	{
	lon_1 = largo_palabra(pal_1);
	lon_2 = largo_palabra(pal_2);
	lon_3 = largo_palabra(pal_3);
	printf("\n\nEl largo de la primer palabra es: %d", lon_1);
	printf("\nEl largo de la segunda palabra es: %d", lon_2);
	printf("\nEl largo de la primer palabra es: %d", lon_3);
	}
	else
    printf("\n\nUsted no ha ingresado ningun dato, por favor vuelva al menu e ingrese las palabras\n\n");
}

void suma_decimal(int ban_1, char pal_1 [ ], char pal_2 [ ], char pal_3 [ ] )
{
	int suma_1 = 0;
	int suma_2 = 0;
	int suma_3 = 0;
	int cont;
	
	if (ban_1 == 1)
	{
	for(cont = 0; cont<=largo_palabra(pal_1); cont++)
	{
		suma_1 = suma_1 + pal_1[cont];
	}
	for(cont = 0; cont<=largo_palabra(pal_2); cont++)
	{
		suma_2 = suma_2 + pal_2[cont];
	}
	for(cont = 0; cont<=largo_palabra(pal_3); cont++)
	{
		suma_3 = suma_3 + pal_3[cont];
	}
	printf("\n\nLa suma decimal de los caracteres de la palabra 1 es: %d", suma_1);
	printf("\n\nLa suma decimal de los caracteres de la palabra 2 es: %d", suma_2);
	printf("\n\nLa suma decimal de los caracteres de la palabra 3 es: %d", suma_3);
	}
	else
    printf("\n\nUsted no ha ingresado ningun dato, por favor vuelva al menu e ingrese las palabras\n\n");
}


int largo_palabra( char palabra[MAX])                                                     //rutina que halla la longitud de la palabra que se le indique en el llamado
{
    int longi = 0;  
    longi = strlen(palabra);
	return longi;
}