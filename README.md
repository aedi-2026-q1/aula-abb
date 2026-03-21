# Aula: ABB

Código-fonte de implementação de árvore binária de busca (ABB). No momento, temos apenas definição de nó, construção manual de árvore e operações de busca (recursiva e iterativa). 

## Estrutura

```
.
├── README.md
├── src/
│   └── search_test.c
└── .devcontainer/
    ├── Dockerfile
    └── devcontainer.json
```

O diretorio build/ e criado apos a compilacao.

## Compilacao

Use clang ou gcc no diretorio do projeto:

```bash
mkdir -p build
clang -Wall -Wextra -pedantic -std=c11 -o build/search_test src/search_test.c
```

## Execucao

```bash
./build/search_test
```

## Saida esperada

O programa imprime o resultado das buscas para chaves que existem e nao existem na arvore, separando:

- Testing recursive search:
- Testing iterative search:

As linhas exibem found ou not found para cada chave testada.

## Como usar

- Edite src/search_test.c para alterar os casos de teste.
- Recompile apos cada mudanca.

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
mkdir -p build
clang -Wall -Wextra -pedantic -std=c11 -o build/search_test src/search_test.c
./build/search_test
```
