#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respos�vel por cuidar das strings.
int registro ()
{
    char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    
    printf("Digite o CPF a ser cadastrado:  ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Respons�vel por criar os valores de string.
    
	
	FILE *file; // Criar arquivo.
    file = fopen(arquivo, "w"); // Cria o arquivo.
    fprintf(file,cpf); // Salva o valor da vari�vel
    fclose(file); // Fecha o arquivo.
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf ("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf (file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf ("%s", cargo);
    
	file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
	
}

int consulta () 
{
    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem.
    
	char cpf[40];
    char conteudo[200];
    printf("Digite o CPF a ser consultado:  ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen (cpf, "r");
    
    if(file == NULL)
    {
    	printf("N�o foi poss�vel abrir o  arquivo, arquivo n�o localizado! \n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
	printf("\n Essas s�o as informa��es do usu�rio: \n");
	printf("%s", conteudo);
	printf("\n\n");
	
	system("pause");
	}
}
int deletar () 
{
    char cpf [40];
	printf("Digite o CPF a ser deletado:");
	
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n\n");
		system("pause");	
	}
	
	else
	{
		fclose(file); // Fecha o arquivo, pois ele existe
        remove(cpf); // Agora voc� pode remover o arquivo
		printf("/n""Usu�rio deletado!" "\n\n");
		system("pause");
	}
		
}  
	
	  
int main ()
{
	int opcao=0; // Definindo as vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
	
	    system("cls"); //Limpando a tela
	
    	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem.
    	
	    printf("###Cart�rio da EBAC###\n\n"); // Inicio do menu.
	    printf("Escolha a op��o desejada:\n\n");
	    printf("\t1 - Registrar nomes \n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n"); 
	    printf("\t4 - Sair do sistema \n");
	    printf("Op��o: \n");// Fim do menu.
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio.
	
	    system("cls"); //Limpando a tela
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro ();
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema! /n/n");
		    return 0;
		    break;
		    
		    default:
		    printf ("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break;    
		}
	}
}
