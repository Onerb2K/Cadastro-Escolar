#include <stdio.h>
#include <string.h>


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
     union{
      brasileiro brasileiro;
      estrangeiro estrangeiro;
     };
     int tipo;
     union{
      aluno aluno;
      professor professor;
     };
     int pnet;
     union{
      pne pne;
     };
     int dia;
     int mes;
     int ano;
     int cep;
     char endereco[200];
    } cadastros ;

    //cadastros cs;
    void cadastrar(cadastros pessoa[], int *qtda )
    {
    char dia[3];
    char mes[3];
    char ano[5];
     if(*qtda > 19){
     printf("Limite maximo de pessoas alcancadas, encerrando cadastro... \n");
     return;
     }
     pessoa[*qtda].nacionalidade=3;
     pessoa[*qtda].dia=32;
     pessoa[*qtda].mes=13;
     pessoa[*qtda].brasileiro.cpf=1;
     pessoa[*qtda].brasileiro.rg=1;
     pessoa[*qtda].pnet=3;
     pessoa[*qtda].cep=1;
     pessoa[*qtda].tipo=3;
     getchar();
     scanf("%[^\n]s;",pessoa[*qtda].nome);
     scanf("%[^\n]s;",pessoa[*qtda].sobrenome);
     while(pessoa[*qtda].nacionalidade < 0 || pessoa[*qtda].nacionalidade > 1)
     {
     scanf("%d", &pessoa[*qtda].nacionalidade);
     getchar();
     if(pessoa[*qtda].nacionalidade<0 || pessoa[*qtda].nacionalidade>1)
     {
     printf("nacionalidade invalida, Digite novamente:\n");
     }
     if(pessoa[*qtda].nacionalidade==0){
         while(pessoa[*qtda].brasileiro.cpf<10000000000 || pessoa[*qtda].brasileiro.cpf>99999999999){
            printf("Digite o numero do CPF de %s:\n", pessoa[*qtda].nome);
            scanf("%d", &pessoa[*qtda].brasileiro.cpf);
             if(pessoa[*qtda].brasileiro.cpf<10000000000 || pessoa[*qtda].brasileiro.cpf>99999999999){
                 printf("CPF invalido! Digite novamente:\n");
             }
         }
         while(pessoa[*qtda].brasileiro.rg<100000000 || pessoa[*qtda].brasileiro.rg>999999999){ 
     printf("Digite o numero do RG de %s:\n", pessoa[*qtda].nome);
     scanf("%d", &pessoa[*qtda].brasileiro.rg);
     if(pessoa[*qtda].brasileiro.rg<100000000 || pessoa[*qtda].brasileiro.rg>999999999){
         printf("RG invalido! Digite novamente:\n");
            }
        }
     }
     if(pessoa[*qtda].nacionalidade==1){
         while(stlen(pessoa[*qtda].estrangeiro.passaporte)<9 || stlen(pessoa[*qtda].estrangeiro.passaporte)>9){
     scanf("%s", pessoa[*qtda].estrangeiro.passaporte);
        }
     printf("Digite o nome do pais de origem de %s:\n", pessoa[*qtda].nome);
     scanf("%[^\n]s", &pessoa[*qtda].estrangeiro.pais_orig);
     }
     }
     while(pessoa[*qtda].mes>12 || pessoa[*qtda].dia>31)
     {
     printf("Digite a data de nascimento DD/MM/AAAA de %s:\n", pessoa[*qtda].nome);
     scanf("%s/%s/%s", dia, mes, ano);
     pessoa[*qtda].dia = atoi(dia);
     pessoa[*qtda].mes = atoi(mes);
     pessoa[*qtda].ano = atoi(ano);
     getchar();
     if(pessoa[*qtda].dia>31)
     {
     printf("Dia invalido, digite novamente.\n");
     }
     if(pessoa[*qtda].mes>12)
     {
     printf("Mes invalido, digite novamente.\n");
     }
     if(pessoa[*qtda].ano>9999){
         printf("Ano invalido, digite novamente.\n");
     }
     }
    while(pessoa[*qtda].pnet < 0 || pessoa[*qtda].pnet > 1){
        printf("%s e portador de necessidades especiais? se sim digite 1, se nao 0:\n", pessoa[*qtda].nome);
        scanf("%d", &pessoa[*qtda].pnet);
        if(pessoa[*qtda].pnet==1){
            printf("Digite o codigo do laudo medico de %s:\n", pessoa[*qtda].nome);
            scanf("%d", &pessoa[*qtda].pne.laudo);
        }
    }
    while(pessoa[*qtda].cep<10000000 || pessoa[*qtda].cep>99999999){
    printf("Digite o CEP de %s", pessoa[*qtda].nome);
    scanf("%d", pessoa[*qtda].cep);
    if(pessoa[*qtda].cep<10000000 || pessoa[*qtda].cep>99999999){
        printf("CEP invalido! Digite novamente:\n");
    }
    }
    printf("Digite o endereco de %s", pessoa[*qtda].nome);
    scanf("%[^\n]s", pessoa[*qtda].endereco);
    while(pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1){
        printf("Digite o tipo da pessoa, 0 para aluno e 1 para professor:\n");
        scanf("%d", &pessoa[*qtda].tipo);
        if(pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1){
            printf("tipo de pessoa inválido! Digite novamente:\n");
        }
        if(pessoa[*qtda].tipo)
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
     if(pos == -1){
     printf("Aluno nao cadastrado!\n");
     return;
     }
     printf("O aluno %s, posicao %d foi deletado\n",pessoa[pos].nome ,pos);
    }
    void exibirdados(cadastros pessoa[], int *qtda)
    {
     printf("Exibindo dados \n");
     for(int i = 0; i < *qtda; i++)
     {
     printf("Nome:%s\n",pessoa[i].nome);
     printf("Sexo:%d \n",pessoa[i].sexo);
     printf("%d/",pessoa[i].dia);
     printf("%d/",pessoa[i].mes);
     printf("%d\n",pessoa[i].ano);
     }
    }

    void exibe(cadastros pessoa[], int *qtda, int pos){
     printf("Nome:%s\n",pessoa[pos].nome);
     printf("Sexo:%d \n",pessoa[pos].sexo);
     printf("%d/",pessoa[pos].dia);
     printf("%d/",pessoa[pos].mes);
     printf("%d\n",pessoa[pos].ano);
    }
    void pessoamaisvelha(cadastros pessoa[], int *qtda)
    {
     int menor=0;
     int i;
     for(i=0 ; i < *qtda; i++)
     {
     if(pessoa[i].ano < pessoa[menor].ano )
     {
     menor = i;
     }
     else if (pessoa[i].ano == pessoa[menor].ano )
     {
     if (pessoa[i].mes < pessoa[menor].mes )
     {
     menor=i;
     }
     else if(pessoa[i].mes == pessoa[menor].mes )
     {
     if(pessoa[i].dia < pessoa[menor].dia )
     {
     menor=i;
     }
     }
     }
     }
     printf("Dados da pessoa mais velha:\n");
     exibe(pessoa, &qtda, menor);
    }
    void pessoamaisnova(cadastros pessoa[], int *qtda)
    {
     int maior=0;
     int i;
     for(i=0 ; i < *qtda; i++)
     {
     if(pessoa[i].ano > pessoa[maior].ano )
     {
     maior = i;
     }
     else if (pessoa[i].ano == pessoa[maior].ano )
     {
     if (pessoa[i].mes > pessoa[maior].mes )
     {
     maior=i;
     }
     else if(pessoa[i].mes == pessoa[maior].mes )
     {
     if(pessoa[i].dia > pessoa[maior].dia )
     {
     maior=i;
     }
     }
     }
     }
     printf("Dados da pessoa mais nova: \n");
     exibe(pessoa, &qtda, maior);
    }

    void help()
    {
     printf("Comandos validos: \n");
     printf(" 1 para cadastrar\n");
     printf(" 2 para remover \n");
     printf(" 3 para exibir dados\n");
     printf(" 4 pessoa mais velha \n");
     printf(" 5 pessoa mais nova\n");
     printf(" 6 mensagem de ajuda \n");
     printf(" 7 sair do programa\n");

    }

    void main()
    {
     help();
     cadastros pessoa[20];
     int qtda = 0;
     int comando;

     printf("Digite a opcao que deseja\n");
     scanf("%d",&comando);

     while (comando != 7)
     {
     switch (comando)
     {
     case 1 :
     cadastrar(pessoa,&qtda);
     break;
     case 2 :
     removerpessoa(pessoa,&qtda);
     break;
     case 3 :
     exibirdados(pessoa, &qtda);
     break;
     case 4 :
     pessoamaisvelha(pessoa,&qtda);
     break;
     case 5 :
     pessoamaisnova(pessoa,&qtda);
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
