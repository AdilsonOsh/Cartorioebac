#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsasvel por cadastrar os usuários no sistema
{   
    //inicio da criação das variáveis/string
    char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação das variáveis/string
    
    printf("Digite o CPF o ser cadastrado: \n"); // coleta das informações do usuário
    scanf("%s", cpf); //%s significa string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Cria o arquivo w de write/escrever
    fprintf(file,cpf); //Salva o valor da variável cpf
    fclose(file);  // Fecha o arquivo
      
    file = fopen(arquivo, "a"); //Abrindo o arquivo com fopen e a de atualizar
    fprintf(file, ","); // virgula para separação dos arquivos
    fclose(file); // Fechamento do arquivo
      
    printf("Digite o nome a ser cadastrado: \n");  //Perguntando nome do usuário
    scanf("%s",nome); //Variável nome
      
    file = fopen(arquivo, "a");  //Atualização de informações com a inclusão do nome
    fprintf(file,nome); //Salvando variável nome
	fclose(file); //fecha o arquivo
      
    file = fopen(arquivo, "a");  //Adicionando outro espaçamento
    fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //Perguntando sobrenome do usuário
    scanf("%s",sobrenome); //Armazenar a informação
      
    file = fopen(arquivo, "a"); //Abrindo o arquivo/salvando e atualizando
    fprintf(file,sobrenome); //Salvando a variável sobrenome
	fclose(file); //fecha o arquivo 
      
    file = fopen(arquivo, "a"); //Adicionando outro espaço
    fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n"); //Perguntando o cargo ao usuário
    scanf("%s",cargo); //Armazenando a variável cargo
      
    file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizar os novos dados
    fprintf(file,cargo); //Colocando a informação de cargo
	fclose(file); // Fechando o arquivo
	
	system("pause"); //Tela Pause
    
}
  
int consulta()
{ 
    setlocale(LC_ALL, "Portuguese"); //Defindo a linguagem no caso Portugues
    
    char cpf[40]; //Localizando o arquivo CPF
    char conteudo[200]; //Armazenando o conteudo do arquivo
    
    printf("Digite o CPF a ser consultado: \n"); //Perguntando ao usuário o CPF
    scanf("%s",cpf); //Salvando na variável
    
    FILE *file; //Acessando o arquivo
    file = fopen(cpf,"r"); //Abrindo o arquivo cpf e lendo com r/read
    
    if(file == NULL) //Validação do arquivo
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Mensagem do arquivo não valida
	}
    
    while(fgets(conteudo, 200, file) != NULL) //Buscando arquivos dentro dos caracteres
    {
    	printf("\nEssas são as informações do usuário: \n"); //Mensagem ao encontrar o arquivo
    	printf("%s", conteudo); //Salvando o conteúdo da string
    	printf("\n\n"); //Espaçamento
    	
	}
    fclose(file); //Fechando o arquivo
    system("pause"); //Tela Pause
    
}
 
int deletar()
{   
    char cpf[40]; //Localizando o arquivo CPF

    printf("Digite o CPF do usuário a ser deletado: "); //Mensagem ao usuário no sub menu
    scanf("%s",cpf); //String cpf
    
    
    FILE *file; //Acessando e buscando o arqivo
    file = fopen(cpf,"r"); //Abrindo e lendo o arquivo cpf
    fclose(file); //Fechando o arquivo
    
    if(file == NULL) //Operação de comparação se o arquivo for igual a nulo
    {
    	printf("O usuário não se encontra no sistema \n"); //Mensagem ao usuário se o arquivo não existe
    	system("pause"); //Tela pause
	}
	
	else //Comparando a instrução anterior e alterando para outra ação
	{
	    remove(cpf); //Função para deletar
		printf("CPF deletado com sucesso\n"); //Mensagem ao usuário ao deletar
    	system("pause"); //Tela de pause		
	}
	
}

int main ()
   {  
   int opcao=0; //Definindo variáveis
   int laco=1;
   
   for(laco=1;laco=1;)
   {    
   
        system("cls");

        setlocale(LC_ALL, "Portuguese"); //Defindo a linguagem 
   
        printf(" Cartório da EBAC \n\n"); //inicio do menu
        printf("\tMENU\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção:"); //fim do menu
   	
        scanf("%d", &opcao); //armazenando a escolha do usuário
   
        system("cls"); //Responsavel por limpar a tela
        
        
        switch(opcao) //Inicio da seleção menu
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
           printf("Opção não disponivel\n"); 
           system("pause");
           break;
		} //fim da seleção menu
        
   }
}
