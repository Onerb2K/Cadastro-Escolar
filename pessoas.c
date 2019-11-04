#include <stdio.h>
#include <string.h>
#include "estruturas.h"

//cadastros cs;
void cadastrar(cadastros pessoa[], int *qtda, int *qtda_al, int *qtda_prof)
{
    char dia[3];
    char mes[3];
    char ano[5];
    if(*qtda_al >=50 || *qtda_prof >=10)
    {
        printf("Limite maximo de pessoas alcancadas, encerrando cadastro... \n");
        return;
    }
    pessoa[*qtda].nacionalidade=3;
    pessoa[*qtda].dia=32;
    pessoa[*qtda].mes=13;
    pessoa[*qtda].pnet=3;
    pessoa[*qtda].cep=1;
    pessoa[*qtda].tipo=3;
    char aux1[20];
    getchar();
    scanf("%[^;]s",pessoa[*qtda].nome);
    getchar();
    scanf("%[^;]s",pessoa[*qtda].sobrenome);
    getchar();
    while(pessoa[*qtda].nacionalidade < 0 || pessoa[*qtda].nacionalidade > 1)
    {
        scanf("%d;", &pessoa[*qtda].nacionalidade);
        if(pessoa[*qtda].nacionalidade<0 || pessoa[*qtda].nacionalidade>1)
        {
            printf("nacionalidade invalida, Digite novamente:\n");
        }
        if(pessoa[*qtda].nacionalidade==0)
        {
            scanf("%[^;]s", pessoa[*qtda].brasileiro.cpf);
            getchar();
            if(strlen(pessoa[*qtda].brasileiro.cpf)<11 || strlen(pessoa[*qtda].brasileiro.cpf)>11)
            {
                printf("CPF invalido! Digite novamente:\n");
            }
            scanf("%[^;]s", pessoa[*qtda].brasileiro.rg);
            getchar();
            if(strlen(pessoa[*qtda].brasileiro.rg)<9 || strlen(pessoa[*qtda].brasileiro.rg)>9)
            {
                printf("RG invalido! Digite novamente:\n");
            }
        }
        if(pessoa[*qtda].nacionalidade==1)
        {
            scanf("%[^;]s", pessoa[*qtda].estrangeiro.passaporte);
            getchar();
            scanf("%[^;]s", &pessoa[*qtda].estrangeiro.pais_orig);
            getchar();
        }
    }
    while(pessoa[*qtda].mes>12 || pessoa[*qtda].dia>31)
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
        if(pessoa[*qtda].dia>31)
        {
            printf("Dia invalido, digite novamente.\n");
        }
        if(pessoa[*qtda].mes>12)
        {
            printf("Mes invalido, digite novamente.\n");
        }
        if(pessoa[*qtda].ano>9999)
        {
            printf("Ano invalido, digite novamente.\n");
        }
    }
    scanf("%d;", &pessoa[*qtda].pnet);
    if(pessoa[*qtda].pnet==1)
    {
        scanf("%[^;]s", pessoa[*qtda].pne.laudo);
        getchar();
    }
    if(pessoa[*qtda].pnet>1 || pessoa[*qtda].pnet<0)
    {
        printf("pne invalido! Digite novamente:");
    }
    while(pessoa[*qtda].cep<10000000 || pessoa[*qtda].cep>99999999)
    {
        scanf("%d;", &pessoa[*qtda].cep);
        if(pessoa[*qtda].cep<10000000 || pessoa[*qtda].cep>99999999)
        {
            printf("CEP invalido! Digite novamente:\n");
        }
    }
    scanf("%[^;]s", pessoa[*qtda].endereco);
    getchar();
    while(pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1)
    {
        scanf("%d;", &pessoa[*qtda].tipo);
        if(pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1)
        {
            printf("tipo de pessoa inválido! Digite novamente:\n");
        }
        if(pessoa[*qtda].tipo==1)
        {
            (*qtda_prof)++;
            scanf("%[^\n]s", pessoa[*qtda].professor.pis);
            getchar();
            if(strlen(pessoa[*qtda].professor.pis)<11 || strlen(pessoa[*qtda].professor.pis)>11)
            {
                printf("pis invalido! Digite novamente:");
                scanf("%[^\n]s", pessoa[*qtda].professor.pis);
                getchar();
            }
        }
        if(pessoa[*qtda].tipo==0)
        {
            pessoa[*qtda].aluno.matricula=19000+*qtda_al;
            (*qtda_al)++;
        }
    }
    (*qtda)++;
}

void removerpessoa(cadastros pessoa[], int *qtda)
{
    char nremov[30];
    int pos=0,i;
    printf("Digite o nome do aluno que deseja remover: \n");
    getchar();
    scanf("%[^\n]s",nremov);
    getchar();
    for(i = 0 ; i < *qtda; i++)
    {
        if(strcmp(nremov, pessoa[i].nome)== 0)
        {
            printf("Aluno encontrado!\n");
            pos = i;
            (*qtda)--;
            for(i = pos; i < *qtda; i++)
            {
                pessoa[i] = pessoa[i+1];
            }
        }
        else
        {
            pos = -1;
        }
    }
    if(pos == -1)
    {
        printf("Pessoa nao cadastrada!\n");
        return;
    }
    printf("A pessoa %s, posicao %d foi deletada\n",pessoa[pos].nome,pos);
}

void exibirdados(cadastros pessoa[], int *qtda)
{
    printf("Exibindo dados \n");
    for(int i = 0; i < *qtda; i++)
    {
        printf("Nome: %s\n",pessoa[i].nome);
        printf("Sobrenome: %s \n",pessoa[i].sobrenome);
        printf("Data de nascimento: %d/",pessoa[i].dia);
        printf("%d/",pessoa[i].mes);
        printf("%d\n",pessoa[i].ano);
        if(pessoa[i].nacionalidade==0)
        {
            printf("Brasileiro\n");
            printf("CPF: %s\n", pessoa[i].brasileiro.cpf);
            printf("RG: %s\n", pessoa[i].brasileiro.rg);
        }
        if(pessoa[i].nacionalidade==1)
        {
            printf("Pais de origem: %s\n", pessoa[i].estrangeiro.pais_orig);
            printf("Numero do passaporte: %s\n", pessoa[i].estrangeiro.passaporte);
        }
        if(pessoa[i].pnet==1)
        {
            printf("Codigo do laudo medico: %s\n", pessoa[i].pne.laudo);

        }
        printf("CEP: %d\n", pessoa[i].cep);
        printf("Endereco: %s\n", pessoa[i].endereco);
        if(pessoa[i].tipo==0)
        {
            printf("Matricula: %d\n", pessoa[i].aluno.matricula);
        }
        if(pessoa[i].tipo==1)
        {
            printf("PIS: %s\n", pessoa[i].professor.pis);
        }
    }
}

void alterarDados(cadastros pessoa[], int *qtda)
{
    int tipo;
    long int matricula;
    char pis[11];
    int achou;
    int controle;
    int id_pessoa;
    int pnet ;
    char laudo[30];
    int cep;
    char endereco[200];
    printf("\nAluno ou Professor?\n");
    scanf("%i", &tipo);
    if (tipo == 1 || tipo == 0)
    {
        if (tipo == 0)
        {
            printf("\nDigite a matricula: \n");
            scanf("%ld",&matricula);
            for (int i = 0; i <= *qtda; i++){
                if (pessoa[i].aluno.matricula == matricula)
                {
                    achou = 1;
                    id_pessoa = i;
                    break;
                }
                }
            if (achou == 1)
            {
                printf("\n1 - Portador de Necessidades especiais?\n2 - Codigo do laudo medico\n3 - CEP\n4 - Endereco\n");
                scanf("%i", &controle);
                switch (controle)
                {
                case 1:
                    printf("\nPNE?\n");
                    scanf("%i", &pnet);
                    if (pnet == 1 || pnet == 0)
                    {
                        if (pessoa[id_pessoa].pnet != pnet)
                        {
                            if (pnet == 1)
                            {
                                pessoa[id_pessoa].pnet = 1;
                                printf("\nDigite o laudo: \n");
                                scanf("%s", pessoa[id_pessoa].pne.laudo);
                            }
                            else if(pnet == 0)
                            {
                                pessoa[id_pessoa].pnet = 0;
                                //strcpy(pessoa[id_pessoa].pne.laudo, NULL);
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
                    if (pessoa[id_pessoa].pnet == 1)
                    {
                        printf("\nDigite o novo laudo: \n");
                        scanf("%30s", laudo);
                        strcpy(pessoa[id_pessoa].pne.laudo, laudo);
                    }
                    else
                    {
                        printf("\nO aluno nao eh PNE.");
                    }
                    break;

                case 3:
                    printf("\nDigite o novo CEP\n");
                    scanf("%i", &cep);
                    pessoa[id_pessoa].cep = cep;
                    break;

                case 4:
                    printf("\nDigite o novo endereco\n");
                    scanf("%[^\n]s", endereco);
                    //strcpy(pessoa[id_pessoa].endereco, endereco);
                    strcpy(endereco,pessoa[id_pessoa].endereco);
                    break;
                default:
                    printf("Comando invalido \n");
                    break;
                }
            }
            else if(achou != 1)
            {
                printf("\nAluno nao encontrado.\n");
                return;
            }
        }
        if (tipo == 1)
        {
            printf("Digite o Pis do professor: \n");
            scanf("%s", pis);
            for (int i = 0; i <= *qtda; i++)
            {
                //if (pessoa[i].professor.pis == pis)
                 if(atoi(pis)==atoi(pessoa[i].professor.pis))
                {
                    achou = 1;
                    id_pessoa = i;
                    break;
                }
            }
            if (achou == 1 )
            {
                printf("\n1 - Portador de Necessidades especiais?\n2 - Codigo do laudo medico\n3 - CEP\n4 - Endereco\n");
                scanf("%i", &controle);
                switch (controle)
                {
                case 1:
                    printf("\nPNE?\n");
                    scanf("%i", &pnet);
                    if (pnet == 1 || pnet == 0)
                    {
                        if (pessoa[id_pessoa].pnet != pnet)
                        {
                            if (pnet == 1)
                            {
                                pessoa[id_pessoa].pnet = 1;
                                printf("\nDigite o laudo: \n");
                                scanf("%s", pessoa[id_pessoa].pne.laudo);
                            }
                             else if(pnet == 0)
                            {
                                pessoa[id_pessoa].pnet = 0;
                                //strcpy(pessoa[id_pessoa].pne.laudo, NULL);
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
                    if (pessoa[id_pessoa].pnet == 1)
                    {
                        printf("\nDigite o novo laudo: \n");
                        scanf("%30s", laudo);
                        strcpy(pessoa[id_pessoa].pne.laudo, laudo);
                    }
                    else
                    {
                        printf("\nO Professor nao eh PNE.");
                    }
                    break;

                case 3:
                    printf("\nDigite o novo CEP\n");
                    scanf("%i", &cep);
                    pessoa[id_pessoa].cep = cep;
                    break;

                case 4:
                    printf("\nDigite o novo endereco\n");
                    scanf("%[^\n]s", endereco);
                    strcpy(pessoa[id_pessoa].endereco, endereco);
                    break;
                default:
                    printf("Comando invalido \n");
                    break;
                }
            }
            else if(achou != 1)
            {
                printf("Professor nao encontrado.\n");
                return;
            }
        }

}
}
void exibe_pessoax(cadastros pessoa[], int *qtda)
{
    int pos=-1;
    char aux[11];
    long int aux2;
    int tipo;
    int i;
    printf("Se a pessoa que deseja exibir for um aluno, digite 0, caso seja um professor, digite 1:");
    scanf("%d", &tipo);
    getchar();
    if(tipo==1){

        printf("Digite o pis do professor:");
        scanf("%s", aux);
        getchar();
        for(i = 0 ; i < *qtda; i++)
        {
            if(atoi(aux)==atoi(pessoa[i].professor.pis))
            {
                printf("professor encontrado!\n");
                pos = i;
            }
        }
    }

    if(tipo==0){

        printf("Digite a matricula do aluno:");
        scanf("%ld", &aux2);
        getchar();
        for(i = 0 ; i < *qtda; i++)
        {
            if(aux2==pessoa[i].aluno.matricula)
            {
                printf("Aluno encontrado!\n");
                pos = i;
            }
        }
    }

    if(pos==-1){
        printf("Pessoa nao encontrada!");
        return;
    }
    printf("Exibindo dados da pessoa, posicao %d:\n", pos);

    printf("Nome: %s\n",pessoa[pos].nome);
    printf("Sobrenome: %s \n",pessoa[pos].sobrenome);
    printf("Data de nascimento: %d/",pessoa[pos].dia);
    printf("%d/",pessoa[pos].mes);
    printf("%d\n",pessoa[pos].ano);
    if(pessoa[pos].nacionalidade==0)
    {
        printf("Brasileiro\n");
        printf("CPF: %s\n", pessoa[pos].brasileiro.cpf);
        printf("RG: %s\n", pessoa[pos].brasileiro.rg);
    }
    if(pessoa[pos].nacionalidade==1)
    {
        printf("Pais de origem: %s\n", pessoa[pos].estrangeiro.pais_orig);
        printf("Numero do passaporte: %s\n", pessoa[pos].estrangeiro.passaporte);
    }
    if(pessoa[pos].pnet==1)
    {
        printf("Codigo do laudo medico: %s\n", pessoa[pos].pne.laudo);

    }
    printf("CEP: %d\n", pessoa[pos].cep);
    printf("Endereco: %s\n", pessoa[pos].endereco);
    if(pessoa[pos].tipo==0)
    {
        printf("Matricula: %d\n", pessoa[pos].aluno.matricula);
    }
    if(pessoa[pos].tipo==1)
    {
        printf("PIS: %s\n", pessoa[pos].professor.pis);
    }
}



void help()
{
    printf("Comandos validos: \n");
    printf(" 1 para cadastrar\n");
    printf(" 2 para remover \n");
    printf(" 3 para exibir todos os dados\n");
    printf(" 4 para exibir dados de uma pessoa especifica\n");
    printf(" 5 alterar dados de uma pessoa especifica\n");
    printf(" 6 mensagem de ajuda \n");
    printf(" 7 sair do programa\n");

}

void main()
{
    help();
    cadastros pessoa[20];
    int qtda=0;
    int qtda_al=0;
    int qtda_prof=0;
    int comando;

    printf("Digite a opcao que deseja\n");
    scanf("%d",&comando);

    while (comando != 7)
    {
        switch (comando)
        {
        case 1 :
            cadastrar(pessoa,&qtda,&qtda_al,&qtda_prof);
            break;
        case 2 :
            removerpessoa(pessoa,&qtda);
            break;
        case 3 :
            exibirdados(pessoa, &qtda);
            break;
        case 4 :
            exibe_pessoax(pessoa, &qtda);
            break;
        case 5 :
            alterarDados(pessoa, &qtda);
            break;
        case 6 :
            help();
            break;
        default:
        {
            while (comando != '\n')
                scanf("%d",&comando);
        };
        }
        scanf("%d",&comando);
    }
}

