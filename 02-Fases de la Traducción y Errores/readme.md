## Autor:
Usuario GitHub: MaximoBoglioli
Nombre: Boglioli Máximo
Legajo: 178.208-3

## Trabajo:
TP #2 "Fases de la Traducción y Errores"

### Enunciado:
1. La primera tarea es investigar las funcionalidades y opciones que su compilador presenta para limitar el inicio y fin de las fases de traducción.
2. La siguiente tarea es poner en uso lo que se encontró.  
Para eso se debe transcribir al readme.md cada comando ejecutado y su resultado o error correspondiente a la siguiente secuencia de pasos.  
También en readme.md se vuelcan las conclusiones y se resuelven los puntos solicitados.  
Para claridad, mantener en readme.md la misma numeración de la secuencia de pasos.

### Hipotesis Inicial:
Seguir cada uno de los pasos e ir registrando todo en este archivo.  


##7.3 Información encontrada respecto al compilador
Información conseguida a través del siguiente link:  
https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html  
Y también a partir del comando "gcc --help"  

Anotaré los comandos que utilizaré para el trabajo o que parecen útiles:  

 -E  
  Solo **Preprosesar**  
  No compila, ni asembla ni linkea  
  
 -S  
  Solo **Compila**  
  No ensambla ni Linkea  
  
 -c  
  **Copila y asembla**  
  No linkea  

-o
  elige el **nombre** del archivo a crear  

-wall
	Agrega todas las posibles warnings

-P
	Quita los numerales iniciales del preprocesamiento
	
hexdump [ARCHIVO]
od -t x1 [ARCHIVO]
	No son comandos de gcc pero son útiles asi que los sumo
	Se utilizan en un BASH para poder visualizar el codigo máquina de forma ordenada
	
##7.3.1 Secuencia de pasos

###1. Preprocesador:
	b) Para preprocesar, utilice el siguiente comando:
	gcc -E hello2.c -o hello2.i
	
	Tras Preprocesar y guardarlo en el "hello2.i" vemos que:
		- copia todo el archivo stdio.h
		- Luego al final se encuentra el resto del hello2.c pero reemplazó el único comentario con un espacio
		- No encontró ningun error.
	
	Yo llego a la conclusión de que no chequea/detecta errores Lexicos, Sintacticos ni pragmáticos
	Además de que se encarga de copiar todos los archivos incluidos (#Include) y de borrar los comentarios.
	
	d) La linea 1 es una declaración de una función. Sabemos la función se llama "printf" que retorna un entero y que al menos recibe 1 dato tipo char \*.
		Como dice const, también sabemos que el puntero (char \*) es de solo lectura y, por el restrict, SOLAMENTE él apunta al objeto que está apuntando (No hay solapamiento).

	e) Para unicamente preprocesarlo, utilicé el siguiente comando:
	gcc -E hello3.c -o hello3.i -P
	
	El archivo hello3.c y hello3.i (si utilizamos el -P) son iguales
	Agregué el -P para que no aparezcan los numerales al comienzo y de esta forma sean iguales. Estos numerales son datos que utiliza nuestro compilador, pero no afecta al programa.


###2. Compilación:
	a) Para compilar el resultado sin ensamblar, utilicé el siguiente comando:
	gcc -S hello3.i -o hello3.s
	
	El archivo hello3.s no se genera ya que hay un error en el programa que evita que compile. También hay un warning, pero estos no evitan que compile.
	
	b) Corrigo el error que aparece cerrando la llave de main.
	Utilizo el siguiente comando para generar hello4.s sin ensamblar
	gcc -S hello4.i -o hello4.s
	
	c) El programa ensamblado hello4.s:
		Empuja y mueve la pila del base pointer (bp) para poder ir apilando las funciones que se estan llamando
		Hace espacio para guardar el valor de "i"
		Llama a la función main
		Llama a "prontf"
		Retorna el valor 0 al registro A (Lo que devuelve el main)
		Y termina el programa
	
	d) Utilizo el siguiente comando para ensamblar hello4.s sin vincular:
	gcc -c hello4.s -o hello4.o


###3.  Vinculación:
	(Aviso: Me olvidé que había que hacerlo hasta antes de la vinculación y seguí adelante hasta que me trabé y revisando el grupo me enteré que era hasta antes de esto. Dejo los progresos y si algo esta mal luego lo modificaré)
	a) el comando gcc sin modificadores vincula con la biblioteca estándard. Utilizo el siguiente comando para generar el ejecutable:
	gcc hello4.o -o hello4.exe
	
	Aqui aparece un error debido a que prontf no existe en la bibliote estándard
	
	b) Modifico el prontf por printf así vincula. Utilizo el siguiente comando para generar el ejecutable:
	gcc hello5.c -o hello5.exe

	c) Para ejecutar el programa utilizo el siguiente comando:
	hello5.exe
	
	el ejecutable da como resultado:
		La respuesta es -214232192
	
	El inicio es correcto (ya que el programa le dice que escriba "La respuesta es "). Sin embargo, luego le decimos que escriba un número entero (con el %d) pero no lo aclaramos. Esto hace que tenga un comportamiento indefinido.
		**Se rompio el contrato, puede pasar cualquier cosa**

###4. 	Corrección de Bug
	a) Yo supongo que querría que muestre el valor de i. Entonces lo corrijo para que muestre eso agregandolo al printf.
	Utilizo el siguiente comando para convertirlo en ejecutable:
		gcc hello6.c -o hello6.exe
	Al correrlo, verifico que funcionó como esperaba. Lo hago con el siguiente comando
	hello6.exe


###5. Remoción de prototipo
	b) Inicialmente, el programa nos muestra 2 warnings.
		El primero indica que hicimos una declaración implicita de printf, y nos pide que la agreguemos.
		El segundo, que la declaración implicita de print no encaja con la declaración por defecto que tiene el compilador para estos casos.

		Por otro lado, el estandard no aclara qué debería hacer el compilador en caso de una declaración implicita.
		Entonces, el programa funciona igualmente porque el compilador "gcc" (el que utilizo) tiene un nivel de flexibilidad mayor.
			Y funciona correctamente, porque printf se encuentra en la biblioteca estandard. Por lo que tiene la definición sobre que hacer con la misma.


###6. Compilación Separada: Contratos y Módulos
	b) Con mi compilador, para generar un programa ejecutable en base a dos archivos .c, debo utilizar un comando con la siguiente estructura:
		gcc [Archivo #1] [Archivo #2]
	Utilizo el siguiente comando para generar el ejecutable:
		gcc hello8.c studio1.c -o hello8.exe
	Funciona correctamente
	
	c) Como gcc es muy permisivo, si agregamos o quitamos argumentos el programa funcionará. Sin embargo entrará en un estado de comportamiento indefinido.
	Esto es así porque:
		-Detecta la declaración implicita, pero la deja pasar porque así funciona gcc
		-Despuáse el vinculador al ser muy básico, vincula la función con la declaración pero no chequea la cantidad de argumentos
		-Luego de esto, lo ejecuta.
		
		Pero como está mal, ya que cambiaste la cantidad de argumentos, pasa a estar en comportamineto indefinido.
	
	En otros compiladores o en otros sistemas operativos puede que no funcione o que tenga un funcionamiento que no nos beneficie.
	
	d)
		iv) La ventaja que otrorga incluir el contrato es que nos permite ver errores en el programa en tiempo de compilación.
			Evitamos tener / reducimos la cantidad de veces que puede tener un comportamiento indefinido. Por lo que nos ayuda a tener un mejor programa.