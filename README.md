# MyVensim

Framework em C++ para construção e execução de modelos de simulação baseados em Dinâmica de Sistemas.

**Disciplina:** BCC322 — Engenharia de Software I · UFOP  
**Professor:** Tiago Garcia de Senna Carneiro

---

## Descrição

API inspirada na linguagem DYNAMO e no simulador Vensim. Permite modelar e executar sistemas dinâmicos compostos por **sistemas** (estoques), **fluxos** (equações de transferência) e **modelos** (orquestradores da simulação).

---

## Estrutura do Projeto

```
MyVensim/
├── include/
│   ├── flow.h
│   ├── flow_impl.h
│   ├── flows.h
│   ├── functional_test.h
│   ├── model.h
│   ├── model_impl.h
│   ├── system.h
│   └── system_impl.h
│
├── src/
│   ├── main.cpp
│   ├── flow_impl.cpp
│   ├── flows.cpp
│   ├── model_impl.cpp
│   └── system_impl.cpp
│
├── test/
│   ├── functional/
│   │   ├── main.cpp
│   │   └── functional_test.cpp
│   └── unit/
│       ├── main.cpp
│       ├── unit_tests.h
│       ├── unit_tests.cpp
│       ├── unit_flow.h
│       ├── unit_flow.cpp
│       ├── unit_model.h
│       ├── unit_model.cpp
│       ├── unit_system.h
│       └── unit_system.cpp
│
├── bin/
├── Makefile
└── README.md
```

---

## Compilação e Execução

> Requer `g++` com suporte a C++17.

| Comando | Descrição |
|---|---|
| `make` | Compila tudo (simulador + testes) |
| `make unit_tests` | Compila e executa os testes unitários |
| `make functional_tests` | Compila e executa os testes funcionais |
| `make run` | Executa testes unitários e funcionais |
| `make clean` | Remove binários e objetos gerados |

---

## Testes

### Unitários
Verificam individualmente os métodos de `System`, `Flow` e `Model`.  
Executável: `bin/progTestUnit`

### Funcionais
Verificam a simulação completa contra valores analíticos esperados para três modelos:

| Modelo | Descrição |
|---|---|
| Exponencial | Crescimento proporcional ao estoque de origem (taxa 1%) |
| Logístico | Crescimento com capacidade limite de 70 |
| Complexo | Rede com 5 sistemas e 6 fluxos interligados |

Executável: `bin/progTestFuncional`

---

## Licença

Desenvolvido exclusivamente para fins acadêmicos na disciplina BCC322 — UFOP.  
Uso comercial não permitido sem autorização prévia do autor.