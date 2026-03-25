# Aula: ABB

Código-fonte de implementação de árvore binária de busca (ABB). No momento, temos apenas definição do TAD e as operações de busca (recursiva e iterativa), inserção (recursiva) e percursos com impressão (recursiva e iterativa). As outras estão pendentes (próxima aula).

## Estrutura

```
.
├── .devcontainer/
│   ├── Dockerfile
│   └── devcontainer.json
├── README.md
└── src/
    ├── bst_iter/
    │   ├── Makefile
    │   ├── README.md
    │   └── src/
    │       ├── bst.c
    │       ├── bst.h
    │       ├── bst_element.c
    │       ├── bst_element.h
    │       ├── bst_node.c
    │       ├── bst_node.h
    │       ├── main.c
    │       ├── stack.c
    │       ├── stack.h
    │       ├── stack_element.c
    │       └── stack_element.h
    ├── bst_recur/
    │   ├── Makefile
    │   └── src/
    │       ├── bst.c
    │       ├── bst.h
    │       ├── element.c
    │       ├── element.h
    │       └── main.c
```

## Compilacao

Ha dois subprojetos com Makefile proprio:

```bash
# Recursivo
cd src/bst_recur
make main

# Iterativo
cd ../bst_iter
make main
```

## Execucao

```bash
# Recursivo
./src/bst_recur/build/main

# Iterativo
./src/bst_iter/build/main
```

## Saida esperada

Cada executavel imprime a arvore e/ou percursos de acordo com o `main.c` de cada subprojeto.

Os formatos de saida podem variar entre `bst_recur` e `bst_iter`.

## Como usar

- Edite `src/bst_recur/src/main.c` para testar a versao recursiva.
- Edite `src/bst_iter/src/main.c` para testar a versao iterativa.
- Recompile no respectivo diretorio apos cada mudanca.

## Ambiente de desenvolvimento (opcional)

O projeto inclui configuracao de Dev Container para VS Code em .devcontainer.

### GitHub Codespaces

1. No GitHub, clique em Code.
2. Selecione a aba Codespaces.
3. Clique em Create codespace on main.

### Docker

Se tiver Docker instalado, voce pode usar o ambiente localmente:

```bash
docker build -t aed-i-c -f .devcontainer/Dockerfile .
docker run --rm -it -v "$PWD":/work -w /work aed-i-c
```

Dentro do container:

```bash
cd src/bst_recur
make main
./build/main
```
