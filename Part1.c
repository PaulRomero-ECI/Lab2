//Escuela colombiana de ingenieria Julio Garavito
//lab2 ALSE-2
//Nombres: Sergio Fernando Quiroga, Paul Romero
//en este programa en C implementa el problema planteado en el ejercicio #1 de la guia propuesta por el profesor.

#include <stdio.h>



typedef struct{                                      //definicion estructura
	int x;
	int y;
}punto;

//definicion prototipo
int mostrar_menu();
void pedir_puntos (punto *p1, punto *p2);
float mostras_pendiente(punto p1,punto p2);
float mostrar_crucey(punto p1, float m);
void mostrar_ecuacion(punto p1, float m, float cy);


void main(void)
{
	float m = 0, cy = 0; 
	char opcion = 0, ban1 = 0, ban2 = 0;
	punto p1={0,0};
	punto p2={0,0};
	
	do{
		opcion = mostrar_menu();
		
		switch(opcion)
		{
			case 1 :
			    {
			    pedir_puntos (&p1, &p2);
				printf("%d",p1.x);
				ban2 = 1;
				}
			break;
			case 2 :
			    {
				if(ban2==1)
				m = mostras_pendiente(p1, p2);
				else 
					printf("\n\nPor favor ingrese valores para los puntos\n\n");
				}
			break;
			case 3 :
			    {
				if(ban2==1)
				cy = mostrar_crucey(p1, m);
				else
					printf("\n\nPor favor ingrese valores para los puntos\n\n");
				}
			break;
			case 4 :
			    {
				if(ban2==1)
				mostrar_ecuacion(p1, m, cy);
				else
					printf("\n\nPor favor ingrese valores para los puntos\n\n");
				}
			break;
		}
	}while(opcion != 5);
	printf("\n\nMuchas Gracias\n\n");
	
	
}


//definicion funciones
int mostrar_menu()
{
	int opc = 0;
	
	printf("\n\nEste programa encuentra la ecuacion de una recto a partir de dos puntos dados por el usuario.\n\nPor favor ingrese el numero de la opcion que desea.\n\n");
	printf("1. Ingresar puntos.\n\n2. Mostrar pendiente.\n\n3. Mostrar cruce con el eje Y.\n\n4. Mostrar ecuación completa.\n\n5. Salir\n\n");
	scanf("%d", &opc);
	if ( opc !=1 && opc !=2 && opc !=3 && opc !=4 && opc !=5 )              //valida si se ingreso un numero diferente del 1 al 5
		printf("\n\t\t¡¡ERROR!!\nPor favor ingrese de nuevo un numero entre el 1 y el 5.\n");
	return opc;
}

void pedir_puntos (punto *p1, punto *p2)
{
	printf("\n\nPor favor ingrese las coordenadas del primer punto \n\n x=");
	scanf("%d", &p1->x);
	printf("\n\n y=");
	scanf("%d", &p1->y);
	printf("\n\nEl Primero Punto es (%d, %d) \n\n", p1->x,p1->y);
	printf("\n\nPor favor ingrese las coordenadas del segundo punto \n\n x=");
	scanf("%d", &p2->x);
	printf("\n\n y=");
	scanf("%d", &p2->y);
	printf("\n\nEl segundo punto es (%d, %d) \n\n", p2->x,p2->y);
}

float mostras_pendiente(punto p1,punto p2)
{
	float num, den, m;
	num = p2.y-p1.y;
	den = p2.x-p1.x;
	m = num/den;
	printf("\n\nLa pendiente de la recta entre los dos punto es m = %.3f\n\n",m);
	return m;	
}

float mostrar_crucey(punto p1, float m)
{
	float cy;
	cy=-1*((m*p1.x)-p1.y);
	printf("\n\nEl cruce con el eje y de la recta entre los dos punto es y = %.3f\n\n", cy);
	return cy;
}

void mostrar_ecuacion(punto p1, float m, float cy)
{
	printf("\n\nLa ecuacion de la recta entre los dos punto es y = %.3fx %.3f\n\n", m, cy);
}