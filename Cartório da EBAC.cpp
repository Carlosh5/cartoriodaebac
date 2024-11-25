#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //Biblioteca resposável por cuidar das strings.
int registro ()
{
    char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    
    printf("Digite o CPF a ser cadastrado:  ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Responsável por criar os valores de string.
    
	
	FILE *file; // Criar arquivo.
    file = fopen(arquivo, "w"); // Cria o arquivo.
    fprintf(file,cpf); // Salva o valor da variável
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
    	printf("Não foi possível abrir o  arquivo, arquivo não localizado! \n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
	printf("\n Essas são as informações do usuário: \n");
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
		printf("O usuário não se encontra no sistema! \n\n");
		system("pause");	
	}
	
	else
	{
		fclose(file); // Fecha o arquivo, pois ele existe
        remove(cpf); // Agora você pode remover o arquivo
		printf("/n""Usuário deletado!" "\n\n");
		system("pause");
	}
		
}  
	
	  
int main ()
{
	int opcao=0; // Definindo as variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
	
	    system("cls"); //Limpando a tela
	
    	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem.
    	
	    printf("###Cartório da EBAC###\n\n"); // Inicio do menu.
	    printf("Escolha a opção desejada:\n\n");
	    printf("\t1 - Registrar nomes \n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n\n\n"); 
	    printf("Opção: \n");// Fim do menu.
	
	    scanf("%d", &opcao); // Armazenando a escolha do usuário.
	
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
		    
		    default:
		    printf ("Essa opção não está disponível!\n");
		    system("pause");
		    break;    
		}
	}
}
