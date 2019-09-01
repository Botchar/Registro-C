#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

int main() {

    //Ajuste de acentos
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    int respuestaPrincipal = 0;
    //Ciclo del menú principal
    do{
        //Impresión del menú principal
        wprintf(L"\n\n#### -- Gestor de datos de la asociación -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Clubes\n\n");
        wprintf(L"[2]Torneo\n\n");
        wprintf(L"[3]Jugadores\n\n");
        wprintf(L"[4]Cerrar\n\n");

        //Obtenemos repsuesta principal
        scanf("%i",&respuestaPrincipal);
        //Comparación de respuesta
        switch (respuestaPrincipal) {
            //Opciones
            case 1:
                system("cls");
                printf("Clubes\n");
            break;
            case 2:
                system("cls");
                printf("Torneos\n");
            break;
            case 3:
                system("cls");
                printf("Jugadores\n");
            break;
            case 4:
                printf("Cerrando\n");
            break;
            default:
                wprintf(L"Opción invalida, cerrando programa\n");
            break;
        }


    }while(respuestaPrincipal == 1 || respuestaPrincipal == 2 || respuestaPrincipal == 3);

    return 0;
}
