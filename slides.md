---
theme: seriph
background: >-
  https://cdn.jsdelivr.net/gh/slidevjs/slidev-covers@main/static/XdcRfXL2hJ4.webp
title: Welcome to Slidev
info: |
  ## Slidev Starter Template
  Presentation slides for developers.

  Learn more at [Sli.dev](https://sli.dev)
class: text-center
highlighter: shiki
drawings:
  persist: false
lineNumbers: true
transition: fade-out
mdc: true
addons:
  - slidev-addon-asciinema
---

# Algoritmos Greedy

Cortoplacismo computacional 🕐

---

# ¿Qué es un Algoritmo Greedy?
Keep it simple

Un algoritmo **Greedy** (avaro/ávido/voraz) es aquel que construye una solución pieza a pieza eligiendo siempre la siguiente pieza que ofrezca el más obvio e **inmediato beneficio**.

**Supone** que eligiendo soluciones óptimas locales nos guían hacia soluciones óptimas globales. <- Lo cual no es siempre cierto!

<v-click>
  <img src="/youknowwhat.jpg" class="absolute bottom-0 right-0 w-1/4" />
</v-click>

---

# Ventajas
👍

- Simplicidad: Los algoritmos greedy son generalmente fáciles de entender e implementar debido a su enfoque directo y local en cada paso.

- Eficiencia: Pueden ser muy rápidos ya que toman decisiones basadas solo en la información disponible en el momento actual, sin necesidad de explorar todas las posibles soluciones. Esto a menudo conduce a soluciones con tiempos de ejecución lineales o polinomiales.

- Menor Complejidad Espacial: Los algoritmos greedy suelen utilizar menos memoria porque no necesitan almacenar todas las soluciones posibles, a diferencia de otros enfoques como la programación dinámica.

- Aplicaciones Prácticas: Son adecuados para problemas donde la solución óptima global se puede construir a partir de soluciones óptimas locales, como el problema del árbol de cubrimiento mínimo.

---

# Desventajas
👎

- Subóptimos: Los algoritmos greedy no siempre encuentran la solución óptima global. En algunos problemas, la solución encontrada puede ser significativamente peor que la óptima.

- Miopía: Los algoritmos greedy pueden ser miopes, es decir, no ven más allá de la elección inmediata. Esto puede llevar a tomar decisiones que parecen buenas en el corto plazo pero que son malas en el largo plazo.

- Dependencia de la Heurística: El éxito de un algoritmo greedy depende en gran medida de la heurística utilizada para tomar decisiones locales. Si la heurística no está bien diseñada, el algoritmo puede fallar en encontrar una buena solución.

---

# Problema del Cambio
Se requiere devolver el cambio con la menor cantidad de monedas posible.

Contamos con las monedas uruguayas (1, 2, 5, 10, 50).

Para cambio de 12 pesos:
- 1 de 10
- 1 de 2

Para cambio de 47 pesos:
- 4 de 10
- 1 de 5
- 1 de 2

<br>

> ¿Cuál es la intuición detrás de este problema?

<v-click>
-> Trato de dar la mayor cantidad de monedas de mayor valor (siempre y cuando no superen el valor que estoy devolviendo).
</v-click>

<img src="/dogecoin.png" class="absolute top-0 right-0 w-50" />

---

# Problema del Cambio
Se requiere devolver el cambio con la menor cantidad de monedas posible.

```cpp
// Función para encontrar el número mínimo de monedas usando un enfoque greedy
int minCoins(int coins[], int n, int amount) {
    int count = 0;

    // Recorrer las denominaciones de las monedas desde la más grande a la más pequeña
    for (int i = n - 1; i >= 0; i--) {
        // Usar tantas monedas de la denominación actual como sea posible
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    // Si el monto es cero, devolver el número de monedas usadas, de lo contrario, devolver -1
    return amount == 0 ? count : -1;
}
```

<br>

> ¿Qué problemas podrían surgir con este enfoque?

<br>

> ¿Qué orden de complejidad tiene este algoritmo?


<img src="/dogecoin.png" class="absolute top-0 right-0 w-50" />

---

# Problema del Cambio
Se requiere devolver el cambio con la menor cantidad de monedas posible.

¿Qué ocurre si tenemos las monedas uruguayas (1, 2, 5, 10, 12, 50)?

Para cambio de 15 pesos:
- 1 de 12
- 1 de 2
- 1 de 1

<br>

¿Qué si no tenemos monedas unitaria (2, 5, 10, 50) y queremos dar el cambio de 13 pesos?


<img src="/dogecoin.png" class="absolute top-0 right-0 w-50" />

---

# El Problema de la Mochila
Tomar el mayor valor posible sin superar la capacidad de la mochila.

<!-- center img -->
<div class="flex justify-center items-center">
  <img src="/mochila.png" class="w-100" />
</div>

<br>

<v-click>
  > ¿Qué enfoque podríamos tomar para resolver este problema?
</v-click>

---

# Ejemplos de Enfoque Greedy: Mochila v1
Valor primero

| Elemento | Valor | Peso | Aceptado |
|----------|-------|------|----------|
| Ruby     | 25    | 8    | Sí       |
| Diamante | 20    | 3    | Sí       |
| Oro      | 10    | 5    | No       |
| Moneda   | 8     | 4    | No       |

Enfoque 1: tratar de meter lo más valioso primero.
Valor recolectado: 45

<img src="/mochila.png" class="absolute bottom-0 right-0 w-60" />

---

# Ejemplos de Enfoque Greedy: Mochila v2
Menor peso primero

| Elemento | Valor | Peso | Aceptado |
|----------|-------|------|----------|
| Diamante | 20    | 3    | Sí       |
| Moneda   | 8     | 4    | Sí       |
| Oro      | 10    | 5    | Sí       |
| Ruby     | 25    | 8    | No       |

Enfoque 2: tratar de meter lo de menor peso primero.
Valor recolectado: 38

<img src="/mochila.png" class="absolute bottom-0 right-0 w-60" />

---

# Ejemplos de Enfoque Greedy: Mochila v3
Mejor ratio valor/peso primero

| Elemento | Valor | Peso | Ratio | Aceptado |
|----------|-------|------|-------|----------|
| Diamante | 20    | 3    | 6.67  | Sí       |
| Ruby     | 25    | 8    | 3.125 | Sí       |
| Oro      | 10    | 5    | 2     | No       |
| Moneda   | 8     | 4    | 2     | No       |

Enfoque 3: tratar de meter el mejor valor/peso ratio primero.
Valor recolectado: 45

<img src="/mochila.png" class="absolute bottom-0 right-0 w-60" />

---

# Solución al Problema de la Mochila

```cpp
// Función para encontrar el valor máximo de la mochila usando un enfoque greedy
// Asume que los elementos están ordenados por enfoque elegido
int knapsackGreedy(int weights[], int values[], int n, int W) {
    int totalValue = 0;
    int totalWeight = 0;

    // Tomar ítems en orden de mayor valor primero hasta que la mochila esté llena
    for (int i = 0; i < n; i++) {
        if (totalWeight + weights[i] <= W) {
            totalWeight += weights[i];
            totalValue += values[i];
        }
    }

    return totalValue;
}
```

<br>

> Tener en cuenta que los elementos deben estar ordenados según el enfoque elegido. De lo contrario habría que ordenarlos previamente.

---

# Limitaciones de los Algoritmos Greedy
Greedy no es óptimo

**Enfoque 1 (mayor valor primero) con una mochila de capacidad 25:**

| Item | Profit | Weight |
|------|--------|--------|
| A    | 24     | 24     |
| B    | 18     | 10     |
| C    | 18     | 10     |
| D    | 10     | 7      |

<br>

Valor recolectado: 24 (A)

-> La solución óptima es 36 (B y C)

---

# Limitaciones de los Algoritmos Greedy
Greedy no es óptimo

**Enfoque 3 (mejor ratio primero) con una mochila de capacidad 60:**

| Item | Price | Weight | Ratio |
|------|-------|--------|-------|
| A    | 100   | 10     | 10    |
| B    | 280   | 40     | 7     |
| C    | 120   | 20     | 6     |

<br>

Valor recolectado: 380 (A y B)

-> La solución óptima es 400 (B y C)

---

# Problema: Actividades
Maximizar la cantidad de actividades realizadas.

- Las actividades se deben realizar enteras.
  - No se puede entrar tarde ni salir temprano.
  - No se pueden solapar.
- Se tiene el tiempo de inicio y fin de cada actividad.
- No tienen ningun orden en particular.
- Pueden tener diferentes duraciones.

<br>

> ¿Qué enfoque podríamos tomar para resolver este problema?

<br>

<v-click>
  Ideas:
</v-click>

<v-clicks>

- Ordenar por tiempo de comienzo.
- Ordenar por duración.
- Ordenar por tiempo de finalización.

</v-clicks>

<img src="/lolla.webp" class="absolute top-0 right-0 h-140" />

---
layout: two-cols
---

# Solución

<<< @/snippets/actividades.cpp {all|18-36|13-15|20|25-26|29-34|40-60|77|80|all}{maxHeight:'400px'}

::right::

# Ejecución

<Asciinema src="./casts/actividades-ascii.cast"/>

---

# Problema: Laberinto
Minimizar la cantidad de paredes rotas.

Se desea salir de un laberinto rompiendo la menor cantidad de paredes posibles.

Se comienza desde la pared izquierda y la salida está por la pared derecha.

```
1 1 1 1 1 1 1 1 1 1
1 1 0 0 1 0 1 0 0 1
0 0 0 1 1 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 0 0
```

---

# Problema: Paréntesis
Minimizar la cantidad de intercambios.

Se tiene una serie de paréntesis rectos que no se encuentran bien apareados.

Se desea saber la mínima cantidad de intercambios necesarios para dejarlo bien formado. Se asume que la cantidad de [ y ] son la misma.


## Ejemplos

Input: `[[][]]][` -> Output: 1

Input: `[][[][[]]]]][[` -> Output: 1

Input: `]]][[[` -> Output: 2

---

# Problema: Policías y Ladrones
Maximizar la cantidad de ladrones capturados.

Dado un conjunto de policías y otro de ladrones, se desea saber el máximo de ladrones capturados. 
Sabiendo que:
- Cada policía puede atrapar como máximo a un ladrón.
- El policía puede capturar a una máxima distancia dada (K).

<br>

## Ejemplos

- PLP, K=1
- LLLPP, K=2
- LPLLPP, K=2
- LLLLPLPPP, K=2

<img src="/policeandthief.gif" class="absolute bottom-0 right-0 w-50" />

---

# Problema: Plataformas
Minimizar la cantidad de plataformas

Se quiere construir una estación de tren y se necesita saber la cantidad de plataformas se necesitan.

Se tiene los horarios tentativos de llegada y partida.

## Ejemplo

Input: 
```
arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
```