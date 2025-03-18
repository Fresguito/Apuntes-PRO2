#include <iostream>
#include "vstack.hh"
#include "html_elem.hh"
using namespace std;

    /**
     * @brief Determina si la pila contiene los tags "head" y "html"
     *
     * @param x La pila donde se va a buscar los tags.
     *
     * @returns `true` si el primer "top" de la pila es el tag "head" y el segundo es el tag "html", si no `false`.
     */
bool correct_script_tag (VStack & x) {
    if (tag_name(x.top(0)) == "head" and tag_name(x.top(-1)) == "html") return true;
    return false;
}

int main() {
    string input;
    VStack open_tags;
    bool print_able = true;

    while (cin >> input) {

        /*
        Separamos dos casos:
            1. El string INPUT es un "tag" de html
            2. El string INPUT NO es un "tag" de html
        
        Para el caso 1:
            Diferenciamos dos posibilidades: 

                OPCIÓN 1. El "tag" es de cierre
                    - Eliminamos de la pila "open_tags" el ultimo "tag" abierto
                    - Verificamos, por si acaso, si el "tag" es de script, para devolver el bool "print_able" a la normalidad

                OPCIÓN 2. El "tag" NO es de cierre
                    - Verificamos si el "tag" es script, y asignamos al booleano "print_able" el resultado de la función "correct_script_tag"
                    - Insertamos a la pila "open_tags" el "tag" abierto

            Siempre printearemos los "tags", por lo que se finaliza con la escritura de este
            
        Para el caso 2:
            - Printearemos el string "input" siempre y cuando el booleano "print_able" valga "true" (se puede escribir el texto)
        */

        if (is_tag(input)) { // CASO 1
            if (is_close_tag(input)) { // OPCIÓN 1
                open_tags.pop();
                if (tag_name(input) == "script") print_able = true;
            } else { // OPCIÓN 2
                if (tag_name(input) == "script") print_able = correct_script_tag(open_tags);
                open_tags.push(input);
            }
            cout << input << " ";
        } else { // CASO 2
            if (print_able) cout << input << " ";
        }
    }
}