//Projeto Portal 
//Controller cpp

#include "ProjPortal-Model.h"
#include "ProjPortal-Controller.h"
#include "ProjPortal-View.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limpar() {
	system("cls");
}

void ftempo(int seg) 
{ 
    time_t  lt1, lt2; 
	lt1 = time(NULL); 
	lt2 = lt1; 
    while (difftime(lt2, lt1) < seg) 
    lt2 = time(NULL); 
} 

void fclear() 
{ 
    int ch; 
    while((ch = fgetc(stdin)) != EOF && ch != '\n'); 
}

void preparaGravacao() {
	sqtd.salvaQt = qtAl;
}

void salvaLista() {
	preparaGravacao();
	
	FILE *fq, *fl;
	
	time_t registrarhora;
	struct tm *horariolocal;
	
	fq = fopen("QTD", "w");
	fl = fopen("LIST", "w");
	
	for(int i = 0; i < qtAl; i++) {
		fwrite(&classe[i], sizeof(struct stnotas), 1, fl);
	}
	
	fwrite(&sqtd, sizeof(struct SalvaQtde), 1, fq);
	
	time(&registrarhora);
	horariolocal = localtime(&registrarhora);
	printf("Salvo em: %02d:%02d:%02d\n", horariolocal->tm_hour, horariolocal->tm_min, horariolocal->tm_sec);
	
	fclose(fl);
	fclose(fq);
}

void carregaCont() {
	FILE *fq = NULL;
	
	fq = fopen("QTD", "r");
	
	fread(&sqtd, sizeof(struct SalvaQtde), 1, fq);
	
	fclose(fq);
	
	qtAl = sqtd.salvaQt;
}

void carregaLista() {
	carregaCont();
	
	FILE *fl = NULL;
	
	fl = fopen("LIST", "r");
	
	for (int i = 0; i <= qtAl; i++) {
		fread(&classe[i], sizeof(struct stnotas), 1, fl);
	}
	
	fclose(fl);
}

void gravaLogin() {
	Snum.qtuser1 = qtuser;
}

void salvaCadastro() {
	gravaLogin();

	FILE *fu, *fd;
	
	fu = fopen("USERS", "w");
	fd = fopen("DATA", "w");
	
	for(int i = 0; i <= qtuser; i++) {
		fwrite(&user[i], sizeof(struct stuser), 1, fu);
	}
	
	fwrite(&Snum, sizeof(struct SalvaLogin), 1, fd);

	fclose(fu);
	fclose(fd);
}            
	
void carregaContador() {
	FILE *fd = NULL;
		
	fd = fopen("DATA", "r");
	
	fread(&Snum, sizeof(struct SalvaLogin), 1, fd);
	
	fclose(fd);	
	
	qtuser = Snum.qtuser1;	
}	
	
void carregaCadastro() {
	carregaContador();
	
	FILE *fu = NULL;
	
	fu = fopen("USERS", "r");
	
	for(int i = 0; i <= qtuser; i++) {
		fread(&user[i], sizeof(struct stuser), 1, fu);
	}
	
	fclose(fu);		
}

void booleanoID() {
	if(id == 1) {
		id = 0;
	}
	else if(id == 0) {
		id = 1;
	}
}

void calculaMedia() {
	for (int i = 0; i <= qtAl; i++) {
		classe[i].mf = ((classe[i].nota1 + classe[i].nota2) / 2);
	}
}
           
void limparLista() {
	for (int i = 0; i < qtAl; i++) {
		for (int j = 0; classe[i].aluno.nome[j] != '\0'; j++) {
			classe[i].aluno.nome[j] = '\0';
		} 
		for (int j = 0; classe[i].aluno.cpf[j] != '\0'; j++) {
			classe[i].aluno.cpf[j] = '\0';
		}
		for (int j = 0; classe[i].aluno.sexo[j] != '\0'; j++) {
			classe[i].aluno.sexo[j] = '\0';
		}
		classe[i].aluno.idade = 0;
		classe[i].nota1 = 0;
		classe[i].nota2 = 0;	
	}
	qtAl = 0;
	
	apresentaMensagem("Lista limpa com sucesso");
	ftempo(3);
}		  

void zerarLogin() {
	for(int i = 0; i <= qtuser; i++) {
		for (int j = 0; user[i].nome[j] != '\0'; j++) {
			user[i].nome[j] = '\0';
		}
		for (int j = 0; user[i].senha[j] != '\0'; j++) {
			user[i].senha[j] = '\0';
		}
	}
	qtuser = 0;
	salvaCadastro();
} 
  
	   
	   
	         