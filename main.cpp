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


int menuInicial() {
	int escolha;
	printf("\n=== Menu Inicial ===\n");
	printf("1. Jogar\n");
	printf("2. Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &escolha);
	return escolha;
}

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

void batalha(Personagem *p1, Personagem *p2) {
	printf("\n=== Detalhes dos Personagens na Batalha ===\n");
	printf("\n--- Detalhes de %s ---\n", p1->nome);
	exibirPersonagem(p1);
	printf("\n--- Detalhes de %s ---\n", p2->nome);
	exibirPersonagem(p2);

	printf("\n%s (Ataque: %d) VS %s (Ataque: %d)\n", p1->nome, p1->ataque, p2->nome, p2->ataque);

	int contadorAtaquesP1 = 0; // Contador de ataques do jogador
	int contadorAtaquesP2 = 0; // Contador de ataques do oponente

	// Simulação de turnos com controle do jogador
	while (p1->vitalidade > 0 && p2->vitalidade > 0) {
    	int acao;
    	int dano1 = 0, dano2 = 0;
    	bool defendendo = false;

    	// Ação do jogador
    	printf("\n%s, escolha sua acao:\n", p1->nome);
    	printf("1. Atacar\n");
    	printf("2. Defender\n");
    	printf("3. Exibir detalhes do personagem\n");
    	printf("Escolha (1-3): ");
    	scanf("%d", &acao);

    	switch (acao) {
        	case 1:
            	contadorAtaquesP1++;
            	if (contadorAtaquesP1 == 2) {
                	dano1 = (p1->ataque * 2) - p2->defesa; // Ataque especial
                	printf("%s realizou um ataque especial!\n", p1->nome);
                	contadorAtaquesP1 = 0; // Resetar o contador
            	} else {
                	dano1 = p1->ataque - p2->defesa;
            	}
            	if (dano1 < 0) dano1 = 0;
            	p2->vitalidade -= dano1;
            	printf("%s atacou %s causando %d de dano!\n", p1->nome, p2->nome, dano1);
            	break;

        	case 2:
            	printf("%s esta se defendendo!\n", p1->nome);
            	defendendo = true;
            	break;

        	case 3:
            	printf("\n--- Detalhes de %s ---\n", p1->nome);
            	exibirPersonagem(p1);
            	continue; // Reexibe o menu de ação
            	break;

        	default:
            	printf("Acao invalida! Perdendo a vez.\n");
            	break;
    	}

    	if (p2->vitalidade <= 0) {
        	printf("%s venceu!\n", p1->nome);
        	adicionarXP(p1, 50); // Premiar jogador com XP ao vencer
        	adicionarXP(p2, -20); // Penalizar o oponente (opcional)
        	break;
    	}

    	// Ação do oponente (simulação simples de ataque)
    	printf("\nTurno de %s:\n", p2->nome);
    	contadorAtaquesP2++;
    	if (contadorAtaquesP2 == 2) {
        	dano2 = (p2->ataque * 2) - p1->defesa; // Ataque especial
        	printf("%s realizou um ataque especial!\n", p2->nome);
        	contadorAtaquesP2 = 0; // Resetar o contador
    	} else {
        	dano2 = p2->ataque - p1->defesa;
    	}
    	if (defendendo) {
        	dano2 /= 2; // Reduz o dano pela metade se estiver defendendo
    	}
    	if (dano2 < 0) dano2 = 0;
    	p1->vitalidade -= dano2;
    	printf("%s atacou %s causando %d de dano!\n", p2->nome, p1->nome, dano2);

    	if (p1->vitalidade <= 0) {
        	printf("%s venceu!\n", p2->nome);
        	adicionarXP(p2, 50); // Premiar oponente com XP ao vencer
        	adicionarXP(p1, -20); // Penalizar jogador por perder
        	break;
    	}

    	// Mostrar o nível de vida dos personagens após cada ação
    	printf("\nNivel de vida apos a rodada:\n");
    	printf("%s: %d\n", p1->nome, p1->vitalidade);
    	printf("%s: %d\n", p2->nome, p2->vitalidade);
	}

	// Exibir mensagem de que os dados foram salvos com sucesso
	printf("\nProgresso salvo com sucesso! Seus dados foram atualizados.\n");
}


// Funcao principal
int main() {

	Personagem personagens[6]; // Array para personagens
	int escolha, personagemEscolhido;
	int numPersonagens = 5; 
	Personagens(personagens);
	printf("=== Bem-vindo ao Velho Oeste RPG! ===\n");

	// Menu inicial
	escolha = menuInicial();
	switch (escolha) {
    	case 1:
        	// Menu de seleção de personagens
        	escolha = menuPersonagem();
        	if (escolha >= 1 && escolha <= 5) { 
            	personagemEscolhido = escolha - 1;
        	} else if (escolha == 6) {
            	printf("\nCriando personagem adicional:\n");
            	criarPersonagem(&personagens[numPersonagens]);
            	personagemEscolhido = numPersonagens;
            	numPersonagens++;
        	} else {
            	printf("Escolha inválida!\n");
            	return 0;
        	}

        	// Menu principal
        	do {
            	printf("\n=== Menu Principal ===\n");
            	printf("1. Modo Historia\n");
            	printf("2. Modo Batalha\n");
            	printf("3. Sair\n");
            	printf("Escolha uma opcao: ");
            	scanf("%d", &escolha);

            	switch (escolha) {
                	case 1:
                    	modoHistoria(&personagens[personagemEscolhido]);
                    	break;

                	case 2:
                    	// Escolher personagens para batalha
                    	printf("\nEscolha os dois personagens para a batalha:\n");
                    	for (int i = 0; i < numPersonagens; i++) {
                        	printf("%d. %s (%s)\n", i + 1, personagens[i].nome, personagens[i].tipo);
                    	}

                    	int p1, p2;
                    	printf("Escolha o personagem 1 (1-%d): ", numPersonagens);
                    	scanf("%d", &p1);
                    	printf("Escolha o personagem 2 (1-%d): ", numPersonagens);
                    	scanf("%d", &p2);

                    	if (p1 >= 1 && p1 <= numPersonagens && p2 >= 1 && p2 <= numPersonagens && p1 != p2) {
                        	batalha(&personagens[p1 - 1], &personagens[p2 - 1]);
                    	} else {
                        	printf("Escolha invalida!\n");
                    	}
                    	break;

                	case 3:
                    	printf("Saindo do jogo...\n");
                    	break;

                	default:
                    	printf("Opcao invalida!\n");
            	}
        	} while (escolha != 3);
        	break;

    	case 2:
        	printf("Saindo do jogo...\n");
        	break;

    	default:
        	printf("Opcao invalida!\n");
	}


	return 0;
}