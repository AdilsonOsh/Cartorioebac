#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsasvel por cadastrar os usu�rios no sistema
{   
    //inicio da cria��o das vari�veis/string
    char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o das vari�veis/string
    
    printf("Digite o CPF o ser cadastrado: \n"); // coleta das informa��es do usu�rio
    scanf("%s", cpf); //%s significa string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Cria o arquivo w de write/escrever
    fprintf(file,cpf); //Salva o valor da vari�vel cpf
    fclose(file);  // Fecha o arquivo
      
    file = fopen(arquivo, "a"); //Abrindo o arquivo com fopen e a de atualizar
    fprintf(file, ","); // virgula para separa��o dos arquivos
    fclose(file); // Fechamento do arquivo
      
    printf("Digite o nome a ser cadastrado: \n");  //Perguntando nome do usu�rio
    scanf("%s",nome); //Vari�vel nome
      
    file = fopen(arquivo, "a");  //Atualiza��o de informa��es com a inclus�o do nome
    fprintf(file,nome); //Salvando vari�vel nome
	fclose(file); //fecha o arquivo
      
    file = fopen(arquivo, "a");  //Adicionando outro espa�amento
    fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //Perguntando sobrenome do usu�rio
    scanf("%s",sobrenome); //Armazenar a informa��o
      
    file = fopen(arquivo, "a"); //Abrindo o arquivo/salvando e atualizando
    fprintf(file,sobrenome); //Salvando a vari�vel sobrenome
	fclose(file); //fecha o arquivo 
      
    file = fopen(arquivo, "a"); //Adicionando outro espa�o
    fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n"); //Perguntando o cargo ao usu�rio
    scanf("%s",cargo); //Armazenando a vari�vel cargo
      
    file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizar os novos dados
    fprintf(file,cargo); //Colocando a informa��o de cargo
	fclose(file); // Fechando o arquivo
	
	system("pause"); //Tela Pause
    
}
  
int consulta()
{ 
    setlocale(LC_ALL, "Portuguese"); //Defindo a linguagem no caso Portugues
    
    char cpf[40]; //Localizando o arquivo CPF
    char conteudo[200]; //Armazenando o conteudo do arquivo
    
    printf("Digite o CPF a ser consultado: \n"); //Perguntando ao usu�rio o CPF
    scanf("%s",cpf); //Salvando na vari�vel
    
    FILE *file; //Acessando o arquivo
    file = fopen(cpf,"r"); //Abrindo o arquivo cpf e lendo com r/read
    
    if(file == NULL) //Valida��o do arquivo
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Mensagem do arquivo n�o valida
	}
    
    while(fgets(conteudo, 200, file) != NULL) //Buscando arquivos dentro dos caracteres
    {
    	printf("\nEssas s�o as informa��es do usu�rio: \n"); //Mensagem ao encontrar o arquivo
    	printf("%s", conteudo); //Salvando o conte�do da string
    	printf("\n\n"); //Espa�amento
    	
	}
    fclose(file); //Fechando o arquivo
    system("pause"); //Tela Pause
    
}
 
int deletar()
{   
    char cpf[40]; //Localizando o arquivo CPF

    printf("Digite o CPF do usu�rio a ser deletado: "); //Mensagem ao usu�rio no sub menu
    scanf("%s",cpf); //String cpf
    
    
    FILE *file; //Acessando e buscando o arqivo
    file = fopen(cpf,"r"); //Abrindo e lendo o arquivo cpf
    fclose(file); //Fechando o arquivo
    
    if(file == NULL) //Opera��o de compara��o se o arquivo for igual a nulo
    {
    	printf("O usu�rio n�o se encontra no sistema \n"); //Mensagem ao usu�rio se o arquivo n�o existe
    	system("pause"); //Tela pause
	}
	
	else //Comparando a instru��o anterior e alterando para outra a��o
	{
	    remove(cpf); //Fun��o para deletar
		printf("CPF deletado com sucesso\n"); //Mensagem ao usu�rio ao deletar
    	system("pause"); //Tela de pause		
	}
	
}

int main ()
   {  
   int opcao=0; //Definindo vari�veis
   int laco=1;
   
   for(laco=1;laco=1;)
   {    
   
        system("cls");

        setlocale(LC_ALL, "Portuguese"); //Defindo a linguagem 
   
        printf(" Cart�rio da EBAC \n\n"); //inicio do menu
        printf("\tMENU\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o:"); //fim do menu
   	
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
   
        system("cls"); //Responsavel por limpar a tela
        
        
        switch(opcao) //Inicio da sele��o menu
        { 
           case 1:
           registro();
           break; 
           
           case 2:
           consulta();
           break;
           
           case 3:
           deletar(); 
           break;
           
           case 4:
           printf("Obrigado por utilizar o sistema");
           return 0;
           break;
           
           default: 
           printf("Op��o n�o disponivel\n"); 
           system("pause");
           break;
		} //fim da sele��o menu
        
   }
}
