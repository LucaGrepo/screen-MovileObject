#include <stdio.h>


#define FILAS 15
#define COLUMNAS 23

/*
implementar:
    -loop de juego (especie de loop que refresca el programa cada segundo permitiendo eventos 
	como el movimiento del punto en la pantalla).
	-ire haciendo algunos experimentos (siguientes versiones) con este codigo base.
*/

void inicio();
void pantalla(int*, int*);
void procesarMov(int*, int*, char,  int*);

int movimientos = 0;
char tecla;
char jugador = 'o';
int x = (FILAS-1)/2+1, y = (COLUMNAS-1)/2+1;

int main(){
	inicio();
    
	return 0;
}

void inicio(){
    tecla = _getch();
    procesarMov(&x, &y, tecla, &movimientos);
    
    while(tecla != '0'){
    	system("cls");
        pantalla(&x,&y);
        tecla = _getch();
        procesarMov(&x, &y, tecla, &movimientos);
    }

    printf("\n                                  FIN \n \n \n");
}

void pantalla(int *pX, int *pY){
    int i, j;
        
    for(i=0; i<FILAS; i++){       
        if(j == COLUMNAS){
                printf("\n");
        }
        printf("                       ");
        printf("| ");
        
        for(j=0; j<COLUMNAS; j++){
            if(i == *pX && j == *pY){
                printf("%c", jugador);
            }else if(j==COLUMNAS-1){
                printf("|");
            }else{
                printf(" ");
            }
        
        }
        
    }
    printf("%d", movimientos);
}

void procesarMov(int *pX, int *pY, char pTecla, int *movs){
    if(pTecla == 'w'){
        *pX -= 1;
		*movs+=1;
    }else if(pTecla == 's'){
        *pX += 1;
        *movs+=1;
    }else if(pTecla == 'a'){
        *pY -= 1;
        *movs+=1;
    }else if(pTecla == 'd'){
        *pY += 1;
        *movs+=1;
    }
}
