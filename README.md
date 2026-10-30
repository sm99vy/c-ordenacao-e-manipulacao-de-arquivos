# 📊 Sistema de Ordenação de Números em C

Projeto desenvolvido em linguagem C para praticar lógica de programação, manipulação de arquivos e implementação de algoritmos de ordenação.

O programa permite cadastrar números em um arquivo, visualizar os valores armazenados, escolher um algoritmo de ordenação e salvar o resultado em um novo arquivo.

## ⚙️ Funcionalidades

- Cadastro de até 100 números inteiros.
- Armazenamento dos valores em `dados.txt`.
- Leitura e exibição dos números cadastrados.
- Escolha entre cinco algoritmos de ordenação.
- Salvamento dos números ordenados em `ordenado.txt`.
- Alteração de valores diretamente no arquivo original.
- Possibilidade de ordenar novamente após as alterações.

## 🔢 Algoritmos de ordenação

O usuário pode escolher entre cinco métodos:

| Algoritmo | Funcionamento |
|---|---|
| Bubble Sort | Compara elementos vizinhos e troca suas posições quando necessário. |
| Insertion Sort | Insere cada elemento na posição correta dentro da parte já ordenada. |
| Selection Sort | Encontra o menor elemento e o coloca na próxima posição. |
| Merge Sort | Divide a lista em partes menores e depois combina os elementos em ordem. |
| Quick Sort | Utiliza um pivô para separar os elementos menores e maiores. |

Todos os métodos organizam os números em ordem crescente, mas utilizam estratégias diferentes.

## 🗂️ Arquivos utilizados

O programa trabalha com dois arquivos de texto:

- `dados.txt`: armazena os números cadastrados e permite alterações.
- `ordenado.txt`: recebe os números após a execução do algoritmo escolhido.

## 🖥️ Menu do programa

Ao iniciar, o programa apresenta as seguintes opções:

```text
========== MENU PRINCIPAL ==========
[1] Mostrar numeros do arquivo
[2] Ordenar numeros
[3] Alterar um numero do arquivo
[4] Sair
```

Ao escolher a opção de ordenação, o usuário pode selecionar um dos cinco algoritmos disponíveis.

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Manipulação de arquivos (`fopen`, `fscanf`, `fprintf` e `fclose`)
- Vetores
- Funções
- Estruturas de repetição e decisão
- Algoritmos de ordenação

## ▶️ Como executar

É necessário ter um compilador C instalado, como o GCC.

**1. Clone o repositório:**

```bash
git clone https://github.com/SEU-USUARIO/SEU-REPOSITORIO.git
```

**2. Entre na pasta do projeto:**

```bash
cd SEU-REPOSITORIO
```

**3. Compile o programa:**

```bash
gcc main.c -o ordenacao
```

**4. Execute:**

No Windows:

```bash
ordenacao.exe
```

No Linux:

```bash
./ordenacao
```

## 🎯 Objetivo do projeto

Praticar os fundamentos da linguagem C por meio de um sistema que reúne manipulação de arquivos, organização de dados e implementação de diferentes algoritmos de ordenação, permitindo observar como cada método resolve o mesmo problema utilizando abordagens distintas.
