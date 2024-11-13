#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class EstruturaDados {
private:
    vector<list<string>> vetorNomes;

    int indice(char letra) {
        return toupper(letra) - 'A';
    }

public:
    EstruturaDados() : vetorNomes(26) {}  // Inicializa o vetor com 26 listas (A-Z)

    // Função para adicionar um nome
    void adicionarNome(const string& nome) {
        int idx = indice(nome[0]);
        auto& lista = vetorNomes[idx];
        lista.insert(lower_bound(lista.begin(), lista.end(), nome), nome);  // Insere em ordem alfabética
    }

    // Função para pesquisar um nome
    bool pesquisarNome(const string& nome) {
        int idx = indice(nome[0]);
        auto& lista = vetorNomes[idx];
        return find(lista.begin(), lista.end(), nome) != lista.end();
    }

    // Função para excluir um nome
    void excluirNome(const string& nome) {
        int idx = indice(nome[0]);
        auto& lista = vetorNomes[idx];
        lista.remove(nome);
    }

    // Função para renomear um nome
    void renomearNome(const string& nomeAntigo, const string& nomeNovo) {
        excluirNome(nomeAntigo);
        adicionarNome(nomeNovo);
    }

    // Função para verificar se a estrutura está vazia
    bool estaVazia() {
        for (const auto& lista : vetorNomes) {
            if (!lista.empty()) return false;
        }
        return true;
    }

    // Função para retornar a quantidade de nomes
    int quantidadeNomes() {
        int quantidade = 0;
        for (const auto& lista : vetorNomes) {
            quantidade += lista.size();
        }
        return quantidade;
    }

    // Função para exibir todos os nomes
    void exibirNomes() {
        for (int i = 0; i < 26; ++i) {
            if (!vetorNomes[i].empty()) {
                cout << (char)(i + 'A') << ": ";
                for (const auto& nome : vetorNomes[i]) {
                    cout << nome << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    EstruturaDados estrutura;

    estrutura.adicionarNome("Aline");
    estrutura.adicionarNome("Amanda");
    estrutura.adicionarNome("Ana");
    estrutura.adicionarNome("Carlos");

    cout << "Nomes na estrutura:" << endl;
    estrutura.exibirNomes();

    cout << "Quantidade de nomes: " << estrutura.quantidadeNomes() << endl;

    string nome = "Ana";
    if (estrutura.pesquisarNome(nome)) {
        cout << nome << " foi encontrado na estrutura." << endl;
    } else {
        cout << nome << " não foi encontrado na estrutura." << endl;
    }

    estrutura.excluirNome("Amanda");
    cout << "Após excluir 'Amanda':" << endl;
    estrutura.exibirNomes();

    estrutura.renomearNome("Carlos", "Carla");
    cout << "Após renomear 'Carlos' para 'Carla':" << endl;
    estrutura.exibirNomes();

    cout << "A estrutura está vazia? " << (estrutura.estaVazia() ? "Sim" : "Não") << endl;

    return 0;
}