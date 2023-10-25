
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class DFSValorado {
public:
    DFSValorado(GrafoValorado<int> const& g, int v, int s) : visit(g.V(), false) {
        dfs(g, v, s);
    }
    bool alcanzable(int v) const {
        return visit[v];
    }
private:
    vector<bool> visit; // visit[v] = ¿hay camino dirigido de s a v?
    void dfs(GrafoValorado<int> const& G, int v, int umbral) {
        visit[v] = true;
        for (auto a : G.ady(v)) {
            if (a.valor() >= umbral) {
                int w = a.otro(v);
                if (!visit[w])
                    dfs(G, w, umbral);
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, E;
    cin >> V >> E;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> g(V);
    int i1, i2, v;
    for (int i = 0; i < E; i++) {
        cin >> i1 >> i2 >> v;
        g.ponArista({ i1 - 1, i2 - 1, v });
    }

    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> i1 >> i2 >> v;
        DFSValorado dfs(g, i1 - 1, v);
        dfs.alcanzable(i2 - 1) ? cout << "SI\n" : cout << "NO\n";
    }
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
