% Contesten aquí la pregunta sobre complejidad
 
La complejidad se vería afectada, ya que para recorrer todas las jugadas, en vez de recorrer una 
secuencia, hay que recorrer un tablero, y la complejidad aumenta de O(n) a O(n^2) = 0(m^2).

En jugarPlus, la complejidad de agregarJugadasNuevas aumentaría a O(n^2), ya que debe recorrer 
todo el tablero. Por lo tanto, la complejidad de jugarPlus quedaría O(m^2 * (n^2 + l)). Pero como
n = m, O((n^2 + l) * m^2) = O(n^4 + l * n^2)

En sugerirAutomatico121, el ciclo aumentaria su complejidad a O(n^2), y lo mismo
sucedería con las funciones existen1y1. Por lo tanto, la complejidad quedaría O(n^2) * O(n^2) = O(n^4).