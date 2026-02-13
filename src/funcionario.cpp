#include "funcionario.h"
#include "pessoa.h"
#include <iostream>

Funcionario::Funcionario(std::string nome, int idade, double salario): Pessoa(nome, idade),salario(salario){

}

void Funcionario::mostrar() const{
    Pessoa::mostrar();
    std::cout<<"Salario: " <<salario <<"\n";
    std::cout<<"====================\n";
}

void Funcionario::salvar(std::ostream& os) const {
    os << "F;" << nome << ";" << idade << ";" << salario << "\n";
}


double Funcionario::getSalario() const{
    return salario;
}


