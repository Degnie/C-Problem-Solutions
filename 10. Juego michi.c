/* Lea una matriz 3x3 que representa un tablero de tres en raya (gato)
e indique qué jugada debería hacerse para ganar (si es posible) o 
al menos evitar una derrota. */

#include <stdio.h>

#define VACIO '.'    // *Se definen como constantes
#define JUGADOR 'X'
#define RIVAL 'O'

int main() {
    char tablero[3][3]={0};

    // Leer tablero
    printf("Ingrese el tablero 3x3 (use X, O, .):\n");
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            char c;
            int valido = 0;
            do
            {
                printf("Ingrese el valor de [%d][%d]: ", i, j);
                scanf(" %c", &c);

                // Normalizamos mayúscula
                if (c == 'x') c = 'X';
                if (c == 'o') c = 'O';

                if (c == 'X' || c == 'O' || c == '.') {
                    tablero[i][j] = c;
                    valido = 1;
                } else {
                    printf("Entrada inválida. Solo se permiten: X, O, . (también x/o)\n");
                }
            } while (!valido);
        }
    }

    // Mostrar tablero
    printf("\nTablero: \n\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c ",tablero[i][j]);
        }
        printf("\n");
    }

    // Revisar todas las filas, columnas y diagonales

    // *Busqueda de jugada ganadora (con X)
    printf("\n");
    for(int i = 0; i < 3; i++) 
    {
        // Filas
        if(tablero[i][0] == JUGADOR && tablero[i][1] == JUGADOR && tablero[i][2] == VACIO) {
            printf("Juega en (%d,%d) para GANAR\n", i, 2); return 0; // !Si encontro, saldra del juego
        }
        if(tablero[i][0] == JUGADOR && tablero[i][2] == JUGADOR && tablero[i][1] == VACIO) {
            printf("Juega en (%d,%d) para GANAR\n", i, 1); return 0;
        }
        if(tablero[i][1] == JUGADOR && tablero[i][2] == JUGADOR && tablero[i][0] == VACIO) {
            printf("Juega en (%d,%d) para GANAR\n", i, 0); return 0;
        }

        // Columnas
        if(tablero[0][i] == JUGADOR && tablero[1][i] == JUGADOR && tablero[2][i] == VACIO) {
            printf("Juega en (%d,%d) para GANAR\n", 2, i); return 0;
        }
        if(tablero[0][i] == JUGADOR && tablero[2][i] == JUGADOR && tablero[1][i] == VACIO) {
            printf("Juega en (%d,%d) para GANAR\n", 1, i); return 0;
        }
        if(tablero[1][i] == JUGADOR && tablero[2][i] == JUGADOR && tablero[0][i] == VACIO) {
            printf("Juega en (%d,%d) para GANAR\n", 0, i); return 0;
        }
    }

    // Diagonales
    if(tablero[0][0] == JUGADOR && tablero[1][1] == JUGADOR && tablero[2][2] == VACIO) {
        printf("Juega en (2,2) para GANAR\n"); return 0;
    }
    if(tablero[0][0] == JUGADOR && tablero[2][2] == JUGADOR && tablero[1][1] == VACIO) {
        printf("Juega en (1,1) para GANAR\n"); return 0;
    }
    if(tablero[1][1] == JUGADOR && tablero[2][2] == JUGADOR && tablero[0][0] == VACIO) {
        printf("Juega en (0,0) para GANAR\n"); return 0;
    }
    if(tablero[0][2] == JUGADOR && tablero[1][1] == JUGADOR && tablero[2][0] == VACIO) {
        printf("Juega en (2,0) para GANAR\n"); return 0;
    }
    if(tablero[0][2] == JUGADOR && tablero[2][0] == JUGADOR && tablero[1][1] == VACIO) {
        printf("Juega en (1,1) para GANAR\n"); return 0;
    }
    if(tablero[1][1] == JUGADOR && tablero[2][0] == JUGADOR && tablero[0][2] == VACIO) {
        printf("Juega en (0,2) para GANAR\n"); return 0;
    }

    // *Si no existe jugada ganadora, bloquear al rival (O)
    for (int i = 0; i < 3; i++) 
    {
        // Filas
        if (tablero[i][0] == RIVAL && tablero[i][1] == RIVAL && tablero[i][2] == VACIO) {
            printf("Juega en (%d,%d) para BLOQUEAR\n", i, 2); return 0;
        }
        if (tablero[i][0] == RIVAL && tablero[i][2] == RIVAL && tablero[i][1] == VACIO) {
            printf("Juega en (%d,%d) para BLOQUEAR\n", i, 1); return 0;
        }
        if (tablero[i][1] == RIVAL && tablero[i][2] == RIVAL && tablero[i][0] == VACIO) {
            printf("Juega en (%d,%d) para BLOQUEAR\n", i, 0); return 0;
        }

        // Columnas
        if (tablero[0][i] == RIVAL && tablero[1][i] == RIVAL && tablero[2][i] == VACIO) {
            printf("Juega en (%d,%d) para BLOQUEAR\n", 2, i); return 0;
        }
        if (tablero[0][i] == RIVAL && tablero[2][i] == RIVAL && tablero[1][i] == VACIO) {
            printf("Juega en (%d,%d) para BLOQUEAR\n", 1, i); return 0;
        }
        if (tablero[1][i] == RIVAL && tablero[2][i] == RIVAL && tablero[0][i] == VACIO) {
            printf("Juega en (%d,%d) para BLOQUEAR\n", 0, i); return 0;
        }
    }

    // Diagonales (para bloquear)
    if(tablero[0][0] == RIVAL && tablero[1][1] == RIVAL && tablero[2][2] == VACIO) {
        printf("Juega en (2,2) para BLOQUEAR\n"); return 0;
    }
    if(tablero[0][0] == RIVAL && tablero[2][2] == RIVAL && tablero[1][1] == VACIO) {
        printf("Juega en (1,1) para BLOQUEAR\n"); return 0;
    }
    if(tablero[1][1] == RIVAL && tablero[2][2] == RIVAL && tablero[0][0] == VACIO) {
        printf("Juega en (0,0) para BLOQUEAR\n"); return 0;
    }
    if(tablero[0][2] == RIVAL && tablero[1][1] == RIVAL && tablero[2][0] == VACIO) {
        printf("Juega en (2,0) para BLOQUEAR\n"); return 0;
    }
    if(tablero[0][2] == RIVAL && tablero[2][0] == RIVAL && tablero[1][1] == VACIO) {
        printf("Juega en (1,1) para BLOQUEAR\n"); return 0;
    }
    if(tablero[1][1] == RIVAL && tablero[2][0] == RIVAL && tablero[0][2] == VACIO) {
        printf("Juega en (0,2) para BLOQUEAR\n"); return 0;
    }

    // !Si no existe jugada de beneficio o peligro
    printf("\nNo hay jugada inmediata para ganar o bloquear.\n");

    system("pause");
    return 0;
}
