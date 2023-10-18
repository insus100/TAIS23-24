
/*@ <answer>
 *
 * Nombre y Apellidos: TAIS69 Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <climits>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Tema {
    string tema;
    int citas, actualizado;

    bool operator<(Tema const& b) const {
        return this->citas > b.citas || (this->citas == b.citas && this->actualizado > b.actualizado);
    }

    void operator-=(Tema const& b) {
        this->actualizado = b.actualizado;
        this->citas -= b.citas;
        //return this->citas - b.citas;
    }
    void operator+=(Tema const& b) {
        this->actualizado = b.actualizado;
        this->citas += b.citas;
    }
};




bool resuelveCaso() {

    // leer los datos de la entrada
    int n;//eventos;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;
    IndexPQ<string, Tema> q;
    for (int i = 0; i < n; i++) {
        string evento;
        cin >> evento;
        if (evento == "C") {//aumentan citas
            Tema t;
            cin >> t.tema >> t.citas;
            t.actualizado = i;
            q.update(t.tema, t);
        }
        else if (evento == "E") {//expiran citas
            Tema t;
            cin >> t.tema >> t.citas;
            t.actualizado = i;
            q.update(t.tema, t, false);
        }
        else if (evento == "TC") {
            int qSize = q.size();
            IndexPQ<string, Tema> q2;
            for (int i = 0; i < 3 && i < qSize; i++) {
                Tema t = q.top().prioridad;
                cout << i + 1 << " " << t.tema << "\n";
                q.pop();
                q2.push(t.tema, t);
            }
            while (!q2.empty()) {
                q.push(q2.top().elem, q2.top().prioridad);
                q2.pop();
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
