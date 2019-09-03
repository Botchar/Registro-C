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
void localidades();

//Clubes
void listacClubes();
void registroClub();

//Torneos
void calendario();
void registroTorneos();

//Jugadores
void rankings();
void registroJugador();

int main() {

    //Ajuste de acentos
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    int respuestaPrincipal = 0;
    char validadorCaracter[0];
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
        scanf("%s",&validadorCaracter);
        /* atoi convierte el numero ingresado como cadena en entero
                   en caso de ser posible, de lo contrario retorna 0*/
        respuestaPrincipal=atoi(validadorCaracter);
        if(respuestaPrincipal!=0){
            //Comparación de respuesta
            switch (respuestaPrincipal) {
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
                    respuestaPrincipal = 0;
                break;
            }
        }else{
            system("cls");
            wprintf(L"Opción invalida\n");
            respuestaPrincipal = 0;
        }


    }while(respuestaPrincipal != 4);

    return 0;
}
//Principales
void clubes(){
    int respuestaClub = 0;
    char validadorClub[0];
    do{
        system("cls");
        //Impresión del menú clubes
        wprintf(L"\n\n#### -- Clubes -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Lista de clubes\n\n");
        wprintf(L"[2]Registro de club\n\n");
        wprintf(L"[3]Gestor de localidades\n\n");
        wprintf(L"[4]Regresar\n\n");
        //Opciones
        scanf("%s",&validadorClub);
        respuestaClub=atoi(validadorClub);
        if(respuestaClub!=0){

        }else{
            wprintf(L"Opción invalida\n");
            respuestaClub = 0;
            system("cls");
        }
    }while(respuestaClub != 4);

}
void torneos(){
    int respuestaTorneo = 0;
    char validadorTorneo[0];
    do{
        system("cls");
        //Impresión del menú torneos
        wprintf(L"\n\n#### -- Torneos -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Calendario\n\n");
        wprintf(L"[2]Registro de torneos\n\n");
        wprintf(L"[3]Regresar\n\n");
        //Opciones
        scanf("%s",&validadorTorneo);
        respuestaTorneo=atoi(validadorTorneo);
        if(respuestaTorneo!=0){

        }else{
            wprintf(L"Opción invalida\n");
            respuestaTorneo = 0;
            system("cls");
        }
    }while(respuestaTorneo != 3);
}
void jugadores(){
    int respuestaJugador = 0;
    char validadorJugador[0];
    do{
        system("cls");
        //Impresión del menú jugadores
        wprintf(L"\n\n#### -- Jugadores -- ####\n\n");
        wprintf(L"Selecciona una opción\n\n");
        wprintf(L"[1]Rankings\n\n");
        wprintf(L"[2]Registro de jugadores\n\n");
        wprintf(L"[3]Gestor de localidades\n\n");
        wprintf(L"[4]Regresar\n\n");
        //Opciones
        scanf("%s",&validadorJugador);
        respuestaJugador=atoi(validadorJugador);
        if(respuestaJugador!=0){

        }else{
            wprintf(L"Opción invalida\n");
            respuestaJugador = 0;
            system("cls");
        }
    }while(respuestaJugador != 4);
}

//Compartidos
void localidades(){

}
