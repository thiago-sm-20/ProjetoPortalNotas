//Projeto Portal
//view cpp

#include "ProjPortal-Controller.h"
#include "ProjPortal-Model.h"
#include "ProjPortal-View.h"
#include <stdio.h>
#include <string.h>

void apresentaMensagem(char mens[100]) {
	printf("%s\n", mens);
} 

void criaLogin() {
	limpar();
	printf("Digite seu nome para cadastar: \n");
	printf("--> ");
	gets(user[qtuser].nome);
	printf("\n");
	printf("Digite uma senha para cadastrar: \n");
	printf("--> ");
	gets(user[qtuser].senha);
	printf("\n");
	printf("Usuario cadastrado com sucesso!!\n");
	qtuser++;
	salvaCadastro();
	
	for(int i = 11; i >= 0; i--) {
		limpar();
		printf("Seu numero de usuario e %d.\n", qtuser);
		printf("O programa ira se encerrar em %d segundos, abra novamente e faca login\n\n", i);
		ftempo(1);
	}
}

void fazLogin() {
	
	int i, cont;
	int k = 0;
	char senhaaux[15];
	
	limpar();
	printf("Digite seu numero de usuario: \n");
	scanf("%d", &i);
	fclear();
	i--;
	
	if (i > qtuser || i < 0) {
		printf("Numero de usuario nao encontrado\n\n");
		ftempo(3);
		fazLogin();
	}
	
	do {
		if(k == 3) {
			printf("Numero de tentativas excedido\n");
			printf("Saindo do programa... \n");
			ftempo(4);
			return;
		}
		printf("\n");
		printf("Digite sua senha: \n");
		printf("--> ");
		gets(senhaaux);
	
		if(strcmp(user[i].senha, senhaaux) == 0) {
			printf("\n");
			printf("Bem vindo, %s", user[i].nome);
			printf("\n\n");
			cont = 1;    
		}
		else {
			printf("Senha incorreta!!!\n\n");
			cont = 0;
			k++;
			ftempo(3);
			limpar();
		}
		
	}while (cont != 1);
	
	printf("Carregando...\n");
	ftempo(5);
	MenuInicial();
}

void loginInicial() {
	char op;
	
	printf("     P O R T A L   N O T A S     \n\n");
	printf("---------------------------------------\n");
	printf("  O que deseja fazer?\n");
	printf("1 - Fazer login\n");
	printf("2 - Criar usuario e login\n");
	printf("3 - Limpar os usuarios e senhas\n");
	printf("---------------------------------------\n");
	printf("--> ");
	scanf("%c", &op);
	fclear();
	
	switch (op) {
		case '1':
			carregaCadastro();
			fazLogin();
			break;
		case '2': 
			carregaCadastro();
			criaLogin();
			break;
		case '3':
			zerarLogin();
			printf("\n");
			printf("Usuarios e senhas resetados!\n");
			ftempo(3);
			limpar();
			loginInicial();
			break;
		default:
			printf("\n\nEscolha invalida\n");
			ftempo(2);
			limpar();
			loginInicial();
			break;
	}
}

void MenuInicial() {
	char op;
	
	while(1) {
		limpar();
		printf("--------------------------------------------------\n");
		printf("                O que deseja fazer?              |\n");
		printf("1) -- Mostrar lista de alunos                    |\n");
		printf("2) -- Escolher mostrar lista com/sem notas       |\n");
		printf("3) -- Cadastar um aluno novo                     |\n");
		printf("4) -- Colocar uma nota a um aluno                |\n");
		printf("5) -- Calcular e mostrar a media final de todos  |\n");
		printf("6) -- Salvar lista de alunos                     |\n");
		printf("7) -- Carregar lista de alunos salva             |\n");
		printf("8) -- Zerar lista de alunos                      |\n");
		printf("9) -- Visualizar dados de um aluno               |\n");
		printf("0) -- Sair do portal                             |\n");
		printf("--------------------------------------------------\n");
		printf("--> ");
		scanf("%c", &op); 
			
		switch (op) {
			case '1':
				limpar();
				if(id == 1) {
					mostrarListaComNotas();	
				}
				if(id == 0) {
					mostrarListaSemNotas();
				}
				break;
			case '2':
				fEscolha();
				break;
			case '3':
				limpar();
				cadastroAluno();
				break;
			case '4':
				limpar();
				colocaNota();
				break;
			case '5': 
				limpar();
				mostraMedia();
				break;
			case '6':
				printf("\n");
				salvaLista();
				printf("Dados salvos com sucesso!\n");
				ftempo(4);
				break;
			case '7':
				carregaLista();
				fclear();
				printf("Dados carregados com sucesso!\n");
				ftempo(3);
				break;
			case '8':
				limparLista();
				break;
			case '9':
				visualizaDados();	
				break;
			case '0':
				printf("Saindo do programa... ate mais!\n");
				ftempo(3);
				exit(0);
				break;
			default:
				printf("Escolha invalida, digite novamente\n\n");
		}
	}
}

void fEscolha() {
	booleanoID();
	limpar();
	if (id == 1) {
		printf("Atual: Com notas\n");
		ftempo(4);
		return;
	}
	else if (id == 0) {
		printf("Atual: Sem notas\n");
		ftempo(4);
		return;
	}
}

void mostrarListaSemNotas() {
	char op1;
	
	printf("==================================\n");
	for (int i = 0; i < qtAl; i++) {
		printf("Aluno %d: %s\n", i+1, classe[i].aluno.nome);
	}
	printf("==================================\n");
	printf("\n\n");
	
	fclear();
	printf("Digite 'v' para voltar ao menu inicial\n");
	scanf("%c", &op1);
	
	switch (op1) {
		case 'v':
			MenuInicial();
			break;
		default:
			printf("Opcao invalida\n");	
	}
}

void mostrarListaComNotas() {
	char op1;
	
	printf("=======================================================\n");
	for (int i = 0; i < qtAl; i++) {
		printf("Aluno %d: %s. Nota 1: %.2f e Nota 2: %.2f\n", i+1, classe[i].aluno.nome, classe[i].nota1, classe[i].nota2);
	}
	printf("=======================================================\n");
	printf("\n\n");
	
	fclear();
	printf("Digite 'v' para voltar ao menu inicial\n");
	scanf("%c", &op1);
	
	switch (op1) {
		case 'v':
			MenuInicial();
			break;
		default:
			printf("Opcao invalida\n");	
	}
}

void cadastroAluno() {
	fclear();
	printf("Digite o nome do aluno:\n");
	gets(classe[qtAl].aluno.nome);
	printf("Digite o CPF do aluno: \n");
	gets(classe[qtAl].aluno.cpf);
	printf("Digite a idade do aluno:\n");
	scanf("%d", &classe[qtAl].aluno.idade);
	fclear();
	printf("Digite o sexo do aluno:\n");
	gets(classe[qtAl].aluno.sexo);
	printf("\n");
	qtAl++;
	
	printf("Aluno cadastrado com sucesso!!\n\n");
	printf("Numero do aluno cadastrado: %d\n", qtAl);

	ftempo(3);
	limpar();
}

void colocaNota() {
	float n1, n2;
	char op, op2;
	int k;
	
	fclear();
	limpar();
	
	printf("Voce sabe o numero do aluno que deseja colocar a nota? \n");
	printf("Digite 's' para sim e 'n' para nao\n");
	scanf("%c", &op);
	fclear();
	
	if (op == 's') {
		printf("Digite o numero do aluno que voce deseja colocar a nota:\n");
		printf("--> ");
		scanf("%d", &k);
		k--;
	
		if (k >= qtAl) {
			printf("Aluno nao cadastrado ainda, tente novamente...\n\n");
			ftempo(1);
			colocaNota(); 
		}
	
		printf("Digite a nota 1 do aluno: \n");
		scanf("%f", &n1);
		printf("\n");
		printf("Digite a nota 2 do aluno: \n");
		scanf("%f", &n2);
	
		classe[k].nota1 = n1;
		classe[k].nota2 = n2;
		printf("Notas cadastradas com sucesso! Deseja cadastrar mais notas? ('s' e 'n')\n");
		fclear();
		scanf("%c", &op2);
		if (op2 == 's') {
			ftempo(1);
			colocaNota();
		}
		if (op2 == 'n') {
		printf("Voltando ao menu, aguarde...\n");
		ftempo(3);
		return;
		}
	}
	if (op == 'n') {
		printf("Entao retorne ao menu inicial e veja na opcao '1'\n\n");
		ftempo(4);
		return;
	}
}

void mostraMedia() {
	calculaMedia();
	
	char op2;
	
	printf("===================================\n");
	for (int i = 0; i < qtAl; i++) {
		printf("Aluno %d: %s - MF = %.2f\n", i+1, classe[i].aluno.nome, classe[i].mf);
	}
	printf("===================================\n");
	
	fclear();
	printf("Digite 'v' para voltar ao menu inicial\n");
	scanf("%c", &op2);
	
	switch (op2) {
		case 'v':
			MenuInicial();
			break;
		default:
			printf("Opcao invalida\n");	
	}
}

void visualizaDados() {
	int i;
	char op3, op1;
	
	fclear();
	
	printf("\n");
	printf("Voce sabe o numero do aluno que quer ver os dados?\n");
	printf("Digite 's' para sim e 'n' para nao...\n\n");
	scanf("%c", &op3);
	printf("\n");
	
	if(op3 == 'n') {
		printf("Entao retorne ao menu inicial e veja na opcao '1'\n\n");
		ftempo(4);
		return;
	}
	if(op3 == 's') {
		limpar();
		fclear();
		printf("Digite o numero do aluno na qual queira ver os dados\n");
		scanf("%d", &i);
		i--;
		printf("\n");
		printf("Nome: ");
		puts(classe[i].aluno.nome);
		printf("Idade: %d\n", classe[i].aluno.idade);
		printf("CPF: ");
		puts(classe[i].aluno.cpf);
		printf("Sexo: ");
		puts(classe[i].aluno.sexo);
		printf("\n\n");
		
		fclear();
		printf("Digite 'v' para voltar ao menu inicial\n");
		scanf("%c", &op1);
	
		switch (op1) {
			case 'v':
				MenuInicial();
				break;
			default:
				printf("Opcao invalida\n");	
		}
	}
}





