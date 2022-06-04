#Warnings hello7
###Comando: gcc -S hello7.c -o hello7.s

hello7.c: In function 'main':
hello7.c:3:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    3 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | int main(void){
hello7.c:3:2: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
    3 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~
hello7.c:3:2: note: include '<stdio.h>' or provide a declaration of 'printf'


#Warnings TEST
###Comando: gcc -S hello7TEST.c -o hello7TEST.s

hello7TEST.c: In function 'main':
hello7TEST.c:4:2: warning: implicit declaration of function 'PruebaNoExistente' [-Wimplicit-function-declaration]
    4 |  PruebaNoExistente("La respuesta es %d\n", i);
      |  ^~~~~~~~~~~~~~~~~
