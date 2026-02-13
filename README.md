# Projeto Cadastro de Pessoas e Funcionários (C++)

Este projeto é um sistema simples de gestão que utiliza conceitos fundamentais de **Programação Orientada a Objetos (POO)** em C++, como herança, polimorfismo e persistência de dados em arquivos.

## 🚀 Funcionalidades
- **Cadastrar**: Adiciona pessoas ou funcionários (com salário).
- **Listar**: Exibe todos os registros salvos no sistema.
- **Persistência**: Salva automaticamente os dados em um arquivo `.txt` e os carrega ao iniciar.
- **Gestão**: Permite buscar por nome, remover registros e aumentar a idade.

## 🛠️ Tecnologias e Conceitos Utilizados
- **Linguagem**: C++17
- **POO**: Uso de `virtual`, `override`, `dynamic_cast` e destruidores virtuais.
- **Smart Pointers**: Gerenciamento de memória seguro com `std::unique_ptr`.
- **Build System**: CMake

## 📁 Estrutura do Projeto
```text
ProjetoPessoa/
├── include/       # Arquivos de cabeçalho (.h)
├── src/           # Implementações (.cpp) e main
├── data/          # Arquivo de persistência (pessoas.txt)
└── CMakeLists.txt # Configuração de compilação
