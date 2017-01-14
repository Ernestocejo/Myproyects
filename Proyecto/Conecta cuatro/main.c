/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ernesto
 *
 * Created on 13 de noviembre de 2016, 1:59
 */

#include <stdio.h>
#include <stdlib.h>
#include"librerias.h"
#define F 6 //Filas
#define C 5 //Columnas

struct jugadores {
    char nombre[30];
};

/**
 * Prototipo tbleroVcio
 * @param cc
 */
void tbleroVcio(char cc[F][C]);
void tabnumcol(char cc[F][C]);

/*
 * 
 */
int main(int argc, char** argv) {
    char cc[F][C]; // arreglo del tablero
    int i, j, a, x, y; // i,j,x,y == posicion de las fichas o tablero, y a imprime numeros del tablero
    int d = 1, e = 1; //para finalizar el while
    struct jugadores j1; // Para guardar el nombre de los jugadores
    struct jugadores j2; // Para guardar el nombre de los jugadores

    puts("El famoso juego de Conecta cuatro");
    puts("ingresa el nombre del jugador numero 1");
    leestring(j1.nombre, 30);
    puts("ingresa el nombre del jugador numero 2");
    leestring(j2.nombre, 30);

    // se llena el tablero con caracteres bacios
//    for (i = 0; i < F; i++) {
//        for (j = 0; j < C; j++) {
//            cc[i][j] = '\0';
//        }
//    }
    //funcion tablero
    tbleroVcio(cc);
    tabnumcol(cc);
/*
    //iprime tblero y con caracteres bacios y o llenos
    for (i = 0; i < F; i++) {
        for (j = 0; j < C; j++) {
            printf("[ %c ]", cc[i][j]);
        }
        puts("");
    }
    // se imprime el numero de columnas
    a = 0;
    for (i = 0; i < C; i++) {
        printf("  %d ", a);
        a++;
    }
*/
    while (d == 1) {
        // Turno del jugador uno
        printf("\n%s es:'X'\n", j1);
        scanf("%d", &x);
        if ((x > (C - 1))) {
            while (x > (C - 1)) {
                puts("Columna imvalida / Vuleve a intentar");
                scanf("%d", &x);
            }
        }

        //condicion para poner ficha en el tablero
        for (y = (F - 1); y >= 0; y--) {
            if (cc[y][x] == '\0' && cc[y][x] != 'X' && cc[y][x] != 'O') {
                cc[y][x] = 'X';
                y = -1;
            }
        }
        //imprime tablero actualizado
         tabnumcol(cc);
/*
        for (i = 0; i < F; i++) {
            for (j = 0; j < C; j++) {
                printf("[ %c ]", cc[i][j]);
            }
            puts("");
        }

        a = 0;
        for (i = 0; i < C; i++) {
            printf("  %d ", a);
            a++;
        }
        puts("");
*/
        //condicion gana 
        for (y = (F - 1); y >= 0; y--) {
            for (x = 0; x <= C; x++) {
                if (cc[y][x] == 'X') {
                    if (cc[y][x + 1] == 'X' && cc[y][x + 2] == 'X' && cc[y][x + 3] == 'X') { // derecha
                        printf("\n%s GANA\n", j1);
                        d = 0;
                        e = 0;
                        x = C + 1;
                        y = -1;
                    } else if (cc[y][x - 1] == 'X' && cc[y][x - 2] == 'X' && cc[y][x - 3] == 'X') { // izquierdaa
                        printf("\n%s GANA\n", j1);
                        d = 0;
                        e = 0;
                        x = C + 1;
                        y = -1;
                    } else if (cc[y - 1][x] == 'X' && cc[y - 2][x] == 'X' && cc[y - 3][x] == 'X') {// arriba
                        printf("\n%s GANA\n", j1);
                        d = 0;
                        e = 0;
                        x = C + 1;
                        y = -1;
                    } else if (cc[y - 1][x + 1] == 'X' && cc[y - 2][x + 2] == 'X' && cc[y - 3][x + 3] == 'X') {//arriba a la derecha
                        printf("\n%s GANA\n", j1);
                        d = 0;
                        e = 0;
                        x = C + 1;
                        y = -1;
                    } else if (cc[y - 1][x - 1] == 'X' && cc[y - 2][x - 2] == 'X' && cc[y - 3][x - 3] == 'X') {// arriba a la izquierda
                        printf("\n%s GANA\n", j1);
                        d = 0;
                        e = 0;
                        x = C + 1;
                        y = -1;
                    }
                }
            }
        }
        //--------------------------------------------------------------------   
        if (e == 1) {
            // jugador 2
            printf("\n%s es:'O'\n", j2);
            scanf("%d", &x);
            if ((x > (C - 1))) {
                while (x > (C - 1)) {
                    puts("Columna imvalida / Vuleve a intentar");
                    scanf("%d", &x);
                }
            }
            //condicion para poner ficha en el tablero
            for (y = (F - 1); y >= 0; y--) {
                if (cc[y][x] == '\0' && cc[y][x] != 'X' && cc[y][x] != 'O') {
                    cc[y][x] = 'O';
                    y = -1;
                }
            }
            //imprime tablero actualizado
            for (i = 0; i < F; i++) {
                for (j = 0; j < C; j++) {
                    printf("[ %c ]", cc[i][j]);
                }
                puts("");
            }

            a = 0;
            for (i = 0; i < C; i++) {
                printf("  %d ", a);
                a++;
            }
            puts("");
            //condicion gana 
            for (y = (F - 1); y >= 0; y--) {
                for (x = 0; x <= C; x++) {
                    if (cc[y][x] == 'O') {
                        if (cc[y][x + 1] == 'O' && cc[y][x + 2] == 'O' && cc[y][x + 3] == 'O') { // derecha
                            printf("\n%s GANA\n", j2);
                            d = 0;
                            e = 0;
                            x = C + 1;
                            y = -1;
                        } else if (cc[y][x - 1] == 'O' && cc[y][x - 2] == 'O' && cc[y][x - 3] == 'O') { // izquierdaa
                            printf("\n%s GANA\n", j2);
                            d = 0;
                            e = 0;
                            x = C + 1;
                            y = -1;
                        } else if (cc[y - 1][x] == 'O' && cc[y - 2][x] == 'O' && cc[y - 3][x] == 'O') {// arriba
                            printf("\n%s GANA\n", j2);
                            d = 0;
                            e = 0;
                            x = C + 1;
                            y = -1;
                        } else if (cc[y - 1][x + 1] == 'O' && cc[y - 2][x + 2] == 'O' && cc[y - 3][x + 3] == 'O') {//arriba a la derecha
                            printf("\n%s GANA\n", j2);
                            d = 0;
                            e = 0;
                            x = C + 1;
                            y = -1;
                        } else if (cc[y - 1][x - 1] == 'O' && cc[y - 2][x - 2] == 'O' && cc[y - 3][x - 3] == 'O') {// arriba a la izquierda
                            printf("\n%s GANA\n", j2);
                            d = 0;
                            e = 0;
                            x = C + 1;
                            y = -1;
                        }
                    }
                }
            }
            /*
                //condicion tablero lleno
                for(y = 0; y < F ;y++){
                    for(x = 0; x < C;x++){
                     if(cc[y][x] != '\0' ||cc[y][x] != 'X' || cc[y][x] != 'O'){
             
                     }else puts("EMPATE");
                    }
                    }
             */
        }
    }


    puts("\nGracias popr jugar con nosotros");
    puts("");
    puts("Estes es un programa echo por Ernesto y Sergio");

    return (EXIT_SUCCESS);

}

/**
 * Funcion tbleroVcio
 * se llena el tablero con caracteres vacios
 * @param cc
 */
void tbleroVcio(char cc[F][C]){
    int i, j;
    for (i = 0; i < F; i++) {
        for (j = 0; j < C; j++) {
            cc[i][j] = '\0';
        }
    }
}
void tabnumcol(char cc[F][C]){
int i, j, a;
 //iprime tblero y con caracteres bacios y o llenos
    for (i = 0; i < F; i++) {
        for (j = 0; j < C; j++) {
            printf("[ %c ]", cc[i][j]);
        }
        puts("");
    }
    // se imprime el numero de columnas
    a = 0;
    for (i = 0; i < C; i++) {
        printf("  %d ", a);
        a++;
    }
    puts("");
}