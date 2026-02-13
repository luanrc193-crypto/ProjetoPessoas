#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
#include <fstream>

class Pessoa {
protected:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade);
    virtual ~Pessoa() {}

    virtual void mostrar() const;
    virtual void salvar(std::ostream& os) const;
    
    void aumentarIdade();
    std::string getNome() const;
    int getIdade() const;
};

#endif
