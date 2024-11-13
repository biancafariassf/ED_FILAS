#include <iostream>
#define MAX 4 // Tamanho máximo do vetor compartilhado

class PilhasCompartilhadas {
private:
    int topoA, topoB;
    int vetor[MAX];

public:
    PilhasCompartilhadas() {
        criaPilha();
    }

    void criaPilha() {
        topoA = -1;       // Inicializa o topo de A
        topoB = MAX;      // Inicializa o topo de B
    }

    void empilhaA(int obj) {
        if (!cheiaA()) {
            vetor[++topoA] = obj;
        } else {
            std::cout << "Pilha A está cheia!" << std::endl;
        }
    }

    void empilhaB(int obj) {
        if (!cheiaB()) {
            vetor[--topoB] = obj;
        } else {
            std::cout << "Pilha B está cheia!" << std::endl;
        }
    }

    bool vaziaA() {
        return topoA == -1;
    }

    bool vaziaB() {
        return topoB == MAX;
    }

    bool cheiaA() {
        return topoA + 1 == topoB;
    }

    bool cheiaB() {
        return topoB - 1 == topoA;
    }

    int desempilhaA() {
        if (!vaziaA()) {
            return vetor[topoA--];
        } else {
            std::cout << "Pilha A está vazia!" << std::endl;
            return -1; // Retorna -1 caso a pilha esteja vazia
        }
    }

    int desempilhaB() {
        if (!vaziaB()) {
            return vetor[topoB++];
        } else {
            std::cout << "Pilha B está vazia!" << std::endl;
            return -1; // Retorna -1 caso a pilha esteja vazia
        }
    }

    int topoA_func() {
        if (!vaziaA()) {
            return vetor[topoA];
        } else {
            std::cout << "Pilha A está vazia!" << std::endl;
            return -1;
        }
    }

    int topoB_func() {
        if (!vaziaB()) {
            return vetor[topoB];
        } else {
            std::cout << "Pilha B está vazia!" << std::endl;
            return -1;
        }
    }

    void mostrarPilhaA() {
        if (!vaziaA()) {
            std::cout << "Pilha A: ";
            for (int i = 0; i <= topoA; i++) {
                std::cout << vetor[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Pilha A está vazia!" << std::endl;
        }
    }

    void mostrarPilhaB() {
        if (!vaziaB()) {
            std::cout << "Pilha B: ";
            for (int i = MAX - 1; i >= topoB; i--) {
                std::cout << vetor[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Pilha B está vazia!" << std::endl;
        }
    }

    int tamanhoA() {
        return topoA + 1;
    }

    int tamanhoB() {
        return MAX - topoB;
    }
};

int main() {
    PilhasCompartilhadas pilhas;

    pilhas.empilhaA(1);
    pilhas.empilhaA(2);
    pilhas.empilhaB(3);
    pilhas.empilhaB(4);

    pilhas.mostrarPilhaA();
    pilhas.mostrarPilhaB();

    std::cout << "Tamanho da pilha A: " << pilhas.tamanhoA() << std::endl;
    std::cout << "Tamanho da pilha B: " << pilhas.tamanhoB() << std::endl;

    pilhas.desempilhaA();
    pilhas.desempilhaB();

    pilhas.mostrarPilhaA();
    pilhas.mostrarPilhaB();

    return 0;
}