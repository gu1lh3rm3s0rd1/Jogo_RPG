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

// Funcao para add XP do personagem
void adicionarXP(Personagem *p, int xpGanho) {
	printf("%s recebeu %d XP!\n", p->nome, xpGanho);
	p->xp += xpGanho;

	if (p->xp < 0) {
    	p->xp = 0; // Evita XP negativo
	}

	// Verificar se o personagem deve subir de nível
	while (p->xp >= p->xpParaProximoNivel) {
    	p->xp -= p->xpParaProximoNivel;
    	p->nivel++;
    	p->xpParaProximoNivel += 50; // Aumenta o limite de XP para o próximo nível
    	printf("%s subiu para o nível %d!\n", p->nome, p->nivel);
    	p->vitalidade += 10; // Opcional: aumente atributos ao subir de nível
    	p->ataque += 2;
    	p->defesa += 2;
	}
}

// Funcao para salvar o progresso
void salvarProgresso(Personagem *p) {
	// Aqui você pode salvar os dados no arquivo ou atualizar o banco de dados
	printf("\nProgresso salvo com sucesso para o personagem %s!\n", p->nome);
	printf("Experiencia: %d\n", p->xp);
}


// Funcao para modo bataha
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

// Funcao para o modo historia
void modoHistoria(Personagem *p) {
	int jogarNovamente;
	do {
    	printf("\nVoce escolheu jogar com %s, o %s!\n", p->nome, p->tipo);
    	printf("Este personagem e conhecido por suas habilidades unicas e coragem no Velho Oeste.\n");

    	printf("\nEscolha uma acao:\n");
    	if (strcmp(p->tipo, "Pistoleiro") == 0) {
        	printf("1. Desafiar um bandido para um duelo.\n");
        	printf("2. Proteger a cidade de um ataque.\n");
        	printf("3. Participar de um torneio de tiro.\n");
    	} else if (strcmp(p->tipo, "Xerife") == 0) {
        	printf("1. Prender um foragido.\n");
        	printf("2. Organizar uma defesa contra bandidos.\n");
        	printf("3. Investigar um roubo misterioso.\n");
    	} else if (strcmp(p->tipo, "Forasteiro") == 0) {
        	printf("1. Explorar uma mina abandonada.\n");
        	printf("2. Procurar tesouros escondidos.\n");
        	printf("3. Ajudar um fazendeiro local.\n");
    	} else if (strcmp(p->tipo, "Guerreiro Indigena") == 0) {
        	printf("1. Defender sua aldeia contra invasores.\n");
        	printf("2. Resgatar um aliado capturado.\n");
        	printf("3. Realizar um ritual sagrado.\n");
    	} else if (strcmp(p->tipo, "Dama Pistoleira") == 0) {
        	printf("1. Defender sua cidade contra invasores.\n");
        	printf("2. Recrutar aliados para a cidade.\n");
        	printf("3. Participar de um torneio de tiro.\n");
    	}

    	int acao;
    	printf("Escolha uma acao (1, 2 ou 3): ");
    	scanf("%d", &acao);

    	switch (acao) {
        	case 1:
                if (strcmp(p->tipo, "Pistoleiro") == 0) {
                    printf("\nVocê desafiou um bandido para um duelo. O sol está alto e o clima é tenso.\n");
                    printf("Você saca sua arma rapidamente e atira. O bandido cai no chão, derrotado.\n");
                    printf("A cidade está segura por enquanto, graças a você.\n");
                    p->xp += 20; // XP inicial pela vitória no duelo.
                
                    // Novo evento
                    printf("\nApós o duelo, você encontra uma carta no bolso do bandido. Ela menciona um tesouro escondido nas montanhas.\n");
                    printf("Você decide seguir as pistas e encontra um baú cheio de ouro.\n");
                    printf("O que você faz?\n");
                    printf("1. Levar o ouro para a cidade.\n");
                    printf("2. Esconder o ouro para uso futuro.\n");
                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                
                    if (decisao == 1) {
                        printf("Você leva o ouro para a cidade e é recebido como um herói.\n");
                        printf("O ouro é usado para melhorar a segurança e infraestrutura local.\n");
                        p->xp += 50; // Recompensa significativa por um ato altruísta e benéfico para todos.
                    } else {
                        printf("Você esconde o ouro e planeja usá-lo em uma emergência futura.\n");
                        printf("Enquanto isso, rumores sobre o tesouro começam a se espalhar.\n");
                
                        // Novo desdobramento
                        printf("\nVocê encontra um grupo de caçadores de tesouros atrás do ouro. O que você faz?\n");
                        printf("1. Enfrentar os caçadores e proteger o ouro.\n");
                        printf("2. Negociar com os caçadores para dividir o tesouro.\n");
                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                
                        if (decisao2 == 1) {
                            printf("Você enfrenta os caçadores em um tiroteio intenso e consegue proteger o ouro.\n");
                            p->xp += 40; // Recompensa por coragem e habilidade em combate.
                        } else {
                            printf("Você negocia com os caçadores e divide o tesouro, garantindo uma parte para si.\n");
                            p->xp += 20; // Recompensa moderada por evitar conflitos, mas mantendo parte do benefício.
                        }
                    }
                	
                	salvarProgresso(p);
               	 
            	} else if (strcmp(p->tipo, "Xerife") == 0) {
                    printf("\nVocê decidiu prender um foragido. Após uma perseguição intensa, você consegue capturá-lo.\n");
                    printf("A cidade está mais segura com menos um criminoso nas ruas.\n");
                    p->xp += 20; // XP inicial pela captura bem-sucedida do foragido.
                
                    // Novo evento
                    printf("\nDurante a prisão, o foragido revela informações sobre uma gangue que planeja atacar a cidade.\n");
                    printf("Você se prepara para enfrentar a gangue e consegue impedir o ataque.\n");
                    printf("O que você faz?\n");
                    printf("1. Interrogar o foragido para obter mais informações.\n");
                    printf("2. Prender o foragido e reforçar a segurança da cidade.\n");
                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                
                    if (decisao == 1) {
                        printf("Você interroga o foragido e descobre mais sobre os planos da gangue.\n");
                        printf("Com as informações, você consegue evitar futuros ataques.\n");
                        p->xp += 30; // Recompensa adicional por obter informações valiosas.
                
                        printf("O que você faz?\n");
                        printf("1. Prender o foragido e reforçar a segurança da cidade.\n");
                        printf("2. Deixar o foragido ir em troca de mais informações.\n");
                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                
                        if (decisao2 == 1) {
                            printf("Você prende o foragido e reforça a segurança da cidade, prevenindo futuros ataques.\n");
                            p->xp += 50; // Recompensa significativa por tomar uma decisão ética e estratégica.
                        } else {
                            printf("Você deixa o foragido ir em troca de mais informações, mas ele foge e a gangue ataca a cidade.\n");
                            printf("Você consegue repelir o ataque, mas a cidade sofre danos.\n");
                            p->xp -= 20; // Penalidade pela decisão arriscada que resultou em prejuízo para a cidade.
                        }
                
                    } else {
                        printf("Você prende o foragido e reforça a segurança da cidade, prevenindo futuros ataques.\n");
                        p->xp += 40; // Recompensa moderada por garantir a segurança sem buscar mais informações.
                    }
         	
                	salvarProgresso(p);
               	 
            	} else if (strcmp(p->tipo, "Forasteiro") == 0) {
                    printf("\nVocê decidiu explorar uma mina abandonada. Dentro, você encontra ouro e outros tesouros.\n");
                    printf("Sua coragem foi recompensada com riquezas.\n");
                    p->xp += 20; // XP inicial pela exploração bem-sucedida da mina.
                
                    // Novo evento
                    printf("\nEnquanto explora a mina, você encontra um mapa antigo que leva a um tesouro ainda maior.\n");
                    printf("Você segue o mapa e encontra uma fortuna escondida.\n");
                    printf("O que você faz?\n");
                    printf("1. Levar o tesouro para a cidade.\n");
                    printf("2. Esconder o tesouro para uso futuro.\n");
                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                
                    if (decisao == 1) {
                        printf("Você leva o tesouro para a cidade e é recebido como um herói.\n");
                        int recompensa = 1000; // Recompensa em dinheiro
                        printf("Você recebe uma recompensa de %d moedas de ouro!\n", recompensa);
                        p->xp += 40; // Recompensa razoável por compartilhar o tesouro e ganhar reconhecimento.
                
                    } else {
                        printf("Você esconde o tesouro e planeja usá-lo em uma emergência futura.\n");
                        p->xp += 30; // Recompensa estratégica menor por manter o tesouro em segredo.
                
                        int decisao2;
                        printf("Você encontra um grupo de bandidos que está atrás do tesouro. O que você faz?\n");
                        printf("1. Lutar contra os bandidos.\n");
                        printf("2. Fugir e esconder o tesouro em outro lugar.\n");
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                
                        if (decisao2 == 1) {
                            printf("Você luta contra os bandidos e consegue proteger o tesouro.\n");
                            p->xp += 50; // Recompensa alta pela coragem e pela vitória contra os bandidos.
                        } else {
                            printf("Você foge e esconde o tesouro em outro lugar, evitando os bandidos.\n");
                            p->xp += 20; // Pequena recompensa por evitar o confronto, mas mantendo o tesouro seguro.
                        }
                    }
                                	
                	salvarProgresso(p);
               	 
            	} else if (strcmp(p->tipo, "Guerreiro Indigena") == 0) {
                    printf("\nVocê decidiu defender sua aldeia contra invasores. Com sua habilidade e bravura, você repele os atacantes.\n");
                    printf("Sua aldeia está segura graças a você.\n");
                    p->xp += 30; // XP inicial pela bravura na batalha.
                
                    // Novo evento
                    printf("\nApós a batalha, você descobre que os invasores estavam atrás de um artefato sagrado.\n");
                    printf("Você recupera o artefato e o devolve à sua aldeia, fortalecendo a proteção espiritual.\n");
                    printf("O que você faz?\n");
                    printf("1. Esconder o artefato em um local seguro.\n");
                    printf("2. Usar o artefato para fortalecer a defesa da aldeia.\n");
                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                
                    if (decisao == 1) {
                        printf("Você esconde o artefato em um local seguro, longe dos olhos dos invasores.\n");
                        p->xp += 20; // Recompensa por tomar uma decisão estratégica de esconder o artefato.
                
                        int decisao2;
                        printf("Você decide revelar a localização do artefato para os anciãos da aldeia?\n");
                        printf("1. Sim\n");
                        printf("2. Não\n");
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                
                        if (decisao2 == 1) {
                            printf("Você revela a localização do artefato para os anciãos da aldeia, que o guardam em segurança.\n");
                            p->xp += 10; // Recompensa adicional pela confiança nos anciãos.
                
                            int decisao3;
                            printf("Alguns dos anciãos são capturados e forçados a revelar o segredo da localização.\n");
                            printf("O que você faz?\n");
                            printf("1. Resgatar os anciãos e proteger o artefato.\n");
                            printf("2. Deixar os anciãos à própria sorte e manter o artefato em segredo em um novo local.\n");
                            printf("Escolha (1 ou 2): ");
                            scanf("%d", &decisao3);
                
                            if (decisao3 == 1) {
                                printf("Você resgatou os anciãos e protege o artefato, garantindo a segurança da aldeia.\n");
                                p->xp += 50; // Grande recompensa pelo ato heroico e difícil de resgate.
                            } else {
                                printf("Você mantém a localização do artefato em segredo, protegendo-o de futuros ataques.\n");
                                p->xp += 10; // Pequena recompensa por priorizar a segurança do artefato.
                            }
                
                        } else {
                            printf("Você mantém a localização do artefato em segredo, protegendo-o de futuros ataques.\n");
                            p->xp += 15; // Recompensa razoável por evitar potenciais riscos ao artefato.
                        }
                
                    } else {
                        printf("Você usa o artefato para fortalecer a defesa da aldeia, garantindo a segurança de todos.\n");
                        p->xp += 40; // Recompensa sólida pela decisão direta de usar o artefato.
                    }
                	
                	salvarProgresso(p);
                               	 
            	} else if (strcmp(p->tipo, "Dama Pistoleira") == 0) {
                	printf("\nVocê decidiu defender sua cidade contra invasores. Com sua mira certeira e coragem, você repele os atacantes com sucesso.\n");
                	printf("A cidade está segura graças à sua bravura.\n");
           	 
                	// Novo evento
                	printf("\nApós a batalha, você descobre que os invasores estavam atrás de um artefato sagrado guardado na cidade.\n");
                	printf("Você recupera o artefato e o devolve, fortalecendo a proteção espiritual da comunidade.\n");
                	printf("O que você faz?\n");
                	printf("1. Esconder o artefato em um local seguro.\n");
                	printf("2. Usar o artefato para fortalecer as defesas da cidade.\n");
               	 
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
               	 
                	if (decisao == 1) {
                    	printf("\nVocê esconde o artefato em um local secreto, longe dos olhos curiosos e das ameaças externas.\n");
                    	printf("Apenas você conhece o esconderijo.\n");
                   	 
                    	int decisao2;
                    	printf("\nVocê decide revelar a localização do artefato para os anciãos da cidade?\n");
                    	printf("1. Sim\n");
                    	printf("2. Não\n");
                    	printf("Escolha (1 ou 2): ");
                    	scanf("%d", &decisao2);
                   	 
                    	if (decisao2 == 1) {
                        	printf("\nVocê revela a localização do artefato para os anciãos, que o guardam em segurança sob juramento de silêncio.\n");
                       	 
                        	int decisao3;
                        	printf("\nInfelizmente, alguns anciãos são capturados por inimigos e forçados a revelar a localização do artefato.\n");
                        	printf("O que você faz?\n");
                        	printf("1. Resgatar os anciãos e proteger o artefato.\n");
                        	printf("2. Abandonar os anciãos e esconder o artefato em outro local.\n");
                        	printf("Escolha (1 ou 2): ");
                        	scanf("%d", &decisao3);
                       	 
                        	if (decisao3 == 1) {
                            	printf("\nVocê organiza uma missão para resgatar os anciãos.\n");
                            	printf("Com sua liderança e habilidade, você os salva e protege o artefato de futuras ameaças.\n");
                            	printf("A cidade comemora sua vitória e você ganha respeito e admiração.\n");
                            	p->xp += 50; // Recompensa por resgatar
                        	} else {
                            	printf("\nVocê prioriza a proteção do artefato e decide escondê-lo em um novo local, garantindo sua segurança.\n");
                            	printf("Embora a decisão seja difícil, você acredita que foi o melhor para a cidade.\n");
                        	}
                       	 
                    	} else {
                        	printf("\nVocê mantém o local do artefato em segredo absoluto.\n");
                        	printf("A cidade continua protegida, mas alguns moradores questionam sua decisão de não compartilhar o conhecimento.\n");
                        	p->xp -= 10; // Penalidade por não compartilhar
                    	}
                   	 
                	} else {
                    	printf("\nVocê usa o artefato para fortalecer as defesas da cidade.\n");
                    	printf("Com o poder do artefato, a cidade ergue novas barreiras espirituais e físicas que intimidam qualquer futuro invasor.\n");
                    	printf("A comunidade celebra sua decisão e se sente mais protegida do que nunca.\n");
                    	p->xp += 50; // Recompensa por fortalecer a cidade
                	}
           	 
                	// Função para salvar o progresso após as decisões
                	salvarProgresso(p);
            	}

            	break;

          	case 2:
            	if (strcmp(p->tipo, "Pistoleiro") == 0) {
                	printf("\nVoce decidiu proteger a cidade de um ataque. Com sua precisao e coragem, voce derrota os bandidos.\n");
                	printf("A cidade esta em paz novamente, graças a voce.\n");
                	// Novo evento
                	printf("\nApos a batalha, voce e convidado pelo prefeito para uma celebracao em sua honra.\n");
                	printf("Durante a celebracao, voce recebe uma medalha de bravura e um terreno na cidade.\n");
                	printf("O que voce faz?\n");
                	printf("1. Aceitar o terreno e se estabelecer na cidade.\n");
                	printf("2. Recusar o terreno e continuar sua jornada.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
                	if (decisao == 1) {
                    	printf("Voce aceita o terreno e se estabelece na cidade, tornando-se um membro respeitado da comunidade.\n");
                    	printf("Voce decide construir uma casa e se torna um cidadao da cidade.\n");
                    	printf("No caminho, voce encontra uma dama em perigo, sendo atormentada por 2 velhos bebados. O que voce faz?\n");
                    	printf("1. Ajudar a dama e enfrentar os bebados.\n");
                    	printf("2. Ignorar a situacao e continuar seu caminho.\n");
                    	int decisao2;
                    	printf("Escolha (1 ou 2): ");
                    	scanf("%d", &decisao2);
                    	if (decisao2 == 1) {
                        	printf("Voce ajuda a dama e enfrenta os bebados, protegendo-a e ganhando sua gratidao.\n");
                        	printf("A dama fica impressionada com sua coragem e deseja te recompensar.\n");
                        	printf("O que voce faz?\n");
                        	printf("1. Aceitar uma recompensa da dama.\n");
                        	printf("2. Aceita um beijo da dama.\n");
                        	p->xp += 50;
                        	int decisao3;
                        	printf("Escolha (1 ou 2): ");
                        	scanf("%d", &decisao3);
                        	if (decisao3 == 1) {
                            	printf("Voce aceita a recompensa da dama e ela te da uma bolsa de moedas de ouro.\n");
                        	} else {
                            	printf("Voce aceita um beijo da dama e ela te agradece com um sorriso.\n");
                            	p->xp += 50;
                        	}
                    	} else {
                        	printf("Voce ignora a situacao e continua seu caminho, deixando a dama em perigo.\n");
                    	}
                	} else {
                    	printf("Voce recusa o terreno e continua sua jornada, em busca de novas aventuras.\n");
                    	p->xp += 50;

                	}
                	salvarProgresso(p);

            	} else if (strcmp(p->tipo, "Xerife") == 0) {
                	printf("\nVoce organizou uma defesa contra bandidos. Com sua liderança, a cidade repele o ataque.\n");
                	printf("Os cidadaos estao gratos pela sua protecao.\n");
                	// Novo evento
                	printf("\nApos a defesa, voce descobre que os bandidos tinham um plano maior para dominar a regiao.\n");
                	printf("Voce organiza uma expedicao para desmantelar a base dos bandidos e consegue captura-los.\n");
                	printf("O que voce faz?\n");
                	printf("1. Interrogar os bandidos capturados para obter mais informacoes.\n");
                	printf("2. Prender os bandidos e reforcar a seguranca da cidade.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
                	if (decisao == 1) {
                    	printf("Voce interroga os bandidos capturados e descobre mais sobre seus planos.\n");
                    	printf("Com as informacoes, voce consegue evitar futuros ataques e proteger a cidade.\n");
                    	printf("Um dos bandidos revela a localizacao de um esconderijo de armas. O que voce faz?\n");
                    	printf("1. Investigar o esconderijo e confiscar as armas.\n");
                    	printf("2. Prender os bandidos e encerrar a investigacao.\n");
                    	int decisao2;
                    	printf("Escolha (1 ou 2): ");
                    	scanf("%d", &decisao2);
                    	if (decisao2 == 1) {
                        	printf("Voce investiga o esconderijo e encontra um arsenal de armas, e encontra um grupo de refens.\n");
                        	printf("Voce liberta os refens e confisca as armas, garantindo a seguranca da cidade.\n");
                        	p->xp += 50;
                    	} else {
                        	printf("Voce prende os bandidos e encerra a investigacao, garantindo a seguranca da cidade.\n");
                    	}
                	} else {
                    	printf("Voce prende os bandidos e reforca a seguranca da cidade, prevenindo futuros ataques.\n");
                    	p->xp += 25;
                	}
                	salvarProgresso(p);

            	} else if (strcmp(p->tipo, "Forasteiro") == 0) {
                	printf("\nVoce decidiu procurar tesouros escondidos. Apos uma longa busca, voce encontra um mapa antigo.\n");
                	printf("O mapa leva a um tesouro enterrado, aumentando suas riquezas.\n");
                	// Novo evento
                	printf("\nEnquanto segue o mapa, voce encontra um grupo de bandidos que tambem esta atras do tesouro.\n");
                	printf("Voce os enfrenta e, apos uma batalha intensa, consegue proteger o tesouro.\n");
                	printf("O que voce faz?\n");
                	printf("1. Levar o tesouro para a cidade.\n");
                	printf("2. Esconder o tesouro para uso futuro.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
                	if (decisao == 1) {
                    	printf("Voce leva o tesouro para a cidade e e recebido como um heroi.\n");
                    	printf("Voce decide doar parte do tesouro para a cidade e e aclamado como um benfeitor.\n");
                    	printf("Um grupo de colonos agradece sua generosidade e te oferece uma oportunidade de trabalhar como colonizador e explorador da cidade.\n");
                    	printf("O que voce faz?\n");
                    	printf("1. Aceitar a oferta e se tornar um colonizador.\n");
                    	printf("2. Recusar a oferta e continuar sua jornada.\n");
                    	int decisao2;
                    	printf("Escolha (1 ou 2): ");
                    	scanf("%d", &decisao2);
                    	if (decisao2 == 1) {
                        	printf("Voce aceita a oferta e se torna um colonizador, ajudando a construir uma nova comunidade.\n");
                        	p->xp += 15;
                    	} else {
                        	printf("Voce recusa a oferta e continua sua jornada solo, em busca de novas aventuras.\n");
                    	}
                	} else {
                    	printf("Voce esconde o tesouro e planeja usa-lo em uma emergencia futura.\n");
                    	p->xp -= 15;
                	}
                	salvarProgresso(p);

            	} else if (strcmp(p->tipo, "Guerreiro Indigena") == 0) {
                	printf("\nVocê decidiu resgatar um aliado capturado. Com sua astúcia e força, você invade o acampamento inimigo e resgata seu aliado.\n");
                	printf("Seu aliado está seguro e sua aldeia está em dívida com você.\n");
                	p->xp += 30; // Recompensa por resgatar o aliado com sucesso.
           	 
                	// Novo evento
                	printf("\nApós o resgate, seu aliado revela informações sobre um ataque iminente à aldeia.\n");
                	printf("Você se prepara e, com a ajuda de seu aliado, consegue repelir o ataque e garantir a segurança da aldeia.\n");
                	printf("O que você faz?\n");
                	printf("1. Fortalecer a defesa da aldeia.\n");
                	printf("2. Planejar um ataque preventivo contra os invasores.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
           	 
                	if (decisao == 1) {
                    	printf("Você fortalece a defesa da aldeia, garantindo a segurança de todos.\n");
                    	p->xp += 40; // Recompensa adicional por tomar uma ação de defesa estratégica.
                	} else {
                    	printf("Você planeja um ataque preventivo e consegue derrotar os invasores antes que ataquem novamente.\n");
                    	p->xp += 60; // Recompensa maior por uma ação ofensiva bem-sucedida.
                	}

                	salvarProgresso(p);
               	 
            	} else if (strcmp(p->tipo, "Dama Pistoleira") == 0) {
                	printf("\nVocê decidiu recrutar aliados para a cidade.\n");
                	printf("Com seu carisma e habilidade, você parte em uma jornada para encontrar pessoas dispostas a ajudar.\n");
           	 
                	// Novo evento
                	printf("\nDurante sua busca, você encontra três potenciais aliados:\n");
                	printf("1. Um ex-militar experiente em estratégias de defesa.\n");
                	printf("2. Um comerciante rico disposto a financiar melhorias na cidade.\n");
                	printf("3. Um jovem destemido que deseja aprender com você e proteger o local.\n");
                	printf("Quem você recruta primeiro?\n");
                	printf("Escolha (1, 2 ou 3): ");
                	int decisao;
                	scanf("%d", &decisao);
           	 
                	switch (decisao) {
                    	case 1:
                        	printf("\nVocê recruta o ex-militar, que imediatamente ajuda a organizar a defesa da cidade.\n");
                        	printf("Com seu conhecimento, fortalece as barreiras e treina os moradores para se defenderem.\n");
                        	printf("Enquanto trabalha na defesa, o militar revela que precisa de mais materiais para construir barricadas eficazes.\n");
                        	printf("O que você faz?\n");
                        	printf("1. Buscar os materiais necessários sozinho.\n");
                        	printf("2. Solicitar ajuda dos moradores para reunir os materiais.\n");
                        	int decisao1;
                        	printf("Escolha (1 ou 2): ");
                        	scanf("%d", &decisao1);
           	 
                        	if (decisao1 == 1) {
                            	printf("\nVocê se aventura para buscar os materiais sozinho e enfrenta bandidos no caminho.\n");
                            	printf("Apesar do perigo, você retorna com sucesso e garante que a defesa da cidade seja reforçada.\n");
                            	p->xp += 50;
                        	} else {
                            	printf("\nVocê convoca os moradores para ajudar na coleta dos materiais.\n");
                            	printf("Com a colaboração de todos, os materiais são reunidos rapidamente e a cidade fica mais segura.\n");
                            	p->xp += 30;
                        	}
                        	break;
           	 
                    	case 2:
                        	printf("\nVocê recruta o comerciante rico, que investe seus recursos para melhorar a infraestrutura da cidade.\n");
                        	printf("Com o financiamento, você constrói novas fortificações e armazena suprimentos.\n");
                        	printf("O comerciante, no entanto, exige algo em troca: uma posição de liderança no conselho da cidade.\n");
                        	printf("O que você faz?\n");
                        	printf("1. Concordar com a exigência dele.\n");
                        	printf("2. Recusar e procurar outro aliado.\n");
                        	int decisao2;
                        	printf("Escolha (1 ou 2): ");
                        	scanf("%d", &decisao2);
           	 
                        	if (decisao2 == 1) {
                            	printf("\nVocê concorda com a exigência, e o comerciante se torna um membro influente na cidade.\n");
                            	printf("Embora ele seja ambicioso, sua ajuda é valiosa para o crescimento da comunidade.\n");
                            	p->xp += 40;
                        	} else {
                            	printf("\nVocê recusa a exigência e decide procurar outro aliado disposto a ajudar sem condições.\n");
                            	printf("Embora isso leve mais tempo, você mantém a integridade da liderança da cidade.\n");
                            	p->xp += 20;
                        	}
                        	break;
           	 
                    	case 3:
                        	printf("\nVocê recruta o jovem destemido, que rapidamente se torna seu aprendiz.\n");
                        	printf("Você o treina em habilidades de combate e liderança, preparando-o para defender a cidade no futuro.\n");
                        	printf("Durante o treinamento, o jovem revela que sua família foi capturada por bandidos em uma vila próxima.\n");
                        	printf("O que você faz?\n");
                        	printf("1. Ajudar o jovem a resgatar sua família.\n");
                        	printf("2. Convencê-lo a se focar na proteção da cidade.\n");
                        	int decisao3;
                        	printf("Escolha (1 ou 2): ");
                        	scanf("%d", &decisao3);
           	 
                        	if (decisao3 == 1) {
                            	printf("\nVocê lidera uma missão de resgate e enfrenta os bandidos que capturaram a família do jovem.\n");
                            	printf("Com sucesso, a família é salva e o jovem fica eternamente grato por sua ajuda.\n");
                            	p->xp += 50;
                        	} else {
                            	printf("\nVocê convence o jovem de que proteger a cidade é a prioridade no momento.\n");
                            	printf("Embora relutante, ele confia em seu julgamento e dedica seu tempo à defesa da comunidade.\n");
                            	p->xp += 30;
                        	}
                        	break;
           	 
                    	default:
                        	printf("\nEscolha inválida! Você perde tempo valioso e os aliados se tornam mais difíceis de encontrar.\n");
                        	break;
                	}
           	 
                	// Evento de conclusão
                	printf("\nApós recrutar aliados, a cidade está mais forte e pronta para enfrentar qualquer ameaça.\n");
                	printf("Sua liderança inspira os moradores, que agora confiam plenamente em você.\n");
                	salvarProgresso(p);
            	}
           	 
            	break;

           	case 3:
            	if (strcmp(p->tipo, "Pistoleiro") == 0) {
                	printf("\nVocê decidiu participar de um torneio de tiro. Sua habilidade com a arma é posta à prova.\n");
                	printf("Você vence o torneio e ganha respeito e reconhecimento na cidade.\n");
                	p->xp += 30; // Recompensa por vencer o torneio e ganhar reconhecimento.
           	 
                	// Novo evento
                	printf("\nApós o torneio, um misterioso homem se aproxima e oferece uma missão secreta.\n");
                	printf("Você aceita a missão e parte em uma nova aventura.\n");
                	printf("O que você faz?\n");
                	printf("1. Aceitar a missão e partir imediatamente.\n");
                	printf("2. Recusar a missão e continuar sua vida na cidade.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
           	 
                	if (decisao == 1) {
                    	printf("Você aceita a missão e parte em uma nova aventura, em busca de mais desafios.\n");
                    	printf("Durante a missão, você descobre uma conspiração para derrubar o governo local.\n");
                    	printf("Você consegue impedir o golpe e salvar a cidade de um destino sombrio.\n");
                    	p->xp += 50; // Grande recompensa por aceitar um desafio e salvar a cidade.
                	} else {
                    	printf("Você recusa a missão e continua sua vida na cidade, aproveitando o respeito conquistado.\n");
                    	p->xp += 20; // Recompensa moderada por manter a situação atual e não arriscar, mas ainda mostrando respeito pela cidade.
                	}
               	 
                	salvarProgresso(p);
               	 
            	} else if (strcmp(p->tipo, "Xerife") == 0) {
                	printf("\nVocê decidiu investigar um roubo misterioso. Após seguir várias pistas, você descobre o culpado.\n");
                	printf("A justiça é feita e a cidade está mais segura.\n");
                	p->xp += 30; // Recompensa por resolver o roubo e melhorar a segurança
           	 
                	// Novo evento
                	printf("\nDurante a investigação, você descobre uma conspiração maior envolvendo figuras importantes da cidade.\n");
                	printf("Você decide continuar investigando para desmantelar a conspiração.\n");
                	printf("O que você faz?\n");
                	printf("1. Continuar investigando a conspiração.\n");
                	printf("2. Prender os culpados e encerrar a investigação.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
           	 
                	if (decisao == 1) {
                    	printf("Você continua investigando e descobre mais sobre a conspiração, desmantelando-a completamente.\n");
                    	printf("A cidade está segura e você é considerado um herói.\n");
                    	p->xp += 50; // Recompensa significativa por continuar a investigação e desmantelar a conspiração
                	} else {
                    	printf("Você prende os culpados e encerra a investigação, garantindo a segurança da cidade.\n");
                    	printf("Durante a prisão, um dos culpados revela a localização de um esconderijo de bandidos.\n");
                    	printf("Você decide explorar o esconderijo e encontra valiosos itens roubados.\n");
                    	printf("O que você faz?\n");
                    	printf("1. Levar os itens para a cidade.\n");
                    	printf("2. Esconder os itens para uso futuro.\n");
                    	int decisao2;
                    	printf("Escolha (1 ou 2): ");
                    	scanf("%d", &decisao2);
           	 
                    	if (decisao2 == 1) {
                        	printf("Você leva os itens para a cidade e é recebido como um herói.\n");
                        	p->xp += 40; // Recompensa alta por ser heroico e levar os itens à cidade
                    	} else {
                        	printf("Você esconde os itens e planeja usá-los em uma emergência futura.\n");
                        	printf("Você acaba negligenciando a justiça em prol de sua própria vantagem.\n");
                        	p->xp -= 10; // Penalização por uma escolha egoísta
                    	}
                	}
                	salvarProgresso(p);
               	 
            	} else if (strcmp(p->tipo, "Forasteiro") == 0) {
                	printf("\nVocê decidiu ajudar um fazendeiro local. Com seu auxílio, a colheita é salva e o fazendeiro está grato.\n");
                	printf("Você ganha a amizade e o apoio da comunidade local.\n");
                	p->xp += 20; // Recompensa por ajudar o fazendeiro e fortalecer laços com a comunidade
           	 
                	// Novo evento
                	printf("\nO fazendeiro revela a localização de um antigo esconderijo de bandidos.\n");
                	printf("Você decide explorar o esconderijo e encontra valiosos itens perdidos.\n");
                	printf("O que você faz?\n");
                	printf("1. Levar os itens para a cidade.\n");
                	printf("2. Esconder os itens para uso futuro.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
           	 
                	if (decisao == 1) {
                    	printf("\nVocê leva os itens para a cidade e é recebido como um herói.\n");
                    	p->xp += 40; // Recompensa maior por ser heroico e compartilhar com a cidade
                	} else {
                    	printf("\nVocê esconde os itens e planeja usá-los em uma emergência futura.\n");
                    	p->xp += 25; // Recompensa menor, mas ainda significativa por ser estratégico e cauteloso
                	}
           	 
                	salvarProgresso(p);
    
               	 
            	} else if (strcmp(p->tipo, "Guerreiro Indigena") == 0) {
                	printf("\nVocê decidiu realizar um ritual sagrado. O ritual fortalece os laços espirituais da sua aldeia.\n");
                	printf("Sua aldeia prospera e você é reverenciado como um grande líder espiritual.\n");
                	p->xp += 20; // Recompensa inicial por realizar o ritual
           	 
                	// Novo evento
                	printf("\nDurante o ritual, você tem uma visão de um perigo iminente.\n");
                	printf("Você se prepara para enfrentar essa nova ameaça e proteger sua aldeia.\n");
                	printf("O que você faz?\n");
                	printf("1. Fortalecer a defesa da aldeia.\n");
                	printf("2. Planejar um ataque preventivo contra os invasores.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
           	 
                	if (decisao == 1) {
                    	printf("\nVocê fortalece a defesa da aldeia, garantindo a segurança de todos.\n");
                    	printf("Durante a preparação, você descobre que a ameaça é uma invasão iminente de bandidos.\n");
                    	printf("Você consegue repelir o ataque e proteger a aldeia.\n");
                    	p->xp += 30; // Recompensa por defesa bem-sucedida
           	 
                    	printf("\nO que você faz?\n");
                    	printf("1. Interrogar os bandidos capturados para obter mais informações.\n");
                    	printf("2. Prender os bandidos e reforçar a segurança da aldeia.\n");
                    	int decisao2;
                    	printf("Escolha (1 ou 2): ");
                    	scanf("%d", &decisao2);
           	 
                    	if (decisao2 == 1) {
                        	printf("\nVocê interroga os bandidos capturados e descobre mais sobre seus planos.\n");
                        	printf("Com as informações, você consegue evitar futuros ataques e proteger a aldeia.\n");
                        	p->xp += 50; // Recompensa adicional por estratégia inteligente
                    	} else {
                        	printf("\nVocê prende os bandidos e reforça a segurança da aldeia, prevenindo futuros ataques.\n");
                        	p->xp += 20; // Recompensa menor, mas ainda positiva
                    	}
                	} else {
                    	printf("\nVocê planeja um ataque preventivo e consegue derrotar os invasores antes que ataquem novamente.\n");
                    	printf("Sua aldeia está segura e você é considerado um herói.\n");
                    	printf("Você decide realizar um ritual de agradecimento aos espíritos pela proteção da aldeia.\n");
                    	p->xp += 40; // Recompensa maior pelo ataque proativo e vitória
                	}
           	 
                	salvarProgresso(p);
    
               	 
            	} else if (strcmp(p->tipo, "Dama Pistoleira") == 0) {
                	printf("\nVocê decidiu participar de um torneio de tiro. Sua habilidade com a arma é posta à prova.\n");
                	printf("Você vence o torneio e ganha respeito e reconhecimento na cidade.\n");
                	p->xp += 20; // Recompensa por vencer o torneio
               	 
                	// Novo evento
                	printf("\nApós o torneio, um misterioso homem se aproxima e oferece uma missão secreta.\n");
                	printf("Você aceita a missão e parte em uma nova aventura.\n");
                	printf("O que você faz?\n");
                	printf("1. Aceitar a missão e partir imediatamente.\n");
                	printf("2. Recusar a missão e continuar sua vida na cidade.\n");
                	int decisao;
                	printf("Escolha (1 ou 2): ");
                	scanf("%d", &decisao);
           	 
                	if (decisao == 1) {
                    	printf("\nVocê aceita a missão e parte em uma nova aventura, em busca de mais desafios.\n");
                    	printf("Durante a missão, você descobre uma conspiração para derrubar o governo local.\n");
                    	printf("Você consegue impedir o golpe e salvar a cidade de um destino sombrio.\n");
           	 
                    	// Recompensa adicional de XP pelo risco e impacto da missão
                    	p->xp += 50;
                    	printf("Você ganhou 50 XP pela coragem e sucesso em sua missão!\n");
           	 
                    	// Recompensa extra se o jogador tiver feito algo excepcional
                    	if (p->nivel > 5) { // Exemplo de condição para bônus
                        	printf("Sua experiência e habilidade lhe renderam um bônus adicional!\n");
                        	p->xp += 10;
                    	}
                	} else {
                    	printf("\nVocê recusa a missão e continua sua vida na cidade, aproveitando o respeito conquistado.\n");
                    	printf("Embora tenha optado por uma vida tranquila, sua reputação ainda lhe rende algum benefício.\n");
           	 
                    	// Pequena recompensa para escolha segura
                    	p->xp += 10;
                    	printf("Você ganhou 10 XP por manter sua posição na cidade.\n");
                	}
           	 
                	salvarProgresso(p);
            	}
               	 
            	break;
       	 
    	default:
        	printf("Escolha invalida!\n");
        	break;
    	}
   	 
    	// Perguntar se o jogador quer jogar novamente ou voltar ao menu principal
    	printf("\nO que voce gostaria de fazer agora?\n");
    	printf("1. Jogar novamente\n");
    	printf("2. Voltar ao menu principal\n");
    	printf("Escolha (1 ou 2): ");
    	scanf("%d", &jogarNovamente);
    	} while (jogarNovamente == 1);
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