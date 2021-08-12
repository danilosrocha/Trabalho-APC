//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

//Defines
#define TAM_SIGLA 5
#define TAM_CIDADE 100
#define TAM_NOME 100
#define TAM_DATA 16
#define TAM_IDADE 5

//Declaração de variáveis globais
char escolha; //Variável para definir qual opção do menu vai ser escolhida;
struct pessoa cadastro;//Variável que guarda os dados de uma pessoa

//Declaração de structs
typedef struct pessoa PESSOA;
struct pessoa{
	char nome[TAM_NOME];
	char sexo;
	char cidade_estado[TAM_CIDADE];
	char nasc[TAM_DATA];
};
//Protótipos de funções
void menu(); //Oferece as opções de entrada da plataforma
void estado(); //Registra um estado
void cidade(); //Registra uma cidade
void pessoa(); //Registra os dados de uma pessoa
void pessoa_cidade(); //Pesquisa pessoa por cidade
void pessoa_estado(); //Pesquisa pessoa por estado
void consulta_pessoa(); //Pesquisa pessoa por nome
void relatorio_demografico(); //Realiza o relatório demográfico
int idade_pessoa(char nasc[]); //Função feita para calcular a idade da pessoa cadastrada
int validar_data(char nasc[]); //Função feita para para validar o formato da data
	
//Programa principal
int main()
{ 
	system("color f0"); //Muda de cor o texto e o fundo
	setlocale(LC_ALL, "Portuguese"); //Deixa colocar acento ortográfico
	menu(); //Entra no procedimento "menu"
	return 0;
}
//Procedimento feito para o menu
void menu()
{
	do{ //Comando de repetição para repetir até que se digite 8
		fflush(stdin);
		printf("--------------------------------------\n");
		printf("----------- MENU DE OPÇÕES -----------\n");
		printf("--  1) Cadastrar Estado             --\n");
		printf("--  2) Cadastrar Cidade             --\n");
		printf("--  3) Cadastrar Pessoa             --\n");
		printf("--  4) Listar pessoas por Estado    --\n");
		printf("--  5) Listar pessoas por Cidade    --\n");
		printf("--  6) Consultar Pessoa por Nome    --\n");
		printf("--  7) Gerar relatório demográfico  --\n");
		printf("--  8) Finalizar Programa           --\n");
		printf("--------------------------------------\n");
		printf("-------- O que deseja fazer? ---------\n");
		scanf("%c", &escolha);
	
		
		switch(escolha){ //Recebe a escolha do usuário e em cada caso entra nos procedimentos
			case '1':
				system("cls");
				estado();
				break;
				
			case '2':
				system("cls");
				cidade();
				break;
				
			case '3':
				system("cls");
				pessoa();
				break;
				
			case '4':
				system("cls");
				pessoa_estado();
				break;
				
			case '5':
				system("cls");
				pessoa_cidade();
				break;
				
			case '6':
				system("cls");
				consulta_pessoa();
				break;
				
			case '7':
				system("cls");
				relatorio_demografico();
				break;
				
			case '8':
				printf("--------------------------------------\n");
				printf("- Obrigado por utilizar a plataforma -\n");	
				printf("--------------------------------------\n");
				break;
				
			default:
				printf("Opção inválida\nReinicie a Plataforma\n");
				system("Pause");
				system("cls");
				break;
		}	
	}while(escolha != '8');
}
//Procedimento para cadastrar Estado
void estado()
{
	FILE *arquivo_estado; //Ponteiro do Arquivo do Estado

    char sigla_estado[TAM_SIGLA]; //Variável para armazenar o estado digitado
    char importar_estado[TAM_SIGLA]; //Variável para importar o estado do arquivo de Estado
    int i; //Funciona como contador para o comando de repetição
       
    printf("Digite a Unidade Federativa (UF) a ser cadastrada: ");
    
	fflush(stdin);
    fgets(sigla_estado, TAM_SIGLA, stdin); //Armazena a sigla digitada
    sigla_estado[strlen(sigla_estado) - 1] = '\0'; //Desconsidera o "\n"
    
    if(strlen(sigla_estado) < 2 || strlen(sigla_estado) >= 3 || sigla_estado[0] == ' ' || sigla_estado[1] == ' '){ //Feito para não aceitar sigla com um ou mais de dois caracteres
	   	printf("A UF deve conter dois caracteres.\nTente novamente...\n");
		system("pause");
		system("cls");
	}else {
	    strupr(sigla_estado);
			
		arquivo_estado = fopen("Sigla_Estados.txt", "a+"); //Serve para abrir, ler e criar um arquivo
		
		while(!feof(arquivo_estado)){ //Comando de repetição para ler todo o arquivo
			fgets(importar_estado, TAM_SIGLA, arquivo_estado); //Importa os Estados do arquivo
			importar_estado[strlen(importar_estado) - 1] = '\0';
			if(strcmp(importar_estado, sigla_estado) == 0){ //Compara o Estado digitado com o já cadastrado
				printf("Unidade Federativa já cadastrada.\n");
				system("pause");
				break;
			}
		}
		if(strcmp(importar_estado, sigla_estado) != 0){ //Condição para cadastrar o estado
			printf("Unidade Federativa cadastrada com sucesso!\n");
			system("pause");
		}
		fprintf(arquivo_estado, "%s\n", sigla_estado); //Faz o print no arquivo
		fclose(arquivo_estado);	
	}
	system("cls");
}
//Procedimento para cadastrar Cidade
void cidade()
{
	FILE *arquivo_cidade; //Ponteiro do Arquivo da cidade
	FILE *arquivo_estado; //Ponteiro do Arquivo do Estado
	
	char estado_cidade [TAM_SIGLA]; //Variável para armazenar o estado digitado
	char importar_estado[TAM_SIGLA]; //Variável para importar o estado do arquivo de Estado
	char nome_cidade[TAM_CIDADE]; //Variável para armazenar a cidade digitada	
	char importar_cidade_estado[TAM_CIDADE]; //Variável para importar a cidade e o estado do arquivo Cidade
	char *cidade; //Ponteiro para separar cidade de estado que está no arquivo
	char *estado; //Ponteiro para separar estado de cidade que está no arquivo
	int i; //Funciona como contador para o comando de repetição
	int contador_estado = 0;//Variável que serve de apoio para as condições do estado já cadastrado ou não
	int contador_cidade = 0;//Variável que serve de apoio para as condições da cidade já cadastrado ou não
	
	printf("Digite a UF da cidade a ser registrada: ");
	fflush(stdin);
	fgets(estado_cidade, TAM_SIGLA, stdin); //Armazena o estado da cidade a ser digitada
	for(i = 0; i < strlen(estado_cidade); i++){
		estado_cidade[i] = toupper(estado_cidade[i]); //Deixa a sigla em maiusculo //STRUPR(NOME)
	}
	

	system("cls");
	
	arquivo_estado = fopen("Sigla_Estados.txt", "r");
	
	if(arquivo_estado == NULL){ //Caso nenhum estado tenha sido cadastrado
		printf("Nenhum Estado foi cadastrado.\nFaça o cadastro de um Estado antes.\n");
		system("pause");
		system("cls");
	}else {
		while(!feof(arquivo_estado)){ //Ler o aquivo do estado até o final
			fgets(importar_estado, TAM_SIGLA, arquivo_estado);
			if(!feof(arquivo_estado)){ //Para tirar o bug de repetição da última linha
				if(strcmp(importar_estado, estado_cidade) == 0){ //Compara o estado digitado com os estados já cadastrados, se já foi cadastrado vai para a cidade
					printf("Escreva o nome da Cidade a ser cadastrada: ");
					fflush(stdin);
					fgets(nome_cidade, TAM_CIDADE, stdin);
					for(i = 0; i < strlen(nome_cidade); i++){ //Deixa o que foi digitado em minúsculo
						nome_cidade[i] = tolower(nome_cidade[i]); 	
					}
					nome_cidade[strlen(nome_cidade) - 1] = '\0'; //Desconsidera o "\n"
					contador_estado = 1;
				}
			}
		}
		
		fclose(arquivo_estado);
		
		if(contador_estado == 0){ //Caso em que o estado ainda não foi cadastrado
			printf("Estado ainda não cadastrado.\nFaça o cadastro do Estado antes.\n");
			system("pause");
			system("cls");
		}else {
			arquivo_cidade = fopen("Cidades.txt", "a+");
			
			while(!feof(arquivo_cidade)){ //Ler o arquivo até o final
				if(fgets(importar_cidade_estado, TAM_CIDADE, arquivo_cidade) != NULL){ //
					cidade = strtok(importar_cidade_estado, "/"); //Cidade vai ser do início do arquivo até a "/"
					estado = strtok(NULL, ""); //Registra o estado como o que está após a barra até o espaço
					if(strcmp(cidade, nome_cidade) == 0 && strcmp(estado, estado_cidade) == 0){ //Compara a cidade e o estado digitado com oo que já está contido no arrquivo das cidades
						printf("Cidade já cadastrada.\n");		
						contador_cidade = 1; // Caso em que a cidade já foi cadastrada
						fclose(arquivo_cidade);
						system("pause");
						system("cls");
						break;
					}
				}
			}	
			if(contador_cidade == 0){ //Caso em que a cidade ainda não foi cadastrada
				arquivo_cidade = fopen("Cidades.txt", "a"); //Acrescenta dados ao arquivo de cidade
				estado_cidade[strlen(estado_cidade) - 1] = '\0'; //Desconsireda o "\n"
				fprintf(arquivo_cidade, "%s/%s\n", nome_cidade, estado_cidade); 
				fclose(arquivo_cidade);
				printf("Cidade cadastrada com sucesso!\n");
				system("pause");
				system("cls");
			}	
		}
	}
}		
//Procedimento para cadastrar Pessoas
void pessoa()
{	
	FILE *arquivo_cidade_estado; //Ponteiro responsável por abrir o arquivo de cidade
	FILE *arquivo_pessoa;//Ponteiro responsável por abrir o arquivo de pessoa
	
	int validar; //Responsável por enviar a data de nascimento pela função criada e retornar um valor int
	char ciadde_estado_arquivo[TAM_CIDADE]; //Importa a cidade e o estado do arquivo de cidades
	int contador_arquivo_cidade_estado = 0; //Contador auxiliar nas condições de continuar a fazer o cadastro ou não
	PESSOA struct_cadastro; //
		
	//Recebe o Estado e a cidade 
	printf("Digite a cidade e o Estado da pessoas a ser cadastrada: < EX: goiania/GO >\n");
	
	fflush(stdin);
	fgets(cadastro.cidade_estado, TAM_CIDADE, stdin); //Variável que recebe a cidade/estado
	strlwr(cadastro.cidade_estado); // Deixa todas a letras minúsculas
	cadastro.cidade_estado[strlen(cadastro.cidade_estado) - 2] = toupper(cadastro.cidade_estado[strlen(cadastro.cidade_estado) - 2]); //Deixa maiúsculo o que é o UF da cidade
	cadastro.cidade_estado[strlen(cadastro.cidade_estado) - 3] = toupper(cadastro.cidade_estado[strlen(cadastro.cidade_estado) - 3]);
			
	arquivo_cidade_estado = fopen("Cidades.txt", "r"); //Serve para o if fazer a condição quando for nulo
	if(arquivo_cidade_estado == NULL){ //Não acontece a repetição porque o arquivo está nulo
	}else {
		arquivo_cidade_estado = fopen("Cidades.txt", "r"); //Abre e lê o arquivo de cidades
	
		while(!feof(arquivo_cidade_estado)){ //Responsável por ler todo arquivo de cidades
			fgets(ciadde_estado_arquivo, TAM_CIDADE, arquivo_cidade_estado); //Importa as cidades
			if(strcmp(ciadde_estado_arquivo, cadastro.cidade_estado) == 0){ //Faz a comparação do que foi digitado do que já estava contido no arquivo
				contador_arquivo_cidade_estado = 1;
				system("cls");
			}
		}
		
		fclose(arquivo_cidade_estado);
	}
	if(contador_arquivo_cidade_estado == 0){ //Condição em que o estado não foi cadastrado
		printf("Cadastre a Unidade Federativa e a Cidade primeiro.\n");
		system("pause");
		system("cls");
	}else { //Quando o Estado já foi cadastrado
		//Recebe o nome 
		printf("Digite o nome da pessoa: ");
		
		fflush(stdin);
	    fgets(cadastro.nome, TAM_NOME, stdin); //Variável para armazenar o nome da pessoa
	    do{
	    	if(cadastro.nome[0] == '\n' || cadastro.nome[0] == ' ' ){ //quanto somente um ou nenhum dígito é digitado
	    		system("cls");
	    		printf("Isso não é um nome, bobo! Digite novamente: ");
				fflush(stdin);
			    fgets(cadastro.nome, TAM_NOME, stdin);
			}
		}while(cadastro.nome[0] == '\n' || cadastro.nome[0] == ' ');//Repete até se escrever corretamente
		strlwr(cadastro.nome); //Deixa todas letras em minúsculo
		system("cls");
		
		//Recebe o sexo
		printf("OBS: 'M' para Masculino; 'F' para feminino.\n");
		printf("Digite o sexo: ");
	       
	    fflush(stdin);
	    scanf("%c", &cadastro.sexo); //Armazena o sexo digitado
	    system("cls");
		
		if(cadastro.sexo != 'f' && cadastro.sexo != 'F' && cadastro.sexo != 'm' && cadastro.sexo != 'M'){//Feito para não aceitar o sexo sem ser f/F ou m/M
		   	do{ //Repetição para ir somento quando for digitado corretamente
			   	printf("Identificação inexistente, digite novamente.\n");
		   		printf("OBS: 'M' para Masculino; 'F' para feminino.\nDigite o sexo: ");
		   		fflush(stdin);
		   		scanf("%c", &cadastro.sexo);
		   	system("cls");	
			}while(cadastro.sexo != 'f' && cadastro.sexo != 'F' && cadastro.sexo != 'm' && cadastro.sexo != 'M');
			system("cls");
		}
		cadastro.sexo = toupper(cadastro.sexo); //coloca em maiúsculo
		
		
		//Recebe a data de nascimento e a idade
		printf("OBS: Formato da data DD/MM/AAAA\nDigite a data de nascimento: ");
		fflush(stdin);
		fgets(cadastro.nasc, TAM_DATA, stdin); //Armazena a data de nascimento
		system("cls");
		validar = validar_data(cadastro.nasc); //Entra na função para verificar se o formato da data digitada está correto
		do{ //Retição feita para ir somente quando o validar for 1
			if(validar != 1){ //Condição quando o formato está incorreto
				printf("Formato incorreto, tente novamente...\n");
				printf("OBS: Formato da data DD/MM/AAAA\nDigite a data de nascimento: ");
				fflush(stdin);
				fgets(cadastro.nasc, TAM_DATA, stdin);
				validar = validar_data(cadastro.nasc);
				system("cls");
			}	 
		}while(validar != 1);
		//Inserindo no arquivo
		arquivo_pessoa = fopen("Pessoas.txt", "ab");//Abre o aquivo em binário
			
	    fwrite(&cadastro, sizeof(PESSOA), 1, arquivo_pessoa); //Printa todo bloco de dados da struct
	    printf("Pessoa cadastrada com sucesso!\n");
	    system("pause");
		fclose(arquivo_pessoa);
	    system("cls");	
	}
}
//Procedimento para listar pessoas por estado
void pessoa_estado()
{
	FILE *arquivo_pessoas; //Ponteiro para abrir o arquivo das Pessoas
	char *estado; //Ponteiro para pegar o final da string importada da struct cidade e estado (separa o estado da cidade)
	char *cidade; //Ponteiro de apoio para ajudar
	PESSOA struct_cadastro; //
	char pessoa_procurada_estado[TAM_SIGLA]; //Variável que vai armazenar o Estado da pessoas a ser procurada
	int verifica_cadastro_estado = 0; //Contador auxiliar nas condições 
	
	arquivo_pessoas = fopen("Pessoas.txt", "rb"); //Abre o arquivo para ler em binário
	
	if(arquivo_pessoas != NULL){ //Condição quando o arquivo é nulo
		fflush(stdin);
		printf("Digite o Estado da pessoa a ser procurada: ");
		fgets(pessoa_procurada_estado, TAM_SIGLA, stdin); // Vai armazenar dados na variável
		strupr(pessoa_procurada_estado); // deixa maiúsculo
		pessoa_procurada_estado[strlen(pessoa_procurada_estado) - 1] = '\0'; //Desconsireda o "\n"
		printf("--------------------- LISTA POR ESTADO (%s) -----------------------\n", pessoa_procurada_estado);
		while(!feof(arquivo_pessoas)){ //Ler o arquivo até o final
			pessoa_procurada_estado[strlen(pessoa_procurada_estado)] = '\n'; //Desconsireda o "\n"
			fread(&struct_cadastro, sizeof(PESSOA), 1, arquivo_pessoas); //Ler todo o bloco de dados da struct
			if(!feof(arquivo_pessoas)){ // bug de printar 2 vezes a última linha
				cidade = strtok(struct_cadastro.cidade_estado, "/"); //Cidade vai ser do início do arquivo até a "/" da cidade/estado cadastrado no arquivo de pessoas
				estado = strtok(NULL, ""); //Registra o estado como o que está após a barra até o espaço
				if(strstr(pessoa_procurada_estado, estado) != NULL){ //Compara a duas strings
					struct_cadastro.nome[strcspn(struct_cadastro.nome, "\n")] = 0; //Desconsidera o \n
					verifica_cadastro_estado = 1; //Contador auxiliar
					printf(" \n");
					printf("-> Nome: %s\n", struct_cadastro.nome); //Mostra na tela o nome das pessoas cadastradas
					printf("-> Sexo: %c\n", struct_cadastro.sexo); //Mostra na tela o sexo das pessoas cadastradas
					printf("-> Data de Nascimento: %s", struct_cadastro.nasc); //Mostra na tela a data de nascimento das pessoas cadastradas
					printf("-> Cidade: %s\n", struct_cadastro.cidade_estado); //Mostra na tela a cidade das pessoas cadastradas
				}
			}
		}
		fclose(arquivo_pessoas); //Fecha o arquivo de pessoas
	
		if(verifica_cadastro_estado == 0){ //Condição quando ainda nenhuma pessoa foi cadastrada no Estado
			printf("- Nenhuma pessoa cadastrada nesse estado, faça o cadastro antes. -\n");
		}
		printf("------------------------------------------------------------------\n");
		system("pause");
		system("cls");
	} else { //Condição quando nenhuma pessoa foi cadastrada ainda 
		printf("Nenhuma pessoa cadastrada ainda, faça o cadastro primeiro.\n");
		system("pause");
		system("cls");
	}
}
//Procedimento para listar pessoas por cidade
void pessoa_cidade()
{
	FILE *arquivo_pessoas; //Ponteiro para abrir o arquivo das Pessoas
	PESSOA struct_cadastro; //
	char pessoa_procurada_cidade[TAM_CIDADE]; //Variável para armazenar a cidade digitada
	int verifica_cadastro_cidade = 0; //Contador para auxiliar na 
	
	arquivo_pessoas = fopen("Pessoas.txt", "rb"); //Abre o arquivo em binário
	
	if(arquivo_pessoas != NULL){ //Condição quando o arquivo e nulo
		fflush(stdin);
		printf("Digite a cidade da pessoa a ser procurada: ");
		fgets(pessoa_procurada_cidade, TAM_CIDADE, stdin);
		strlwr(pessoa_procurada_cidade);
		pessoa_procurada_cidade[strlen(pessoa_procurada_cidade) - 2] = toupper(pessoa_procurada_cidade[strlen(pessoa_procurada_cidade) - 2]); //Deixa as antepenultima e penultima caracter da string em maiusulo
		pessoa_procurada_cidade[strlen(pessoa_procurada_cidade) - 3] = toupper(pessoa_procurada_cidade[strlen(pessoa_procurada_cidade) - 3]);		  
		
		printf("------------------------ LISTA POR CIDADE ------------------------\n");
		while(!feof(arquivo_pessoas)){ //Responsável por ler o arquivo até o final
			fread(&struct_cadastro, sizeof(PESSOA), 1, arquivo_pessoas); //Responsável por ler o bloco de dados da struct
			if(!feof(arquivo_pessoas)){ //Tira o bug do print da ultima linha 2 vezes
				if(strstr(pessoa_procurada_cidade, struct_cadastro.cidade_estado) != NULL){ //Compara o que foi digitado com que estava no arquivo
					struct_cadastro.nome[strcspn(struct_cadastro.nome, "\n")] = 0; //Desconsidera o \n
					printf(" \n");
					printf("-> Nome: %s\n", struct_cadastro.nome); //Mostra na tela o nome das pessoas cadastradas
					printf("-> Sexo: %c\n", struct_cadastro.sexo); //Mostra na tela o sexo das pessoas cadastradas
					printf("-> Data de Nascimento: %s", struct_cadastro.nasc); //Mostra na tela a data de nascimento das pessoas cadastradas
					verifica_cadastro_cidade = 1; //Contador auxiliador
				}
			}
		}
		fclose(arquivo_pessoas); //Fecha o arquivo
	
		if(verifica_cadastro_cidade == 0){ //Condição quando nenhuma pessoa foi cadastrada na cidade 
			printf("- Nenhuma pessoa cadastrada nessa Cidade, faça o cadastro antes. -\n");
		}
		printf("------------------------------------------------------------------\n");
		system("pause");
		system("cls");
	} else { //Quando nenhuma pessoa foi cadastrada no programa
		printf("Nenhuma pessoa foi cadastrada ainda, faça o cadastro primeiro.\n");
		system("pause");
		system("cls");
	}
}
//Procedimento para consultar pessoas
void consulta_pessoa()
{
	FILE *arquivo_pessoas; //Ponteiro para abrir o arquivo das Pessoas/
	PESSOA struct_cadastro; //
	char pessoa_consulta_nome[TAM_CIDADE]; //Variável para armazenar a cidade digitada
	int verifica_consulta_nome = 0; //Contador para auxiliar na 
	
	arquivo_pessoas = fopen("Pessoas.txt", "rb"); //Abre o arquivo em binário
	
	if(arquivo_pessoas != NULL){ //Condição quando o arquivo e nulo
		fflush(stdin);
		printf("Digite o nome da pessoa a ser consultada: ");
		fgets(pessoa_consulta_nome, TAM_NOME, stdin);
		pessoa_consulta_nome[strcspn(pessoa_consulta_nome, "\n")] = 0;
		printf("-------------------- CONSULTA POR NOME ---------------------\n");
		while(!feof(arquivo_pessoas)){ //Responsável por ler o arquivo até o final
			fread(&struct_cadastro, sizeof(PESSOA), 1, arquivo_pessoas); //Responsável por ler o bloco de dados da struct
			if(!feof(arquivo_pessoas)){ //Tira o bug do print da ultima linha 2 vezes
				if(strstr(struct_cadastro.nome, pessoa_consulta_nome) != NULL){ //Compara o que foi digitado com que estava no arquivo
					struct_cadastro.cidade_estado[strcspn(struct_cadastro.cidade_estado, "\n")] = 0; //Desconsidera o \n
					printf(" \n");
					printf("-> Nome: %s", struct_cadastro.nome);
					if(struct_cadastro.sexo == 'M'){
						printf("-> Sexo: Masculino\n"); //Printa o sexo masculino
					} else {
						printf("-> Sexo: Feminino\n"); //Printa o sexo feminino 
					}
					printf("-> Data de Nascimento: %s", struct_cadastro.nasc); //Printa a data de nascimento da pessoa
					printf("-> Cidade e Estado: %s\n", struct_cadastro.cidade_estado); //Printa a cidade e o estado da pessoa					
					verifica_consulta_nome = 1; //Contador auxiliador
				}
			}
		}
		fclose(arquivo_pessoas); //Fecha o arquivo
	
		if(verifica_consulta_nome == 0){ //Condição quando nenhuma pessoa foi cadastrada na cidade 
			printf("- Nenhuma pessoa com esse nome, ou parte do nome.          -\n");
		}
		printf("------------------------------------------------------------\n");
		system("pause");
		system("cls");
	} else { //Quando nenhuma pessoa foi cadastrada
		printf("Nenhuma pessoa cadastrada ainda, faça o cadastro primeiro. -\n");
		system("pause");
		system("cls");
	}
}
//Procedimento para fazer o relatório demográfico
void relatorio_demografico()
{
	FILE *arquivo_dados_pessoas; //Ponteiro para abrir o arquivo de pessoas
	PESSOA dados_pessoa; //
	float cont_fem = 0; //Contador de sexo feminino
	float cont_masc = 0; //Contador de sexo masculino
	float cont_sexo = 0; //Contador de sexo
	int idade; //Variável que armazena as idades
	float percentual_masc, percentual_fem; //Percentual de sexo masc/fem
	float cont_etaria_geral = 0, cont_etaria_1 = 0, cont_etaria_2 = 0, cont_etaria_3 = 0, cont_etaria_4 = 0, cont_etaria_5 = 0, cont_etaria_6 = 0; //Contador para as 6 faixa etárias
	float percentual_etario_1, percentual_etario_2, percentual_etario_3, percentual_etario_4, percentual_etario_5, percentual_etario_6; //Percentual para as seis faixa etárias
	

	arquivo_dados_pessoas = fopen("Pessoas.txt", "rb"); //Abre o arquivo em binário
	if(arquivo_dados_pessoas != NULL){
		while(!feof(arquivo_dados_pessoas)){ //Responsável por ler o arquivo até o final
			fread(&dados_pessoa, sizeof(PESSOA), 1, arquivo_dados_pessoas); //Responsável por ler o bloco de dados da struct
			if(!feof(arquivo_dados_pessoas)){ //Tira o bug do print da ultima linha 2 vezes
				//Fazer o contar de sexo masculino e feminino
				if(dados_pessoa.sexo == 'M' || dados_pessoa.sexo == 'F'){ //Condição para somar 1 ao contador de sexo geral
					cont_sexo++;
				}
				if(dados_pessoa.sexo == 'M'){ //Se for m, o contador mascculino é acrescentado em 1
					cont_masc++;
			 	}
			 	if(dados_pessoa.sexo == 'F'){ //Se for f, o contador mascculino é acrescentado em 1
			 		cont_fem++;
			 	}
			 	//Fazer a faixa etária
			 	idade = idade_pessoa(dados_pessoa.nasc); //Manda na função idade_pessoa, criada para calcular a idade da pessoa a partir da data de nascimento
			
			 	if(idade >= 0){ //Condição para somar 1 ao contador de idade geral
			 		cont_etaria_geral++;
				}
				//Condições para separar cada faixa etária
				if(idade >= 0 && idade <= 5){
					cont_etaria_1++;
				}
				if(idade >= 6 && idade <= 10){
					cont_etaria_2++;
				}
				if(idade >= 11 && idade <= 20){
					cont_etaria_3++;
				}
				if(idade >= 21 && idade <= 40){
					cont_etaria_4++;
				}
				if(idade >= 41 && idade <= 60){
					cont_etaria_5++;
				}
				if(idade >= 60){
					cont_etaria_6++;
				}
			}
		}
		//Calculo de percentual de sexo
		percentual_masc = (cont_masc / cont_sexo); 
		percentual_fem = (cont_fem / cont_sexo);
		
		//Cálculo de percentual etário
		percentual_etario_1 = cont_etaria_1 / cont_etaria_geral;
		percentual_etario_2 = cont_etaria_2 / cont_etaria_geral;
		percentual_etario_3 = cont_etaria_3 / cont_etaria_geral;
		percentual_etario_4 = cont_etaria_4 / cont_etaria_geral;
		percentual_etario_5 = cont_etaria_5 / cont_etaria_geral;
		percentual_etario_6 = cont_etaria_6 / cont_etaria_geral;
		
		printf("----------------- PERCENTUAL ETÁRIO -----------------\n");
		printf("- \n");
		printf("- De 0 a 5 anos: %.1f por cento.\n", percentual_etario_1 * 100);
		printf("- De 6 a 10 anos: %.1f por cento.\n", percentual_etario_2 * 100);
		printf("- De 11 a 20 anos: %.1f por cento.\n", percentual_etario_3 * 100);
		printf("- De 21 a 40 anos: %.1f por cento.\n", percentual_etario_4 * 100);
		printf("- De 41 a 60 anos: %.1f por cento.\n", percentual_etario_5 * 100);
		printf("- Acima de 60 anos: %.1f por cento.\n", percentual_etario_6 * 100);
		printf("- \n");
		printf("---------------- PERCENTUAL POR SEXO ----------------\n");
		printf("- \n");
		printf("- Percentual Masculino: %.1f por cento.\n", percentual_masc * 100);
		printf("- Percentual Feminino: %.1f por cento.\n", percentual_fem * 100);
		printf("- \n");
		printf("-----------------------------------------------------\n");
		system("pause");
		system("cls");		
	} else{ //Condição quando nenhuma pessoa tenha sido cadastrada
		printf("Nenhuma pessoa foi cadastrada.\n");
		system("pause");
		system("cls");		
	}
}
//Função para identificar a idade da pessoa
int idade_pessoa(char nasc[])
{
	struct tm *data_atual;
	//Ponteiros para separar a data de nascimento em partes de dia, mes e ano
	char *dia_c; 
	char *mes_c;
	char *ano_c;
	//variável para receber o time da máquina
	time_t segundos;
	//Variáveis para armazenar a data atual e a idade da pessoa
	int dia_hoje, mes_hoje, ano_hoje;
	int idade;
	
	//Separa a string da data de nascimento em dia/mes/ano
	dia_c = strtok(nasc, "/");
	mes_c = strtok(NULL, "/");
	ano_c = strtok(NULL, "");
	//Vai transformar em int
	int dia = atoi(dia_c);
	int mes = atoi(mes_c);
	int ano = atoi(ano_c);
	//Serve para pegar a data do sistema
	time(&segundos);
	data_atual = localtime(&segundos);
	
	dia_hoje = data_atual->tm_mday;
	mes_hoje = data_atual->tm_mon + 1;
	ano_hoje = data_atual->tm_year + 1900;
	//Calculo da idade
	idade = (ano_hoje - 1) - ano;
	
	if(mes_hoje > mes){
		idade++;
	}
	if(mes_hoje == mes && dia_hoje >= dia){
		idade++;
	}
	return idade;
}
//Função para validar data
int validar_data(char nasc[])
{
	char data[TAM_DATA]; //Feito para não ser retornado o valor inteiro da data de nascimento
	//Ponteiros para separar a data de nascimento
	char *dia_c;
	char *mes_c;
	char *ano_c;
	//Copia a string da data de nascimento a que foi criada
	strcpy(data, nasc);
	//Separa a string da data de nascimento em dia/mes/ano
	dia_c = strtok(data, "/");
	mes_c = strtok(NULL, "/");
	ano_c = strtok(NULL, "");
	//Vai transformar em int
	int dia = atoi(dia_c); 
	int mes = atoi(mes_c);
	int ano = atoi(ano_c);
	int validar_data = 0;
	if(ano % 4 == 0 && ano != 0){ //Condição de um ano bissexto
	//Condições para cada mes que for digitado poder ter o seu limite de dias
		if(mes == 2){
			if(dia > 0 && dia <= 29){
			}
		}
		if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
			if(dia > 0 && dia <= 31){
				validar_data++;
			}
		}
		if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
			if(dia > 0 && dia <= 30){
				validar_data++;
			}
		}
	} else if(ano % 4 != 0 && ano != 0){ //Condição para um ano normal
	//Condições para cada mes que for digitado poder ter o seu limite de dias
		if(mes == 2){
			if(dia > 0 && dia <= 28){
			}
		}
		if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
			if(dia > 0 && dia <= 31){
				validar_data++;
			}
		}
		if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
			if(dia > 0 && dia <= 30){
				validar_data++;
			}
		}
	}
	return validar_data;
}
