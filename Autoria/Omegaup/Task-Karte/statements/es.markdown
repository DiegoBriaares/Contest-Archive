## Tarea Karte

En la mesa de Vito hay $N$ cartas rojas numeradas del $1$ al $N$ y $M$ cartas azules numeradas del $1$ al $M$. Cada par de cartas roja y azul $(c, p)$ (donde $c$ representa una carta roja y $p$ una carta azul) puede crear un movimiento COMBO.

La fuerza de un mazo de cartas se define como:
$$
\text{fuerza} = (\text{n�mero de movimientos COMBO}) - X \cdot (\text{n�mero de cartas rojas}) - Y \cdot (\text{n�mero de cartas azules})
$$

donde el n�mero de movimientos COMBO es el n�mero de pares $(c, p)$ tales que la carta roja $c$ y la carta azul $p$ est�n en el mazo elegido. Vito puede incluir cualquier carta de la mesa en su mazo. Ayuda a Vito a encontrar el valor del mazo m�s fuerte que pueda construir. Vito tambi�n puede elegir un mazo vac�o.

### Entrada

La primera l�nea contiene $4$ n�meros naturales $N, M, X, Y$ $(1 \leq N, M \leq 21, 0 \leq X, Y \leq 30)$. 
En las siguientes $N$ l�neas, hay una secuencia de $M$ caracteres ($0$ o $1$), donde el $j$-�simo car�cter indica si la carta roja $i$-�sima y la carta azul $j$-�sima crean un movimiento COMBO.

### Salida

En la primera y �nica l�nea, imprime el valor del mazo m�s fuerte que Vito pueda construir.


||input
2 2 0 0
11
10
||output
3
||end

||input
3 3 1 0
111
111
000
||output
4
||end

||input
3 3 1 1
111
101
011
||output
1
||end