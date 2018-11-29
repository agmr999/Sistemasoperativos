/*
* PARVAR.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct particion particion;
struct particion{
	char parti;
	int nparti;
};

int main(int argc, char **argv)
{
	FILE *text;
	FILE *leer;
	int n=4096,men=0,par=0,p=0,p2=0,lon;	
	particion parti[n];
	char prue[512];
	char parti2[n];
	int acum,ss,err,i,may=0;
	char nombre[20];
	for(int e=0;e<n;e++){
		parti[e].parti='*';
		parti[e].nparti=0;
		parti2[e]='*';
	}
	while(men!=3){
		acum=0;ss=1;
		int frag=0;
		printf("MENU\n1)Ingresar archivo\n2)Ver memoria\n3)Salir\n4)Mostrar programa especifico\n5)Borrar programa especifico\n6)Mostrar fragmentacion\n7)Guardar programa\n");
		scanf("%d",&men);
		getchar();
		system ("clear");
		switch(men){
		case 1:
			i=0;
			char direccion[80];
			int rep=0;
			fflush(stdin);	
			int aa=0;
			printf("Ingresa el nombre del archivo que deseas abrir: ");
			scanf("%s",direccion);
			//char direccion[]="/home/abnermr/Documentos/Balance ejer";
			text=fopen(direccion,"r");
			if(text==NULL){
				printf("Error al abrir el archivo de texto\n");
			}
			else{
				char c;
				while((c=fgetc(text))!=EOF){
					prue[aa++]=c;
				}
				fclose(text);
			}
			/*for(int pru=0;pru<aa;pru++){
				printf("%c",prue[pru]);
			}
			printf("\n%d",aa);*/
			lon=0;
			par=0;
			may=0;
regreso:	while(parti[lon].parti!='*'){lon++;i++;
			if(parti[lon].nparti>may){may=parti[lon].nparti;}
			}
			while((parti[lon].parti=='*') && (aa>0)){
				if(i==0){
					parti[lon].nparti=1;	
				}
				else{
					if(rep==0){
						parti[lon].nparti=may+1;
						rep=may+1;
					}
				else{
					parti[lon].nparti=rep;
				}
				}
				parti[lon].parti=prue[par++];
				aa--;
				lon++;
			}
			if(aa>0){
				goto regreso;
				rep=rep;
			}
			break;
		case 2:
			for(int le=0;le<n;le++){
				printf("%c",parti[le].parti);
			}
			printf("\n");
			for(int le=0;le<n;le++){
				printf("%i",parti[le].nparti);
			}
			printf("\n");
			break;
		case 4:
			err=0;
			printf("¿Que programa quieres ver?\n");
			scanf("%d",&p);
			for(int lee=0;lee<n;lee++){
				if(parti[lee].nparti==p){
					int trans=parti[lee].parti;
					if(trans!=0){
						printf("%c",parti[lee].parti);
					}
					err++;
				}
			}
			//printf("\n%s",parti2);
			printf("\n\n\n");
			break;
		case 5:
			printf("¿Que programa quieres borrar?\n");
			scanf("%d",&p);
			for(int lee=0;lee<n;lee++){
				if(parti[lee].nparti==p){
					int trans=parti[lee].parti;
					if(trans!=0){
						parti[lee].parti='*';
						parti[lee].nparti=0;
					}
					err++;
				}
			}
			break;
		case 6:
			acum=0;
			while(acum!=n){
				if(parti[acum].parti=='*'){frag++;}
				acum++;	
			}
			printf("\nLa fragmentacion es: %d\n\n",frag);
			break;
		case 7:
			err=0;
			may=0;
			printf("Escribe el nombre del archivo a guardar\n");
			scanf("%s",nombre);
			leer=fopen(nombre,"w");
			printf("Programa que desea guardar: ");
			scanf("%i", &p2);
			for(int lee=0;lee<n;lee++){
				if(parti[lee].nparti>may){may=parti[lee].nparti;}
			}
			while(p2>may){printf("Errro debe ser un numero menor que: %i",may+1);printf("Programa que desea guardar: ");scanf("%i", &p2);}
			for(int lee=0;lee<n;lee++){
				//printf("%c",parti[lee].parti);
				if(parti[lee].nparti==p2){
					int trans=parti[lee].parti;
					if(trans!=0){
						fputc(parti[lee].parti,leer);
						//printf("%i\n",prue[err]);
					}
					err++;
				}
			}
			fclose(leer);
			break;
		default: printf("Gracias por usar el programa\n");
		}
		while(acum<n){
			while(parti2[acum]=='*'){
				acum++;	
			}	
			acum++;
			ss++;
		}	
	}
	return 0;
}


