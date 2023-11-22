
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 f(i,j) = numero de formas de llegar a (n,m) desde (i,j)
 f(1,1) inicial
 Caso Base:
 f(n,m) = 1
 Caso recursivo
 f(i,j) = f(i + aij) + f(i, j + aij)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int formas(Matriz<int> const& m, Matriz<int> &f, int const& i, int const& j) {
    if (i == m.numfils() - 1 && j == m.numcols() - 1) {
        //f[i][j] = 1;
        return 1;
    }
    else if (f[i][j] != -1) {
        return f[i][j];
    }
    else {
        int sum = 0;
        if (i + m[i][j] < m.numfils()) {
            sum += formas(m, f, i + m[i][j], j);
        }
        if (j + m[i][j] < m.numcols()) {
            sum += formas(m, f, i, j + m[i][j]);
        }
        f[i][j] = sum;
        return sum;
    }
}

bool resuelveCaso() {
    int n, m;
    // leer los datos de la entrada
    cin >> n >> m;
    if (!std::cin)  // fin de la entrada
        return false;
    Matriz<int> matriz(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matriz[i][j];
    // resolver el caso posiblemente llamando a otras funciones
    Matriz<int> f(n, m, -1);
    cout << formas(matriz, f, 0, 0) << "\n";
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
