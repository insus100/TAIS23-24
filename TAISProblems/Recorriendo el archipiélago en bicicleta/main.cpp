
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
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
    bool esConexo() {
        return cjtosDisjuntos < 2;
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cjtosDisjuntos(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
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
    int I, P;//islas, puentes.
    cin >> I >> P;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> g(I);
    int i1, i2, v;
    for (int i = 0; i < P; i++) {
        cin >> i1 >> i2 >> v;
        g.ponArista({ i1 - 1, i2 - 1, v });
    }

    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(g);
    // escribir la solución
    arm.esConexo() ? cout << arm.costeARM() << "\n" : cout << "No hay puentes suficientes\n";
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
