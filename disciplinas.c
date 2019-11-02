#include <stdio.h>
#include <string.h>
#include "estruturas.h"

int cadastraDisciplina(cadastros *Professores, disciplina *Disciplinas, int qtdDisciplinas)
{
    int pis = 0;
    int codigo = 0;
    char nome[30];
    int carga = 0;
    int achou = 0;
    int idprofessor = 0;
    if (qtdDisciplinas < 10)
    {
        scanf("%i;%[^;];%i;%i", &codigo, nome, &carga, &pis);
        printf("%s\n", nome);
        printf("%i\n", codigo);
        printf("%i\n", carga);
        printf("%i\n", pis);
        printf("%i\n", Professores[qtdDisciplinas].professor.pis);

        for (int i = 0; i <= sizeof(Professores) / sizeof(Professores[0]); i++)
        {
            if (Professores[i].professor.pis == pis)
            {
                achou = 1;
                idprofessor = i;
                break;
            }
        }
        if (achou == 1)
        {
            Disciplinas[qtdDisciplinas].codigo = codigo;
            strcpy(Disciplinas[qtdDisciplinas].nome, nome);
            Disciplinas[qtdDisciplinas].carga = carga;
            Disciplinas[qtdDisciplinas].professordisciplina = Professores[idprofessor];
            qtdDisciplinas++;
            printf("\nMateria Cadastrada!\n");
            return 1;
        }
        else
        {
            printf("\nProfessor nao encontrado.\n");
            return 0;
        }
    }
    else
    {
        printf("\nNumero maximo de disciplinas atingido.\nNao e possivel inserir mais disciplinas.\n");
        return 0;
    }
};

void alteraDisciplina(cadastros *Professores, disciplina *Disciplinas)
{
    int codigo = 0;
    int pis = 0;
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int id_professor = 0;
    scanf("%i", &codigo);
    for (int i = 0; i <= sizeof(Disciplinas) / sizeof(Disciplinas[0]); i++)
    {
        if (Disciplinas[i].codigo == codigo)
        {
            achou = 1;
            id_disciplina = i;
            break;
        }
    }
    if (achou == 1)
    {
        scanf("%i", &pis);
        for (int i = 0; i <= (sizeof(Professores) / sizeof(Professores[0])) + 1; i++)
        {
            if (Professores[i].professor.pis == pis)
            {
                achou2 = 1;
                id_professor = i;
                break;
            }
        }
        if (achou2 == 1)
        {
            Disciplinas[id_disciplina].professordisciplina = Professores[id_professor];
            printf("\nProfessor da disciplina alterado.\n");
            return;
        }
        else
        {
            printf("\nProfessor nao encontrado.\n");
            return;
        }
        
    }
    else
    {
        printf("\nCodigo de disciplina invalido.\n");
        return;
    }
};

void adicionaAluno(){

};

void removeAluno(){

};

void exibeDisciplina(){

};

int main(int argc, char const *argv[])
{
    cadastros professores[10];
    cadastros alunos[50];
    disciplina disciplinas[10];
    int qtd = 0;
    int controle = 0;
    int qtdDisciplinas = 0;
    int resultado = 0;
    escola Escola;

    strcpy(professores[0].nome, "marcos");
    strcpy(professores[0].sobrenome, "sousa");
    professores[0].nacionalidade = 1;
    professores[0].brasileiro.cpf = 111111111;
    professores[0].brasileiro.rg = 1111111;
    professores[0].dia = 26;
    professores[0].mes = 8;
    professores[0].ano = 1999;
    professores[0].pnet = 0;
    professores[0].cep = 1111111;
    strcpy(professores[0].endereco, "q300 cj52 cs12");
    professores[0].tipo = 1;
    professores[0].professor.pis = 11111;

    strcpy(professores[1].nome, "laura");
    strcpy(professores[1].sobrenome, "evelyn");
    professores[1].nacionalidade = 1;
    professores[1].brasileiro.cpf = 222222222;
    professores[1].brasileiro.rg = 2222222;
    professores[1].dia = 20;
    professores[1].mes = 10;
    professores[1].ano = 2000;
    professores[1].pnet = 0;
    professores[1].cep = 22222222;
    strcpy(professores[1].endereco, "q300 cj52 cs12");
    professores[1].tipo = 1;
    professores[1].professor.pis = 22222;

    do
    {
        printf("\nSistema de Disciplinas-------------\n1 - Cadastrar disciplina\n2 - Alterar professor de uma disciplina\n3 - Adicionar um aluno a uma disciplina\n4 - Remover aluno de uma disciplina\n5 - Exibir dados de uma disciplina\n6 - Voltar ao menu principal\n");
        scanf("%i", &controle);
        switch (controle)
        {
        case 1:
            resultado = cadastraDisciplina(professores, disciplinas, qtdDisciplinas);
            if (resultado == 1)
            {
                qtdDisciplinas++;
            }
            break;

        case 2:
            alteraDisciplina(professores, disciplinas);
            break;

        case 6:
            printf("\nVoltando ao menu.\n");
            break;

        default:
            printf("\nComando Invalido.\n");
            break;
        }
    } while (controle != 6);

    return 0;
}
