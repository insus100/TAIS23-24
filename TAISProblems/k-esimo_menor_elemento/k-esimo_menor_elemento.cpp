
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se añade el atributo tamaño a cada nodo que almacena el número de nodos en el hijo izquierdo más 1.
 El coste de la operacion kesimo es de O(logN) siendo N el número de nodos que tiene el árbol.


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    Set<int> arbol;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        arbol.insert(h);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        try {
            cout << arbol.kesimo(k) << "\n";
        }
        catch (std::out_of_range &e) {
            cout << "??\n";
        }
    }
    cout << "---\n";

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
