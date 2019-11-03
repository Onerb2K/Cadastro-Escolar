#include <stdio.h>
#include "estruturas.h"

int main(int argc, char const *argv[])
{
    escola Escola;
    int controle = 0;
    do
    {
        printf("\nCadastro Escolar------------------\n1 - Sistema de Pessoas.\n2 - Sistema de Disciplinas.\n3 - Sair do Sistema.\n");
        scanf("%i", &controle);
        switch (controle)
        {
        case 1:
            
            break;

        case 2:

            break;

        case 3:
            printf("\nSaindo do Sistema.\n");
            return 0;
            break;

        default:
            printf("\nOpcao Invalida.\n");
            break;
        }
    } while (controle != 3);

    return 0;
}
