#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int cadastro() //cadastro do usuario
{
	//inicio da criacao das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char curso[40];
	//final da criacao das variaveis
	
	printf("Digite o CPF: ");//coletando as infromacoes
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Curso: ");
	scanf("%s", curso);
	
	file = fopen(arquivo, "a");
	fprintf(file,curso);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if (file == NULL)
	{
		printf("CPF não encontrado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nSegue o resultado da consulta: ");
		printf("%s", conteudo);
		printf("\n\n\n");
	}
	
	system("pause");
	
	fclose(file);
	
}

int exclusao()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("CPF não encontrado!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("CPF excluido com sucesso!\n");
		system("pause");
	}
	
	fclose(file);
}

int main() 
{
	int opcao=0; //Definindo as Variaveis
	int laco=1; //laco de Repeticao
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cadastro de Alunos EBAC ###\n\n"); //Inicio do menu
		printf("Selecione a opção desejada:\n\n");
		printf("\t1 Incluir Novo Aluno\n");
		printf("\t2 Consultar Aluno\n");
		printf("\t3 Excluir Aluno\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a opcao do usuario
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			cadastro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			exclusao();
			break;
			
			default:
			printf("Opção Incorreta! Tente Novamente!\n");
			system("pause");
		}
	
	}
}
