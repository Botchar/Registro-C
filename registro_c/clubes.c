#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>
#include "sqlite3.h"

void clubes(void){
    //Opciones para lo terminar con memoria
    int  * respuestaClub = (int *)malloc(sizeof(int));
    char * validadorClub = (char *)malloc(sizeof (char));

    if(respuestaClub == NULL && validadorClub == NULL){
        system("cls");
        printf("Problema de memoria en el apartado clubes");

    }else{
        //Instancia de sqlite
        sqlite3 *db = NULL;
        do{
            //Impresión del menú clubes
            wprintf(L"\n\n#### -- Clubes -- ####\n\n");
            wprintf(L"Selecciona una opción\n\n");
            wprintf(L"[1]Lista de clubes\n\n");
            wprintf(L"[2]Registro de club\n\n");
            wprintf(L"[3]Gestor de localidades\n\n");
            wprintf(L"[4]Regresar\n\n");
            //Opciones
            scanf("%s",validadorClub);
            *respuestaClub=atoi(validadorClub);


            if(*respuestaClub!=0){

            }else{
                *respuestaClub = 0;
                system("cls");
                wprintf(L"Opción invalida\n");
            }

        }while(*respuestaClub != 4);
        free(respuestaClub);
        free(validadorClub);
        system("cls");
    }

}
