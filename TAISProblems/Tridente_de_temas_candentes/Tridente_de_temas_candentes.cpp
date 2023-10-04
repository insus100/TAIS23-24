
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

//#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Evento {
    string tipo, tema;
    int citas, actualizado;
};

bool operator<(Evento const& a, Evento const& b) {
    return a.citas < b.citas || (a.citas == b.citas && a.actualizado < b.actualizado);
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;//eventos;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;
    //IndexPQ<Evento> q(n);
    priority_queue<Evento> q, q2;
    for (int i = 0; i < n; i++) {
        Evento e;
        cin >> e.tipo;
        e.actualizado = i;
        if (e.tipo == "C") {
            cin >> e.tema >> e.citas;
            bool inserted = false;
            while (!q.empty() && !inserted) {
                Evento aux = q.top(); q.pop();
                if (aux.tema == e.tema) {
                    aux.citas += e.citas;
                    aux.actualizado = i;
                    q.push(aux);
                    inserted = true;
                }
                else {
                    q2.push(aux);
                }
            }
            while (!q2.empty()) {
                Evento e = q2.top(); q2.pop();
                q.push(e);
            }
            if (!inserted) {
                q.push(e);
            }
        }
        else if (e.tipo == "E") {
            cin >> e.tema >> e.citas;
            bool inserted = false;
            while (!q.empty() && !inserted) {
                Evento aux = q.top(); q.pop();
                if (aux.tema == e.tema) {
                    aux.citas -= e.citas;
                    aux.actualizado = i;
                    q.push(aux);
                    inserted = true;
                }
                else {
                    q2.push(aux);
                }
            }
            while (!q2.empty()) {
                Evento e = q2.top(); q2.pop();
                q.push(e);
            }
            if (!inserted) {
                q.push(e);
            }
        }
        else {
            if (!q.empty()) {
                int qOrigSize = q.size();
                for (int i = 0; i < 3 && i < qOrigSize; i++) {
                    Evento e = q.top(); q.pop();
                    q2.push(e);
                    cout << i + 1 << " " << e.tema << "\n";
                }
            }
            while (!q2.empty()) {
                Evento e = q2.top(); q2.pop();
                q.push(e);
            }
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
