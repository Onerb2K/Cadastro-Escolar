#include <stdio.h>
#include <string.h>
#include "estruturas.h"

//cadastros cs;
void cadastrar(cadastros pessoa[], int *qtda)
{
    char dia[3];
    char mes[3];
    char ano[5];
    if (*qtda > 19)
    {
        printf("Limite maximo de pessoas alcancadas, encerrando cadastro... \n");
        return;
    }
    pessoa[*qtda].nacionalidade = 3;
    pessoa[*qtda].dia = 32;
    pessoa[*qtda].mes = 13;
    pessoa[*qtda].pnet = 3;
    pessoa[*qtda].cep = 1;
    pessoa[*qtda].tipo = 3;
    char aux1[20];
    getchar();
    scanf("%[^;]s", pessoa[*qtda].nome);
    getchar();
    printf("%s", pessoa[*qtda].nome);
    scanf("%[^;]s", pessoa[*qtda].sobrenome);
    getchar();
    printf("%s", pessoa[*qtda].sobrenome);
    while (pessoa[*qtda].nacionalidade < 0 || pessoa[*qtda].nacionalidade > 1)
    {
        scanf("%d;", &pessoa[*qtda].nacionalidade);
        printf("%d", pessoa[*qtda].nacionalidade);
        if (pessoa[*qtda].nacionalidade < 0 || pessoa[*qtda].nacionalidade > 1)
        {
            printf("nacionalidade invalida, Digite novamente:\n");
        }
        if (pessoa[*qtda].nacionalidade == 0)
        {
            scanf("%[^;]", pessoa[*qtda].brasileiro.cpf);
            getchar();
            printf("%s", pessoa[*qtda].brasileiro.cpf);
            if (strlen(pessoa[*qtda].brasileiro.cpf) < 11 || strlen(pessoa[*qtda].brasileiro.rg) > 11)
            {
                printf("RG invalido! Digite novamente:\n");
            }
            scanf("%[^;]", pessoa[*qtda].brasileiro.rg);
            getchar();
            printf("%s", pessoa[*qtda].brasileiro.rg);
            if (strlen(pessoa[*qtda].brasileiro.rg) < 9 || strlen(pessoa[*qtda].brasileiro.rg) > 9)
            {
                printf("CPF invalido! Digite novamente:\n");
            }
        }
        if (pessoa[*qtda].nacionalidade == 1)
        {
            scanf("%[^;]s", pessoa[*qtda].estrangeiro.passaporte);
            getchar();
            scanf("%[^;]s", &pessoa[*qtda].estrangeiro.pais_orig);
            getchar();
        }
    }
    while (pessoa[*qtda].mes > 12 || pessoa[*qtda].dia > 31)
    {
        scanf("%[^/]s", dia);
        getchar();
        scanf("%[^/]s", mes);
        getchar();
        scanf("%[^;]s", ano);
        getchar();
        pessoa[*qtda].dia = atoi(dia);
        pessoa[*qtda].mes = atoi(mes);
        pessoa[*qtda].ano = atoi(ano);
        printf("Data de nascimento: %d/", pessoa[*qtda].dia);
        printf("%d/", pessoa[*qtda].mes);
        printf("%d\n", pessoa[*qtda].ano);
        if (pessoa[*qtda].dia > 31)
        {
            printf("Dia invalido, digite novamente.\n");
        }
        if (pessoa[*qtda].mes > 12)
        {
            printf("Mes invalido, digite novamente.\n");
        }
        if (pessoa[*qtda].ano > 9999)
        {
            printf("Ano invalido, digite novamente.\n");
        }
    }
    scanf("%d;", &pessoa[*qtda].pnet);
    printf("%d", pessoa[*qtda].pnet);
    if (pessoa[*qtda].pnet == 1)
    {
        scanf("%[^;]s", pessoa[*qtda].pne.laudo);
        getchar();
        printf("%s", pessoa[*qtda].pne.laudo);
    }
    if (pessoa[*qtda].pnet > 1 || pessoa[*qtda].pnet < 0)
    {
        printf("pne invalido! Digite novamente:");
    }
    while (pessoa[*qtda].cep < 10000000 || pessoa[*qtda].cep > 99999999)
    {
        scanf("%d;", &pessoa[*qtda].cep);
        printf("%d", pessoa[*qtda].cep);
        if (pessoa[*qtda].cep < 10000000 || pessoa[*qtda].cep > 99999999)
        {
            printf("CEP invalido! Digite novamente:\n");
        }
    }
    scanf("%[^;]s", pessoa[*qtda].endereco);
    getchar();
    printf("%s", pessoa[*qtda].endereco);
    while (pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1)
    {
        scanf("%d;", &pessoa[*qtda].tipo);
        printf("%d", pessoa[*qtda].tipo);
        if (pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1)
        {
            printf("tipo de pessoa inválido! Digite novamente:\n");
        }
        if (pessoa[*qtda].tipo == 1)
        {
            scanf("%[^\n]s", pessoa[*qtda].professor.pis);
            getchar();
            printf("%s", pessoa[*qtda].professor.pis);
            if (strlen(pessoa[*qtda].professor.pis) < 11 || strlen(pessoa[*qtda].professor.pis) > 11)
            {
                printf("pis invalido! Digite novamente:");
                scanf("%[^\n]s", pessoa[*qtda].professor.pis);
                getchar();
            }
        }
        if (pessoa[*qtda].tipo == 0)
        {
            pessoa[*qtda].aluno.matricula = 19000 + 1 + *qtda;
            printf("%ld", pessoa[*qtda].aluno.matricula);
        }
    }
    printf("cpf: %s", pessoa[*qtda].brasileiro.cpf);
    (*qtda)++;
}

void removerpessoa(cadastros pessoa[], int *qtda)
{
    char nremov[30];
    int pos = 0, i;
    printf("Digite o nome do aluno que deseja remover: \n");
    getchar();
    scanf("%[^\n]s", nremov);
    getchar();
    for (i = 0; i < *qtda; i++)
    {
        if (strcmp(nremov, pessoa[i].nome) == 0)
        {
            printf("Aluno encontrado!\n");
            pos = i;
            (*qtda)--;
            for (i = pos; i < *qtda; i++)
            {
                pessoa[i] = pessoa[i + 1];
            }
        }
        else
        {
            pos = -1;
        }
    }
    if (pos == -1)
    {
        printf("Pessoa nao cadastrada!\n");
        return;
    }
    printf("A pessoa %s, posicao %d foi deletada\n", pessoa[pos].nome, pos);
}

void exibirdados(cadastros pessoa[], int *qtda)
{
    printf("Exibindo dados \n");
    for (int i = 0; i < *qtda; i++)
    {
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Sobrenome: %s \n", pessoa[i].sobrenome);
        printf("Data de nascimento: %d/", pessoa[i].dia);
        printf("%d/", pessoa[i].mes);
        printf("%d\n", pessoa[i].ano);
        if (pessoa[i].nacionalidade == 0)
        {
            printf("Brasileiro\n");
            printf("CPF: %s\n", pessoa[i].brasileiro.cpf);
            printf("RG: %s\n", pessoa[i].brasileiro.rg);
        }
        if (pessoa[i].nacionalidade == 1)
        {
            printf("Pais de origem: %s\n", pessoa[i].estrangeiro.pais_orig);
            printf("Numero do passaporte: %s\n", pessoa[i].estrangeiro.passaporte);
        }
        if (pessoa[i].pnet == 1)
        {
            printf("Codigo do laudo medico: %s\n", pessoa[i].pne.laudo);
        }
        printf("CEP: %d\n", pessoa[i].cep);
        printf("Endereco: %s\n", pessoa[i].endereco);
        if (pessoa[i].tipo == 0)
        {
            printf("Matricula: %d\n", pessoa[i].aluno.matricula);
        }
        if (pessoa[i].tipo == 1)
        {
            printf("PIS: %s\n", pessoa[i].professor.pis);
        }
    }
}

void exibe(cadastros pessoa[], int *qtda, int pos)
{
    printf("Nome: %s\n", pessoa[pos].nome);
    printf("Sobrenome: %s \n", pessoa[pos].sobrenome);
    printf("Data de nascimento: %d/", pessoa[pos].dia);
    printf("%d/", pessoa[pos].mes);
    printf("%d\n", pessoa[pos].ano);
    if (pessoa[pos].nacionalidade == 0)
    {
        printf("Brasileiro\n");
        printf("CPF: %d\n", pessoa[pos].brasileiro.cpf);
        printf("RG: %d\n", pessoa[pos].brasileiro.rg);
    }
    if (pessoa[pos].nacionalidade == 1)
    {
        printf("Pais de origem: %s\n", pessoa[pos].estrangeiro.pais_orig);
        printf("Numero do passaporte: %s\n", pessoa[pos].estrangeiro.passaporte);
    }
    if (pessoa[pos].pnet == 1)
    {
        printf("Codigo do laudo medico: %d\n", pessoa[pos].pne.laudo);
    }
    printf("CEP: %d\n", pessoa[pos].cep);
    printf("Endereco: %s\n", pessoa[pos].endereco);
    if (pessoa[pos].tipo == 0)
    {
        printf("Matricula: %d\n", pessoa[pos].aluno.matricula);
    }
    if (pessoa[pos].tipo == 1)
    {
        printf("PIS: %d\n", pessoa[pos].professor.pis);
    }
}

void alterarDados(cadastros *Pessoas)
{
    int tipo;
    long matricula;
    char pis[11];
    int achou;
    int controle;
    int id_pessoa;
    int pnet;
    char laudo[30];
    int cep;
    char endereco[200];
    scanf("%i", &tipo);
    if (tipo == 1 || tipo == 0)
    {
        if (tipo == 0)
        {
            scanf("%ld", matricula);
            for (int i = 0; i <= sizeof(Pessoas) / sizeof(Pessoas[0]); i++)
            {
                if (Pessoas[i].aluno.matricula == matricula)
                {
                    achou = 1;
                    id_pessoa = i;
                    break;
                }
            }
            if (achou)
            {
                scanf("%i", &controle);
                switch (controle)
                {
                case 1:
                    scanf("%i", pnet);
                    if (pnet == 1 || pnet == 0)
                    {
                        if (Pessoas[id_pessoa].pnet != pnet)
                        {
                            if (pnet == 1)
                            {
                                scanf("%s", Pessoas[id_pessoa].pne.laudo);
                            }
                            else
                            {
                                strcpy(Pessoas[id_pessoa].pne.laudo, NULL);
                            }
                        }
                        else
                        {
                            printf("\nStatus ja presente no sistema.\n");
                        }
                    }
                    else
                    {
                        printf("\nValor Invalido.\n");
                    }
                    break;

                case 2:
                    if (Pessoas[id_pessoa].pnet == 1)
                    {
                        scanf("%30s", laudo);
                        strcpy(Pessoas[id_pessoa].pne.laudo, laudo);
                    }
                    else
                    {
                        printf("\nO aluno não é PNE.\n");
                    }
                    break;

                case 3:
                    scanf("%i", &cep);
                    Pessoas[id_pessoa].cep = cep;
                    break;

                case 4:
                    scanf("%200[^\n]", endereco);
                    strcpy(Pessoas[id_pessoa].endereco, endereco);
                    break;

                default:
                    break;
                }
            }
            else
            {
                printf("\nAluno nao encontrado.\n");
                return;
            }
        }

        if (tipo == 1)
        {
            scanf("%11s", pis);
            for (int i = 0; i <= sizeof(Pessoas) / sizeof(Pessoas[0]); i++)
            {
                if (Pessoas[i].professor.pis == pis)
                {
                    achou = 1;
                    id_pessoa = i;
                    break;
                }
            }
            if (achou)
            {
                scanf("%i", &controle);
                switch (controle)
                {
                case 1:
                    scanf("%i", pnet);
                    if (pnet == 1 || pnet == 0)
                    {
                        if (Pessoas[id_pessoa].pnet != pnet)
                        {
                            if (pnet == 1)
                            {
                                scanf("%s", Pessoas[id_pessoa].pne.laudo);
                            }
                            else
                            {
                                strcpy(Pessoas[id_pessoa].pne.laudo, NULL);
                            }
                        }
                        else
                        {
                            printf("\nStatus ja presente no sistema.\n");
                        }
                        
                    }
                    else
                    {
                        printf("\nValor Invalido.\n");
                    }
                    break;

                case 2:
                    if (Pessoas[id_pessoa].pnet == 1)
                    {
                        scanf("%30s", laudo);
                        strcpy(Pessoas[id_pessoa].pne.laudo, laudo);
                    }
                    else
                    {
                        printf("\nO professor não é PNE.\n");
                    }
                    break;

                case 3:
                    scanf("%i", &cep);
                    Pessoas[id_pessoa].cep = cep;
                    break;

                case 4:
                    scanf("%200[^\n]", endereco);
                    strcpy(Pessoas[id_pessoa].endereco, endereco);
                    break;

                default:
                    break;
                }
            }
            else
            {
                printf("\nProfessor nao encontrado.\n");
                return;
            }
        }
    }
    else
    {
        printf("\nValor invalido.\n");
        return;
    }
}

void help()
{
    printf("Comandos validos: \n");
    printf(" 1 para cadastrar\n");
    printf(" 2 para remover \n");
    printf(" 3 para exibir dados\n");
    printf(" 4 mensagem de ajuda \n");
    printf(" 5 sair do programa\n");
}

void main()
{
    help();
    cadastros pessoa[20];
    int qtda = 0;
    int comando;

    printf("Digite a opcao que deseja\n");
    scanf("%d", &comando);

    while (comando != 5)
    {
        switch (comando)
        {
        case 1:
            cadastrar(pessoa, &qtda);
            break;
        case 2:
            removerpessoa(pessoa, &qtda);
            break;
        case 3:
            exibirdados(pessoa, &qtda);
            break;
        case 4:
            help();
            break;
        default:
        {
            while (comando != '\n')
                scanf("%d", &comando);
        };
        }
        scanf("%d", &comando);
    }
}