
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Paciente {
    string nombre;
    int gravedad;
    int espera;
};

bool operator<(Paciente const& a, Paciente const& b) {
    if (a.gravedad == b.gravedad) return a.espera > b.espera;
    else return a.gravedad < b.gravedad;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    priority_queue<Paciente> q;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'I') {//ingreso de paciente
            Paciente p;
            cin >> p.nombre >> p.gravedad;
            q.push({ p.nombre, p.gravedad, i });
        }
        else if (c == 'A') {//atender paciente
            Paciente p = q.top(); q.pop();
            cout << p.nombre << "\n";
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
