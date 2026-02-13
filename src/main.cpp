#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <fstream>
#include "funcionario.h"
#include <sstream>
#include "pessoa.h"

// --------- tipos ---------

void mostrarMenu();
void cadastrar(std::vector<std::unique_ptr<Pessoa>>& lista);
void listar(const std::vector<std::unique_ptr<Pessoa>>& lista);
void aumentar(std::vector<std::unique_ptr<Pessoa>>& lista);
void buscar(const std::vector<std::unique_ptr<Pessoa>>& lista);
void remover(std::vector<std::unique_ptr<Pessoa>>& lista);

void salvar(const std::vector<std::unique_ptr<Pessoa>>& lista);
void carregar(std::vector<std::unique_ptr<Pessoa>>& lista);



int main() {
    std::vector<std::unique_ptr<Pessoa>>lista;
    carregar(lista);

    int opcao;

    do {
        mostrarMenu();
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcao){
            case 1: cadastrar(lista); break;
            case 2: listar(lista); break;
            case 3: aumentar(lista); break;
            case 4: buscar(lista); break;
            case 5: remover(lista); break;
        }

        salvar(lista);

    } while(opcao != 0);

    return 0;
}

void mostrarMenu(){
    std::cout << "\n1 - Cadastrar pessoa\n";
    std::cout << "2 - Listar pessoas\n";
    std::cout << "3 - Aumentar idade\n";
    std::cout << "4 - Buscar por nome\n";
    std::cout << "5 - Remover pessoa\n";
    std::cout << "0 - Sair\n";
    std::cout << "Escolha: ";
}

void cadastrar(std::vector<std::unique_ptr<Pessoa>>& lista){
    int tipo;

    std::cout << "1 - Pessoa\n";
    std::cout << "2 - Funcionario\n";
    std::cout << "Escolha o tipo: ";
    std::cin >> tipo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string nome;
    int idade;

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "Idade: ";
    std::cin >> idade;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(tipo == 1){
        lista.push_back(std::make_unique<Pessoa>(nome, idade));
    }
    else if(tipo == 2){
        double salario;
        std::cout << "Salario: ";
        std::cin >> salario;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        lista.push_back(std::make_unique<Funcionario>(nome, idade, salario));
    }
}

void listar(const std::vector<std::unique_ptr<Pessoa>>& lista){
    for(size_t i = 0; i < lista.size(); i++){
        std::cout << "Numero: " << i << "\n";
        lista[i]->mostrar();
    }
}

void aumentar(std::vector<std::unique_ptr<Pessoa>>& lista){
    size_t indice;

    std::cout << "Numero da pessoa: ";
    std::cin >> indice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(indice < lista.size()){
        lista[indice]->aumentarIdade();
        std::cout << "Idade aumentada\n";
    } else {
        std::cout << "Numero invalido\n";
    }
}

void buscar(const std::vector<std::unique_ptr<Pessoa>>& lista){
    std::string nomeBusca;

    std::cout << "Nome para buscar: ";
    std::getline(std::cin, nomeBusca);

    bool encontrado = false;

    for(const auto& pessoa : lista){
        if(pessoa->getNome() == nomeBusca){
            pessoa->mostrar();
            encontrado = true;
        }
    }

    if(!encontrado){
        std::cout << "Pessoa nao encontrada.\n";
    }
}

void remover(std::vector<std::unique_ptr<Pessoa>>& lista){
    size_t indice;

    std::cout << "Numero para remover: ";
    std::cin >> indice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(indice < lista.size()){
        lista.erase(lista.begin() + indice);
        std::cout << "Pessoa removida!\n";
    } else {
        std::cout << "Numero invalido!\n";
    }
}

void salvar(const std::vector<std::unique_ptr<Pessoa>>& lista){
    std::ofstream arquivo("pessoas.txt");

    for(const auto& pessoa : lista){

        if(auto func = dynamic_cast<Funcionario*>(pessoa.get())){
            arquivo << "Funcionario;"<< func->getNome() << ";"<< func->getIdade() << ";"<< func->getSalario() << "\n";
        }
        else{
            arquivo << "Pessoa;"<< pessoa->getNome() << ";"<< pessoa->getIdade() << "\n";
        }
    }
}

void carregar(std::vector<std::unique_ptr<Pessoa>>& lista){
    std::ifstream arquivo("pessoas.txt");

    if(!arquivo.is_open())
        return;

    std::string linha;

    while(std::getline(arquivo, linha)){

        std::stringstream ss(linha);
        std::string tipo, nome, idadeStr, salarioStr;

        std::getline(ss, tipo, ';');
        std::getline(ss, nome, ';');
        std::getline(ss, idadeStr, ';');

        int idade = std::stoi(idadeStr);

        if(tipo == "Pessoa"){
            lista.push_back(std::make_unique<Pessoa>(nome, idade));
        }
        else if(tipo == "Funcionario"){
            std::getline(ss, salarioStr, ';');
            double salario = std::stod(salarioStr);

            lista.push_back(std::make_unique<Funcionario>(nome, idade, salario));
        }
    }
}

