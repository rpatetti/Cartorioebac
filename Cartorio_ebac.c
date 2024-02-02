#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro () //Função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis/ string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//inicio da criação de variaveis/ string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSOBRENOME:");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem (idioma)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file ==NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	printf("\nEssas são as informações do usuario: \n ");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");	
	
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
	
	else
	{
		remove (cpf);
		printf("Usuário deletado com sucesso! \n\n");
	}
	
		system("pause");
		return 0;
}

int main ()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		 system("cls");
		 for (laco=1;laco=1;)
		 {
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem (idioma)
	
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema \n\n");
			printf("opção: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuario
	
			system("cls"); // resónsavel por limpar a tela
	
			switch(opcao) //Inicio da selação do menu
			{
				case 1: 
				registro(); //chamada funções
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não esta disponivel!\n");
				system("pause");
				break; 
			}	//Fim da seleção
		}
	}
	
	else
		printf("Senha Incorreta");
}
