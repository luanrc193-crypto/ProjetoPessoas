#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"

class Funcionario : public Pessoa {
private:
    double salario;

public:
    Funcionario(std::string nome, int idade, double salario);
    
    void mostrar() const override;
    void salvar(std::ostream& os) const override;
    
    double getSalario() const;
};

#endif
