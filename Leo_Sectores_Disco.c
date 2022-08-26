
/* 
-----------------------------
Aut viam inveniam aut faciam.
*****************************
     Leo_Sectores_Disco.c
*******************************
-----------------------------------
Hilario Iglesias Martínez.
*********************************
Este programa ha sido realizado en.
LINUX Ubuntu 20.04.4 LTS.
Bajo el standard ANSI C.-C-11
Consola de Linux.
***********************************
V-0 -Ag/2022.
--------------------------------------
El programa, abre un fichero por consola,
y va pidiendo sectores del disco :0,1,2,3,4...
hasta llegar al final de lectura de Buffer,
remarcado en otro color,volcando 
el contenido en las sucesivas peticiones.

Forma de compilarlo bajo prompt:

gcc -Wall Leo_Sectores_Disco.c -o LeoSectores

*********************************************
Una posibles salida por consola de parte
de un sector de disco sería la siguiente,
(después de haber ejecutado, en este caso
de ejemplo, un fichero de texto para
prueba llamado Alicia.txt):

./LeoSectores Alicia.txt

Introduzca el Sector que quiere abrir:0
41 6C 69 63 69 61 20 65  73 74 C3 A1 20 61 20 70   |  Alicia est.. a p 
75 6E 74 6F 20 64 65 20  71 75 65 64 61 72 73 65   |  unto de quedarse 
20 64 6F 72 6D 69 64 61  20 64 65 62 69 64 6F 20   |   dormida debido  
61 6C 20 61 62 75 72 72  69 6D 69 65 6E 74 6F 20   |  al aburrimiento  
71 75 65 20 73 69 65 6E  74 65 20 6D 69 65 6E 74   |  que siente mient 
72 61 73 20 65 73 74 C3  A1 20 63 6F 6E 20 73 75   |  ras est.. con su 
20 68 65 72 6D 61 6E 61  20 73 65 6E 74 61 64 61   |   hermana sentada 
20 61 20 6C 61 20 6F 72  69 6C 6C 61 20 64 65 6C   |   a la orilla del 

**********************************************************************
Funciones importantes que utilizamos en el programa:
------------------------------------------------------------------
"fseek()
---------------------------------------------------------------------
        La función fseek() establece el indicador de posición del archivo para el
        flujo apuntado. La nueva posición, medida en
        bytes, se obtiene añadiendo bytes de desplazamiento a la posición
        especificada.se establece con:
        SEEK_SET,
        SEEK_CUR,
        SEEK_END,
        El desplazamiento es relativo al inicio del archivo, el
        indicador de posición actual o fin de archivo, respectivamente.

        La llamada exitosa a la función fseek() borra al final del archivo
        el indicador de flujo, y deshace cualquier efecto.
        En resumen: La función fseek establece un indicador
        de posición de archivo para un flujo de archivo establecido.
---------------------------------------------------------------------
"fread()
-----------------------------------------------------------------------
La función fread() es el complementario de las funciones como fwrite()

fread().
Esta función se usa comúnmente para leer datos binarios.
Acepta los mismos argumentos que la fwrite() 

La llamada fread()está compuesta por una serie de parámetros.
Veamos, en rasgos generales, cada uno de ellos :

-Búfer: Puntero al búfer donde se almacenarán los datos.
Un búfer es una región de la memoria utilizada para 
almacenar datos temporalmente.
-Tamaño: El tamaño de cada elemento a leer en bytes.
-Count: Contador del número de elementos a leer.
-Stream: Puntero al objeto FILE desde donde se leerán los datos.
++++
---Valor devuelto:
Tras una ejecución exitosa, la función devuelve un
valor entero equivalente a count .
Devuelve el número de elementos completos leídos
realmente, que puede ser menor que count 
si se produce un error, o se encuentra
un final de archivo antes de llegar al
parámetro count declarado como constante
en el programa, dependiendo de la ejecución 
que queramos dar al mismo.

-------------------------------------------
Las librerías utilizadas son las siguientes:
include <stdio.h>
include <ctype.h>
include <stdlib.h>


*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int Mostrar_n, Mostrar_m;
#define DIMENSION 128
char Mi_Bufer [DIMENSION];
int Los_Sectores,Cantidad_Leidos;
int Parte_Sector;
char Codigo_ascii[17];
int i;
#define ROJO "\x1b[31m"

int main(int argc, char const *argv[])
{
	FILE *Descriptor_Fichero;
	if (argc!=2)
	{
		printf("Debes de poner el nombre del archivo: \n");
		return 1;
	}

if ((Descriptor_Fichero=fopen(argv[1],"rb"))==NULL)
{
	printf("No se ha podido abrir el archivo.\n");
	return 1;
}

do{
	printf("Introduzca el Sector que quiere abrir:" );

	scanf("%d",&Parte_Sector);
	if (Parte_Sector>=0)
	{
		if(fseek(Descriptor_Fichero,Parte_Sector*DIMENSION, SEEK_SET)){
		printf("Ha surgido un error en la búsqueda\n");
		
			
	}
if ((Cantidad_Leidos=fread(Mi_Bufer,1,DIMENSION,Descriptor_Fichero))!=DIMENSION){

	printf(ROJO "Se ha llegado al final del SECTOR alcanzado:\n");
   exit(EXIT_SUCCESS);
	}
for (i = 0; i < 128; ++i) {
        printf("%02X ", ((unsigned char*)&Mi_Bufer)[i]);
        if (((unsigned char*)&Mi_Bufer)[i] >= ' ' && ((unsigned char*)&Mi_Bufer)[i] <= '~')
         {
            Codigo_ascii[i % 16] = ((unsigned char*)&Mi_Bufer)[i];
        } else {
            Codigo_ascii[i % 16] = '.';
        }
        if ((i+1) % 8 == 0 || i+1==128) {
            printf(" ");
            if ((i+1) % 16 == 0) {
                printf(" |  %s \n", Codigo_ascii);
      
}}}
printf("-----------------------------------------------\n");          
}
}
while(Parte_Sector>=0);

}





	









	



