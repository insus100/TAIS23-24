
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "ConjuntosDisjuntos.h"
#include "IndexPQ.h"
#include "DigrafoValorado.h"
using Camino = deque<AristaDirigida<int>>;
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
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    Camino camino(int v) const {
        Camino cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<int> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

struct Carretera {
    int puntoA, puntoB, coste;
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    int camiones = N - 2;
    DigrafoValorado<int> g(N);

    int p1, p2, c;
    for (int i = 0; i < M; i++) {
        cin >> p1 >> p2 >> c;
        g.ponArista({ p1 - 1, p2 - 1, c });
        g.ponArista({ p2 - 1, p1 - 1, c });
    }
    Dijkstra<int> plantaA(g, 0);
    Dijkstra<int> plantaB(g, N-1);
    vector<bool> sumado(N, false);
    int coste = 0, camionesA = camiones / 2, camionesB = camiones / 2;
    for (int i = 1; i < N - 1; i++) {
        if (sumado[i]) continue;
        if (plantaA.hayCamino(i) && plantaB.hayCamino(i)) {
            if (plantaA.distancia(i) < plantaB.distancia(i) && camionesA > 0) {
                Camino c = plantaA.camino(i);
                for (AristaDirigida<int> const& a : c) {
                    if (!sumado[a.hasta()]) {
                        sumado[a.hasta()] = true;
                        sumado[a.desde()] = true;
                        coste += a.valor() * 2;
                    }
                    else camionesA++;
                }
                //coste += plantaA.distancia(i) * 2;
                camionesA--;
                
            }
            else if(camionesB > 0) {
                Camino c = plantaB.camino(i);
                for (AristaDirigida<int> const& a : c) {
                    if (!sumado[a.hasta()]) {
                        sumado[a.hasta()] = true;
                        sumado[a.desde()] = true;
                        coste += a.valor() * 2;
                    }
                    else camionesB++;
                }
                camionesB--;
            }
        }
        else {
            if (plantaA.hayCamino(i) && camionesA > 0) {
                Camino c = plantaA.camino(i);
                for (AristaDirigida<int> const& a : c) {
                    if (!sumado[a.hasta()]) {
                        sumado[a.hasta()] = true;
                        sumado[a.desde()] = true;
                        coste += a.valor() * 2;
                    }
                    else camionesA++;
                }
                camionesA--;
            }
            else if (plantaB.hayCamino(i) && camionesB > 0) {
                Camino c = plantaB.camino(i);
                for (AristaDirigida<int> const& a : c) {
                    if (!sumado[a.hasta()]) {
                        sumado[a.hasta()] = true;
                        sumado[a.desde()] = true;
                        coste += a.valor() * 2;
                    }
                    else camionesB++;
                }
                camionesB--;
            }
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << coste << " " << camiones << "\n";
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
