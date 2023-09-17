
/*@ <answer>
 *
 * Nombre y Apellidos: Íñigo Velasco Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Usuario {
    int momento;
    int id;
    int periodo;
};

bool operator<(Usuario const& a, Usuario const& b) {
    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    priority_queue<Usuario> cola;
    for (int i = 0; i < N; i++) {
        int id, periodo;
        cin >> id >> periodo;
        cola.push({ periodo, id, periodo });
    }

    int k;
    cin >> k;//envios
    // resolver el caso posiblemente llamando a otras funciones
    while (k--) {
        auto u = cola.top(); cola.pop();
        cout << u.id << "\n";
        u.momento += u.periodo;
        cola.push(u);
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
