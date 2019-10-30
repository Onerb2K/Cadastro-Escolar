#include <stdio.h>

typedef struct Brasileiro
{
    int cpf;
    int rg;
} brasileiro;

typedef struct Estrangeiro
{
    char passaporte[10];
    char pais_orig[20];
} estrangeiro;

typedef struct PNE
{
    int laudo;
} pne;

typedef struct Aluno
{
    int matricula;
} aluno;

typedef struct Professor
{
    int pis;
} professor;

typedef struct Cadastro
{
    char nome[15];
    char sobrenome[30];
    int nacionalidade;
    union {
        brasileiro brasileiro;
        estrangeiro estrangeiro;
    };
    int tipo;
    union {
        aluno aluno;
        professor professor;
    };
    int pnet;
    union {
        pne pne;
    };
    int dia;
    int mes;
    int ano;
    int cep;
    char endereco[200];
} cadastros;

typedef struct Disciplina
{
    int codigo;
    char nome[30];
    int carga;

} disciplina;

typedef struct Escola
{
    disciplina disciplinas[10];
} escola;
