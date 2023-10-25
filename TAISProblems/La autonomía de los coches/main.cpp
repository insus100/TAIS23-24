
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
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

 Utilizo el algoritmo de Kruskal con un grafo valorado no dirigido para sacar el ARM.
 He modificado el algoritmo de Kruskal para que guarde el valor mayor en una variable, así como el número de conjuntos disjuntos para ver si el grafo es conexo.
 El tamaño del conjunto de conjuntos disjuntos final será el número de componentes conexas, si hay más de una, no se puede viajar a todas las ciudades por carretera.
 El coste en tiempo del algoritmo de Kruskal O(AlogA) y el coste en espacio de orden O(A), siendo A el numero de aristas del grafo valorado.
 Se construye una cola de prioridad con A elementos que son las aristas, y se realiza la operación pop (coste O(logA)) A veces.
 El resto de métodos tienen coste O(1) pues solo devuelven un valor almacenado en memoria.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    int cjtosDisjuntos;
    int maximo;
public:
    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    bool esConexo() {
        return cjtosDisjuntos < 2;
    }
    int getMax() {
        return maximo;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), maximo(0){
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (a.valor() > maximo) maximo = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        cjtosDisjuntos = cjtos.num_cjtos();
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> g(N);
    int c1, c2, v;
    for (int i = 0; i < M; i++) {
        cin >> c1 >> c2 >> v;
        g.ponArista({ c1 - 1, c2 - 1, v });
    }
    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(g);
    // escribir la solución
    arm.esConexo() ? cout << arm.getMax() << "\n" : cout << "Imposible\n";
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
