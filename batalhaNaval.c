#include <stdio.h>

#define TAMANHO_TABULEIRO 10   // Tamanho fixo do tabuleiro
#define TAMANHO_NAVIO 3        // Tamanho fixo dos navios
#define AGUA 0                 // Representa água no tabuleiro
#define NAVIO 3                // Representa parte do navio no tabuleiro

// Função para verificar se é possível posicionar o navio
int pode_posicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
            return 0; // Fora dos limites
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO)
                return 0; // Sobreposição
        }
    } else if (orientacao == 'V') { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
            return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int c = 0; c < TAMANHO_TABULEIRO; c++) {
        printf("%d ", c);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa todas as posições com 0 (água)

    // Coordenadas fixas para os dois navios
    int linha1 = 2, coluna1 = 3; // Navio 1 - horizontal
    int linha2 = 5, coluna2 = 7; // Navio 2 - vertical

    // Verifica e posiciona o primeiro navio (horizontal)
    if (pode_posicionar(tabuleiro, linha1, coluna1, 'H')) {
        posicionar_navio(tabuleiro, linha1, coluna1, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    // Verifica e posiciona o segundo navio (vertical)
    if (pode_posicionar(tabuleiro, linha2, coluna2, 'V')) {
        posicionar_navio(tabuleiro, linha2, coluna2, 'V');
    } else {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    // Exibe o tabuleiro final
    printf("Tabuleiro com navios posicionados:\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}
