## Sobre o Projeto

Este projeto é uma simulação de um sistema bancario desenvolvido em linguagem C. Ele permite que os usuários realizem operações bancárias básicas como login, depósito, saque, consulta de saldo e visualização de extrato de transações através de uma interface de linha de comando.

## Funcionalidades

*   **Login de Usuário:** Autenticação com número de conta e senha.
*   **Depósito:** Adiciona fundos à conta do usuário.
*   **Saque:** Retira fundos da conta do usuário, com verificação de saldo.
*   **Consulta de Saldo:** Exibe o saldo atual da conta.
*   **Extrato de Transações:** Mostra um histórico detalhado de todas as transações (depósitos e saques) com data e valor.

## Construído com

*   **Linguagem C**

## ✅ Pré-requisitos

Para compilar e executar este programa, você precisará de um compilador C instalado em seu sistema. O GCC (GNU Compiler Collection) é o mais comum e recomendado.

### 💻 GCC (GNU Compiler Collection)

Você pode verificar se o GCC está instalado com:

```shell
gcc --version
```

Se não estiver instalado, você pode instalá-lo no Linux (Ubuntu/Debian) via terminal:

```shell
sudo apt update
sudo apt install build-essential
```

Para outros sistemas operacionais, consulte a documentação oficial do GCC ou um gerenciador de pacotes apropriado.

## 🚀 Como Compilar e Executar

1.  **Clone o repositório (ou baixe o arquivo `main.c`):**

    ```
    git clone https://github.com/Rodrigodx/sistema-bancario-simples
    cd <sistema-bancario-simples>
    ```

2.  **Compile o código-fonte:**

    ```
      gcc main.c -o caixa_eletronico
    ```

3.  **Execute o programa:**

    ```
    ./sistema-bancario-simples
    ```

## 💡 Uso do Programa

Ao executar o programa, você será solicitado a fazer login com um número de conta e senha. Após o login bem-sucedido, um menu de opções será exibido:

1.  **Login:**
    *   Número da Conta: `12345`
    *   Senha: `123`

2.  **Menu de Operações:**
    *   `(s)` Sacar
    *   `(d)` Depositar
    *   `(v)` Visualizar Saldo
    *   `(e)` Extrato de Transações

Siga as instruções na tela para interagir com o sistema.

## 🤝 Contribuindo

Contribuições são bem-vindas! Se você deseja contribuir para este projeto, por favor, siga os passos abaixo:

1.  Faça um Fork do projeto.
2.  Crie uma nova Branch para sua feature (`git checkout -b feature/sua-feature`).
3.  Faça suas alterações e commit (`git commit -m 'Adiciona nova feature'`).
4.  Envie para a sua Branch (`git push origin feature/sua-feature`).
5.  Abra um Pull Request.

## 👤 Contato

Para dúvidas ou sugestões, entre em contato:

*   **Rodrigo Correia** - [LinkedIn](https://www.linkedin.com/in/rodrigobcorreia)
*   **E-mail:** rodrigodx52@gmail.com
