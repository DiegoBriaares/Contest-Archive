## Tarea Karte

En la mesa de Vito hay $N$ cartas rojas numeradas del $1$ al $N$ y $M$ cartas azules numeradas del $1$ al $M$. Cada par de cartas roja y azul $(c, p)$ (donde $c$ representa una carta roja y $p$ una carta azul) puede crear un movimiento COMBO.

La fuerza de un mazo de cartas se define como:
$$
\text{fuerza} = (\text{número de movimientos COMBO}) - X \cdot (\text{número de cartas rojas}) - Y \cdot (\text{número de cartas azules})
$$

donde el número de movimientos COMBO es el número de pares $(c, p)$ tales que la carta roja $c$ y la carta azul $p$ están en el mazo elegido. Vito puede incluir cualquier carta de la mesa en su mazo. Ayuda a Vito a encontrar el valor del mazo más fuerte que pueda construir. Vito también puede elegir un mazo vacío.

### Entrada

La primera línea contiene $4$ números naturales $N, M, X, Y$ $(1 \leq N, M \leq 21, 0 \leq X, Y \leq 30)$. 
En las siguientes $N$ líneas, hay una secuencia de $M$ caracteres ($0$ o $1$), donde el $j$-ésimo carácter indica si la carta roja $i$-ésima y la carta azul $j$-ésima crean un movimiento COMBO.

### Salida

En la primera y única línea, imprime el valor del mazo más fuerte que Vito pueda construir.


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