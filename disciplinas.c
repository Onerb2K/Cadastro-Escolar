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
            Disciplinas[qtdDisciplinas].qtdAlunos = 0;
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

void adicionaAluno(disciplina *Disciplinas, cadastros *Alunos)
{
    int codigo = 0;
    int matricula = 0;
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int qtdAlunos;
    cadastros Aluno;
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
        scanf("%i", &matricula);
        qtdAlunos = Disciplinas[id_disciplina].qtdAlunos;
        for (int i = 0; i <= (sizeof(Alunos) / sizeof(Alunos[0])) + 1; i++)
        {
            if (Alunos[i].aluno.matricula == matricula)
            {
                achou2 = 1;
                Aluno = Alunos[i];
                break;
            }
        }
        if (achou2 == 1)
        {
            printf("%i", Disciplinas[id_disciplina].qtdAlunos);
            Disciplinas[id_disciplina].alunos[qtdAlunos] = Aluno;
            Disciplinas[id_disciplina].qtdAlunos++;
            printf("%i", Disciplinas[id_disciplina].qtdAlunos);
            printf("\nAluno cadastrado com sucesso.\n");
            return;
        }
        else
        {
            printf("\nMatricula nao encontrada.\n");
            return;
        }
    }
    else
    {
        printf("\nDisciplina nao existe.\n");
        return;
    }
};

void removeAluno(disciplina *Disciplinas, cadastros *Alunos)
{
    int codigo = 0;
    int matricula = 0;
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int id_aluno = 0;
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
        scanf("%i", &matricula);
        for (int i = 0; i <= (sizeof(Alunos) / sizeof(Alunos[0])) + 1; i++)
        {
            if (Alunos[i].aluno.matricula == matricula)
            {
                achou2 = 1;
                id_aluno = i;
                break;
            }
        }
        if (achou2 == 1)
        {
            for (int i = id_aluno; i <= (sizeof(Alunos) / sizeof(Alunos[0])) + 1; i++)
            {
                if (i < (sizeof(Alunos) / sizeof(Alunos[0])) + 1)
                {
                    Disciplinas[id_disciplina].alunos[i] = Disciplinas[id_disciplina].alunos[i + 1];
                }
                else
                {
                    Disciplinas[id_disciplina].alunos[i] = EmptyStruct;
                }
            }
            printf("\nAluno removido com sucesso.\n");
            return;
        }
        else
        {
            printf("\nMatricula nao encontrada.\n");
            return;
        }
    }
    else
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }
};

void exibeDisciplina(disciplina *Disciplinas)
{
    int codigo = 0;
    int achou = 0;
    int id_disciplina = 0;
    scanf("%i", &codigo);

    for (int i = 0; i < (sizeof(Disciplinas) / sizeof(Disciplinas[0]))+1; i++)
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
        printf("%i\n", Disciplinas[id_disciplina].codigo);
        printf("%s\n", Disciplinas[id_disciplina].nome);
        printf("%s\n", Disciplinas[id_disciplina].professordisciplina.nome);
        for (int i = 0; i < Disciplinas[id_disciplina].qtdAlunos; i++)
        {
            printf("%i ", Disciplinas[id_disciplina].alunos[i].aluno.matricula);
            printf("%s", Disciplinas[id_disciplina].alunos[i].nome);
        }
        return;
    }
    else
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }
};

int main(int argc, char const *argv[])
{
    escola escola;
    int controle = 0;
    escola.qtdDisciplinas = 0;
    int resultado = 0;

    strcpy(escola.professores[0].nome, "marcos");
    strcpy(escola.professores[0].sobrenome, "sousa");
    escola.professores[0].nacionalidade = 1;
    escola.professores[0].brasileiro.cpf = 111111111;
    escola.professores[0].brasileiro.rg = 1111111;
    escola.professores[0].dia = 26;
    escola.professores[0].mes = 8;
    escola.professores[0].ano = 1999;
    escola.professores[0].pnet = 0;
    escola.professores[0].cep = 1111111;
    strcpy(escola.professores[0].endereco, "q300 cj52 cs12");
    escola.professores[0].tipo = 1;
    escola.professores[0].professor.pis = 11111;

    strcpy(escola.professores[1].nome, "laura");
    strcpy(escola.professores[1].sobrenome, "evelyn");
    escola.professores[1].nacionalidade = 1;
    escola.professores[1].brasileiro.cpf = 222222222;
    escola.professores[1].brasileiro.rg = 2222222;
    escola.professores[1].dia = 20;
    escola.professores[1].mes = 10;
    escola.professores[1].ano = 2000;
    escola.professores[1].pnet = 0;
    escola.professores[1].cep = 22222222;
    strcpy(escola.professores[1].endereco, "q300 cj52 cs12");
    escola.professores[1].tipo = 1;
    escola.professores[1].professor.pis = 22222;

    strcpy(escola.alunos[0].nome, "marcos");
    strcpy(escola.alunos[0].sobrenome, "sousa");
    escola.alunos[0].nacionalidade = 1;
    escola.alunos[0].brasileiro.cpf = 333333333;
    escola.alunos[0].brasileiro.rg = 3333333;
    escola.alunos[0].dia = 26;
    escola.alunos[0].mes = 8;
    escola.alunos[0].ano = 1999;
    escola.alunos[0].pnet = 0;
    escola.alunos[0].cep = 33333333;
    strcpy(escola.alunos[0].endereco, "q300 cj52 cs12");
    escola.alunos[0].tipo = 1;
    escola.alunos[0].aluno.matricula = 12345;

    do
    {
        printf("\nSistema de Disciplinas-------------\n1 - Cadastrar disciplina\n2 - Alterar professor de uma disciplina\n3 - Adicionar um aluno a uma disciplina\n4 - Remover aluno de uma disciplina\n5 - Exibir dados de uma disciplina\n6 - Voltar ao menu principal\n");
        scanf("%i", &controle);
        switch (controle)
        {
        case 1:
            resultado = cadastraDisciplina(escola.professores, escola.disciplinas, escola.qtdDisciplinas);
            if (resultado == 1)
            {
                escola.qtdDisciplinas++;
            }
            break;

        case 2:
            alteraDisciplina(escola.professores, escola.disciplinas);
            break;

        case 3:
            adicionaAluno(escola.disciplinas, escola.alunos);
            break;

        case 4:
            removeAluno(escola.disciplinas, escola.alunos);
            break;

        case 5:
            exibeDisciplina(escola.disciplinas);
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
