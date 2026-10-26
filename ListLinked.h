
#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:

      Node<T>* first;

      int n;

public:
    
    ListLinked() : first(nullptr), n(0) {}

    
    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posicion no valida");
        }

                if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* aux = first;
	    for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            
            aux->next = new Node<T>(e, aux->next);
        }

        n++;
    }

    
    void append(T e) override {
        insert(n, e);
    }

    
    void prepend(T e) override {
        insert(0, e);
    }

    
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no valida");
        }

        T elemento;

        
        if (pos == 0) {
            Node<T>* aux = first;
            elemento = first->data;
            first = first->next;
            delete aux;
        } else {
            Node<T>* aux = first;

            
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

    
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no valida");
        }

        Node<T>* aux = first;

        
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    
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

    
    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    
    T operator[](int pos) {
        return get(pos);
    }

    
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
