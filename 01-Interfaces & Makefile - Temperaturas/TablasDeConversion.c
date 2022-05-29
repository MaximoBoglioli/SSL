//Este programa tiene el objetivo de crear 2 tablas de conversion. Una de Fahrenheit a Celsius y otra al revés.

#include <stdio.h>
#include "Conversion.h"

int main (void) {
 
    float num; 

    //Tabla Far a Celsius
    printf ("Tabla de Fahrenheit a Celsius:\n\n");

    for (num = 0.0; num <= 200; num = num + 20) {
        printf("%3.0f %6.2f\n", num, Celsius(num));
    }

    //Tabla Celsius a Far
    printf ("\n\nTabla de Celsius a Fahrenheit:\n\n");

    for (num = 0.0; num <= 100; num = num + 10) {
        printf("%3.0f %6.2f\n", num, Farenheit(num));
    }

}