#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

int cadastraDisciplina(cadastros *Pessoas, disciplina *Disciplinas, int qtdDisciplinas)
{
    char pis[11];
    int codigo = 0;
    char nome[30];
    int carga = 0;
    int achou = 0;
    int idprofessor = 0;
    if (qtdDisciplinas < 10)
    {
        printf("\nDigite o codigo, o nome, a carga horaria e o PIS do professor da materia (codigo;nome;carga.pis): \n");
        scanf("%i;%15[^;];%i;%s", &codigo, nome, &carga, pis);
        printf("%s\n", nome);
        printf("%i\n", codigo);
        printf("%i\n", carga);
        printf("%s\n", pis);
        printf("%s\n", Pessoas[qtdDisciplinas].professor.pis);

        for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 1; i++)
        {
            if (atoi(Pessoas[i].professor.pis) == atoi(pis))
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
            Disciplinas[qtdDisciplinas].professordisciplina = Pessoas[idprofessor];
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

void alteraDisciplina(cadastros *Pessoas, disciplina *Disciplinas)
{
    int codigo = 0;
    char pis[11];
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int id_professor = 0;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i <= (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
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
        printf("\nDigite o pis do novo professor da Disciplina: \n");
        scanf("%11s", pis);
        for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 1; i++)
        {
            if (atoi(Pessoas[i].professor.pis) == atoi(pis))
            {
                achou2 = 1;
                id_professor = i;
                break;
            }
        }
        if (achou2 == 1)
        {
            Disciplinas[id_disciplina].professordisciplina = Pessoas[id_professor];
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

void adicionaAluno(disciplina *Disciplinas, cadastros *Pessoas)
{
    int codigo = 0;
    long int matricula = 0;
    int achou = 0;
    int achou2 = 0;
    int existe = 0;
    int id_disciplina = 0;
    int qtdAlunos;
    cadastros Aluno;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i <= (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
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
        printf("\nDigite a matricula do aluno que deseja adicionar a materia: \n");
        scanf("%ld", &matricula);
        qtdAlunos = Disciplinas[id_disciplina].qtdAlunos;
        for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 2; i++)
        {
            if (Pessoas[i].aluno.matricula == matricula)
            {
                achou2 = 1;
                Aluno = Pessoas[i];
                break;
            }
        }
        if (achou2 == 1)
        {
            for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 2; i++)
            {
                if (Disciplinas[id_disciplina].alunos[i].aluno.matricula == matricula)
                {
                    existe = 1;
                    break;
                }
            }

            if (existe == 0)
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
                printf("\nAluno já cadastrado.\n");
                return;
            }
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

void removeAluno(disciplina *Disciplinas, cadastros *Pessoas)
{
    int codigo = 0;
    long int matricula = 0;
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int id_aluno = 0;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i <= (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
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
        printf("\nDigite a matricula do aluno a ser removido: \n");
        scanf("%ld", &matricula);
        for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 2; i++)
        {
            if (Pessoas[i].aluno.matricula == matricula)
            {
                achou2 = 1;
                id_aluno = i;
                break;
            }
        }
        if (achou2 == 1)
        {
            for (int i = id_aluno; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 2; i++)
            {
                if (i < (sizeof(Pessoas) / sizeof(Pessoas[0])) + 1)
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
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i < (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
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
        printf("\nCodigo da Disciplina: ");
        printf("%i\n", Disciplinas[id_disciplina].codigo);
        printf("\nNome da Disciplina: ");
        printf("%s\n", Disciplinas[id_disciplina].nome);
        printf("\nProfessor da Disciplina: ");
        printf("%s ", Disciplinas[id_disciplina].professordisciplina.nome);
        printf("%s\n", Disciplinas[id_disciplina].professordisciplina.sobrenome);
        printf("\nAlunos da Disciplina: ");
        for (int i = 0; i < Disciplinas[id_disciplina].qtdAlunos; i++)
        {
            printf("%ld ", Disciplinas[id_disciplina].alunos[i].aluno.matricula);
            printf("%s\n", Disciplinas[id_disciplina].alunos[i].nome);
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

    strcpy(escola.pessoas[0].nome, "marcos");
    strcpy(escola.pessoas[0].sobrenome, "sousa");
    escola.pessoas[0].nacionalidade = 1;
    strcpy(escola.pessoas[0].brasileiro.cpf, "11111111111");
    strcpy(escola.pessoas[0].brasileiro.rg, "111111111");
    escola.pessoas[0].dia = 26;
    escola.pessoas[0].mes = 8;
    escola.pessoas[0].ano = 1999;
    escola.pessoas[0].pnet = 0;
    escola.pessoas[0].cep = 1111111;
    strcpy(escola.pessoas[0].endereco, "q300 cj52 cs12");
    escola.pessoas[0].tipo = 1;
    strcpy(escola.pessoas[0].professor.pis, "11111");

    strcpy(escola.pessoas[1].nome, "laura");
    strcpy(escola.pessoas[1].sobrenome, "evelyn");
    escola.pessoas[1].nacionalidade = 1;
    strcpy(escola.pessoas[1].brasileiro.cpf, "22222222222");
    strcpy(escola.pessoas[1].brasileiro.rg, "222222222");
    escola.pessoas[1].dia = 20;
    escola.pessoas[1].mes = 10;
    escola.pessoas[1].ano = 2000;
    escola.pessoas[1].pnet = 0;
    escola.pessoas[1].cep = 22222222;
    strcpy(escola.pessoas[1].endereco, "q300 cj52 cs12");
    escola.pessoas[1].tipo = 1;
    strcpy(escola.pessoas[1].professor.pis, "22222");

    strcpy(escola.pessoas[2].nome, "marcos");
    strcpy(escola.pessoas[2].sobrenome, "sousa");
    escola.pessoas[2].nacionalidade = 1;
    strcpy(escola.pessoas[2].brasileiro.cpf, "33333333333");
    strcpy(escola.pessoas[2].brasileiro.rg, "333333333");
    escola.pessoas[2].dia = 26;
    escola.pessoas[2].mes = 8;
    escola.pessoas[2].ano = 1999;
    escola.pessoas[2].pnet = 0;
    escola.pessoas[2].cep = 33333333;
    strcpy(escola.pessoas[2].endereco, "q300 cj52 cs12");
    escola.pessoas[2].tipo = 1;
    escola.pessoas[2].aluno.matricula = 12345;

    do
    {
        printf("\nSistema de Disciplinas-------------\n1 - Cadastrar disciplina\n2 - Alterar professor de uma disciplina\n3 - Adicionar um aluno a uma disciplina\n4 - Remover aluno de uma disciplina\n5 - Exibir dados de uma disciplina\n6 - Voltar ao menu principal\n");
        scanf("%i", &controle);
        switch (controle)
        {
        case 1:
            resultado = cadastraDisciplina(escola.pessoas, escola.disciplinas, escola.qtdDisciplinas);
            if (resultado == 1)
            {
                escola.qtdDisciplinas++;
            }
            break;

        case 2:
            alteraDisciplina(escola.pessoas, escola.disciplinas);
            break;

        case 3:
            adicionaAluno(escola.disciplinas, escola.pessoas);
            break;

        case 4:
            removeAluno(escola.disciplinas, escola.pessoas);
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
