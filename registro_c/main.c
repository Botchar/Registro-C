#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>
#include "sqlite3.h"

//Estructuras
typedef struct Lugar Lugar;
typedef struct Club Club;
typedef struct Categoria Categoria;
typedef struct Torneo Torneo;
typedef struct Evento_torneo Evento_torneo;
typedef struct Jugador Jugador;
typedef struct Inscripcion Inscripcion;

struct Lugar{
    int id_lugar;
    char descripcion[500];
    char tipo[500];
    Lugar *siguiente;
};

struct Club{
    int id_club;
    char nombre[500];
    char colonia[500];
    int canchas_duras;
    int canchas_arcilla;
    int canchas_pasto;
    char vigencia[500];
    Lugar id_estado;
    Lugar id_alcaldia;
    char tipo[500];
    Club *siguiente;
};

struct Categoria{
    int id_categoria;
    char descripcion[500];
    Categoria *siguiente;
};

struct Torneo{
    int id_torneo;
    char nombre[500];
    char fecha_inicio[500];
    char fecha_fin[500];
    double costo;
    Torneo *siguiente;
};

struct Evento_torneo{
    int id_evento;
    Club id_club;
    Torneo id_torneo;
    Categoria id_categoria;
    Evento_torneo *siguiente;
};

struct Jugador{
    int id_jugador;
    char nombre[500];
    char apellido_paterno[500];
    char apellido_materno[500];
    char fecha_nacimiento[500];
    Club id_club;
    Lugar estado;
    Lugar alcaldia;
    char vigencia[500];
    Jugador *siguiente;
};

struct Inscripcion{
    int id_inscripcion;
    Torneo id_torneo;
    Jugador id_jugador;
    Categoria id_categoria;
    char ronda[500];
    int puntos;
    char pagado[500];
};

//Prototipos
//Principales
void clubes(void);
void torneos(void);
void jugadores(void);

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

    //Conexión de base de datos

    //Ajuste de acentos
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    //Memoria dinamica
    int  * respuestaPrincipal = (int *)malloc(sizeof(int));
    char * validadorCaracter = (char *)malloc(sizeof (char));
    //Verificacion de memoria
    if(respuestaPrincipal == NULL && validadorCaracter == NULL){
        printf("Problema de memoria en el apartado principal");
    }else{

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
    }

    return 0;
}
//Principales

void torneos(void){
    int  * respuestaTorneo = (int *)malloc(sizeof(int));
    char * validadorTorneo = (char *)malloc(sizeof (char));
    if(respuestaTorneo == NULL && validadorTorneo == NULL){
        system("cls");
        printf("Problema de memoria en el apartado de torneos");
    }else{

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

}
void jugadores(void){
    int  * respuestaJugador = (int *)malloc(sizeof(int));
    char * validadorJugador = (char *)malloc(sizeof (char));
    if(respuestaJugador == NULL && validadorJugador == NULL){
        system("cls");
        printf("Problema de memoria en el apartado de jugadores");
    }else{

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

}

//Compartidos
void localidades(){

}
