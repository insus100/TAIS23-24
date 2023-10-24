
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

template <typename Valor>
class ARM_Kruskal {
private:
    vector<Arista<Valor>> _ARM;
    Valor coste;
    int cjtosDisjuntos;
public:
    Valor costeARM() const {
        return coste;
    }
    vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    int componentesConexas() {
        return cjtosDisjuntos;
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g, int const&A) : coste(0), cjtosDisjuntos(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w) && a.valor() < A) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        cjtosDisjuntos = cjtos.num_cjtos();
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M, A;
    cin >> N >> M >> A;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> g(N);
    for (int i = 0; i < M; i++) {
        int i1, i2, c;
        cin >> i1 >> i2 >> c;
        g.ponArista({ i1 - 1, i2 - 1, c });
    }
    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(g, A);
    // escribir la solución
    cout << arm.componentesConexas() * A + arm.costeARM() << " " << arm.componentesConexas() << "\n";
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
