Si jugadas fuera una matriz, en el peor de los casos (todas las posiciones fueron jugadas) un ciclo que recorra
todo jugadas  se ejecutaría la misma cantidad de veces (`|j|`, que es igual a la cantidad de posiciones en el tablero).

En la mayoría de los casos la matriz tomaría más iteraciones que la lista de posiciones, pero en el peor de los casos
es lo mismo, entonces la complejidad no cambia.