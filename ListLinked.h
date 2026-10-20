
#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    // Puntero al primer nodo de la lista
    Node<T>* first;

    // Numero de elementos de la lista
    int n;

public:
    // Constructor: crea una lista vacia
    ListLinked() : first(nullptr), n(0) {}

    // Destructor: libera la memoria de todos los nodos
    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    // Inserta un elemento en la posicion indicada
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posicion no valida");
        }

        // Insertar al principio
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* aux = first;

            // Avanzar hasta el nodo anterior a la posicion
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            // Enlazar el nuevo nodo con el siguiente
            aux->next = new Node<T>(e, aux->next);
        }

        n++;
    }

    // Anade un elemento al final de la lista
    void append(T e) override {
        insert(n, e);
    }

    // Anade un elemento al principio de la lista
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento de la posicion indicada
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no valida");
        }

        T elemento;

        // Eliminar el primer nodo
        if (pos == 0) {
            Node<T>* aux = first;
            elemento = first->data;
            first = first->next;
            delete aux;
        } else {
            Node<T>* aux = first;

            // Avanzar hasta el nodo anterior al que se elimina
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            Node<T>* borrar = aux->next;
            elemento = borrar->data;
            aux->next = borrar->next;
            delete borrar;
        }

        n--;
        return elemento;
    }

    // Devuelve el elemento de la posicion indicada
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no valida");
        }

        Node<T>* aux = first;

        // Recorrer la lista hasta la posicion buscada
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    // Busca un elemento y devuelve su posicion, o -1 si no existe
    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;

        while (aux != nullptr) {
            if (aux->data == e) {
                return pos;
            }

            aux = aux->next;
            pos++;
        }

        return -1;
    }

    // Indica si la lista esta vacia
    bool empty() override {
        return n == 0;
    }

    // Devuelve el numero de elementos de la lista
    int size() override {
        return n;
    }

    // Permite acceder a un elemento mediante el operador []
    T operator[](int pos) {
        return get(pos);
    }

    // Permite imprimir la lista por pantalla
    friend std::ostream& operator<<(std::ostream& out,
                                    ListLinked<T>& lista) {
        out << "[";
        Node<T>* aux = lista.first;

        while (aux != nullptr) {
            out << aux->data;

            if (aux->next != nullptr) {
                out << ", ";
            }

            aux = aux->next;
        }

        out << "]";
        return out;
    }
};

#endif
