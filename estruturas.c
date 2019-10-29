#include <stdio.h>

typedef struct Disciplina
{
    int codigo;
    char nome[30];
    int carga;

}Disciplina;

typedef struct Escola
{
    Disciplina disciplinas[10];
}Escola;
