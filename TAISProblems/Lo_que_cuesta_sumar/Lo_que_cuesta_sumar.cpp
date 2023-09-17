
/*@ <answer>
 *
 * Nombre y Apellidos: Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
using lli = long long int;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Coste bucle O(NlogN)

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

    // resolver el caso posiblemente llamando a otras funciones
    priority_queue<lli, vector<lli>, greater<lli>> cola;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cola.push(n);
    }
    lli esfuerzoMinimo = 0;
    while (N > 1) {
        auto a = cola.top(); cola.pop();
        auto b = cola.top(); cola.pop();
        a += b;
        esfuerzoMinimo += a;
        cola.push(a);
        N--;
    }
    // escribir la solución
    cout << esfuerzoMinimo << "\n";
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
