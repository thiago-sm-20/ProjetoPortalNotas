//Projeto Portal
//model-h

#ifndef MODEL_H
#define MODEL_H


typedef struct staluno {
	char nome[30];
	int idade;
	char cpf[12];
	char sexo[2];
} aluno;

typedef struct stnotas {
	struct staluno aluno;
	float nota1;
	float nota2;
	float mf;
} Notas;

typedef struct stuser {
	char nome[30];
	char senha[15];
} User;

Notas classe[30];
int id = 0; 
int qtAl;
int qtuser = 0;
User user[4];

typedef struct SalvaLogin {
	int qtuser1;
} NumUsers;

NumUsers Snum;

typedef struct SalvaQtde {
	int salvaQt;
} salvaQt;

salvaQt sqtd;

#endif
