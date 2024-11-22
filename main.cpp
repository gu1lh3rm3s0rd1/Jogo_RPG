#include <iostream>
#include <stdio.h>
#include <string.h>


// Definicao da struct para representar um personagem
typedef struct {
	char nome[50];  // Nome
	char tipo[30];  // Tipo do personagem
	int vitalidade; // Vida
	int ataque; 	// Poder de ataque
	int defesa; 	// Defesa contra ataques
	int xp;     	// XP atual do jogador
	int xpParaProximoNivel; // XP necessário para avançar de nivel
	int nivel;  	// Nivel do personagem
} Personagem;

// Funcoes
void criarPersonagem(Personagem *p);
void exibirPersonagem(const Personagem *p);


// Menu do personagem
int menuPersonagem() {
	int escolha;
	printf("\n=== Escolha um Personagem ===\n");
	printf("1. Joao (Pistoleiro)\n");
	printf("2. Nascimento (Xerife)\n");
	printf("3. Pedro (Forasteiro)\n");
	printf("4. Cacique (Guerreiro Indigena)\n");
	printf("5. Marina (Dama Pistoleira)\n");
	printf("6. Criar um novo personagem\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &escolha);
	return escolha;
}

// Funcao para os detalhes dos personagens
void Personagens(Personagem personagens[]) {
	strcpy(personagens[0].nome, "Joao Mira Rapida");
	strcpy(personagens[0].tipo, "Pistoleiro");
	personagens[0].vitalidade = 100;
	personagens[0].ataque = 30;
	personagens[0].defesa = 20;
	personagens[0].xp = 0;
	personagens[0].xpParaProximoNivel = 1000;
	personagens[0].nivel = 1;

	strcpy(personagens[1].nome, "Xerife Nascimento");
	strcpy(personagens[1].tipo, "Xerife");
	personagens[1].vitalidade = 120;
	personagens[1].ataque = 25;
	personagens[1].defesa = 25;
	personagens[1].xp = 0;
	personagens[1].xpParaProximoNivel = 1000;
	personagens[1].nivel = 1;

	strcpy(personagens[2].nome, "Pedro Bala de Prata");
	strcpy(personagens[2].tipo, "Forasteiro");
	personagens[2].vitalidade = 90;
	personagens[2].ataque = 35;
	personagens[2].defesa = 15;
	personagens[2].xp = 0;
	personagens[2].xpParaProximoNivel = 1000;
	personagens[2].nivel = 1;

	strcpy(personagens[3].nome, "Cacique Galo Velho");
	strcpy(personagens[3].tipo, "Guerreiro Indigena");
	personagens[3].vitalidade = 110;
	personagens[3].ataque = 28;
	personagens[3].defesa = 22;
	personagens[3].xp = 0;
	personagens[3].xpParaProximoNivel = 1000;
	personagens[3].nivel = 1;
    
	strcpy(personagens[4].nome, "Marina Sorrateira");
	strcpy(personagens[4].tipo, "Dama Pistoleira");
	personagens[4].vitalidade = 110;
	personagens[4].ataque = 20;
	personagens[4].defesa = 15;
	personagens[4].xp = 0;
	personagens[4].xpParaProximoNivel = 1000;
	personagens[4].nivel = 1;
}



// Funcao para criar um personagem
void criarPersonagem(Personagem *p) {
	int escolha;

	printf("Escolha o tipo do personagem:\n");
	printf("1. Pistoleiro\n");
	printf("2. Xerife\n");
	printf("3. Forasteiro\n");
	printf("4. Guerreiro Indigena\n");
	printf("5. Dama Pistoleira\n");
	printf("Digite sua escolha (1-5): ");
	scanf("%d", &escolha);

	// Define os detalhes com base no tipo escolhido
	switch (escolha) {
    	case 1:
        	strcpy(p->tipo, "Pistoleiro");
        	p->vitalidade = 100;
        	p->ataque = 30;
        	p->defesa = 20;
        	break;
    	case 2:
        	strcpy(p->tipo, "Xerife");
        	p->vitalidade = 120;
        	p->ataque = 25;
        	p->defesa = 25;
        	break;
    	case 3:
        	strcpy(p->tipo, "Forasteiro");
        	p->vitalidade = 90;
        	p->ataque = 35;
        	p->defesa = 15;
        	break;
    	case 4:
        	strcpy(p->tipo, "Guerreiro Indigena");
        	p->vitalidade = 110;
        	p->ataque = 28;
        	p->defesa = 22;
        	break;
    	case 5:
        	strcpy(p->tipo, "Dama Pistoleira");
        	p->vitalidade = 95;
        	p->ataque = 32;    
        	p->defesa = 18;	 
        	break;
    	default:
        	printf("Escolha invalida! Atribuindo o tipo padrao: Pistoleiro.\n");
        	strcpy(p->tipo, "Pistoleiro");
        	p->vitalidade = 100;
        	p->ataque = 30;
        	p->defesa = 20;
        	break;
	}

	// Solicita o nome do personagem
	printf("Digite o nome do personagem: ");
	scanf(" %[^\n]", p->nome);
}

// Funcao para exibir os detalhes de um personagem
void exibirPersonagem(const Personagem *p) {
	printf("Nome: %s\n", p->nome);
	printf("Tipo: %s\n", p->tipo);
	printf("Nivel: %d\n", p->nivel);
	printf("XP: %d/%d\n", p->xp, p->xpParaProximoNivel);
	printf("Vitalidade: %d\n", p->vitalidade);
	printf("Ataque: %d\n", p->ataque);
	printf("Defesa: %d\n", p->defesa);
}

// Funcao para salvar o progresso
void salvarProgresso(Personagem *p) {
	// Aqui você pode salvar os dados no arquivo ou atualizar o banco de dados
	printf("\nProgresso salvo com sucesso para o personagem %s!\n", p->nome);
	printf("Experiencia: %d\n", p->xp);
}

// Funcao principal
int main() {


	return 0;
}