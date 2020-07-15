#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "funcoes.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    TModulo1 mod1;
    TModulo2 mod2;
    TModulo3 mod3;

    inicializaMod1(&mod1);
    inicializaMod2(&mod2);
    inicializaMod3(&mod3);

    TLivro book;
    TUsuario user;
    TEmprestimo borrow;

    int opcao = 0;

    do{
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                SubMenuModulo1(&mod1, book);
                break;
            case 2:
                SubMenuModulo2(&mod2, user);
                break;
            case 3:
                SubMenuModulo3(&mod3, borrow, &mod2, &mod1, user);
                break;
            case 4:
                printf("\nTerminando programa...\n");
                system("PAUSE");
                break;
            default:
                printf("\nERRO: Opcao inválida!\n");
                system("PAUSE");
        }
    }while(opcao != 4);

    return 0;
}
