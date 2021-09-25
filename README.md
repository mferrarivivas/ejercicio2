Ejercicio 2: Anillo.

Desarrollar un programa MPI denominado “anillo”, en donde los procesos deben hacer circular un mensaje a través de un “anillo lógico”. El programa deberá recibir como parámetro un entero n que indicará la cantidad de vueltas que el mensaje debe dar al anillo. 

Ejemplo con cuatro procesos:[Falta imagen]

El proceso 0 envía el M0 con el dato “A” al proceso 1 El proceso 1 envía el M1 con el dato “A” al proceso 2 El proceso 2 envía el M2 con el dato “A” al proceso 3 El proceso 3 envía el M3 con el dato “A” al proceso 0

Este proceso será repetido tantas veces como lo indique El parámetro “n”.
 
