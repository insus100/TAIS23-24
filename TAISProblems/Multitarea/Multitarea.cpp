
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
struct Tarea {
    bool repite;
    int inicio;
    int fin;
    int intervalo;
};
bool operator<(Tarea const& a, Tarea const& b) {
    return a.inicio > b.inicio;

}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M, T;
    cin >> N >> M >> T;
    if (!std::cin)  // fin de la entrada
        return false;
    priority_queue<Tarea> q;
    for (int i = 0; i < N; i++) {//tareas unicas
        Tarea t{ 0,0,-1 };
        cin >> t.inicio >> t.fin;
        q.push({ false, t.inicio, t.fin, 0 });
    }

    for (int i = 0; i < M; i++) {//tareas periodicas
        Tarea t{ 0,0,0 };
        cin >> t.inicio >> t.fin >> t.intervalo;
        q.push({ true, t.inicio, t.fin, t.intervalo });
    }
    // resolver el caso posiblemente llamando a otras funciones
    bool conflicto = false;
    int ocupado = 0;// hasta cuándo estoy ocupado con las tareas procesadas
    while (!conflicto && !q.empty() && q.top().inicio < T) {
        auto [rep, inicio, fin, intervalo] = q.top(); q.pop();
        conflicto = inicio < ocupado;
        ocupado = fin;
        if (rep) {//si es periodica hay que añadirla de nuevo a la cola con los intervalos
            q.push({ true, inicio + intervalo, fin + intervalo, intervalo });
        }
    }
    // escribir la solución
    conflicto ? cout << "SI\n" : cout << "NO\n";
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
