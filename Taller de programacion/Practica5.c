#include <stdio.h>

int input_power(int*, int*);
void calculate_power(int, int);
void print_binary(int);

int main() {
    int base, exponent;
    char answer;
    do {
        do {
            system("cls");
            input_power(&base, &exponent);
            printf("Datos Introducidos:\nBase: %i\nExponente: %i\nSon estos datos correctos? (y/n): ", base, exponent);
            fflush(stdin);
            scanf("%c", &answer);
        } while (answer == 'N' || answer == 'n');

        calculate_power(base, exponent);

        printf("Desea repetir? (y/n):");
        fflush(stdin);
        scanf("%c", &answer);
    } while(answer == 'y' || answer == 'Y' || answer == '\n');
}

int input_power(int *base, int *exponent){
    do {
        printf("Introduzca la base [2-10]: ");
        fflush(stdin);
        scanf("%i", base);
    } while (*base < 2 || *base > 10);

    do {
        printf("Introduzca el exponente [0-10]: ");
        fflush(stdin);
        scanf("%i", exponent);
    } while (*exponent < 0 || *exponent > 10);
}

void calculate_power(int base, int exponent){
    int position = 0, decimal;

    system("cls");
    if (exponent == 0) {
        printf("%i^%i=1\n---\n", base, position);
        printf("Bit 0: 1\n");
        printf("---\n");
    } else {
        decimal = 1;
        for (position = 1; position <= exponent; position++) {
            system("cls");
            printf("%i^%i=%i\n---\n", base, position, decimal *= base);
            print_binary(decimal);
            printf("---\nPULSE ENTER PARA CONTINUAR\n");
            getchar();
        }
    }
}

void print_binary (int decimal){
    int position_binary = 0;
    float binary;
    binary = decimal;
    while (binary >= 1)
        printf("Bit %d: %d \n", position_binary++, ((binary = binary / 2) - (int) binary) >= 0.5 ? 1 : 0);
}
