
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
using Camino = deque<int>;
#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Problema {
public:
    Problema(Grafo const& g, int s, int trabajo) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s), trabajo(trabajo) {
        bfs(g);
    }

    bool hayCamino(int v) const {
        return visit[v];
    }
    int distancia(int v) const {
        return dist[v];
    }
    Camino camino(int v) const {
        if (!hayCamino(v)) throw std::domain_error("No existe camino");
        Camino cam;
        for (int x = v; x != s; x = ant[x])
            cam.push_front(x);
        cam.push_front(s);
        return cam;
    }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int s, trabajo;
    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C, casaA, casaL, trabajo;
    cin >> N >> C >> casaA >> casaL >> trabajo;
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo g(N);

    for (int i = 0; i < C; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g.ponArista(v1 - 1, v2 - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    Problema alex(g, casaA - 1, trabajo - 1);
    Problema lucas(g, casaL - 1, trabajo - 1);
    //Problema tr(g, trabajo - 1);
    /*if (alex.hayCamino(casaL - 1)) {
        Camino c = alex.camino(casaL - 1);
        cout << c.front();
    }*/
    
    // escribir la solución
    cout << alex.distancia(casaL - 1) + lucas.distancia(trabajo - 1) << "\n";
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
