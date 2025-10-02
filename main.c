#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct transacao {
    char tipo[10];
    double valor;
    struct tm *local;
    time_t timestamp;
};

struct Usuario {
    char nome[50];
    int idade;
    int numeroConta;
    char senha[8];
    double saldo;

    struct transacao historico[100];

    int numeroTransacoes;
};


void registrarTransacao (struct Usuario *u, const char *tipo, double valor) {
    int indice = u->numeroTransacoes;

    strcpy(u->historico[indice].tipo, tipo);
    u->historico[indice].valor = valor;

    time(&u->historico[indice].timestamp);

    u->numeroTransacoes++;
}

double verificaSaldo (const struct Usuario *u) {
    return u->saldo;
}


void exibirExtrato(struct Usuario *u) {
    for (int i = 0; i < u->numeroTransacoes; i++) {
        struct transacao t = u->historico[i];
        struct tm *local = localtime(&t.timestamp);

        int dia = local->tm_mday;
        int mes = local->tm_mon + 1;
        int ano = local->tm_year + 1900;

        printf("Data: %02d/%02d/%d | Tipo: %s | valor: R$ %.2f\n", dia, mes, ano, t.tipo, t.valor );
    }
    printf("-------------------------\n");
    printf("Saldo: %.2f\n", verificaSaldo(u));
}


void depositar (struct Usuario *u, double valor) {

    if (u == NULL) {
        printf("Erro: Usuário invalido. \n");
        return;
    }

    if (valor <= 0) {
        printf("Erro: Valor do depósito deve ser maior que 0. \n");
        return;
    }

    u->saldo += valor;

    registrarTransacao(u, "DEPOSITO", valor);
}

void sacar (struct Usuario *u, double valor) {

    if (u-> saldo < valor) {
        printf("Não foi possível sacar o valor de R$ %.2f, saldo atual é de R$ %.2f", valor, u->saldo);
        return;
    }

    u->saldo -= valor;

    registrarTransacao(u, "SAQUE", valor);
}

 bool login(struct  Usuario *u, int numeroConta, const char *senha) {
    if (u->numeroConta != numeroConta || strcmp(senha, u->senha) != 0) {
        return false;
    }
    return true;
}


int main(void) {
    setlocale(LC_ALL, "Portuguese");

    struct Usuario u;
    strcpy(u.nome, "Cliente 1");
    u.numeroConta = 12345;
    strcpy(u.senha, "123");
    u.numeroTransacoes = 0;

    int numeroContaInput;
    char senhaInput[8];
    double valor;
    char opcao;
    char continua = 's';
    int tentativas = 0;
    const int MAX_TENTATIVAS = 3;
    bool logado = false;

    u.saldo = 150.25;


    printf("\n--- Bem-vindo ao Caixa Eletronico ---\n");
    printf("Faça login para visualizar as opções \n");

    while (!logado && tentativas < MAX_TENTATIVAS) {
        printf("Digite o numero da conta: ");
        scanf("%d", &numeroContaInput);

        printf("Digite sua senha: ");
        scanf("%s", senhaInput);

        if (login(&u, numeroContaInput, senhaInput)) {
            logado = true;
            printf("\nLogin bem-sucedido! Bem-vindo, %s.\n", u.nome);
        } else {
            printf("Numero de conta ou senha invalidos! Tente novamente.\n");
            tentativas++;
        }
    }

    if (logado == true) {
        while (continua == 's' || continua == 'S') {

            printf("\n (s) Sacar\n");
            printf(" (d) Depositar\n");
            printf(" (v) Visualizar Saldo\n");
            printf(" (e) Extrato de Transacoes\n");
            printf("Escolha uma das opcoes: ");

            scanf(" %c", &opcao);

            switch (opcao) {
                case 's':
                case 'S':
                    printf("\n--- Saque ---\n");
                    printf("Digite o valor que deseja sacar: ");
                    scanf("%lf", &valor);
                    sacar(&u, valor);
                    printf("Realizado o saque de R$ %.2f com sucesso! \n", valor);
                    break;
                case 'd':
                case 'D':
                    printf("\n--- Deposito ---\n");
                    printf("Digite o valor que deseja depositar: ");
                    scanf("%lf", &valor);
                    depositar(&u, valor);
                    printf("Deposito de R$ %.2f realizado com sucesso! \n", valor);
                    break;
                case 'v':
                case 'V':
                    printf("\n--- Saldo ---\n");
                    printf("R$ %.2f", verificaSaldo(&u));
                    break;
                case 'e':
                case 'E':
                    printf("\n--- Extrato de Transacoes ---\n");
                    exibirExtrato(&u);
                    break;
                default:
                    printf("Opcao invalida! Por favor, tente novamente.\n");
                    break;
            }

            printf("\nDeseja fazer outra operacao? (s/n): ");
            scanf(" %c", &continua);
        }
    }else {
        printf("\nNumero maximo de tentativas de login atingido. Encerrando o programa.\n");
    }

    printf("\nObrigado por usar nosso banco!\n");

    return 0;
}