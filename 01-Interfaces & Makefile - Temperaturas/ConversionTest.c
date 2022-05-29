//Este programa tiene como objetivo verificar que las funciones actuen de manera adecuada.

#include <stdio.h> 
#include <assert.h>
#include "Conversion.h"

int main ( void ){ 

const float PC1 = 0.0;
const float PC2 = 25.0;
const float PC3 = 28.0;

const float PF1 = 32.0;
const float PF2 = 77.0;
const float PF3 = 82.4;


//Tabla Far a Celsius
printf ("Prueba Celsius:\n");

assert (Celsius(32.0) == PC1);
assert (Celsius(77.0) == PC2);
assert (Celsius(82.4) == PC3);

//Tabla Celsius a Far
printf ("\nPrueba Fahrenheit:\n");


assert (Farenheit(0.0) == PF1);
assert (Farenheit(25.0) == PF2);
assert (Farenheit(28.0) == PF3);

printf ("\nLas pruebas funcionaron a la perfeccion\n\n\n");
}
