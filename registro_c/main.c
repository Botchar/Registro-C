#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

//Prototipos
//Principales
void clubes();
void torneos();
void jugadores();

//Compartidos
void localidades(void);

//Clubes
void listacClubes(void);
void registroClub(void);

//Torneos
void calendario(void);
void registroTorneos(void);

//Jugadores
void rankings(void);
void registroJugador(void);

int main() {

    //Ajuste de acentos
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    //Memoria dinamica
    int  * respuestaPrincipal = (int *)malloc(sizeof(int));
    char * validadorCaracter = (char *)malloc(sizeof (char));
    //Verificacion de memoria



    //Ciclo del menú principal
    do{
        //Impresión del menú principal
        wprintf(L"\n\n#### -- Gestor de datos de la asociación -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Clubes\n\n");
        wprintf(L"[2]Torneo\n\n");
        wprintf(L"[3]Jugadores\n\n");
        wprintf(L"[4]Cerrar\n\n");

        //Obtenemos repsuesta principalsystem("cls");
        scanf("%s",validadorCaracter);

        //free(validadorCaracter);
        /* atoi convierte el numero ingresado como cadena en entero
                   en caso de ser posible, de lo contrario retorna 0*/

        *respuestaPrincipal=atoi(validadorCaracter);

        if(*respuestaPrincipal!=0){
            //Comparación de respuesta
            switch (*respuestaPrincipal) {
                //Opciones
                case 1:
                    system("cls");
                    clubes();
                break;
                case 2:
                    system("cls");
                    torneos();
                break;
                case 3:
                    system("cls");
                    jugadores();
                break;
                case 4:
                    system("cls");
                    printf("Cerrando\n");
                break;
                default:
                    system("cls");
                    wprintf(L"Opción invalida\n");
                    *respuestaPrincipal = 0;
                break;
            }
        }else{
            system("cls");
            wprintf(L"Opción invalida\n");
            *respuestaPrincipal = 0;
        }


    }while(*respuestaPrincipal != 4);
    //Liberamos memoria
    free(respuestaPrincipal);
    free(validadorCaracter);

    return 0;
}
//Principales
void clubes(){
    int  * respuestaClub = (int *)malloc(sizeof(int));
    char * validadorClub = (char *)malloc(sizeof (char));
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
void torneos(){
    int  * respuestaTorneo = (int *)malloc(sizeof(int));
    char * validadorTorneo = (char *)malloc(sizeof (char));
    do{
        //Impresión del menú torneos
        wprintf(L"\n\n#### -- Torneos -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Calendario\n\n");
        wprintf(L"[2]Registro de torneos\n\n");
        wprintf(L"[3]Regresar\n\n");
        //Opciones
        scanf("%s",validadorTorneo);
        *respuestaTorneo=atoi(validadorTorneo);
        if(*respuestaTorneo!=0){

        }else{
            *respuestaTorneo = 0;
            system("cls");
            wprintf(L"Opción invalida\n");
        }
    }while(*respuestaTorneo != 3);
    free(respuestaTorneo);
    free(validadorTorneo);
    system("cls");
}
void jugadores(){
    int  * respuestaJugador = (int *)malloc(sizeof(int));
    char * validadorJugador = (char *)malloc(sizeof (char));
    do{
        //Impresión del menú jugadores
        wprintf(L"\n\n#### -- Jugadores -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Rankings\n\n");
        wprintf(L"[2]Registro de jugadores\n\n");
        wprintf(L"[3]Gestor de localidades\n\n");
        wprintf(L"[4]Regresar\n\n");
        //Opciones
        scanf("%s",validadorJugador);
        *respuestaJugador=atoi(validadorJugador);
        if(*respuestaJugador!=0){

        }else{
            *respuestaJugador = 0;
            system("cls");
            wprintf(L"Opción invalida\n");
        }
    }while(*respuestaJugador != 4);
    free(respuestaJugador);
    free(validadorJugador);
    system("cls");
}

//Compartidos
void localidades(){

}
