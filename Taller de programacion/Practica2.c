#include <stdio.h>

int main()
{
    float input;
    int position;
    char answer;

    do {
        do {
            printf("Introduzca un numero entre el 0 y el 256: ");
            fflush(stdin);
            scanf("%f", &input);
        } while (input<=0 || input>256);
        printf("Ha introducido el numero %f\n", input);

        position = 0;
        while (input >= 1)
            printf("Bit %d: %d \n", position++, ((input = input / 2) - (int) input >= 0.5)? 1 : 0);

        printf("Desea repetir la experiencia inolvidable que es convertir un numero a binario? (y/n)");
        fflush(stdin);
        scanf("%c", &answer);
    } while (answer == 'y' || answer == 'Y' || answer == '\n');

    printf("Gracias por utilizar el sistema de conversion a binario!");
}

