typedef struct data{
    int dia;
    int mes;
    int ano;
}TData;

struct tm *data_hora_atual;

typedef struct endereco{
    char logradouro[100];
    int numero;
    char complemento[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char CEP[11];
}TEndereco;

typedef struct isbn{
    char ISBN[100];
}TISBN;

typedef struct livro{
    TISBN ID;
    char titulo_do_livro[50];
    char editora[15];
    char local_de_publicacao[50];
    TData data_publicacao;
    char nome_1_autor[30];
    char nome_2_autor[30];
    int n_edicao;
    int qtd_livros;
    int qtd_livros_emprestados;
}TLivro;

typedef struct emprestimo{
    char CPF[20];
    TISBN ISBN;
    TData data_emprestimo;
    TData data_entrega_livro;
    TData data_devolucao;
    float multa;
    int PG;
}TEmprestimo;

typedef struct usuario{
    char nome[20];
    char sobrenome[50];
    char CPF[20];
    char identidade[20];
    TEndereco end;
    TData data_nascimento;
    int tipo_usuario;
    int qtd_livros;
    char departamento[100];
}TUsuario;

//CAPACIDADE PARA 100 LIVROS
typedef struct modulo1{
    TLivro vetor[100];
    int indice;
}TModulo1;

//CAPACIDADE PARA 100 USUÁRIOS
typedef struct modulo2{
    TUsuario vetor[100];
    int indice;
}TModulo2;

//CAPACIDADE PARA 100 EMPRÉSTIMOS
typedef struct modulo3{
    TEmprestimo vetor[100];
    int indice;
}TModulo3;

void inicializaMod1(TModulo1 *modulo);
void inicializaMod2(TModulo2 *modulo);
void inicializaMod3(TModulo3 *modulo);
TData CalcularDataEntrega(TData data_emprestimo);
void lerLivro(TLivro *book);
void lerUsuarios(TUsuario *user);
void lerEmprestimo(TEmprestimo *empr);
void imprimirUsuario(TUsuario user);
void imprimirLivro(TLivro book);
void imprimirEmprestimo(TEmprestimo empr);
int pesquisarLivro(TModulo1 modulo, TLivro book);
int pesquisarUsuario(TModulo2 modulo, TUsuario user);
int pesquisarEmprestimo(TModulo3 modulo, TEmprestimo emp);
void inserirLivro(TModulo1 *modulo, TLivro book);
void inserirUsuario(TModulo2 *modulo, TUsuario user);
void inserirEmprestimo(TModulo3 *modulo, TEmprestimo emp, TModulo2 *mod2, TModulo1 *mod);
void alterarLivro(TModulo1 *modulo, TLivro book);
void alterarUsuario(TModulo2 *modulo, TUsuario user);
void alterarEmprestimo(TModulo3 *modulo, TEmprestimo emp);
void excluirLivro(TModulo1 *modulo, TLivro book);
void excluirUsuario(TModulo2 *modulo, TUsuario user);
void excluirEmprestimo(TModulo3 *modulo, TModulo1 *mod1, TEmprestimo emp);
void imprimirTodosLivros(TModulo1 modulo);
void imprimirTodosUsuarios(TModulo2 modulo);
void imprimirTodosEmprestimo(TModulo3 modulo);
void realizarBaixaEmprestimo(TModulo3 *modulo, TModulo1 * mod1, TModulo2 *mod2, TEmprestimo emp);
void EfetuarPagamento(TModulo3 *modulo, TModulo1 *mod1, TEmprestimo borrow);
void RelatorioMensal(TModulo3 mod3, int mes);
void ColocarOrdemAlfabetica(TModulo2 *mod2);
void MSG_MENU();
void MSG_SUBMENU(int numero_modulo);
void SubMenuModulo1(TModulo1 *modulo, TLivro book);
void SubMenuModulo2(TModulo2 *modulo, TUsuario user);
void SubMenuModulo3(TModulo3 *modulo, TEmprestimo borrow, TModulo2 *mod2, TModulo1 *mod1, TUsuario user);

