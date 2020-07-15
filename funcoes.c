#include "funcoes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaMod1(TModulo1 *modulo){
    modulo->indice = 0;
}

void inicializaMod2(TModulo2 *modulo){
    modulo->indice = 0;
}

void inicializaMod3(TModulo3 *modulo){
    modulo->indice = 0;
}

TData CalcularDataEntrega(TData data_emprestimo){
    if(data_emprestimo.ano % 4 == 0 && (data_emprestimo.ano % 400 == 0 || data_emprestimo.ano % 100 != 0)) { // bissexto
        if(data_emprestimo.mes == 2){
            if(data_emprestimo.dia <= 29){
                data_emprestimo.dia = data_emprestimo.dia + 14;
                if(data_emprestimo.dia > 29){
                    data_emprestimo.dia = data_emprestimo.dia - 29;
                    data_emprestimo.mes = data_emprestimo.mes + 1;
                }
            }
        }
        else if(data_emprestimo.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
            if(data_emprestimo.dia <= 31){
                data_emprestimo.dia = data_emprestimo.dia + 14;
                if(data_emprestimo.dia > 31){
                    data_emprestimo.dia = data_emprestimo.dia - 31;
                    data_emprestimo.mes = data_emprestimo.mes + 1;
                    if(data_emprestimo.mes > 12){
                        data_emprestimo.mes = data_emprestimo.mes - 12;
                        data_emprestimo.ano = data_emprestimo.ano + 1;
                    }
                }
            }
        }//meses com 31 dias
        else if(data_emprestimo.mes == 4 || 6 || 9 || 11){
            if(data_emprestimo.dia <= 3){
                data_emprestimo.dia = data_emprestimo.dia + 14;
                if(data_emprestimo.dia > 30){
                    data_emprestimo.dia = data_emprestimo.dia - 31;
                    data_emprestimo.mes = data_emprestimo.mes + 1;
                }
            }
        }//meses com 30 dias
    }//bissexto
    else{ // n�o bissexto
        if(data_emprestimo.mes == 2){
            if(data_emprestimo.dia <= 28){
                data_emprestimo.dia = data_emprestimo.dia + 14;
                if(data_emprestimo.dia > 28){
                    data_emprestimo.dia = data_emprestimo.dia - 28;
                    data_emprestimo.mes = data_emprestimo.mes + 1;
                }
            }
        }//mes com 28 dias
        else if(data_emprestimo.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
            if(data_emprestimo.dia <= 31){
                data_emprestimo.dia = data_emprestimo.dia + 14;
                if(data_emprestimo.dia > 31){
                    data_emprestimo.dia = data_emprestimo.dia - 31;
                    data_emprestimo.mes = data_emprestimo.mes + 1;
                    if(data_emprestimo.mes > 12){
                        data_emprestimo.mes = data_emprestimo.mes - 12;
                        data_emprestimo.ano = data_emprestimo.ano + 1;
                    }
                }
            }
        }//meses com 31 dias
        else if(data_emprestimo.mes == 4 || 6 || 9 || 11){
            if(data_emprestimo.dia <= 3){
                data_emprestimo.dia = data_emprestimo.dia + 14;
                if(data_emprestimo.dia > 30){
                    data_emprestimo.dia = data_emprestimo.dia - 31;
                    data_emprestimo.mes = data_emprestimo.mes + 1;
                }
            }
        }//meses com 30 dias
    }
    return data_emprestimo;
}

void lerLivro(TLivro *book){
    printf("Digite o ISBN do livro:\n");
    fflush(stdin);
    fgets(book->ID.ISBN, 99,stdin);
    printf("Digite o t�tulo do livro:\n");
    fflush(stdin);
    fgets(book->titulo_do_livro, 49, stdin);
    printf("Digite a editora do livro:\n");
    fflush(stdin);
    fgets(book->editora, 14,stdin);
    printf("Digite o local de publica��o do livro: \n");
    fflush(stdin);
    fgets(book->local_de_publicacao, 49,stdin);
    printf("Informa��es sobre a data de publica��o do livro\n");
    printf("Dia de publica��o do livro: ");
    fflush(stdin);
    scanf("%d", &book->data_publicacao.dia);
    printf("M�s de publica��o do livro: ");
    fflush(stdin);
    scanf("%d", &book->data_publicacao.mes);
    printf("Ano de publica��o do livro: ");
    fflush(stdin);
    scanf("%d", &book->data_publicacao.ano);
    printf("Digite o nome do 1 autor do livro:\n");
    fflush(stdin);
    fgets(book->nome_1_autor, 29,stdin);
    printf("Digite o nome do 2 autor do livro:\n");
    fflush(stdin);
    fgets(book->nome_2_autor, 29,stdin);
    printf("Digite o n�mero da edi��o do livro:\n");
    fflush(stdin);
    scanf("%d", &book->n_edicao);
    printf("Digite a quantidade de livros dispon�veis:\n");
    fflush(stdin);
    scanf("%d", &book->qtd_livros);
    fflush(stdin);
    book->qtd_livros_emprestados = 0;
}

void lerUsuarios(TUsuario *user){
    printf("Digite seu nome:\n");
    fflush(stdin);
    fgets(user->nome, 19, stdin);
    printf("Digite seu sobrenome:\n");
    fflush(stdin);
    fgets(user->sobrenome, 49, stdin);
    printf("Digite seu CPF:\n");
    fflush(stdin);
    fgets(user->CPF, 15, stdin);
    printf("Digite sua identidade:\n");
    fflush(stdin);
    fgets(user->identidade, 19, stdin);
    printf("Informa��es sobre seu endere�o.\n");
    printf("Logradouro:\n");
    fflush(stdin);
    fgets(user->end.logradouro, 99, stdin);
    printf("Bairro:\n");
    fflush(stdin);
    fgets(user->end.bairro, 49, stdin);
    printf("N�mero:\n");
    fflush(stdin);
    scanf("%d", &user->end.numero);
    printf("Complemento:\n");
    fflush(stdin);
    fgets(user->end.complemento, 49, stdin);
    printf("CEP:\n");
    fflush(stdin);
    fgets(user->end.CEP, 10, stdin);
    printf("Cidade:\n");
    fflush(stdin);
    fgets(user->end.cidade, 49, stdin);
    printf("Estado: \n");
    fflush(stdin);
    fgets(user->end.estado, 49,stdin);
    printf("Informa��es sobre a data de nascimento.\n");
    printf("Dia:\n");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.dia);
    printf("M�s:\n");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.mes);
    printf("Ano:\n");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.ano);
    printf("Digite a op��o que se equivale a sua ocupa��o:\n");
    printf("1 - professor\n");
    printf("2 - estudante universit�rio\n");
    printf("3 - t�cnico administrativo\n");
    printf("Op��o:\n");
    fflush(stdin);
    scanf("%d", &user->tipo_usuario);
    printf("Digite o seu departamento caso seja professor ou ent�o o curso, caso seja aluno: \n");
    fflush(stdin);
    fgets(user->departamento, 99,stdin);
    fflush(stdin);
    user->qtd_livros = 0;
}

void lerEmprestimo(TEmprestimo *empr){
    printf("Digite o CPF da pessoa: \n");
    fflush(stdin);
    fgets(empr->CPF, 15,stdin);
    printf("Data do empr�stimo:\n");
    empr->data_emprestimo.dia = data_hora_atual->tm_mday;
    empr->data_emprestimo.mes = data_hora_atual->tm_mon+1;
    empr->data_emprestimo.ano = data_hora_atual->tm_year+1900;
    fflush(stdin);
    printf("%d/%d/%d\n", empr->data_emprestimo.dia, empr->data_emprestimo.mes, empr->data_emprestimo.ano);
    empr->data_entrega_livro = CalcularDataEntrega(empr->data_emprestimo);
    fflush(stdin);
    printf("Data de devolu��o do empr�stimo:\n");
    printf("%d/%d/%d", empr->data_entrega_livro.dia, empr->data_entrega_livro.mes, empr->data_entrega_livro.ano);
    printf("\nDigite o ISBN do livro que ser� emprestado: ");
    fflush(stdin);
    fgets(empr->ISBN.ISBN, 99, stdin);
}

void imprimirUsuario(TUsuario user){
    printf("\n--- INFO USU�RIO:");
    printf("\n\tNome: %s", user.nome);
    printf("\tSobrenome: %s", user.sobrenome);
    printf("\tCPF: %s", user.CPF);
    printf("\tIdentidade: %s", user.identidade);
    printf("\tData de nascimento: %2d/%2d/%4d", user.data_nascimento.dia, user.data_nascimento.mes, user.data_nascimento.ano);
    printf("\n\tEndere�o");
    printf("\n\tlogradouro: %s", user.end.logradouro);
    printf("\tbairro: %s", user.end.bairro);
    printf("\tn�mero: %d", user.end.numero);
    printf("\n\tcomplemento: %s", user.end.complemento);
    printf("\tCEP: %s", user.end.CEP);
    printf("\tcidade: %s", user.end.cidade);
    printf("\testado: %s", user.end.estado);
    printf("\ttipo de usu�rio: %d", user.tipo_usuario);
    printf("\n\tdepartamento: %s", user.departamento);
    printf("\tLivros emprestados: %d\n", user.qtd_livros);
}

void imprimirLivro(TLivro book){
    printf("\n--- INFO LIVRO:");
    printf("\n\tT�tulo do livro: %s", book.titulo_do_livro);
    printf("\tData de publica��o: %2d/%2d/%4d", book.data_publicacao.dia, book.data_publicacao.mes, book.data_publicacao.ano);
    printf("\n\tEditora: %s", book.editora);
    printf("\tLocal de publica��o do livro: %s", book.local_de_publicacao);
    printf("\tNome do 1 autor: %s", book.nome_1_autor);
    printf("\tNome do 2 autor: %s", book.nome_2_autor);
    printf("\tN� da edi��o: %d", book.n_edicao);
    printf("\n\tQuantidade de livros: %d", book.qtd_livros);
    printf("\n\tQuantidade emprestadas: %d", book.qtd_livros_emprestados);
    printf("\n\tISBN: %s", book.ID.ISBN);
}

void imprimirEmprestimo(TEmprestimo empr){
    printf("\n--- INFO EMPR�STIMO:");
    printf("\n\tCPF do respons�vel: %s", empr.CPF);
    printf("\tData do empr�stimo: %2d/%2d/%4d", empr.data_emprestimo.dia, empr.data_emprestimo.mes, empr.data_emprestimo.ano);
    printf("\n\tData prevista de devolu��o: %2d/%2d/%4d",empr.data_entrega_livro.dia, empr.data_entrega_livro.mes, empr.data_entrega_livro.ano);
    printf("\n\tData em que realmente foi devolvido: %2d/%2d/%4d", empr.data_devolucao.dia, empr.data_devolucao.mes, empr.data_devolucao.ano);
    printf("\n\tMulta: %.2f", empr.multa);
    printf("\tEsta pago: %d\n", empr.PG);
    printf("\tISBN do livro: %s", empr.ISBN.ISBN);
}

int pesquisarLivro(TModulo1 modulo, TLivro book){
    int i;
    for(i = 0; i < modulo.indice; i++){
        if(strcmp(modulo.vetor[i].ID.ISBN, book.ID.ISBN) == 0){
            return i;
        }
    }
    return -1;
}

int pesquisarUsuario(TModulo2 modulo, TUsuario user){
    int i;
    for(i = 0; i < modulo.indice; i++){
        if(strcmp(modulo.vetor[i].CPF, user.CPF) == 0){
            return i;
        }
    }
    return -1;
}

int pesquisarEmprestimo(TModulo3 modulo, TEmprestimo emp){
    int i;
    for(i = 0; i < modulo.indice; i++){
        if((strcmp(modulo.vetor[i].CPF, emp.CPF) == 0) && (modulo.vetor[i].data_emprestimo.dia == emp.data_emprestimo.dia) &&
           (modulo.vetor[i].data_emprestimo.mes == emp.data_emprestimo.mes) && (modulo.vetor[i].data_emprestimo.ano == emp.data_emprestimo.ano) &&
           (strcmp(modulo.vetor[i].ISBN.ISBN, emp.ISBN.ISBN) == 0)){
            return i;
        }
    }
    return -1;
}

void inserirLivro(TModulo1 *modulo, TLivro book){
    int i;
    if(modulo->indice < 100){
        for(i = 0; i < modulo->indice; i++){
            if(strcmp(modulo->vetor[i].ID.ISBN, book.ID.ISBN) == 0){
                printf("\nErro. Livro j� cadastrado!\n");
                return;
            }
        }
        modulo->vetor[modulo->indice] = book;
        modulo->indice++;
        printf("\n Cadastro efetuado com sucesso!\n");
    }
    else printf("\n O cadastro n�o foi efetuado!");
}

void inserirUsuario(TModulo2 *modulo, TUsuario user){
    int i;
    if(modulo->indice < 100){
        for(i = 0; i < modulo->indice; i++){
            if(strcmp(user.CPF, modulo->vetor[i].CPF) == 0){
                printf("\nErro. Usu�rio j� cadastrado!\n");
                return;
            }
        }
        modulo->vetor[modulo->indice] = user;
        modulo->indice++;
        printf("\n Usu�rio cadastrado com sucesso!\n");
    }
    else printf("\n O cadastro n�o foi efetuado!");
}

void inserirEmprestimo(TModulo3 *modulo, TEmprestimo emp, TModulo2 *mod2, TModulo1 *mod){
    TUsuario user;
    TLivro book;
    strcpy(user.CPF, emp.CPF);
    int aux, aux1, i;
    aux = pesquisarUsuario(*mod2, user);
    if(aux == -1){
        printf("\nUsu�rio n�o cadastrado no sistema!\n");
    }
    else{
        if(strlen(emp.ISBN.ISBN) != 0){
            strcpy(book.ID.ISBN, emp.ISBN.ISBN);
            aux1 = pesquisarLivro(*mod, book);
            if(aux1 == -1){
                printf("\nLivro n�o cadastrado no sistema!\n");
            }
            else{
                if(mod2->vetor[aux].tipo_usuario == 2 || 3){
                    if(mod2->vetor[aux].qtd_livros < 3){
                        for(i = 0; i < modulo->indice; i++){
                            if(strcmp(modulo->vetor[i].CPF, mod2->vetor[aux].CPF) == 0){
                                if(modulo->vetor[i].multa != 0){
                                    printf("\nUsuario possui multa em aberto, n�o � poss�vel realizar o empr�stimo!\n");
                                    return;
                                }
                            }
                        }
                        if(mod->vetor[aux1].qtd_livros_emprestados <= (0.9*mod->vetor[aux1].qtd_livros)){
                            if(modulo->indice < 100){
                                modulo->vetor[modulo->indice] = emp;
                                modulo->indice++;
                                mod->vetor[aux1].qtd_livros_emprestados+=1;
                                mod2->vetor[aux].qtd_livros+=1;
                                printf("\n Empr�stimo cadastrado com sucesso!\n");
                            }
                            else printf("\n O empr�stimo n�o foi efetuado!\n");
                        }
                        else{
                        printf("\nN�o � possivel efetuar o empr�stimo, todos os exemplares emprestados!\n");
                        }
                    }
                    else printf("\n N�mero m�ximo de livros j� emprestados ao usu�rio!\n");
                }
                else if(mod2->vetor[aux].tipo_usuario == 1){
                    for( i = 0; i < modulo->indice; i++){
                        if(modulo->vetor[i].CPF == user.CPF){
                            if(modulo->vetor[i].multa != 0){
                                printf("\nUsu�rio possui multa em aberto!\n");
                                system("PAUSE");
                                break;
                            }
                        }
                    }
                    if(mod2->vetor[aux].qtd_livros < 5){
                        if(mod->vetor[aux1].qtd_livros_emprestados <= (0.9*mod->vetor[aux1].qtd_livros)){
                            if(modulo->indice < 100){
                                modulo->vetor[modulo->indice] = emp;
                                modulo->indice++;
                                mod->vetor[aux1].qtd_livros_emprestados+=1;
                                mod2->vetor[aux].qtd_livros+=1;
                                printf("\n Empr�stimo cadastrado com sucesso!\n");
                            }
                            else printf("\n O empr�stimo n�o foi efetuado!\n");
                        }
                        else{
                        printf("\nN�o � poss�vel efetuar o empr�stimo, todos os exemplares emprestados!\n");
                        }
                    }
                    else printf("\n N�mero m�ximo de livros j� emprestados ao usu�rio!\n");
                }
            }
        }
    }
}

void alterarLivro(TModulo1 *modulo, TLivro book){
    int aux;
    aux = pesquisarLivro(*modulo, book);
    if(aux == -1){
        printf("\nLivro n�o encontrado!\n");
    }
    else{
        printf("\nLivro encontrado! Digite os novos dados do livro.\n");
        lerLivro(&book);
        modulo->vetor[aux] = book;
    }
    system("PAUSE");
}

void alterarUsuario(TModulo2 *modulo, TUsuario user){
    int aux;
    aux = pesquisarUsuario(*modulo, user);
    if(aux == -1){
        printf("\nUsu�rio n�o encontrado!\n");
    }
    else{
        printf("\nUsu�rio encontrado! Digite os novos dados do usu�rio.\n");
        lerUsuarios(&user);
        modulo->vetor[aux] = user;
        printf("\nUsu�rio alterado com sucesso!\n");
    }
    system("PAUSE");
}

void alterarEmprestimo(TModulo3 *modulo, TEmprestimo emp){
    int aux;
    aux = pesquisarEmprestimo(*modulo, emp);
    if(aux == -1){
        printf("\nEmpr�stimo n�o encontrado!");
    }
    else{
        printf("\nEmpr�stimo encontrado! Digite os novos dados do empr�stimo.\n");
        lerEmprestimo(&emp);
        modulo->vetor[aux] = emp;
        printf("\nEmpr�stimo alterado com sucesso!\n");
    }
    system("PAUSE");
}

void excluirLivro(TModulo1 *modulo, TLivro book){
    int aux, flag;
    aux = pesquisarLivro(*modulo, book);
    if(aux == -1){
        printf("\nLivro n�o encontrado!\n");
    }
    else{
        printf("Livro encontrado!\n");
        system("PAUSE");
        system("cls");
        imprimirLivro(modulo->vetor[aux]);
        printf("Deseja realmente excluir este livro?\n");
        printf("1 - SIM 2 - N�O\n");
        fflush(stdin);
        scanf("%d", &flag);
        if(flag == 1){
            for(int i = 0; i <= modulo->indice; i++){
                modulo->vetor[aux] = modulo->vetor[aux+1];
                aux++;
            }
            modulo->indice--;
            printf("Livro exclu�do com sucesso.\n");
        }
        else{
            printf("Exclus�o abortada.\n");
        }
    }
    system("PAUSE");
}

void excluirUsuario(TModulo2 *modulo, TUsuario user){
    int aux, flag;
    aux = pesquisarUsuario(*modulo, user);
    if(aux == -1){
        printf("\nUsu�rio n�o encontrado!");
    }
    else{
        printf("Usu�rio encontrado!\n");
        system("PAUSE");
        system("cls");
        imprimirUsuario(modulo->vetor[aux]);
        printf("Deseja realmente excluir este usu�rio?\n");
        printf("1 - SIM 2 - N�O\n");
        fflush(stdin);
        scanf("%d", &flag);
        if(flag == 1){
            for(int i = 0; i <= modulo->indice; i++){
                modulo->vetor[aux] = modulo->vetor[aux+1];
                aux++;
            }
            modulo->indice--;
            printf("Usu�rio exclu�do com sucesso.\n");
        }
        else{
            printf("Exclus�o abortada.\n");
        }
    }
    system("PAUSE");
}

void excluirEmprestimo(TModulo3 *modulo, TModulo1 *mod1, TEmprestimo emp){
    int aux, flag;
    TLivro book;
    strcpy(book.ID.ISBN, emp.ISBN.ISBN);
    aux = pesquisarEmprestimo(*modulo, emp);
    if(aux == -1){
        printf("\nEmpr�stimo n�o encontrado!");
    }
    else{
        printf("\nEmpr�stimo encontrado!\n");
        system("PAUSE");
        system("cls");
        imprimirEmprestimo(modulo->vetor[aux]);
        printf("Deseja realmente excluir este empr�stimo?\n");
        printf("1 - SIM 2 - N�O\n");
        fflush(stdin);
        scanf("%d", &flag);
        if(flag == 1){
            for(int i = 0; i <= modulo->indice; i++){
                modulo->vetor[aux] = modulo->vetor[aux+1];
                aux++;
            }
            modulo->indice--;
            printf("Empr�stimo exclu�do com sucesso.\n");
        }
        else{
            printf("Exclus�o abortada.\n");
        }
    }
    system("PAUSE");
}

void imprimirTodosLivros(TModulo1 modulo){
    int i;
    if(modulo.indice <= 0){
        printf("N�o h� livros cadastrados para efetuar a impress�o do relat�rio!\n");
    }
    else{
        for(i = 0; i < modulo.indice; i++){
            imprimirLivro(modulo.vetor[i]);
        }
        printf("\nRelat�rio impresso!\n");
    }
}

void imprimirTodosUsuarios(TModulo2 modulo){
    int i;
    if( modulo.indice <= 0){
        printf("N�o h� usu�rios cadastrados para efetuar a impress�o do relat�rio!\n");
    }
    else{
        for(i = 0; i < modulo.indice; i++){
            imprimirUsuario(modulo.vetor[i]);
        }
        printf("\nRelat�rio impresso!\n");
    }
}

void imprimirTodosEmprestimo(TModulo3 modulo){
    int i;
    for(i = 0; i < modulo.indice; i++){
        imprimirEmprestimo(modulo.vetor[i]);
    }
    printf("\nRelat�rio impresso!\n");
}

void realizarBaixaEmprestimo(TModulo3 *modulo, TModulo1 * mod1, TModulo2 *mod2, TEmprestimo emp){
    int aux;
    TLivro book;
    TData date;
    TData date1;
    strcpy(book.ID.ISBN, emp.ISBN.ISBN);
    aux = pesquisarEmprestimo(*modulo, emp);
    if(aux == -1){
        printf("\nEmpr�stimo n�o encontrado! Verifique os dados.");
    }
    else{
        printf("Empr�stimo encontrado!");
        if(modulo->vetor[aux].PG == 1){
            printf("\nErro! Empr�stimo j� foi dado baixa.\n");
            system("PAUSE");
            return;
        }
        else{
            modulo->vetor[aux].data_devolucao = emp.data_devolucao;
            if(emp.data_emprestimo.ano % 4 == 0 && (emp.data_emprestimo.ano % 400 == 0 || emp.data_emprestimo.ano % 100 != 0)){ //ano bissexto
                if(emp.data_entrega_livro.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
                    date.dia = (emp.data_entrega_livro.mes * 31) + (emp.data_entrega_livro.ano * 366) + emp.data_entrega_livro.dia;
                }
                else if(emp.data_entrega_livro.mes == 4 || 6 || 9 || 11){
                    date.dia = (emp.data_entrega_livro.mes * 30) + (emp.data_entrega_livro.ano * 366) + emp.data_entrega_livro.dia;
                }
                else{
                    date.dia = (emp.data_entrega_livro.mes * 29) + (emp.data_entrega_livro.ano * 366) + emp.data_entrega_livro.dia;
                }
                if(emp.data_devolucao.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
                    date1.dia = (emp.data_devolucao.mes * 31) + (emp.data_devolucao.ano * 366) + emp.data_devolucao.dia;
                }
                else if(emp.data_devolucao.mes == 4 || 6 || 9 || 11){
                    date1.dia = (emp.data_devolucao.mes * 30) + (emp.data_devolucao.ano * 366) + emp.data_devolucao.dia;
                }
                else{
                    date1.dia = (emp.data_devolucao.mes * 29) + (emp.data_devolucao.ano * 366) + emp.data_devolucao.dia;
                }
                date.dia = date1.dia - date.dia;
            }
            else{// ano n�o bissexto
                if(emp.data_entrega_livro.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
                    date.dia = (emp.data_entrega_livro.mes * 31) + (emp.data_entrega_livro.ano * 365) + emp.data_entrega_livro.dia;
                }
                else if(emp.data_entrega_livro.mes == 4 || 6 || 9 || 11){
                    date.dia = (emp.data_entrega_livro.mes * 30) + (emp.data_entrega_livro.ano * 365) + emp.data_entrega_livro.dia;
                }
                else{
                    date.dia = (emp.data_entrega_livro.mes * 28) + (emp.data_entrega_livro.ano * 365) + emp.data_entrega_livro.dia;
                }
                if(emp.data_devolucao.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
                    date1.dia = (emp.data_devolucao.mes * 31) + (emp.data_devolucao.ano * 365) + emp.data_devolucao.dia;
                }
                else if(emp.data_devolucao.mes == 4 || 6 || 9 || 11){
                    date1.dia = (emp.data_devolucao.mes * 30) + (emp.data_devolucao.ano * 365) + emp.data_devolucao.dia;
                }
                else{
                    date1.dia = (emp.data_devolucao.mes * 28) + (emp.data_devolucao.ano * 365) + emp.data_devolucao.dia;
                }
                date.dia = date1.dia - date.dia;
            }
        }
        aux = pesquisarLivro(*mod1, book);
        mod1->vetor[aux].qtd_livros_emprestados--;
        mod2->vetor[aux].qtd_livros--;
        int i;
        if(date.dia >= 1){
            modulo->vetor[aux].multa = date.dia * 2.00;
            printf("\nMulta calculada!");
            printf("\nO valor da multa � de R$ %.2f", modulo->vetor[aux].multa);
            printf("\nPagar agora?");
            printf("\n1 - SIM  2 - N�O\n");
            scanf("%d", &i);
            if(i == 1){
                modulo->vetor[aux].PG = 1;
                printf("\nMulta paga!");
                system("PAUSE");
            }
            else{
                modulo->vetor[aux].PG = 0;
                printf("\nMulta pendente.");
                printf("\nBaixa realizada com sucesso!\n");
                system("PAUSE");
            }
        }
        else{
            printf("\nEmpr�stimo quitado sem multas!\n");
            modulo->vetor[aux].PG = 1;
            system("PAUSE");
        }
    }
}

void EfetuarPagamento(TModulo3 *modulo, TModulo1 *mod1, TEmprestimo borrow){
    int aux;
    aux = pesquisarEmprestimo(*modulo, borrow);

    printf("\nMulta no valor de R$ %.2f", modulo->vetor[aux].multa);
    modulo->vetor[aux].PG = 1;
    printf("\nPagamento efetuado com sucesso!\n");
}

void RelatorioMensal(TModulo3 mod3, int mes){
    int total_livros_emprestados = 0, total_dentro_prazo = 0, total_fora_prazo = 0;
    int i;
    for(i = 0; i < mod3.indice; i++){
        if(mod3.vetor[i].data_emprestimo.mes == mes){
            if(mod3.vetor[i].multa != 0.0){
                total_fora_prazo +=1;
            }
            else if(mod3.vetor[i].data_devolucao.dia != 0 && mod3.vetor[i].multa == 0.0){
                total_dentro_prazo +=1;
            }
            total_livros_emprestados +=1;
        }
    }
    printf("Total de livros emprestados no m�s %d: %d livro(s)\n", mes, total_livros_emprestados);
    printf("Total de livros entregues dentro do prazo no m�s %d: %d livro(s)\n", mes, total_dentro_prazo);
    printf("Total de livros entregues fora do prazo no m�s %d: %d livro(s)\n", mes, total_fora_prazo);
    system("PAUSE");
}

void ColocarOrdemAlfabetica(TModulo2 *mod2){
    TUsuario user;
    int i, j;
    for(i = 0; i < mod2->indice; i++){
        for (j = 0; j < mod2->indice-1; j++){
            if(strcmp(mod2->vetor[j].nome, mod2->vetor[j+1].nome) > 0){
                user = mod2->vetor[j+1];
                mod2->vetor[j+1] = mod2->vetor[j];
                mod2->vetor[j] = user;
            }
        }
    }
    printf("\nOpera��o realizada com sucesso! \nUtilize a op��o 5 para verificar o relat�rio de nomes em ordem alfab�tica.\n\n");
    system("PAUSE");
}

void MSG_MENU(){
    printf("\tSistema Bibliotec�rio\n");
    printf("\n --- Menu:\n\n");
    printf("\t1. Livro\n");
    printf("\t2. Usu�rio\n");
    printf("\t3. Empr�stimo\n");
    printf("\t4. Sair\n");
}

void MSG_SUBMENU(int numero_modulo){
    if(numero_modulo == 3){
        system("cls");
        printf("\n --- Empr�stimo\n\n");
        printf("\t1. Cadastrar\n");
        printf("\t2. Pesquisar\n");
        printf("\t3. Alterar\n");
        printf("\t4. Excluir\n");
        printf("\t5. Realizar baixa\n");
        printf("\t6. Efetuar pagamento\n");
        printf("\t7. Imprimir relat�rio\n");
        printf("\t8. Computar empr�stimos pelo m�s\n");
        printf("\t9. Voltar ao menu principal\n");
    }
    else if(numero_modulo == 2){
         system("cls");
        printf("\n --- Usu�rio\n\n");
        printf("\t1. Cadastrar\n");
        printf("\t2. Pesquisar\n");
        printf("\t3. Alterar\n");
        printf("\t4. Excluir\n");
        printf("\t5. Imprimir relat�rio\n");
        printf("\t6. Colocar usu�rios em ordem alfab�tica\n");
        printf("\t7. Voltar ao menu principal\n");
    }
    else{
        system("cls");
        printf("\n --- Livro\n\n");
        printf("\t1. Cadastrar\n");
        printf("\t2. Pesquisar\n");
        printf("\t3. Alterar\n");
        printf("\t4. Excluir\n");
        printf("\t5. Imprimir relat�rio\n");
        printf("\t6. Voltar ao menu principal\n");
    }
}

void SubMenuModulo1(TModulo1 *modulo, TLivro book){
    int opcao = 0;
    int aux;
    do{
        MSG_SUBMENU(1);
        printf("\n\nDigite uma op��o: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                lerLivro(&book);
                inserirLivro(modulo, book);
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\nDigite o ISBN do livro procurado: ");
                fflush(stdin);
                fgets(book.ID.ISBN, 99, stdin);
                aux = pesquisarLivro(*modulo, book);
                if(aux == -1){
                    printf("Livro n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    printf("Livro encontrado!\n");
                    imprimirLivro(modulo->vetor[aux]);
                    system("PAUSE");
                }
                break;
            case 3:
                system("cls");
                printf("\nDigite o ISBN do livro que desejas alterar: ");
                fflush(stdin);
                fgets(book.ID.ISBN, 99, stdin);
                alterarLivro(modulo, book);
                break;
            case 4:
                system("cls");
                printf("\nDigite o ISBN do livro a ser exclu�do: ");
                fflush(stdin);
                fgets(book.ID.ISBN, 99, stdin);
                excluirLivro(modulo, book);
                break;
            case 5:
                system("cls");
                imprimirTodosLivros(*modulo);
                system("PAUSE");
                break;
            case 6:
                printf("\nVoltando ao menu...\n");
                system("PAUSE");
                break;
            default:
                printf("\nERRO: Op��o inv�lida!\n");
                system("PAUSE");
        }
    }while(opcao != 6);
}

void SubMenuModulo2(TModulo2 *modulo, TUsuario user){
    int opcao = 0;
    int aux;
    do{
        MSG_SUBMENU(2);
        printf("\n\nDigite uma op��o: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                lerUsuarios(&user);
                inserirUsuario(modulo, user);
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\nDigite o CPF do usu�rio procurado: ");
                fflush(stdin);
                fgets(user.CPF, 15, stdin);
                aux = pesquisarUsuario(*modulo, user);
                if(aux == -1){
                    printf("Usu�rio n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    printf("Usu�rio encontrado!\n");
                    imprimirUsuario(modulo->vetor[aux]);
                    system("PAUSE");
                }
                break;
            case 3:
                system("cls");
                printf("\nDigite o CPF do usu�rio que desejas alterar: ");
                fflush(stdin);
                fgets(user.CPF, 15, stdin);
                alterarUsuario(modulo, user);
                break;
            case 4:
                system("cls");
                printf("\nDigite o CPF do usu�rio a ser exclu�do: ");
                fflush(stdin);
                fgets(user.CPF, 15, stdin);
                excluirUsuario(modulo, user);
                break;
            case 5:
                system("cls");
                imprimirTodosUsuarios(*modulo);
                system("PAUSE");
                break;
            case 6:
                ColocarOrdemAlfabetica(modulo);
                break;
            case 7:
                printf("\nVoltando ao menu...\n");
                system("PAUSE");
                break;
            default:
                printf("\nERRO: Op��o inv�lida!\n");
                system("PAUSE");
        }
    }while(opcao != 7);
}

void SubMenuModulo3(TModulo3 *modulo, TEmprestimo borrow, TModulo2 *mod2, TModulo1 *mod1, TUsuario user){
    int opcao = 0;
    int aux;
    do{
        MSG_SUBMENU(3);
        printf("\n\nDigite uma op��o: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                lerEmprestimo(&borrow);
                inserirEmprestimo(modulo, borrow, mod2, mod1);
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\nDigite o CPF do respons�vel pelo empr�stimo: ");
                fflush(stdin);
                fgets(borrow.CPF, 15, stdin);
                printf("\nDigite o ISBN do livro: ");
                fflush(stdin);
                fgets(borrow.ISBN.ISBN, 99, stdin);
                printf("\nDigite a data do empr�stimo\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.dia);
                printf("M�s: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.mes);
                printf("Ano: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.ano);
                aux = pesquisarEmprestimo(*modulo, borrow);
                if(aux == -1){
                    printf("Empr�stimo n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    printf("Empr�stimo encontrado!\n");
                    imprimirEmprestimo(modulo->vetor[aux]);
                    system("PAUSE");
                }
                break;
            case 3:
                system("cls");
                printf("\nDigite o CPF da pessoa que possui o empr�stimo ao qual desejas alterar: ");
                fflush(stdin);
                fgets(borrow.CPF, 15, stdin);
                printf("\nDigite o ISBN do livro: ");
                fflush(stdin);
                fgets(borrow.ISBN.ISBN, 99, stdin);
                printf("\nDigite a data do empr�stimo\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.dia);
                printf("M�s: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.mes);
                printf("Ano: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.ano);
                aux = pesquisarEmprestimo(*modulo, borrow);
                if(aux == -1){
                    printf("Empr�stimo n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    alterarEmprestimo(modulo, borrow);
                }
                break;
            case 4:
                system("cls");
                printf("\nDigite o CPF do respons�vel pelo empr�stimo: ");
                fflush(stdin);
                fgets(borrow.CPF, 15, stdin);
                printf("\nDigite o ISBN do livro: ");
                fflush(stdin);
                fgets(borrow.ISBN.ISBN, 99, stdin);
                printf("\nDigite a data do empr�stimo\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.dia);
                printf("M�s: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.mes);
                printf("Ano: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.ano);
                aux = pesquisarEmprestimo(*modulo, borrow);
                if(aux == -1){
                    printf("Empr�stimo n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    if(modulo->vetor[aux].PG == 0){
                        printf("Este empr�stimo ainda n�o foi pago, efetue a baixa primeiro.\n");
                        system("PAUSE");
                    }
                    else{
                        excluirEmprestimo(modulo, mod1, borrow);
                    }
                }
                break;
            case 5:
                system("cls");
                printf("\nDigite o CPF do respons�vel pelo empr�stimo: ");
                fflush(stdin);
                fgets(borrow.CPF, 15, stdin);
                printf("\nDigite o ISBN do livro: ");
                fflush(stdin);
                fgets(borrow.ISBN.ISBN, 99, stdin);
                printf("\nDigite a data do empr�stimo\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.dia);
                printf("M�s: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.mes);
                printf("Ano: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.ano);
                borrow.data_devolucao.dia = data_hora_atual->tm_mday;
                borrow.data_devolucao.mes = data_hora_atual->tm_mon+1;
                borrow.data_devolucao.ano = data_hora_atual->tm_year+1900;
                fflush(stdin);
                aux = pesquisarEmprestimo(*modulo, borrow);
                if(aux == -1){
                    printf("Empr�stimo n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    realizarBaixaEmprestimo(modulo, mod1, mod2, borrow);
                }
                break;
            case 6:
                system("cls");
                printf("\nDigite o CPF do respons�vel pelo empr�stimo: ");
                fflush(stdin);
                fgets(borrow.CPF, 15, stdin);
                printf("\nDigite o ISBN do livro: ");
                fflush(stdin);
                fgets(borrow.ISBN.ISBN, 99, stdin);
                printf("\nDigite a data do empr�stimo\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.dia);
                printf("M�s: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.mes);
                printf("Ano: ");
                fflush(stdin);
                scanf("%d", &borrow.data_emprestimo.ano);
                fflush(stdin);
                aux = pesquisarEmprestimo(*modulo, borrow);
                if(aux == -1){
                    printf("Empr�stimo n�o encontrado!\n");
                    system("PAUSE");
                }
                else{
                    EfetuarPagamento(modulo, mod1, borrow);
                    system("PAUSE");
                }
                break;
            case 7:
                system("cls");
                imprimirTodosEmprestimo(*modulo);
                system("PAUSE");
                break;
            case 8:
                system("cls");
                printf("Digite o n�mero correspondente ao m�s no qual gostaria de obter o relat�rio: \n");
                fflush(stdin);
                scanf("%d", &aux);
                RelatorioMensal(*modulo, aux);
                break;
            case 9:
                printf("\nVoltando ao menu...\n");
                system("PAUSE");
                break;
            default:
                printf("\nERRO: Op��o inv�lida!\n");
                system("PAUSE");
        }
    }while(opcao != 9);
}
