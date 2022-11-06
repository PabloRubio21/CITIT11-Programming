#include <stdio.h>

int main()
{
    float input, integer, decimals;
    int position;
    char answer;

    do{
        printf("Introduzca un numero: ");
        fflush(stdin);
        scanf("%f", &input);
        printf("Ha introducido el numero %f\n", input);

        integer = input;
        decimals = integer - (int) integer;

        if (integer > 1) {
            printf("--- Parte entera (%f) ---\n", integer - decimals);
            position = 0;
            while (integer >= 1)
                printf("Bit %d: %d \n", position++, (integer = integer / 2) - (int) integer >= 0.5 ? 1 : 0);
        }

        if (decimals > 0) {
            printf("--- Parte decimal (%f) ---\n", decimals);
            position = 0;
            do {
                printf("Bit %i: %i\n", position++, (decimals *= 2) >= 1 ? 1 : 0);
                decimals = decimals - (int) decimals;
            } while (position <= 23);
        }

        printf("Desea repetir la experiencia inolvidable que es convertir un numero a binario? (y/n)");
        fflush(stdin);
        scanf("%c", &answer);
    } while (answer == 'y' || answer == 'Y' || answer == '\n');

    printf("Gracias por utilizar el sistema de conversion a binario!");
}
