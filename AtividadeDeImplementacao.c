//Filiphe Natannael
//João Gabriel
//Rômulo de Souza

#include <stdio.h>

int main(){
    char entrada[100];
    char lexema[100];//armazena as entradas aceitas a cada caracter lido
    int estado = 0;
    int i = 0, j = 0;

    printf("Digite a entrada: ");
    fgets(entrada, 100, stdin);
   //só para a busca no final da string
    while (entrada[i] != '\0') {
        char c = entrada[i];

        switch (estado) {

            case 0:
                if (c == '-') {
                    estado = 1;
                    lexema[j++] = c;
                } else if (c >= '0' && c <= '9') {//verificar se é um digito
                    estado = 2;
                    lexema[j++] = c;
                }
                break;
            
            case 1:
                if (c >= '0' && c <= '9') {
                    estado = 2;
                    lexema[j++] = c;
                } else {
                    estado = 0;
                    j = 0;
                }
                break;

            case 2:
                if (c >= '0' && c <= '9') {
                    estado = 2;
                    lexema[j++] = c;
                } else if (c== ',') {
                    estado = 3;
                    lexema[j++] = c;
                } else {
                    lexema[j] = '\0';
                    printf("Token reconhecido: %s\n", lexema);
                    return 0;
                }
                break;

            case 3:
                if (c >= '0' && c <= '9') {
                    estado = 4;
                    lexema[j++] = c;
                } else {
                    estado = 0;
                    j = 0;
                }
                break;

            case 4:
                if (c >= '0' && c <= '9') {
                    estado = 4;
                    lexema[j++] = c;
                } else {
                    lexema[j] = '\0';
                    printf("Token reconhecido: %s\n", lexema);
                    return 0;
                }
                break;
        }

        i++;//avança a fita de entrad
    }

    if (estado == 2 || estado == 4) {
        lexema[j] = '\0';
        printf("Token reconhecido: %s\n", lexema);
    } else {
        printf("Nenhum token reconhecido!\n");
    }

    return 0;
}