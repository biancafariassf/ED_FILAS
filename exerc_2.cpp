#include <iostream>
using namespace std;

class FilaCircular {
private:
    int frente, final, tamanho, capacidade;
    int *fila;

public:
    // Construtor que cria a fila com capacidade especificada e inicia frente e final
    FilaCircular(int capacidade) {
        this->capacidade = capacidade;
        fila = new int[capacidade];
        frente = -1;
        final = -1;
        tamanho = 0;
    }

    // Método que adiciona um elemento no final da fila
    void enfileira(int obj) {
        if (cheia()) {
            cout << "Fila cheia. Não é possível enfileirar." << endl;
            return;
        }
        
        if (frente == -1) frente = 0;
        final = (final + 1) % capacidade;
        fila[final] = obj;
        tamanho++;
    }

    // Método que remove e retorna o elemento do início da fila
    int desenfileira() {
        if (vazia()) {
            cout << "Fila vazia. Não é possível desenfileirar." << endl;
            return -1;
        }

        int obj = fila[frente];
        if (frente == final) {
            frente = -1;
            final = -1;
        } else {
            frente = (frente + 1) % capacidade;
        }
        tamanho--;
        return obj;
    }

    // Método que retorna o elemento do início da fila sem removê-lo
    int cabeca() {
        if (vazia()) {
            cout << "Fila vazia." << endl;
            return -1;
        }
        return fila[frente];
    }

    // Método que retorna o elemento do final da fila sem removê-lo
    int cauda() {
        if (vazia()) {
            cout << "Fila vazia." << endl;
            return -1;
        }
        return fila[final];
    }

    // Método que verifica se a fila está vazia
    bool vazia() {
        return tamanho == 0;
    }

    // Método que verifica se a fila está cheia
    bool cheia() {
        return tamanho == capacidade;
    }

    // Método que exibe todos os elementos da fila
    void mostrarFila() {
        if (vazia()) {
            cout << "Fila vazia." << endl;
            return;
        }
        int i = frente;
        while (true) {
            cout << fila[i] << " ";
            if (i == final) break;
            i = (i + 1) % capacidade;
        }
        cout << endl;
    }

    // Método que pesquisa um elemento na fila
    bool pesquisa(int obj) {
        if (vazia()) return false;
        int i = frente;
        while (true) {
            if (fila[i] == obj) return true;
            if (i == final) break;
            i = (i + 1) % capacidade;
        }
        return false;
    }

    // Método que retorna o tamanho atual da fila
    int tamanhoFila() {
        return tamanho;
    }

    // Destrutor para liberar a memória alocada
    ~FilaCircular() {
        delete[] fila;
    }
};

int main() {
    FilaCircular fila(5);

    // Testando a fila circular
    fila.enfileira(1);
    fila.enfileira(2);
    fila.enfileira(3);
    fila.mostrarFila(); // Saída: 1 2 3

    cout << "Cabeça: " << fila.cabeca() << endl; // Saída: 1
    cout << "Cauda: " << fila.cauda() << endl; // Saída: 3

    fila.desenfileira();
    fila.mostrarFila(); // Saída: 2 3

    cout << "Está cheia? " << (fila.cheia() ? "Sim" : "Não") << endl;
    cout << "Está vazia? " << (fila.vazia() ? "Sim" : "Não") << endl;

    fila.enfileira(4);
    fila.enfileira(5);
    fila.enfileira(6);
    fila.mostrarFila(); // Saída: 2 3 4 5 6

    cout << "Tamanho: " << fila.tamanhoFila() << endl; // Saída: 5

    cout << "Pesquisa por 3: " << (fila.pesquisa(3) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Pesquisa por 7: " << (fila.pesquisa(7) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}