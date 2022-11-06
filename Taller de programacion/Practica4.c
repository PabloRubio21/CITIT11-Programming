#include <stdio.h>

int main()
{
    int decimal, base, exponent, binary_position, i;
    float binary;
    char answer;

    do {
        do {
            do {
                printf("Introduzca la base [2-10]: ");
                fflush(stdin);
                scanf("%i", &base);
            } while (base < 2 || base > 10);

            do {
                printf("Introduzca el exponente [0-10]: ");
                fflush(stdin);
                scanf("%i", &exponent);
            } while (exponent < 0 || exponent > 10);

            printf("Datos introducidos:\nBase: %i\nExponente: %i\nSon estos datos correctos? (y/n): ", base, exponent);
            fflush(stdin);
            scanf("%c", &answer);
        } while (answer == 'N' || answer == 'n');

        if (exponent == 0) {
            printf("\n%i^%i=1\n---\nBit 0: 1\n---\n", base, i);
        } else {
            decimal = 1;
            for (i = 1; i <= exponent; i++) {
                printf("\n%i^%i=%i\n---\n", base, i, decimal *= base);

                binary_position = 0;
                binary = decimal;
                while (binary >= 1)
                    printf("Bit %d: %d \n", binary_position++, ((binary = binary / 2) - (int) binary) >= 0.5 ? 1 : 0);

                printf("---\nPULSE ENTER PARA CONTINUAR");
                fflush(stdin);
                getchar();
            }
        }

        printf("\nDesea repetir? (y/n): ");
        fflush(stdin);
        scanf("%c", &answer);
    }while(answer=='y'||answer=='Y'||answer=='\n');
}
