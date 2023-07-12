#include <stdio.h> // biblioteca de cominicação com o úsuario
#include <stdlib.h> // bibliogeca de aloação de espaço e memoria
#include <locale.h> // biblioteca de aloção de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string 
   
   int registro() // funcão responsavél por cadrastar os úsuarios no sistema 
{
 // inicio da criação de variaveis/strings
   char arquivo[40]; 
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
 // final da criação de variaveis

   printf ("Digite o CPF a ser cadrastado: "); // coletando as informacões do usuario
   scanf ("%s", cpf); // refere-se as strings
   strcpy(arquivo, cpf); // reponsavél por copiar os valores das string 

   FILE *file; // criar o arquivo
   file = fopen(arquivo, "w"); //criar arquivo o "w" significa escrever
   fprintf (file, cpf); // salvar o valor da variavel
   fclose (file); //fechar o arquivo
   
   file = fopen (arquivo, "a"); // criar o arquivo o "a" significa arquivar
   fprintf (file,","); 
   fclose (file); // responsavel por fechar o arquivo

   printf("Digite o nome a ser cadastrado: "); // responsavel por cuidar dos valores do usuario
   scanf ("%s", nome); // refere-se as strings

   file = fopen (arquivo, "a"); // abertura do arquivo o "a" significa arquivar
   fprintf (file, nome); // responsavél por ler o aquivo
   fclose (file); // fechar o arquivo

   file = fopen (arquivo, "a"); 
   fprintf (file,",");
   fclose (file);

   printf("Digite o sobrenome a ser cadastrado: "); // responsáel por cuidar os valores do usuario

   scanf ("%s", sobrenome); // refece-se as strings

   file = fopen(arquivo, "a"); // responsavel por criar o arquivo o "a" signifca arquivar
   fprintf (file, sobrenome); // responsavel por ler o arquivo
   fclose (file); // responsavel por fechar o arquivo
  
   file = fopen (arquivo, "a"); // responsavel por criar o arquivo o "a" signifca arquivar
   fprintf (file,",");
   fclose (file); // responsavel por fechar o arquivo

   printf ("Digite o cargo a ser cadastrado: "); // responsavel por cuidar dos valores do usuario
   scanf ( "%s", cargo); // refere-se as strings

   file = fopen (arquivo, "a"); //responsavel por criar o arquivo o "a" signifca arquivar
   fprintf( file, cargo); // responsavel por ler o arquivo 
   fclose (file); // responsavel por fechar o arquivo

   system ("pause"); // responsavel por pausar a tela
   
}


   int consultar() // funcão responsavel por consultar os dados do úsuario
   {
   
    setlocale ( LC_ALL, "protuguese"); // definição de linguagem
     
     // inicio da criação de variaveis/strings

    char cpf[40]; 
    char conteudo [200];
    
    printf ("Digite o CPF a ser consultado: "); // responsavel por cuidar dos valores do usuario
    scanf ( "%s", cpf); // refere-se strings 

    FILE *file; // criacao do arquivo
    file = fopen(cpf, "r"); // esponsavel por criar o arquivo o "r" significa ler

    if (file == NULL) // responsavel por 
    {
    
    printf ("\nNão foi possivel abrir o arquivo, não localizado!\n\n ");    

        }
       while (fgets(conteudo, 200, file) != NULL)
       {
        printf( "\nEssas são as informacões do usuario: \n\n");
        printf ("%s", conteudo);
        printf ("\n\n");
       }


        fclose(file);
        system("pause");
     
   }

        int deletar()

      {
        char cpf[40];
     
       printf("Digite o CPF a ser deletado: \n");
       scanf ("%s", cpf);
       system("pause");
     
       remove (cpf);

       FILE *file;
        file = fopen (cpf, "r");
       fclose (file);

       if (file == NULL) 
       {
        printf ("usúario não se encontra no sistema! \n");
        system("pause");
       }
      }
        int main()
      {
        int opcao=0; //definições de Variaveis
        int laco=1;
        char senhadigitada[]="a";
        int comparacao;

        printf (" -- Cartório da Ebac -- \n\n");
        printf ("Login de Administrador!\n\n Digite a sua senha:");
        scanf ("%s", senhadigitada);

       comparacao =  strcmp (senhadigitada, "admin");

       if (comparacao == 0)
         {
          system("cls");
          for (laco=1; laco=1;)
          {
    
          system ("cls"); // limpar a tela

          setlocale ( LC_ALL, "protuguese"); // definição de linguagem

          printf (" -- Cartório da Ebac -- \n\n "); // inicio do menu
          printf ("Escolha a opção desejada no menu \n\n");
          printf ("\t-1 Registro de Nomes\n");
          printf ("\t-2 Consultar nomes\n");
          printf ("\t-3 Excluír Nomes\n\n"); //fim do menu
          printf ("\t-4 Sair do sistema \n\n");
          printf ("Opção:");
          scanf ("%d", &opcao); // armazenando a escolha do usuario
   
           system ("cls"); // responsável por limpar a tela

           switch (opcao) //inicio das selecões 
            {   
             case 1: // camada de funcões
             registro();
             break;
        
             case 2:
             consultar();
             break;

             case 3:
             deletar();
             break;
        
             case 4:
             printf("Obrigado por ultilizar o sistema!\n\n");
             return 0;
             break;

             default:
             printf ("Essa opção não está disponivel\n");
             system("pause");
             break;
            }

           } 
         
          } 
          
          else 
          printf ( "Senha digitada incorreta!\n\n");
       }
