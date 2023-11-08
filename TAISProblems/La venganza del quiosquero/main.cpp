
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 Coste O(N^2) en el caso peor.
 Creo un vector de valores incrementados de uno en uno.
 El valor siguiente en la suma de los valores sera el siguiente al ultimo valor del vector o el siguiente a S (en caso de que S no esté en el vector)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resolver(vector<int>& v, int S) {
    if (v.size() == 1) return v[0];
    int siguiente = max(v[v.size() - 1], S) + 1;
    
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] + v[j] == S) {
                v[j] = siguiente;
                siguiente++;
            }
        }
    }
    int sum = 0;
    for (int& r : v)
        sum += r;

    return sum;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, S;//numero de resistencias, numero de ohmnios que no puede sumar.
    cin >> N >> S;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    int cont = 0, val = 1;
    vector<int> v(N);

    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    cout << resolver(v, S) << "\n";

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
