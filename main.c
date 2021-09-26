#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "cabecalho.h"

struct Cliente
{
    char nome_usuario[39], email_usuario[39], login_usuario[19], senha_usuario[19], confirma_senha[19];
};

struct Registro
{
    char login_registro[30], senha_registro[30], plataforma_registro[30];
};

struct Registro_Matriz
{
    int login_registro[2][15], senha_registro[2][15], plataforma_registro[2][15];
};

//Escopo Global para utilização na função de contagem
//- Tratamento de erro, inserção de dados em branco.

struct Cliente dados;

//int contador_string(){

//}

int main()
{

    //Arquivo
    FILE *arq_cadastro;

    //Estruturas
    struct Registro dados_registro[6];
    struct Registro_Matriz dados_registro_cript[6];
    struct Registro_Matriz dados_registro_descript[6];

    //Validacao
    int escolha_plataforma, escolha_senha_segura;
    int menu_opcao = 0;
    char nome2_usuario[30], email2_usuario[30], login2_usuario[30], senha2_usuario[30];
    char login_input[30], senha_input[30], login_input2[30], senha_input2[30];

    // Fixo do cabeçalho do arquivo.
    char texto1[40], texto2[40], texto3[40], texto4[40];

    //Flags e limitadores
    int flag_login = 0, flag_registro = 0, flag_senha = 0, flag_descript = 0, flag_visualizar_dados = 1;
    int limite_plataforma = 6;
    int flag_limite_tamanho_string = 1;
    int size_nomeUsuario, size_emailUsuario, size_loginUsuario, size_senhaUsuario;

    //Variaveis de para criptografar
    char texto[33];
    float matriz_a[2][2], matriz_b[2][2];
    float matriz_n[2][2];
    int determinante;
    int tamanho, metade_tamanho;
    int texto_asc[2][15], texto_asc_cript[2][15], texto_asc_descript[2][15], temporario1, temporario2;
    float temporario3, temporario4;
    int copia_metade_tamanho, copia_tamanho;

    //Variaveis para teste
    int aleatorio;
    //int vetorTeste[22];
    char senhaForte[20] = "aaaaaaaaaaaaaaa";
    //char testeSenha[14];

    //sugestaoSenha(senhaForte);
    //printf("%s \n", senhaForte);

    //Contador
    // int i = 0, j = 0, k = 0, l = 0;

    //aleatorio = numero_aleatorio(4,10);
    //printf("n aleatorio: %d \n", aleatorio);

    //--------------------------------------------------------
    //              Matrizes
    //--------------------------------------------------------
    matriz_a[0][0] = numero_aleatorio(1, 4);
    matriz_a[0][1] = numero_aleatorio(4, 8);
    matriz_a[1][0] = numero_aleatorio(8, 12);
    matriz_a[1][1] = numero_aleatorio(12, 16);

    //printf("matriz: %f \n", matriz_a[0][0]);
    //printf("matriz: %f \n", matriz_a[0][1]);
    //printf("matriz: %f \n", matriz_a[1][0]);
    //printf("matriz: %f \n", matriz_a[1][1]);

    matriz_b[0][0] = matriz_a[1][1];
    matriz_b[0][1] = matriz_a[0][1] * (-1);
    matriz_b[1][0] = matriz_a[1][0] * (-1);
    matriz_b[1][1] = matriz_a[0][0];

    determinante = ((matriz_a[0][0] * matriz_a[1][1]) - (matriz_a[0][1] * matriz_a[1][0]));

    matriz_n[0][0] = matriz_b[0][0] / determinante;
    matriz_n[0][1] = matriz_b[0][1] / determinante;
    matriz_n[1][0] = matriz_b[1][0] / determinante;
    matriz_n[1][1] = matriz_b[1][1] / determinante;

    //----------------------------------------------------------
    //                  Login
    //----------------------------------------------------------

    do
    {
        printf("Bem-vindo ao CriptoC: \n");
        printf("Voce ja possui cadastro: 1-sim 2-nao -->: ");
        scanf("%d", &menu_opcao);
        system("cls");

    } while (menu_opcao < 1 || menu_opcao > 2);

    switch (menu_opcao)
    {
    case 1:

        arq_cadastro = fopen("dados_cadastro.txt", "r");
        
        
        fscanf(arq_cadastro, "%s %s", texto1, nome2_usuario);
        fscanf(arq_cadastro, "%s %s", texto2, login2_usuario);
        fscanf(arq_cadastro, "%s %s", texto3, email2_usuario);
        fscanf(arq_cadastro, "%s %s", texto4, senha2_usuario);
        fclose(arq_cadastro);

        printf("Bem vindo ao Cripto-C\n");
        printf("Faca seu login para continuar\n\n");

        getchar();
        printf("Digite seu login -->: ");
        scanf("%[^\n]", login_input);

        getchar();
        printf("Digite sua senha -->: ");
        scanf("%[^\n]", senha_input);
        getchar();

        // Sistema de loginvgggng

        do
        {

            if (strcmp(login_input, login2_usuario) == 0 && strcmp(senha_input, senha2_usuario) == 0)
            {
                system("cls");
                printf("***Login com sucesso***\n");
                flag_login = 1;

                strcpy(dados.nome_usuario, nome2_usuario);
                strcpy(dados.email_usuario, email2_usuario);
                strcpy(dados.login_usuario, login2_usuario);
                strcpy(dados.senha_usuario, senha2_usuario);
            }
            else
            {
                system("cls");
                printf("Senha ou login estao errados \n");
                printf("Tente novamente\n");

                printf("Digite seu login -->:");
                scanf("%[^\n]", login_input);
                getchar();

                printf("Digite sua senha -->:");
                scanf("%[^\n]", senha_input);
                getchar();

                flag_login = 0;
            }

        } while (flag_login < 1);

        break;

    case 2:

        printf("-------------------------------------\n");
        printf("Bem vindo a etapa de registro\n\n");
        printf("Quantidade de caracteres permitidas: \n");
        printf("-NOME--: MIN: 1 || MAX: 40 \n");
        printf("-EMAIL-: MIN: 10|| MAX: 40 \n");
        printf("-LOGIN-: MIN: 1 || MAX: 20 \n");
        printf("-SENHA-: MIN: 1 || MAX: 20 \n");
        printf("-------------------------------------\n");

        do
        {
            getchar(); // Limitado a 40
            printf("Digite seu nome  -->: ");
            scanf("%[^\n]", dados.nome_usuario);
            getchar();

            printf("Digite seu email -->: "); // Limitado a 40
            scanf("%[^\n]", dados.email_usuario);
            getchar();

            printf("Digite seu login -->: "); // Limitado a 15
            scanf("%[^\n]", dados.login_usuario);
            getchar();

            //Sugestao de senha
            escolha_senha_segura = 0;
            printf("Voce deseja ver uma sugestao de senha forte? 1-sim 2-nao (leva 15 segundos): ");
            scanf("%d", &escolha_senha_segura);
            if (escolha_senha_segura == 1)
            {
                sugestaoSenha(senhaForte);
                printf("A nossa sugestao: %s \n", senhaForte);
            }

            getchar();

            printf("Digite sua senha -->: "); // Limitado a 15
            scanf("%[^\n]", dados.senha_usuario);
            getchar();

            printf("Confirme sua senha -->: ");
            scanf("%[^\n]", dados.confirma_senha);
            getchar();

            size_nomeUsuario = tamanhoString(dados.nome_usuario);
            size_emailUsuario = tamanhoString(dados.email_usuario);
            size_loginUsuario = tamanhoString(dados.login_usuario);
            size_senhaUsuario = tamanhoString(dados.senha_usuario);
            //printf("Size: %d \n", size_nomeUsuario);
            // printf("Size: %d \n", size_emailUsuario);
            // printf("Size: %d \n", size_loginUsuario);
            // printf("Size: %d \n", size_senhaUsuario);

            if (size_nomeUsuario < 1 || size_emailUsuario < 10 || size_loginUsuario < 1 || size_senhaUsuario < 1 || size_nomeUsuario > 40 || size_emailUsuario > 40 || size_loginUsuario > 15 || size_senhaUsuario > 20)
            {
                system("cls");
                printf("Preenchimento incompleto e/ou fora dos parametros !\n");
                printf("Pressione enter para continuar com o registro ->");
                flag_registro = 0;
            }
            else
            {
                flag_registro = 1;
            }

        } while (flag_registro < 1);

        do
        {
            if (strcmp(dados.senha_usuario, dados.confirma_senha) == 0)
            {
                flag_senha = 1;
            }
            else
            {

                system("cls");
                printf("As senhas nao correspondem\n");
                printf("Tente novamente\n");

                printf("Digite sua senha -->: ");
                scanf("%[^\n]", dados.senha_usuario);
                getchar();

                printf("Confirme sua senha -->: ");
                scanf("%[^\n]", dados.confirma_senha);
                getchar();
                flag_senha = 0;
            }

        } while (flag_senha < 1);

        printf("\n");
        printf("Usuario cadastrado com sucesso: \n");
        printf("Nome : %s \n", dados.nome_usuario);
        printf("Login: %s \n", dados.login_usuario);
        printf("Email: %s \n", dados.email_usuario);
        printf("Senha: %s \n", dados.senha_usuario);
        printf("\n");
        //
        strcpy(login2_usuario, dados.login_usuario);
        strcpy(senha2_usuario, dados.senha_usuario);

        //Passando os dados para um arquivo
        arq_cadastro = fopen("dados_cadastro.txt", "w");
        if (arq_cadastro == NULL){
            printf("Erro para abrir um arquivo \n");
            exit(1);
        }

        fprintf(arq_cadastro, "Nome: %s \n", dados.nome_usuario);
        fprintf(arq_cadastro, "Login: %s \n", dados.login_usuario);
        fprintf(arq_cadastro, "Email: %s \n", dados.email_usuario);
        fprintf(arq_cadastro, "Senha: %s \n", dados.senha_usuario);

        fclose(arq_cadastro);
        break;
    }

    while (limite_plataforma > 5)
    {
        printf("Digite a quantidade de registros que voce quer fazer: \n");
        printf("(limite de registros 5) -->: ");
        scanf("%d", &limite_plataforma);
    }

    if (limite_plataforma == 0)
    {
        return 0;
    }
    //-----------------------------------------------------
    //Incio do registro dos dados para serem criptografados
    //-----------------------------------------------------
    getchar();
    for (int i = 1; i <= limite_plataforma; i++)
    {
        flag_limite_tamanho_string = 1;
        while (flag_limite_tamanho_string == 1)
        { //fflush(stdin);
            system("cls");
            printf("======================================= \n");
            printf("Inicio de registro %d \n", i);
            printf("-------------------------------------\n");
            printf("Quantidade de caracteres permitidas: \n");
            printf("-PLATAFORMA-: MAX: 30 \n");
            printf("-LOGIN------: MAX: 30 \n");
            printf("-SENHA------: MAX: 30 \n");
            printf("-------------------------------------\n");

            printf("EM CASO DE ENTRADAS VAZIAS SERA RETORNADO LIXO DE MEMORIA !!!!!\n\n");
        
            printf("Qual a plataforma: ");
            scanf("%[^\n]", dados_registro[i].plataforma_registro);
            getchar();
            tamanho = 0;
            tamanho = tamanhoString(dados_registro[i].plataforma_registro);
            if (tamanho == 0)
            {
                dados_registro[i].plataforma_registro[0] = 32;
                dados_registro[i].plataforma_registro[1] = '\0';
            }
            //printf("Tamanho: %d \n", tamanho);
            if (tamanho % 2 != 0 && tamanho != 0)
            {
                dados_registro[i].plataforma_registro[tamanho + 1] = '\0';
                dados_registro[i].plataforma_registro[tamanho] = 32;
            }
            if (tamanho > 30)
            {
                flag_limite_tamanho_string = 1;
                printf("Tamanho superior ao permitido, digite novamente. \n");
            }
            else
            {
                flag_limite_tamanho_string = 0;
            }
            //printf("tamanho do nome da plataforma: %d \n", tamanho);
        }

        flag_limite_tamanho_string = 1;
        while (flag_limite_tamanho_string == 1)
        {
            fflush(stdin);
            printf("Digite o login: ");
            scanf("%[^\n]", dados_registro[i].login_registro);
            getchar();
            tamanho = 0;
            tamanho = tamanhoString(dados_registro[i].login_registro);
            if (tamanho == 0)
            {
                dados_registro[i].login_registro[0] = 32;
                dados_registro[i].login_registro[1] = '\0';
            }
            if (tamanho % 2 != 0 && tamanho != 0)
            {
                dados_registro[i].login_registro[tamanho + 1] = '\0';
                dados_registro[i].login_registro[tamanho] = 32;
            }
            if (tamanho > 30)
            {
                flag_limite_tamanho_string = 1;
                printf("Tamanho superior ao permitido, digite novamente. \n");
            }
            else
            {
                flag_limite_tamanho_string = 0;
            }
            //printf("tamanho do login: %d \n", tamanho);
        }

        flag_limite_tamanho_string = 1;
        while (flag_limite_tamanho_string == 1)
        {
            fflush(stdin);

            printf("Digite a senha: ");
            scanf("%[^\n]", dados_registro[i].senha_registro);
            getchar();
            tamanho = 0;
            tamanho = tamanhoString(dados_registro[i].senha_registro);
            if (tamanho == 0)
            {
                dados_registro[i].senha_registro[0] = 32;
                dados_registro[i].senha_registro[1] = '\0';
            }
            if (tamanho % 2 != 0 && tamanho != 0)
            {
                dados_registro[i].senha_registro[tamanho + 1] = '\0';
                dados_registro[i].senha_registro[tamanho] = 32;
            }
            if (tamanho > 30)
            {
                flag_limite_tamanho_string = 1;
                printf("Tamanho superior ao permitido, digite novamente. \n");
            }
            else
            {
                flag_limite_tamanho_string = 0;
            }
            //printf("tamanho da senha: %d \n", tamanho);
        }
    }
    //dados_registro[1].plataforma_registro[3] = 'f';
    //printf("string:  %s \n", dados_registro[1].plataforma_registro);

    /* code */

    //----------------------------------------------------------
    // CRIPTOGRAFANDO O NOME DA PLATAFORMA
    //----------------------------------------------------------
    //printf("Digite uma string: \n");
    //scanf("%[^\n]", texto);

    for (int k = 1; k <= limite_plataforma; k++)
    {
        /* code */

        strcpy(texto, dados_registro[k].plataforma_registro);
        //tamanho = strlen(texto);
        tamanho = tamanhoString(texto);
        metade_tamanho = tamanho / 2;
        copia_metade_tamanho = metade_tamanho;
        // printf("Tamanho da string: %d \n", tamanho);

        //--------------------------------------------------------
        //              Passando o texto para uma matriz
        //--------------------------------------------------------
        //
        for (int i = 0; i < metade_tamanho; i++)
        {
            texto_asc[0][i] = texto[i];
            //dados_registro_cript[0].plataforma_registro[0][i] = texto[i];
            //printf("Na estrutura: %d \n",dados_registro_cript[0].plataforma_registro[0][i]);
            //printf("No outro: %d \n", texto_asc[0][i]);
        }
        for (int j = 0; j < metade_tamanho; j++)
        {
            texto_asc[1][j] = texto[copia_metade_tamanho];
            //dados_registro_cript[0].plataforma_registro[1][j] = texto[copia_metade_tamanho];
            //printf("Na estrutura: %d \n", dados_registro_cript[0].plataforma_registro[1][j]);
            //printf("No outro: %d \n", texto_asc[1][j]);
            copia_metade_tamanho++;
        }

        //--------------------------------------------------------
        //                      Criptografando
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario1 = matriz_a[0][0] * texto_asc[0][i];
            temporario2 = matriz_a[0][1] * texto_asc[1][i];
            //dados_registro_cript[0].plataforma_registro[0][i] = temporario1 + temporario2;
            texto_asc_cript[0][i] = temporario1 + temporario2;
            dados_registro_cript[k].plataforma_registro[0][i] = texto_asc_cript[0][i];
            //printf("Cript: %d \n", dados_registro_cript[0].plataforma_registro[0][i]);
        }

        for (int j = 0; j < metade_tamanho; j++)
        {
            temporario1 = matriz_a[1][0] * texto_asc[0][j];
            temporario2 = matriz_a[1][1] * texto_asc[1][j];
            //dados_registro_cript[0].plataforma_registro[0][j] = temporario1 + temporario2;
            texto_asc_cript[1][j] = temporario1 + temporario2;
            dados_registro_cript[k].plataforma_registro[0][j] = texto_asc_cript[1][j];
            //printf("Cript: %d  \n", dados_registro_cript[0].plataforma_registro[0][j]);
        }

        //--------------------------------------------------------
        //                      Descriptografando PLATAFORMA
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario3 = matriz_n[0][0] * texto_asc_cript[0][i];
            temporario4 = matriz_n[0][1] * texto_asc_cript[1][i];
            //dados_registro_descript[0].plataforma_registro[0][i] = temporario3 + temporario4 + 0.111;
            texto_asc_descript[0][i] = temporario3 + temporario4 + 0.111;
            dados_registro_descript[k].plataforma_registro[0][i] = texto_asc_descript[0][i];
            //printf("Descript: %d \n",dados_registro_descript[0].plataforma_registro[0][i]);
        }

        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario3 = matriz_n[1][0] * texto_asc_cript[0][i];
            temporario4 = matriz_n[1][1] * texto_asc_cript[1][i];
            //dados_registro_descript[0].plataforma_registro[1][i] = temporario3 + temporario4 + 0.111;
            texto_asc_descript[1][i] = temporario3 + temporario4 + 0.111;
            dados_registro_descript[k].plataforma_registro[1][i] = texto_asc_descript[1][i];
            //printf("Descript: %d \n", dados_registro_descript[0].plataforma_registro[1][i]);
        }

        //----------------------------------------------------------
        // CRIPTOGRAFANDO O LOGIN
        //----------------------------------------------------------
        //printf("Digite uma string: \n");
        //scanf("%[^\n]", texto);

        strcpy(texto, dados_registro[k].login_registro);
        //tamanho = strlen(texto);
        tamanho = tamanhoString(texto);
        metade_tamanho = tamanho / 2;
        copia_metade_tamanho = metade_tamanho;
        // printf("Tamanho da string: %d \n", tamanho);

        //--------------------------------------------------------
        //              Passando o texto para uma matriz
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            texto_asc[0][i] = texto[i];
            //printf("%d \n", texto_asc[0][i]);
        }
        for (int j = 0; j < metade_tamanho; j++)
        {
            texto_asc[1][j] = texto[copia_metade_tamanho];
            copia_metade_tamanho++;
            //printf("%d \n", texto_asc[1][j]);
        }

        //--------------------------------------------------------
        //                      Criptografando LOGIN
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario1 = matriz_a[0][0] * texto_asc[0][i];
            temporario2 = matriz_a[0][1] * texto_asc[1][i];
            //dados_registro_cript[0].login_registro[0][i] = temporario1 + temporario2;
            texto_asc_cript[0][i] = temporario1 + temporario2;
            dados_registro_cript[k].login_registro[0][i] = texto_asc_cript[0][i];
            //printf("Cript: %d \n", dados_registro_cript[0].login_registro[0][i]);
        }

        for (int j = 0; j < metade_tamanho; j++)
        {
            temporario1 = matriz_a[1][0] * texto_asc[0][j];
            temporario2 = matriz_a[1][1] * texto_asc[1][j];
            //dados_registro_cript[0].login_registro[0][j] = temporario1 + temporario2;
            texto_asc_cript[1][j] = temporario1 + temporario2;
            dados_registro_cript[k].login_registro[0][j] = texto_asc_cript[1][j];
            //printf("Cript: %d \n", dados_registro_cript[0].login_registro[0][j]);
        }

        //--------------------------------------------------------
        //                      Descriptografando
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario3 = matriz_n[0][0] * texto_asc_cript[0][i];
            temporario4 = matriz_n[0][1] * texto_asc_cript[1][i];
            //dados_registro_descript[0].login_registro[0][i] = temporario3 + temporario4 + 0.111;
            texto_asc_descript[0][i] = temporario3 + temporario4 + 0.111;
            dados_registro_descript[k].login_registro[0][i] = texto_asc_descript[0][i];
            //printf("Descript: %d  \n", dados_registro_descript[0].login_registro[0][i]);
            //printf("%d \n", texto_asc_descript[0][i]);
        }

        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario3 = matriz_n[1][0] * texto_asc_cript[0][i];
            temporario4 = matriz_n[1][1] * texto_asc_cript[1][i];
            //dados_registro_descript[0].login_registro[1][i] = temporario3 + temporario4 + 0.111;
            texto_asc_descript[1][i] = temporario3 + temporario4 + 0.111;
            dados_registro_descript[k].login_registro[1][i] = texto_asc_descript[1][i];
            //printf("Descript: %d  \n", dados_registro_descript[0].login_registro[1][i]);
            //printf("%d \n", texto_asc_descript[1][i]);
        }

        //----------------------------------------------------------
        // CRIPTOGRAFANDO O SENHA
        //----------------------------------------------------------
        //printf("Digite uma string: \n");
        //scanf("%[^\n]", texto);

        strcpy(texto, dados_registro[k].senha_registro);
        //tamanho = strlen(texto);
        tamanho = tamanhoString(texto);
        metade_tamanho = tamanho / 2;
        copia_metade_tamanho = metade_tamanho;
        // printf("Tamanho da string: %d \n", tamanho);

        //--------------------------------------------------------
        //              Passando o texto para uma matriz
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            texto_asc[0][i] = texto[i];
            //printf("%d \n", texto_asc[0][i]);
        }
        for (int j = 0; j < metade_tamanho; j++)
        {
            texto_asc[1][j] = texto[copia_metade_tamanho];
            copia_metade_tamanho++;
            //printf("%d \n", texto_asc[1][j]);
        }

        //--------------------------------------------------------
        //                      Criptografando SENHA
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario1 = matriz_a[0][0] * texto_asc[0][i];
            temporario2 = matriz_a[0][1] * texto_asc[1][i];
            //dados_registro_cript[0].senha_registro[0][i] = temporario1 + temporario2;
            texto_asc_cript[0][i] = temporario1 + temporario2;
            dados_registro_cript[k].senha_registro[0][i] = texto_asc_cript[0][i];
            //printf("Cript: %d \n", dados_registro_cript[0].senha_registro[0][i]);
        }

        for (int j = 0; j < metade_tamanho; j++)
        {
            temporario1 = matriz_a[1][0] * texto_asc[0][j];
            temporario2 = matriz_a[1][1] * texto_asc[1][j];
            //dados_registro_cript[0].senha_registro[0][j] = temporario1 + temporario2;
            texto_asc_cript[1][j] = temporario1 + temporario2;
            dados_registro_cript[k].senha_registro[0][j] = texto_asc_cript[1][j];
            //printf("Cript: %d \n", dados_registro_cript[0].senha_registro[0][j]);
        }

        //--------------------------------------------------------
        //                      Descriptografando SENHA
        //--------------------------------------------------------
        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario3 = matriz_n[0][0] * texto_asc_cript[0][i];
            temporario4 = matriz_n[0][1] * texto_asc_cript[1][i];
            //dados_registro_descript[0].senha_registro[0][i] = temporario3 + temporario4 + 0.111;
            texto_asc_descript[0][i] = temporario3 + temporario4 + 0.111;
            dados_registro_descript[k].senha_registro[0][i] = texto_asc_descript[0][i];
            //printf("Descript: %d \n", dados_registro_descript[0].senha_registro[0][i]);
            //printf("%d \n", texto_asc_descript[0][i]);
        }

        for (int i = 0; i < metade_tamanho; i++)
        {
            temporario3 = matriz_n[1][0] * texto_asc_cript[0][i];
            temporario4 = matriz_n[1][1] * texto_asc_cript[1][i];
            //dados_registro_descript[0].senha_registro[1][i] = temporario3 + temporario4 + 0.111;
            texto_asc_descript[1][i] = temporario3 + temporario4 + 0.111;
            dados_registro_descript[k].senha_registro[1][i] = texto_asc_descript[1][i];
            //printf("Descript: %d \n", dados_registro_descript[0].senha_registro[1][i]);
            //printf("%d \n", texto_asc_descript[1][i]);
        }
    }

    //---------------------------------------------
    // Vendo os dados CRIPT
    //----------------------------------------------
    system("cls");
    printf("----DADOS CRIPTOGRAFADOS----\n\n");

    for (int l = 1; l <= limite_plataforma; l++)
    {

        //Nome da plataforma
        tamanho = tamanhoString(dados_registro[l].plataforma_registro);
        metade_tamanho = tamanho / 2;

        for (int i = 0; i < metade_tamanho; i++)
        {
            printf("%d", dados_registro_cript[l].plataforma_registro[0][i]);
        }
        for (int i = 0; i < metade_tamanho; i++)
        {
            printf("%d", dados_registro_cript[l].plataforma_registro[1][i]);
        }
        printf("\n");

        //Login da plataforma
        tamanho = tamanhoString(dados_registro[l].login_registro);
        metade_tamanho = tamanho / 2;

        for (int i = 0; i < metade_tamanho; i++)
        {
            printf("%d", dados_registro_cript[l].login_registro[0][i]);
        }
        for (int i = 0; i < metade_tamanho; i++)
        {
            printf("%d", dados_registro_cript[l].login_registro[1][i]);
        }
        printf("\n");

        //Senha da plataforma
        tamanho = tamanhoString(dados_registro[l].senha_registro);
        metade_tamanho = tamanho / 2;

        for (int i = 0; i < metade_tamanho; i++)
        {
            printf("%d", dados_registro_cript[l].senha_registro[0][i]);
        }
        for (int i = 0; i < metade_tamanho; i++)
        {
            printf("%d", dados_registro_cript[l].senha_registro[1][i]);
        }
        printf("\n");
    }

    printf("==================================================\n");
    printf("==================================================\n");

    //---------------------------------------------------------
    // LOGIN PARA VER OS DADOS DESCRIPT
    //---------------------------------------------------------

    printf("Para verificar as informacoes adiante insira seu LOGIN e SENHA ! \n");
    printf("Limitado a 3 tentativas !!\n\n");

    printf("Digite seu login -->: ");
    scanf("%[^\n]", login_input2);
    getchar();

    printf("Digite sua senha -->: ");
    scanf("%[^\n]", senha_input2);
    getchar();

    do
    {
        if (strcmp(login_input2, login2_usuario) == 0 && strcmp(senha_input2, senha2_usuario) == 0)
        {
            system("cls");
            printf("***Login com sucesso***\n");

            while (flag_visualizar_dados != 0)
            {
                printf("-------------------------------------------------------\n");

                printf("Digite zero para sair \n");
                printf("Qual plataforma voce deseja ver os dados: 1-%d :\n", limite_plataforma);
                scanf("%d", &escolha_plataforma);
                flag_visualizar_dados = escolha_plataforma;
                if (escolha_plataforma <= limite_plataforma)
                {
                    //Nome da plataforma
                    tamanho = tamanhoString(dados_registro[escolha_plataforma].plataforma_registro);
                    metade_tamanho = tamanho / 2;

                    system("cls");

                    for (int i = 0; i < metade_tamanho; i++)
                    {
                        printf("%c", dados_registro_descript[escolha_plataforma].plataforma_registro[0][i]);
                    }
                    for (int i = 0; i < metade_tamanho; i++)
                    {
                        printf("%c", dados_registro_descript[escolha_plataforma].plataforma_registro[1][i]);
                    }
                    printf("\n");

                    //Login da plataforma
                    tamanho = tamanhoString(dados_registro[escolha_plataforma].login_registro);
                    metade_tamanho = tamanho / 2;

                    for (int i = 0; i < metade_tamanho; i++)
                    {
                        printf("%c", dados_registro_descript[escolha_plataforma].login_registro[0][i]);
                    }
                    for (int i = 0; i < metade_tamanho; i++)
                    {
                        printf("%c", dados_registro_descript[escolha_plataforma].login_registro[1][i]);
                    }
                    printf("\n");

                    //Senha da plataforma
                    tamanho = tamanhoString(dados_registro[escolha_plataforma].senha_registro);
                    metade_tamanho = tamanho / 2;

                    for (int i = 0; i < metade_tamanho; i++)
                    {
                        printf("%c", dados_registro_descript[escolha_plataforma].senha_registro[0][i]);
                    }
                    for (int i = 0; i < metade_tamanho; i++)
                    {
                        printf("%c", dados_registro_descript[escolha_plataforma].senha_registro[1][i]);
                    }
                    printf("\n");

                    flag_descript = 4;
                }
                else
                {
                    system("cls");
                    printf("Valor nao disponivel \n");
                }
            }
        }
        else
        {
            printf("Senha ou login estao errados \n");
            printf("Tente novamente\n");

            printf("Digite seu login -->:");
            scanf("%[^\n]", login_input2);
            getchar();

            printf("Digite sua senha -->:");
            scanf("%[^\n]", senha_input2);
            getchar();
            flag_descript++;
        }
    } while (flag_descript <= 1);

    if (flag_descript == 2)
    {
        printf("Acesso bloqueado !!!!");
        return 0;
    }

    return 0;
}
