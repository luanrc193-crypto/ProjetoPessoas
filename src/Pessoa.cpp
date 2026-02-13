#include "pessoa.h"
#include <iostream>

Pessoa::Pessoa(std::string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}

void Pessoa::mostrar() const{
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Idade: " << idade << "\n";
    std::cout << "++++++++++++++++++\n";
}

void Pessoa::aumentarIdade(){
    idade++;
}

void Pessoa::salvar(std::ostream& os) const {
    os << "P;" << nome << ";" << idade << "\n";
}


std::string Pessoa::getNome() const{
    return nome;
}

int Pessoa::getIdade() const{
    return idade;
}
