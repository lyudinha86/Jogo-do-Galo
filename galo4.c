#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogador1[20], jogador2[20];
void iniciaTabuleiro();
int eValido(char letra);
int coordenadaEhValida(int x, int y);
int posicaVazia(int x, int y);
int verificaLinhas();
int verificaColunas();
int verificadiagPrincipal();
int verificadiagSecundaria();
void mostraTabuleiro();
void jogar();
void instrucoes();
void menu();

int main() 
{
    int n;
    printf("Jogaador 1 digite seu nome: \n");
    fgets(jogador1, 20, stdin);
    printf("Jogador 2 digite seu nome: \n");
    fgets(jogador2, 20, stdin);
    printf("\n%s, voce vai jogar com o simbolo X\n", jogador1);
    printf("\n%s, voce vai jogar com o simbolo 0\n", jogador2);  
    

    while( 1 )
    {
        menu();
        printf( "Opção: " );
        scanf( "%d", &n );
        switch( n )
        {
            case 1:
                instrucoes();
                break;
            case 2:
                jogar();
                break;
            case 3:
                return( 0 );
            default:
                printf( "Opção errada.\n" );
        }
    }
    return( 0 );
} 

void iniciaTabuleiro() {
    int i,j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

int eValido(char letra) {
    if(letra == 'x' || letra == '0')
        return 1;
    else
        return 0;
}

int coordenadaEhValida(int x, int y) {
    if(x >= 0 && x < 3) {
        if(y >= 0 && y < 3)
            return 1;
    }
    return 0;
}

int posicaVazia(int x, int y) {
    if(tabuleiro[x][y] != 'x' && tabuleiro[x][y] != '0')
        return 1;
    return 0;
}

int verificaLinhas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(eValido(tabuleiro[i][j]) && tabuleiro[i][j] == tabuleiro[i][j+1])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int verificaColunas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(eValido(tabuleiro[j][i]) && tabuleiro[j][i] == tabuleiro[j+1][i])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int verificadiagPrincipal() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(eValido(tabuleiro[i][i]) && tabuleiro[i][i] == tabuleiro[i+1][i+1])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

int verificadiagSecundaria() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(eValido(tabuleiro[i][3-i-1]) && tabuleiro[i][3-i-1] == tabuleiro[i+1][3-i-2])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

void mostraTabuleiro() {
    int lin, col;

    printf("\n\t    0  1  2\n");
    for(lin = 0; lin < 3; lin++) {
        printf("\t%d ", lin);
        for(col = 0; col < 3; col++) {
            if(col < 2)
                printf(" %c |", tabuleiro[lin][col]);
            else
                printf(" %c ", tabuleiro[lin][col]);
        }
        if(lin < 2)
            printf("\n\t   ---------\n");
    }
}

void jogar() {
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

    do {
        do {
           mostraTabuleiro() ;
            printf("\nDigite a coordenada que deseja jogar: ");
            scanf("%d%d", &x, &y);
            valida = coordenadaEhValida(x, y);
            if(valida == 1)
                valida += posicaVazia(x, y);
        } while(valida != 2);
        if(ordem == 1)
            tabuleiro[x][y] = 'x';
        else
            tabuleiro[x][y] = '0';
        jogadas++;
        ordem++;
        if(ordem == 3)
            ordem = 1;
        ganhou += verificaLinhas();
        ganhou += verificaColunas();
        ganhou += verificadiagPrincipal();
        ganhou += verificadiagSecundaria();
    } while(ganhou == 0 && jogadas < 9);

    if(ganhou != 0) {
        mostraTabuleiro();
        if(ordem - 1 == 1)
            printf("\nParabens. Voce venceu %s\n", jogador1);
        else
            printf("\nParabens. Voce venceu %s\n", jogador2);
    } else
        printf("\nEmpate. Ninguem venceu!\n\n");
}
void instrucoes()
{
    printf( "INSTRUÇÕES DO JOGO DO GALO\n" );
    printf( "==========================\n" );
    printf( "Jogador 1 (X) introduz linha e coluna de cada jogada que fizer.\n" );
    printf( "Jogador 2 (O) joga depois do Jogador 1.\n" );
    printf( "Os jogadores continuam a jogar até haver um vencedor ou um empate.\n" );
    printf( "\n" );
} 

void menu()
{
    printf( "JOGO DO GALO\n" );
    printf( "============\n" );
    printf( "1-Instruções\n" );
    printf( "2-Jogar\n" );
    printf( "3-Sair\n" );
    printf( "\n" );
} 
