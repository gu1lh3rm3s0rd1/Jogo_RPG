#include <iostream>
#include <stdio.h>
#include <string.h>

// Definicao da struct para representar um personagem
struct Personagem {
    char nome[50];          // Nome
    char tipo[30];          // Tipo do personagem
    int vitalidade;         // Vida
    int ataque;             // Poder de ataque
    int defesa;             // Defesa contra ataques
    int xp;                 // XP atual do jogador
    int xpParaProximoNivel; // XP necessario para avancar de nivel
    int nivel;              // Nivel do personagem
};

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
    personagens[0].xpParaProximoNivel = 100;
    personagens[0].nivel = 1;

    strcpy(personagens[1].nome, "Xerife Nascimento");
    strcpy(personagens[1].tipo, "Xerife");
    personagens[1].vitalidade = 120;
    personagens[1].ataque = 25;
    personagens[1].defesa = 25;
    personagens[1].xp = 0;
    personagens[1].xpParaProximoNivel = 100;
    personagens[1].nivel = 1;

    strcpy(personagens[2].nome, "Pedro Bala de Prata");
    strcpy(personagens[2].tipo, "Forasteiro");
    personagens[2].vitalidade = 90;
    personagens[2].ataque = 35;
    personagens[2].defesa = 15;
    personagens[2].xp = 0;
    personagens[2].xpParaProximoNivel = 100;
    personagens[2].nivel = 1;

    strcpy(personagens[3].nome, "Cacique Galo Velho");
    strcpy(personagens[3].tipo, "Guerreiro Indigena");
    personagens[3].vitalidade = 110;
    personagens[3].ataque = 32;
    personagens[3].defesa = 22;
    personagens[3].xp = 0;
    personagens[3].xpParaProximoNivel = 100;
    personagens[3].nivel = 1;

    strcpy(personagens[4].nome, "Marina Sorrateira");
    strcpy(personagens[4].tipo, "Dama Pistoleira");
    personagens[4].vitalidade = 110;
    personagens[4].ataque = 20;
    personagens[4].defesa = 15;
    personagens[4].xp = 0;
    personagens[4].xpParaProximoNivel = 100;
    personagens[4].nivel = 1;
}

// Funcao para criar um personagem
void criarPersonagem(struct Personagem *p) {
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
        p->ataque = 32;
        p->defesa = 22;
        break;
    case 5:
        strcpy(p->tipo, "Dama Pistoleira");
        p->vitalidade = 95;
        p->ataque = 20;
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
void exibirPersonagem(const struct Personagem *p) {
    printf("Nome: %s\n", p->nome);
    printf("Tipo: %s\n", p->tipo);
    printf("Nivel: %d\n", p->nivel);
    printf("XP: %d/%d\n", p->xp, p->xpParaProximoNivel);
    printf("Vitalidade: %d\n", p->vitalidade);
    printf("Ataque: %d\n", p->ataque);
    printf("Defesa: %d\n", p->defesa);
}

// Funcao para add XP do personagem
void adicionarXP(struct Personagem *p, int xpGanho) {
    printf("%s recebeu %d XP!\n", p->nome, xpGanho);
    p->xp += xpGanho;

    // Evita XP negativo
    if (p->xp < 0) {
        p->xp = 0;
    }

    // Verificar se o personagem deve subir de nivel
    while (p->xp >= p->xpParaProximoNivel) {
        p->xp -= p->xpParaProximoNivel;
        p->nivel++;
        p->xpParaProximoNivel += 50; // Aumenta o limite de XP para o proximo nivel
        printf("%s subiu para o nivel %d!\n", p->nome, p->nivel);
        p->vitalidade += 10;
        p->ataque += 2;
        p->defesa += 2;
    }
}

// Funcao para salvar o progresso
void salvarProgresso(struct Personagem *p) {
    printf("\nProgresso salvo com sucesso para o personagem %s!\n", p->nome);
    printf("Experiencia: %d\n", p->xp);
}

// Funcao para modo bataha
void batalha(struct Personagem *p1, struct Personagem *p2) {
    printf("\n=== Detalhes dos Personagens na Batalha ===\n");
    printf("\n--- Detalhes de %s ---\n", p1->nome);
    exibirPersonagem(p1);
    printf("\n--- Detalhes de %s ---\n", p2->nome);
    exibirPersonagem(p2);

    printf("\n%s (Ataque: %d) VS %s (Ataque: %d)\n", p1->nome, p1->ataque, p2->nome, p2->ataque);

    int contadorAtaquesP1 = 0; // Contador de ataques do jogador
    int contadorAtaquesP2 = 0; // Contador de ataques do oponente

    // Simulacao de turnos com controle do jogador
    while (p1->vitalidade > 0 && p2->vitalidade > 0) {
        int acao;
        int dano1 = 0, dano2 = 0;
        bool defendendo = false;

        // Acao do jogador
        printf("\n%s, escolha sua acao:\n", p1->nome);
        printf("1. Atacar\n");
        printf("2. Defender\n");
        printf("3. Exibir detalhes do personagem\n");
        printf("Escolha (1-3): ");
        scanf("%d", &acao);

        switch (acao)
        {
        case 1:
            contadorAtaquesP1++;
            if (contadorAtaquesP1 == 2) {
                dano1 = (p1->ataque * 2) - p2->defesa; // Ataque especial
                printf("%s realizou um ataque especial!\n", p1->nome);
                contadorAtaquesP1 = 0; // Resetar o contador

            } else {
                dano1 = p1->ataque - p2->defesa;
            }

            if (dano1 < 0)
                dano1 = 0;

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
            continue; // menu de acao
            break;

        default:
            printf("Acao invalida! Perdendo a vez.\n");
            break;
        }

        if (p2->vitalidade <= 0) {
            printf("%s venceu!\n", p1->nome);
            adicionarXP(p1, 50);  // Premiar jogador com XP ao vencer
            adicionarXP(p2, -20); // Penalizar o oponente por perder
            break;
        }

        // Acao do oponente
        printf("\nTurno de %s:\n", p2->nome);
        contadorAtaquesP2++;
        if (contadorAtaquesP2 == 2)  {
            dano2 = (p2->ataque * 2) - p1->defesa; // Ataque especial
            printf("%s realizou um ataque especial!\n", p2->nome);
            contadorAtaquesP2 = 0; // Resetar o contador
        }
        else{
            dano2 = p2->ataque - p1->defesa;
        }
        if (defendendo) {
            dano2 /= 2; // Reduz o dano pela metade se estiver defendendo
        }

        if (dano2 < 0)
            dano2 = 0;
        p1->vitalidade -= dano2;
        printf("%s atacou %s causando %d de dano!\n", p2->nome, p1->nome, dano2);

        if (p1->vitalidade <= 0) {
            printf("%s venceu!\n", p2->nome);
            adicionarXP(p2, 50);  // Premiar oponente com XP ao vencer
            adicionarXP(p1, -20); // Penalizar jogador por perder
            break;
        }

        // Mostrar o nivel de vida dos personagens apos cada acao
        printf("\nNivel de vida apos a rodada:\n");
        printf("%s: %d\n", p1->nome, p1->vitalidade);
        printf("%s: %d\n", p2->nome, p2->vitalidade);
    }

    // Exibir o vencedor
    printf("\n=== Fim da Batalha ===\n");
    printf("Vencedor: %s\n", p1->vitalidade > 0 ? p1->nome : p2->nome);

    // Salvar o progresso dos personagens
    salvarProgresso(p1);
    salvarProgresso(p2);
}

// Funcao para o modo historia
void modoHistoria(struct Personagem *p) {
    int jogarNovamente;

    do {
        printf("\n========================================\n");
        printf("Voce escolheu jogar com %s, o %s!\n", p->nome, p->tipo);
        printf("Este personagem e conhecido por suas habilidades unicas e coragem no Velho Oeste.\n");
        printf("========================================\n");

        printf("\nEscolha uma acao:\n");
        if (strcmp(p->tipo, "Pistoleiro") == 0) {
            printf("1. Desafiar um bandido para um duelo.\n");
            printf("2. Proteger a cidade de um ataque.\n");
            printf("3. Participar de um torneio de tiro.\n");
        }
        else if (strcmp(p->tipo, "Xerife") == 0) {
            printf("1. Prender um foragido.\n");
            printf("2. Organizar uma defesa contra bandidos.\n");
            printf("3. Investigar um roubo misterioso.\n");
        }
        else if (strcmp(p->tipo, "Forasteiro") == 0) {
            printf("1. Explorar uma mina abandonada.\n");
            printf("2. Procurar tesouros escondidos.\n");
            printf("3. Ajudar um fazendeiro local.\n");
        }
        else if (strcmp(p->tipo, "Guerreiro Indigena") == 0) {
            printf("1. Defender sua aldeia contra invasores.\n");
            printf("2. Resgatar um aliado capturado.\n");
            printf("3. Realizar um ritual sagrado.\n");
        }
        else if (strcmp(p->tipo, "Dama Pistoleira") == 0) {
            printf("1. Defender sua cidade contra invasores.\n");
            printf("2. Recrutar aliados para a cidade.\n");
            printf("3. Participar de um torneio de tiro.\n");
        }

        int acao;
        printf("Escolha uma acao (1, 2 ou 3): ");
        scanf("%d", &acao);

        switch (acao){
            case 1:
                if (strcmp(p->tipo, "Pistoleiro") == 0)
                {
                    printf("\n========================================\n");
                    printf("Voce desafiou um bandido para um duelo. O sol esta alto e o clima eh tenso.\n");
                    printf("Voce saca sua arma rapidamente e atira. O bandido cai no chao, derrotado.\n");
                    printf("A cidade esta segura por enquanto, gracas a Voce.\n");
                    p->xp += 20;

                    printf("\nApos o duelo, Voce encontra uma carta no bolso do bandido. Ela menciona um tesouro escondido nas montanhas.\n");
                    printf("Voce decide seguir as pistas e encontra um baú cheio de ouro.\n");
                    printf("========================================\n");

                    printf("Voce ganhou 20 XP pela decisao de desafiar um bandido para um duelo.\n");
                    p->vitalidade += 40; // Aumenta a vitalidade em +40
                    printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);

                    printf("O que Voce faz?\n");
                    printf("1. Levar o ouro para a cidade.\n");
                    printf("2. Esconder o ouro para uso futuro.\n");

                    int decisao;
                    printf("\nEscolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce leva o ouro para a cidade e eh recebido como um heroi.\n");
                        printf("O ouro eh usado para melhorar a seguranca e infraestrutura local.\n");
                        printf("========================================\n");
                        p->xp += 50;

                        printf("Voce ganhou 50 XP pela decisao de levar o ouro para a cidade.\n");
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce esconde o ouro e planeja usa-lo em uma emergência futura.\n");
                        printf("Enquanto isso, rumores sobre o tesouro comecam a se espalhar.\n");
                        printf("Voce encontra um grupo de cacadores de tesouros atras do ouro.\n");
                        printf("========================================\n");

                        printf("O que Voce faz?\n");
                        printf("1. Enfrentar os cacadores e proteger o ouro.\n");
                        printf("2. Negociar com os cacadores para dividir o tesouro.\n");

                        int decisao2;
                        printf("\nEscolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce enfrenta os cacadores em um tiroteio intenso e consegue proteger o ouro.\n");
                            printf("========================================\n");
                            p->xp += 40;

                            printf("Voce ganhou 40 XP pela decisao de enfrentar os cacadores e proteger o ouro.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce negocia com os cacadores e divide o tesouro, garantindo uma parte para si.\n");
                            printf("========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de negociar com os cacadores para dividir o tesouro.\n");
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Xerife") == 0)
                {
                    printf("\n========================================\n");
                    printf("Voce decidiu prender um foragido. Apos uma perseguicao intensa, Voce consegue captura-lo.\n");
                    printf("A cidade esta mais segura com menos um criminoso nas ruas.\n");
                    printf("========================================\n");
                    p->xp += 20;

                    printf("\nDurante a prisao, o foragido revela informacoes sobre uma gangue que planeja atacar a cidade.\n");
                    printf("Voce se prepara para enfrentar a gangue e consegue impedir o ataque.\n");
                    printf("O que Voce faz?\n");
                    printf("1. Interrogar o foragido para obter mais informacoes.\n");
                    printf("2. Prender o foragido e reforcar a seguranca da cidade.\n");

                    int decisao;
                    printf("\nEscolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce interroga o foragido e descobre mais sobre os planos da gangue.\n");
                        printf("Com as informacoes, Voce consegue evitar futuros ataques.\n");
                        printf("========================================\n");
                        p->xp += 30;

                        printf("\nO que Voce faz?\n");
                        printf("1. Prender o foragido e reforcar a seguranca da cidade.\n");
                        printf("2. Deixar o foragido ir em troca de mais informacoes.\n");

                        int decisao2;
                        printf("\nEscolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce prende o foragido e reforca a seguranca da cidade, prevenindo futuros ataques.\n");
                            printf("========================================\n");
                            p->xp += 50;

                            printf("Voce ganhou 50 XP pela decisao de prender o foragido e reforcar a seguranca da cidade.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce deixa o foragido ir em troca de mais informacoes, mas ele foge e a gangue ataca a cidade.\n");
                            printf("Voce consegue repelir o ataque, mas a cidade sofre danos.\n");
                            printf("========================================\n");
                            p->xp -= 20;

                            printf("Voce perdeu 20 XP pela decisao de deixar o foragido ir em troca de mais informacoes.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce prende o foragido e reforca a seguranca da cidade, prevenindo futuros ataques.\n");
                        printf("========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela decisao de prender o foragido e reforcar a seguranca da cidade.\n");
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Forasteiro") == 0)
                {
                    printf("\n========================================\n");
                    printf("Voce decidiu explorar uma mina abandonada. Dentro, Voce encontra ouro e outros tesouros.\n");
                    printf("Sua coragem foi recompensada com riquezas.\n");
                    printf("========================================\n");
                    p->xp += 20;

                    printf("\nEnquanto explora a mina, Voce encontra um mapa antigo que leva a um tesouro ainda maior.\n");
                    printf("Voce segue o mapa e encontra uma fortuna escondida.\n");
                    printf("O que Voce faz?\n");
                    printf("1. Levar o tesouro para a cidade.\n");
                    printf("2. Esconder o tesouro para uso futuro.\n");

                    int decisao;
                    printf("\nEscolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce leva o tesouro para a cidade e eh recebido como um heroi.\n");
                        printf("O tesouro eh usado para melhorar a seguranca e infraestrutura local.\n");
                        printf("========================================\n");
                        p->xp += 50;

                        printf("Voce ganhou 50 XP pela decisao de levar o tesouro para a cidade.\n");
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce esconde o tesouro e planeja usa-lo em uma emergência futura.\n");
                        printf("Enquanto isso, rumores sobre o tesouro comecam a se espalhar.\n");
                        printf("Voce encontra um grupo de bandidos atras do tesouro.\n");
                        printf("========================================\n");

                        printf("O que Voce faz?\n");
                        printf("1. Enfrentar os bandidos e proteger o tesouro.\n");
                        printf("2. Negociar com os bandidos para dividir o tesouro.\n");

                        int decisao2;
                        printf("\nEscolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce enfrenta os bandidos em um tiroteio intenso e consegue proteger o tesouro.\n");
                            printf("========================================\n");
                            p->xp += 40;

                            printf("Voce ganhou 40 XP pela decisao de enfrentar os bandidos e proteger o tesouro.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce negocia com os bandidos e divide o tesouro, garantindo uma parte para si.\n");
                            printf("========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de negociar com os bandidos para dividir o tesouro.\n");
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Guerreiro Indigena") == 0)
                {
                    printf("\n========================================\n");
                    printf("Voce decidiu defender sua aldeia contra invasores. Com sua habilidade e bravura, Voce repele os atacantes.\n");
                    printf("Sua aldeia esta segura gracas a Voce.\n");
                    printf("========================================\n");
                    p->xp += 30;

                    printf("\nApos a batalha, Voce descobre que os invasores estavam atras de um artefato sagrado.\n");
                    printf("Voce recupera o artefato e o devolve à sua aldeia, fortalecendo a protecao espiritual.\n");
                    printf("========================================\n");

                    printf("Voce ganhou 30 XP pela decisao de defender sua aldeia contra invasores.\n");

                    printf("O que Voce faz?\n");
                    printf("1. Esconder o artefato em um local seguro.\n");
                    printf("2. Usar o artefato para fortalecer a defesa da aldeia.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce esconde o artefato em um local seguro, longe dos olhos dos invasores.\n");
                        printf("========================================\n");
                        p->xp += 20;

                        printf("Voce ganhou 20 XP pela decisao de esconder o artefato em um local seguro.\n");

                        printf("Voce decide revelar a localizacao do artefato para os anciaos da aldeia?\n");
                        printf("1. Sim\n");
                        printf("2. Nao\n");
                        printf("Escolha (1 ou 2): ");
                        int decisao2;
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce revela a localizacao do artefato para os anciaos da aldeia, que o guardam em seguranca.\n");
                            printf("========================================\n");
                            p->xp += 10;

                            printf("Voce ganhou 10 XP pela decisao de revelar a localizacao do artefato para os anciaos da aldeia.\n");

                            printf("O que Voce faz?\n");
                            printf("1. Resgatar os anciaos capturados e proteger o artefato.\n");
                            printf("2. Deixar os anciaos à propria sorte e manter o artefato em segredo em um novo local.\n");
                            printf("Escolha (1 ou 2): ");
                            int decisao3;
                            scanf("%d", &decisao3);

                            if (decisao3 == 1)
                            {
                                printf("\n========================================\n");
                                printf("Voce resgatou os anciaos e protege o artefato, garantindo a seguranca da aldeia.\n");
                                printf("========================================\n");
                                p->xp += 50;

                                printf("Voce ganhou 50 XP pela decisao de resgatar os anciaos e proteger o artefato.\n");
                            }
                            else
                            {
                                printf("\n========================================\n");
                                printf("Voce mantehm a localizacao do artefato em segredo, protegendo-o de futuros ataques.\n");
                                printf("========================================\n");
                                p->xp += 10;

                                printf("Voce ganhou 10 XP pela decisao de nao revelar a localizacao do artefato para os anciaos da aldeia.\n");
                                p->vitalidade += 40; // Aumenta a vitalidade em +40
                                printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);
                            }
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce mantehm a localizacao do artefato em segredo, protegendo-o de futuros ataques.\n");
                            printf("========================================\n");
                            p->xp += 15;

                            printf("Voce ganhou 15 XP pela decisao de nao revelar a localizacao do artefato para os anciaos da aldeia.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce usa o artefato para fortalecer a defesa da aldeia, garantindo a seguranca de todos.\n");
                        printf("========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela decisao de usar o artefato para fortalecer a defesa da aldeia.\n");
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Dama Pistoleira") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu defender sua cidade contra invasores. Com sua mira certeira e coragem, Voce repele os atacantes com sucesso.\n");
                    printf("A cidade esta segura gracas à sua bravura.\n");
                    printf("\nApos a batalha, Voce descobre que os invasores estavam atras de um artefato sagrado guardado na cidade.\n");
                    printf("Voce recupera o artefato e o devolve, fortalecendo a protecao espiritual da comunidade.\n");
                    printf("\n========================================\n");
                    p->xp += 30;

                    printf("Voce ganhou 30 XP pela decisao de defender a cidade contra invasores.\n");
                    p->vitalidade += 40; // Aumenta a vitalidade em +40
                    printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);

                    printf("O que Voce faz?\n");
                    printf("1. Esconder o artefato em um local seguro.\n");
                    printf("2. Usar o artefato para fortalecer as defesas da cidade.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("\nVoce esconde o artefato em um local secreto, longe dos olhos curiosos e das ameacas externas.\n");
                        printf("Apenas Voce conhece o esconderijo.\n");
                        printf("\n========================================\n");
                        p->xp += 20;

                        printf("Voce ganhou 20 XP pela decisao de esconder o artefato em um local seguro.\n");

                        printf("\nVoce decide revelar a localizacao do artefato para os anciaos da cidade?\n");
                        printf("1. Sim\n");
                        printf("2. Nao\n");
                        printf("Escolha (1 ou 2): ");
                        int decisao2;
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("\nVoce revela a localizacao do artefato para os anciaos, que o guardam em seguranca sob juramento de silêncio.\n");
                            printf("\nInfelizmente, alguns anciaos sao capturados por inimigos e forcados a revelar a localizacao do artefato.\n");
                            printf("\n========================================\n");
                            p->xp += 10;

                            printf("Voce ganhou 10 XP pela decisao de revelar a localizacao do artefato para os anciaos da cidade.\n");

                            printf("O que Voce faz?\n");
                            printf("1. Resgatar os anciaos e proteger o artefato.\n");
                            printf("2. Abandonar os anciaos e esconder o artefato em outro local.\n");
                            printf("Escolha (1 ou 2): ");
                            int decisao3;
                            scanf("%d", &decisao3);

                            if (decisao3 == 1)
                            {
                                printf("\n========================================\n");
                                printf("\nVoce organiza uma missao para resgatar os anciaos.\n");
                                printf("Com sua lideranca e habilidade, Voce os salva e protege o artefato de futuras ameacas.\n");
                                printf("A cidade comemora sua vitoria e Voce ganha respeito e admiracao.\n");
                                printf("\n========================================\n");
                                p->xp += 50;

                                printf("Voce ganhou 50 XP pela decisao de resgatar os anciaos e proteger o artefato.\n");
                            }
                            else
                            {
                                printf("\n========================================\n");
                                printf("\nVoce prioriza a protecao do artefato e decide escondê-lo em um novo local, garantindo sua seguranca.\n");
                                printf("Embora a decisao seja dificil, Voce acredita que foi o melhor para a cidade.\n");
                                printf("\n========================================\n");
                                p->xp += 20;

                                printf("Voce ganhou 20 XP pela decisao de esconder o artefato em um novo local.\n");
                            }
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("\nVoce mantehm o local do artefato em segredo absoluto.\n");
                            printf("A cidade continua protegida, mas alguns moradores questionam sua decisao de nao compartilhar o conhecimento.\n");
                            printf("\n========================================\n");
                            p->xp -= 10;

                            printf("Voce perdeu 10 XP pela decisao de nao revelar a localizacao do artefato para os anciaos da cidade.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("\nVoce usa o artefato para fortalecer as defesas da cidade.\n");
                        printf("Com o poder do artefato, a cidade ergue novas barreiras espirituais e fisicas que intimidam qualquer futuro invasor.\n");
                        printf("A comunidade celebra sua decisao e se sente mais protegida do que nunca.\n");
                        printf("\n========================================\n");
                        p->xp += 50;

                        printf("Voce ganhou 50 XP pela decisao de usar o artefato para fortalecer as defesas da cidade.\n");
                    }

                    salvarProgresso(p);
                }
                break;

            case 2:
                if (strcmp(p->tipo, "Pistoleiro") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu proteger a cidade de um ataque. Com sua precisao e coragem, Voce derrota os bandidos.\n");
                    printf("A cidade esta em paz novamente, gracas a Voce.\n");
                    printf("\nApos a batalha, Voce eh convidado pelo prefeito para uma celebracao em sua honra.\n");
                    printf("Durante a celebracao, Voce recebe uma medalha de bravura e um terreno na cidade.\n");
                    printf("\n========================================\n");
                    p->xp += 30;

                    printf("Voce ganhou 30 XP pela decisao de proteger a cidade de um ataque.\n");

                    printf("O que Voce faz?\n");
                    printf("1. Aceitar o terreno e se estabelecer na cidade.\n");
                    printf("2. Recusar o terreno e continuar sua jornada.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce aceita o terreno e se estabelece na cidade, tornando-se um membro respeitado da comunidade.\n");
                        printf("Voce decide construir uma casa e se torna um cidadao da cidade.\n");
                        printf("No caminho, Voce encontra uma dama em perigo, sendo atormentada por dois bêbados.\n");
                        printf("\n========================================\n");
                        p->xp += 20;

                        printf("Voce ganhou 20 XP pela decisao de aceitar o terreno e se estabelecer na cidade.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Ajudar a dama e enfrentar os bêbados.\n");
                        printf("2. Ignorar a situacao e continuar seu caminho.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce ajuda a dama e enfrenta os bêbados, protegendo-a e ganhando sua gratidao.\n");
                            printf("A dama fica impressionada com sua coragem e deseja te recompensar.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de ajudar a dama e enfrentar os bêbados.\n");

                            printf("O que Voce faz?\n");
                            printf("1. Aceitar uma recompensa da dama.\n");
                            printf("2. Aceitar um beijo da dama.\n");

                            int decisao3;
                            printf("Escolha (1 ou 2): ");
                            scanf("%d", &decisao3);
                            if (decisao3 == 1)
                            {
                                printf("\n========================================\n");
                                printf("Voce aceita a recompensa da dama e ela te da uma bolsa de moedas de ouro.\n");
                                printf("\n========================================\n");
                                p->xp += 20;

                                printf("Voce ganhou 20 XP pela decisao de aceitar a recompensa da dama.\n");
                            }
                            else
                            {
                                printf("\n========================================\n");
                                printf("Voce aceita um beijo da dama e ela te agradece com um sorriso.\n");
                                printf("\n========================================\n");
                                p->xp += 50;

                                printf("Voce ganhou 50 XP pela decisao de aceitar um beijo da dama.\n");
                            }
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce ignora a situacao e continua seu caminho, deixando a dama em perigo.\n");
                            printf("\n========================================\n");
                            p->xp -= 10;

                            printf("Voce perdeu 10 XP pela decisao de ignorar a situacao e continuar seu caminho.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce recusa o terreno e continua sua jornada, em busca de novas aventuras.\n");
                        printf("\n========================================\n");
                        p->xp += 50;

                        printf("Voce ganhou 50 XP pela decisao de recusar o terreno e continuar sua jornada.\n");
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Xerife") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce organizou uma defesa contra bandidos. Com sua lideranca, a cidade repele o ataque.\n");
                    printf("Os cidadaos estao gratos pela sua protecao.\n");
                    printf("\nApos a defesa, Voce descobre que os bandidos tinham um plano maior para dominar a regiao.\n");
                    printf("Voce organiza uma expedicao para desmantelar a base dos bandidos e consegue captura-los.\n");
                    printf("\n========================================\n");
                    p->xp += 30;

                    printf("Voce ganhou 30 XP pela decisao de organizar a defesa da cidade.\n");

                    printf("O que Voce faz?\n");
                    printf("1. Interrogar os bandidos capturados para obter mais informacoes.\n");
                    printf("2. Prender os bandidos e reforcar a seguranca da cidade.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce interroga os bandidos capturados e descobre mais sobre seus planos.\n");
                        printf("Com as informacoes, Voce consegue evitar futuros ataques e proteger a cidade.\n");
                        printf("Um dos bandidos revela a localizacao de um esconderijo de armas.\n");
                        printf("\n========================================\n");
                        p->xp += 20;

                        printf("Voce ganhou 20 XP pela decisao de interrogar os bandidos.\n");
                        p->vitalidade += 40; // Aumenta a vitalidade em +40
                        printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);

                        printf("O que Voce faz?\n");
                        printf("1. Investigar o esconderijo e confiscar as armas.\n");
                        printf("2. Prender os bandidos e encerrar a investigacao.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce investiga o esconderijo e encontra um arsenal de armas, alehm de um grupo de refehns.\n");
                            printf("Voce liberta os refehns e confisca as armas, garantindo a seguranca da cidade.\n");
                            printf("\n========================================\n");
                            p->xp += 50;

                            printf("Voce ganhou 50 XP pela decisao de investigar o esconderijo e confiscar as armas.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce prende os bandidos e encerra a investigacao, garantindo a seguranca da cidade.\n");
                            printf("\n========================================\n");
                            p->xp += 25;

                            printf("Voce ganhou 25 XP pela decisao de prender os bandidos e encerrar a investigacao.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce prende os bandidos e reforca a seguranca da cidade, prevenindo futuros ataques.\n");
                        printf("\n========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela decisao de prender os bandidos e reforcar a seguranca da cidade.\n");
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Forasteiro") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu procurar tesouros escondidos. Apos uma longa busca, Voce encontra um mapa antigo.\n");
                    printf("O mapa leva a um tesouro enterrado, aumentando suas riquezas.\n");
                    printf("\nEnquanto segue o mapa, Voce encontra um grupo de bandidos que tambehm esta atras do tesouro.\n");
                    printf("Voce os enfrenta e, apos uma batalha intensa, consegue proteger o tesouro.\n");
                    printf("\n========================================\n");
                    p->xp += 30;

                    printf("Voce ganhou 30 XP pela decisao de procurar tesouros escondidos e enfrentar os bandidos.\n");

                    printf("O que Voce faz?\n");
                    printf("1. Levar o tesouro para a cidade.\n");
                    printf("2. Esconder o tesouro para uso futuro.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);
                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce leva o tesouro para a cidade e eh recebido como um heroi.\n");
                        printf("Voce decide doar parte do tesouro para a cidade e eh aclamado como um benfeitor.\n");
                        printf("Um grupo de colonos agradece sua generosidade e te oferece uma oportunidade de trabalhar como colonizador e explorador da cidade.\n");
                        printf("\n========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela decisao de levar o tesouro para a cidade e doar parte dele.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Aceitar a oferta e se tornar um colonizador.\n");
                        printf("2. Recusar a oferta e continuar sua jornada.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce aceita a oferta e se torna um colonizador, ajudando a construir uma nova comunidade.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de se tornar um colonizador.\n");

                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce recusa a oferta e continua sua jornada solo, em busca de novas aventuras.\n");
                            printf("\n========================================\n");
                            p->xp += 10;

                            printf("Voce ganhou 10 XP pela decisao de continuar sua jornada.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce esconde o tesouro e planeja usa-lo em uma emergência futura.\n");
                        printf("Enquanto isso, rumores sobre o tesouro comecam a se espalhar.\n");
                        printf("Voce encontra um grupo de bandidos atras do tesouro.\n");
                        printf("\n========================================\n");
                        p->xp -= 10;

                        printf("Voce perdeu 10 XP pela decisao de esconder o tesouro.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Enfrentar os bandidos e proteger o tesouro.\n");
                        printf("2. Negociar com os bandidos para dividir o tesouro.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);
                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce enfrenta os bandidos em um tiroteio intenso e consegue proteger o tesouro.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de enfrentar os bandidos e proteger o tesouro.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce negocia com os bandidos e divide o tesouro, garantindo uma parte para si.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de negociar com os bandidos para dividir o tesouro.\n");
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Guerreiro Indigena") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu resgatar um aliado capturado. Com sua astúcia e forca, Voce invade o acampamento inimigo e resgata seu aliado.\n");
                    printf("Seu aliado esta seguro e sua aldeia esta em divida com Voce.\n");
                    printf("\n========================================\n");
                    p->xp += 30;

                    printf("Voce ganhou 30 XP pela coragem e sucesso em sua missao!\n");

                    printf("\nApos o resgate, seu aliado revela informacoes sobre um ataque iminente à aldeia.\n");
                    printf("Voce se prepara e, com a ajuda de seu aliado, consegue repelir o ataque e garantir a seguranca da aldeia.\n");
                    printf("\n========================================\n");

                    printf("O que Voce faz?\n");
                    printf("1. Fortalecer a defesa da aldeia.\n");
                    printf("2. Planejar um ataque preventivo contra os invasores.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce fortalece a defesa da aldeia, garantindo a seguranca de todos.\n");
                        printf("Voce constroi barricadas, treina os guerreiros e prepara armadilhas para os invasores.\n");
                        printf("\n========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela decisao de fortalecer a defesa da aldeia.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Continuar fortalecendo a defesa.\n");
                        printf("2. Realizar um ritual de protecao.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce continua fortalecendo a defesa, garantindo que a aldeia esteja preparada para qualquer ataque futuro.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de continuar fortalecendo a defesa.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce realiza um ritual de protecao, invocando os espiritos ancestrais para proteger a aldeia.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de realizar um ritual de protecao.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce planeja um ataque preventivo e consegue derrotar os invasores antes que ataquem novamente.\n");
                        printf("Voce lidera seus guerreiros em uma emboscada, pegando os invasores de surpresa e garantindo a vitoria.\n");
                        printf("\n========================================\n");
                        p->xp += 60;

                        printf("Voce ganhou 60 XP pela decisao de planejar um ataque preventivo.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Celebrar a vitoria com um grande banquete.\n");
                        printf("2. Realizar um ritual de agradecimento aos espiritos.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce celebra a vitoria com um grande banquete, fortalecendo os lacos entre os membros da aldeia.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de celebrar a vitoria com um banquete.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce realiza um ritual de agradecimento aos espiritos, garantindo a protecao continua da aldeia.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de realizar um ritual de agradecimento aos espiritos.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Dama Pistoleira") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu recrutar aliados para a cidade.\n");
                    printf("Com seu carisma e habilidade, Voce parte em uma jornada para encontrar pessoas dispostas a ajudar.\n");
                    printf("\n========================================\n");

                    printf("\nDurante sua busca, Voce encontra três potenciais aliados:\n");
                    printf("1. Um ex-militar experiente em estratehgias de defesa.\n");
                    printf("2. Um comerciante rico disposto a financiar melhorias na cidade.\n");
                    printf("3. Um jovem destemido que deseja aprender com Voce e proteger o local.\n");
                    printf("Quem Voce recruta primeiro?\n");
                    printf("Escolha (1, 2 ou 3): ");

                    int decisao;
                    scanf("%d", &decisao);

                    switch (decisao)
                    {
                    case 1:
                        printf("\n========================================\n");
                        printf("\nVoce recruta o ex-militar, que imediatamente ajuda a organizar a defesa da cidade.\n");
                        printf("Com seu conhecimento, fortalece as barreiras e treina os moradores para se defenderem.\n");
                        printf("Enquanto trabalha na defesa, o militar revela que precisa de mais materiais para construir barricadas eficazes.\n");
                        printf("\n========================================\n");

                        printf("O que Voce faz?\n");
                        printf("1. Buscar os materiais necessarios sozinho.\n");
                        printf("2. Solicitar ajuda dos moradores para reunir os materiais.\n");

                        int decisao1;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao1);

                        if (decisao1 == 1)
                        {
                            printf("\n========================================\n");
                            printf("\nVoce se aventura para buscar os materiais sozinho e enfrenta bandidos no caminho.\n");
                            printf("Apesar do perigo, Voce retorna com sucesso e garante que a defesa da cidade seja reforcada.\n");
                            printf("\n========================================\n");
                            p->xp += 50;

                            printf("Voce ganhou 50 XP pela coragem e sucesso em sua missao!\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("\nVoce convoca os moradores para ajudar na coleta dos materiais.\n");
                            printf("Com a colaboracao de todos, os materiais sao reunidos rapidamente e a cidade fica mais segura.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela coragem e sucesso em sua missao!\n");
                        }
                        break;

                    case 2:
                        printf("\n========================================\n");
                        printf("\nVoce recruta o comerciante rico, que investe seus recursos para melhorar a infraestrutura da cidade.\n");
                        printf("Com o financiamento, Voce constroi novas fortificacoes e armazena suprimentos.\n");
                        printf("O comerciante, no entanto, exige algo em troca: uma posicao de lideranca no conselho da cidade.\n");
                        printf("\n========================================\n");

                        printf("O que Voce faz?\n");
                        printf("1. Concordar com a exigência dele.\n");
                        printf("2. Recusar e procurar outro aliado.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("\nVoce concorda com a exigência, e o comerciante se torna um membro influente na cidade.\n");
                            printf("Embora ele seja ambicioso, sua ajuda eh valiosa para o crescimento da comunidade.\n");
                            printf("\n========================================\n");
                            p->xp += 40;

                            printf("Voce ganhou 40 XP pela decisao de concordar com a exigência do comerciante.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("\nVoce recusa a exigência e decide procurar outro aliado disposto a ajudar sem condicoes.\n");
                            printf("Embora isso leve mais tempo, Voce mantehm a integridade da lideranca da cidade.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de recusar a exigência do comerciante.\n");
                        }
                        break;

                    case 3:
                        printf("\n========================================\n");
                        printf("\nVoce recruta o jovem destemido, que rapidamente se torna seu aprendiz.\n");
                        printf("Voce o treina em habilidades de combate e lideranca, preparando-o para defender a cidade no futuro.\n");
                        printf("Durante o treinamento, o jovem revela que sua familia foi capturada por bandidos em uma vila proxima.\n");
                        printf("\n========================================\n");

                        printf("O que Voce faz?\n");
                        printf("1. Ajudar o jovem a resgatar sua familia.\n");
                        printf("2. Convencê-lo a se focar na protecao da cidade.\n");

                        int decisao3;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao3);

                        if (decisao3 == 1)
                        {
                            printf("\n========================================\n");
                            printf("\nVoce lidera uma missao de resgate e enfrenta os bandidos que capturaram a familia do jovem.\n");
                            printf("Com sucesso, a familia eh salva e o jovem fica eternamente grato por sua ajuda.\n");
                            printf("\n========================================\n");
                            p->xp += 50;

                            printf("Voce ganhou 50 XP pela decisao de ajudar o jovem a resgatar sua familia.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("\nVoce convence o jovem de que proteger a cidade eh a prioridade no momento.\n");
                            printf("Embora relutante, ele confia em seu julgamento e dedica seu tempo à defesa da comunidade.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de convencer o jovem a se focar na protecao da cidade.\n");
                        }
                        break;

                    default:
                        printf("\nEscolha invalida! Voce perde tempo valioso e os aliados se tornam mais dificeis de encontrar.\n");
                        break;
                    }

                    printf("\n========================================\n");
                    printf("\nApos recrutar aliados, a cidade esta mais forte e pronta para enfrentar qualquer ameaca.\n");
                    printf("Sua lideranca inspira os moradores, que agora confiam plenamente em Voce.\n");
                    printf("\n========================================\n");

                    salvarProgresso(p);
                }
                break;

            case 3:
                if (strcmp(p->tipo, "Pistoleiro") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu participar de um torneio de tiro. Sua habilidade com a arma eh posta à prova.\n");
                    printf("Voce vence o torneio e ganha respeito e reconhecimento na cidade.\n");
                    p->xp += 30;

                    printf("\nApos o torneio, um misterioso homem se aproxima e oferece uma missao secreta.\n");
                    printf("Voce aceita a missao e parte em uma nova aventura.\n");
                    printf("\n========================================\n");

                    printf("Voce ganhou 30 XP pela coragem e sucesso em sua missao!\n");
                    p->vitalidade += 40; // Aumenta a vitalidade em +40
                    printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);

                    printf("O que Voce faz?\n");
                    printf("1. Aceitar a missao e partir imediatamente.\n");
                    printf("2. Recusar a missao e continuar sua vida na cidade.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce aceita a missao e parte em uma nova aventura, em busca de mais desafios.\n");
                        printf("Durante a missao, Voce descobre uma conspiracao para derrubar o governo local.\n");
                        printf("Voce consegue impedir o golpe e salvar a cidade de um destino sombrio.\n");
                        printf("\n========================================\n");
                        p->xp += 50;

                        printf("Voce ganhou 50 XP pela coragem e sucesso em sua missao!\n");

                        printf("O que Voce faz?\n");
                        printf("1. Revelar a conspiracao ao público.\n");
                        printf("2. Manter a conspiracao em segredo e proteger a cidade discretamente.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce revela a conspiracao ao público, ganhando ainda mais respeito e reconhecimento.\n");
                            printf("A cidade se une contra a ameaca e Voce eh celebrado como um heroi.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de revelar a conspiracao ao público.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce mantehm a conspiracao em segredo e trabalha discretamente para proteger a cidade.\n");
                            printf("Embora poucos saibam de seus feitos, Voce garante a seguranca da cidade.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de manter a conspiracao em segredo.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce recusa a missao e continua sua vida na cidade, aproveitando o respeito conquistado.\n");
                        printf("\n========================================\n");
                        p->xp += 20;

                        printf("Voce ganhou 20 XP pela decisao de recusar a missao e continuar sua vida na cidade.\n");
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Xerife") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu investigar um roubo misterioso. Apos seguir varias pistas, Voce descobre o culpado.\n");
                    printf("A justica eh feita e a cidade esta mais segura.\n");
                    p->xp += 30;

                    printf("\nDurante a investigacao, Voce descobre uma conspiracao maior envolvendo figuras importantes da cidade.\n");
                    printf("Voce decide continuar investigando para desmantelar a conspiracao.\n");
                    printf("\n========================================\n");

                    printf("Voce ganhou 30 XP pela coragem e sucesso em sua missao!\n");

                    printf("O que Voce faz?\n");
                    printf("1. Continuar investigando a conspiracao.\n");
                    printf("2. Prender os culpados e encerrar a investigacao.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("Voce continua investigando e descobre mais sobre a conspiracao, desmantelando-a completamente.\n");
                        printf("A cidade esta segura e Voce eh considerado um heroi.\n");
                        printf("\n========================================\n");
                        p->xp += 50;

                        printf("Voce ganhou 50 XP pela coragem e sucesso em sua missao!\n");

                        printf("O que Voce faz?\n");
                        printf("1. Revelar a conspiracao ao público.\n");
                        printf("2. Manter a conspiracao em segredo e proteger a cidade discretamente.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce revela a conspiracao ao público, ganhando ainda mais respeito e reconhecimento.\n");
                            printf("A cidade se une contra a ameaca e Voce eh celebrado como um heroi.\n");
                            printf("\n========================================\n");
                            p->xp += 45;

                            printf("Voce ganhou 30 XP pela decisao de revelar a conspiracao ao público.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce mantehm a conspiracao em segredo e trabalha discretamente para proteger a cidade.\n");
                            printf("Embora poucos saibam de seus feitos, Voce garante a seguranca da cidade.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de manter a conspiracao em segredo.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("Voce prende os culpados e encerra a investigacao, garantindo a seguranca da cidade.\n");
                        printf("Durante a prisao, um dos culpados revela a localizacao de um esconderijo de bandidos.\n");
                        printf("Voce decide explorar o esconderijo e encontra valiosos itens roubados.\n");
                        printf("\n========================================\n");

                        printf("O que Voce faz?\n");
                        printf("1. Levar os itens para a cidade.\n");
                        printf("2. Esconder os itens para uso futuro.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce leva os itens para a cidade e eh recebido como um heroi.\n");
                            printf("\n========================================\n");
                            p->xp += 40;

                            printf("Voce ganhou 40 XP pela coragem e sucesso em sua missao!\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce esconde os itens e planeja usa-los em uma emergência futura.\n");
                            printf("Voce acaba negligenciando a justica em prol de sua propria vantagem.\n");
                            printf("\n========================================\n");
                            p->xp -= 10;

                            printf("Voce perdeu 10 XP por priorizar seus interesses pessoais em vez da justica.\n");
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Forasteiro") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu ajudar um fazendeiro local. Com seu auxilio, a colheita eh salva e o fazendeiro esta grato.\n");
                    printf("Voce ganha a amizade e o apoio da comunidade local.\n");
                    p->xp += 20;

                    printf("\nO fazendeiro revela a localizacao de um antigo esconderijo de bandidos.\n");
                    printf("Voce decide explorar o esconderijo e encontra valiosos itens perdidos.\n");
                    printf("\n========================================\n");
                    printf("Voce ganhou 20 XP pela coragem e sucesso em sua missao!\n");

                    printf("O que Voce faz?\n");
                    printf("1. Levar os itens para a cidade.\n");
                    printf("2. Esconder os itens para uso futuro.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("\nVoce leva os itens para a cidade e eh recebido como um heroi.\n");
                        printf("Os itens sao usados para melhorar a seguranca e infraestrutura local.\n");
                        printf("\n========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela decisao de levar os itens para a cidade.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Aceitar uma posicao de lideranca na cidade.\n");
                        printf("2. Recusar a posicao e continuar sua jornada.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("\nVoce aceita a posicao de lideranca e ajuda a guiar a cidade para um futuro prospero.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de aceitar a posicao de lideranca.\n");
                            p->vitalidade += 40; // Aumenta a vitalidade em +40
                            printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("\nVoce recusa a posicao e continua sua jornada, em busca de novas aventuras.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de continuar sua jornada.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("\nVoce esconde os itens e planeja usa-los em uma emergência futura.\n");
                        printf("Enquanto isso, rumores sobre os itens comecam a se espalhar.\n");
                        printf("Voce encontra um grupo de bandidos atras dos itens.\n");
                        printf("\n========================================\n");
                        p->xp += 25;

                        printf("Voce ganhou 25 XP pela decisao de esconder os itens.\n");

                        printf("O que Voce faz?\n");
                        printf("1. Enfrentar os bandidos e proteger os itens.\n");
                        printf("2. Negociar com os bandidos para dividir os itens.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce enfrenta os bandidos em um tiroteio intenso e consegue proteger os itens.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de enfrentar os bandidos e proteger os itens.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce negocia com os bandidos e divide os itens, garantindo uma parte para si.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de negociar com os bandidos para dividir os itens.\n");
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Guerreiro Indigena") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu realizar um ritual sagrado. O ritual fortalece os lacos espirituais da sua aldeia.\n");
                    printf("Sua aldeia prospera e Voce eh reverenciado como um grande lider espiritual.\n");
                    p->xp += 20;

                    printf("\nDurante o ritual, Voce tem uma visao de um perigo iminente.\n");
                    printf("Voce se prepara para enfrentar essa nova ameaca e proteger sua aldeia.\n");
                    printf("\n========================================\n");
                    printf("Voce ganhou 20 XP pela coragem e sucesso em sua missao!\n");

                    printf("O que Voce faz?\n");
                    printf("1. Fortalecer a defesa da aldeia.\n");
                    printf("2. Planejar um ataque preventivo contra os invasores.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("\nVoce fortalece a defesa da aldeia, garantindo a seguranca de todos.\n");
                        printf("Durante a preparacao, Voce descobre que a ameaca eh uma invasao iminente de bandidos.\n");
                        printf("Voce consegue repelir o ataque e proteger a aldeia.\n");
                        printf("\n========================================\n");
                        p->xp += 30;
                        printf("Voce ganhou 30 XP pela coragem e sucesso em sua missao!\n");
                        p->vitalidade += 40; // Aumenta a vitalidade em +40
                        printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);

                        printf("\nO que Voce faz?\n");
                        printf("1. Interrogar os bandidos capturados para obter mais informacoes.\n");
                        printf("2. Prender os bandidos e reforcar a seguranca da aldeia.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("\nVoce interroga os bandidos capturados e descobre mais sobre seus planos.\n");
                            printf("Com as informacoes, Voce consegue evitar futuros ataques e proteger a aldeia.\n");
                            printf("\n========================================\n");
                            p->xp += 50;
                            printf("Voce ganhou 50 XP pela coragem e sucesso em sua missao!\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("\nVoce prende os bandidos e reforca a seguranca da aldeia, prevenindo futuros ataques.\n");
                            printf("\n========================================\n");
                            p->xp += 20;
                            printf("Voce ganhou 20 XP pela coragem e sucesso em sua missao!\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("\nVoce planeja um ataque preventivo e consegue derrotar os invasores antes que ataquem novamente.\n");
                        printf("Sua aldeia esta segura e Voce eh considerado um heroi.\n");
                        printf("Voce decide realizar um ritual de agradecimento aos espiritos pela protecao da aldeia.\n");
                        printf("\n========================================\n");
                        p->xp += 40;

                        printf("Voce ganhou 40 XP pela coragem e sucesso em sua missao!\n");

                        printf("O que Voce faz?\n");
                        printf("1. Celebrar a vitoria com um grande banquete.\n");
                        printf("2. Realizar um ritual de agradecimento aos espiritos.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce celebra a vitoria com um grande banquete, fortalecendo os lacos entre os membros da aldeia.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de celebrar a vitoria com um banquete.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce realiza um ritual de agradecimento aos espiritos, garantindo a protecao continua da aldeia.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de realizar um ritual de agradecimento aos espiritos.\n");
                        }
                    }

                    salvarProgresso(p);
                }
                else if (strcmp(p->tipo, "Dama Pistoleira") == 0)
                {
                    printf("\n========================================\n");
                    printf("\nVoce decidiu participar de um torneio de tiro. Sua habilidade com a arma eh posta à prova.\n");
                    printf("Voce vence o torneio e ganha respeito e reconhecimento na cidade.\n");
                    p->xp += 20;

                    printf("\nApos o torneio, um misterioso homem se aproxima e oferece uma missao secreta.\n");
                    printf("Voce aceita a missao e parte em uma nova aventura.\n");
                    printf("\n========================================\n");
                    printf("Voce ganhou 20 XP pela coragem e sucesso em sua missao!\n");

                    printf("O que Voce faz?\n");
                    printf("1. Aceitar a missao e partir imediatamente.\n");
                    printf("2. Recusar a missao e continuar sua vida na cidade.\n");

                    int decisao;
                    printf("Escolha (1 ou 2): ");
                    scanf("%d", &decisao);

                    if (decisao == 1)
                    {
                        printf("\n========================================\n");
                        printf("\nVoce aceita a missao e parte em uma nova aventura, em busca de mais desafios.\n");
                        printf("Durante a missao, Voce descobre uma conspiracao para derrubar o governo local.\n");
                        printf("Voce consegue impedir o golpe e salvar a cidade de um destino sombrio.\n");
                        printf("\n========================================\n");
                        p->xp += 50;
                        printf("Voce ganhou 50 XP pela coragem e sucesso em sua missao!\n");
                        p->vitalidade += 40; // Aumenta a vitalidade em +40
                        printf("Voce recebeu um premio! Sua vitalidade aumentou para %d.\n", p->vitalidade);

                        printf("O que Voce faz?\n");
                        printf("1. Revelar a conspiracao ao público.\n");
                        printf("2. Manter a conspiracao em segredo e proteger a cidade discretamente.\n");

                        int decisao2;
                        printf("Escolha (1 ou 2): ");
                        scanf("%d", &decisao2);

                        if (decisao2 == 1)
                        {
                            printf("\n========================================\n");
                            printf("Voce revela a conspiracao ao público, ganhando ainda mais respeito e reconhecimento.\n");
                            printf("A cidade se une contra a ameaca e Voce eh celebrada como uma heroina.\n");
                            printf("\n========================================\n");
                            p->xp += 30;

                            printf("Voce ganhou 30 XP pela decisao de revelar a conspiracao ao público.\n");
                        }
                        else
                        {
                            printf("\n========================================\n");
                            printf("Voce mantehm a conspiracao em segredo e trabalha discretamente para proteger a cidade.\n");
                            printf("Embora poucos saibam de seus feitos, Voce garante a seguranca da cidade.\n");
                            printf("\n========================================\n");
                            p->xp += 20;

                            printf("Voce ganhou 20 XP pela decisao de manter a conspiracao em segredo.\n");
                        }
                    }
                    else
                    {
                        printf("\n========================================\n");
                        printf("\nVoce recusa a missao e continua sua vida na cidade, aproveitando o respeito conquistado.\n");
                        printf("Embora tenha optado por uma vida tranquila, sua reputacao ainda lhe rende algum beneficio.\n");
                        printf("\n========================================\n");
                        p->xp += 10;

                        printf("Voce ganhou 10 XP por manter sua posicao na cidade.\n");
                    }

                    salvarProgresso(p);
                }
                break;

            default:
                printf("Escolha invalida!\n");
                continue;
        }

        printf("\nO que voce gostaria de fazer agora?\n");
        printf("1. Jogar novamente\n");
        printf("2. Exibir detalhes do personagem\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha (1, 2 ou 3): ");
        scanf("%d", &jogarNovamente);

        switch (jogarNovamente) {
            case 1:
                // Reiniciar a história ou missão
                continue;
            case 2:
                // Exibir detalhes do personagem
                exibirPersonagem(p);
                break;
            case 3:
                // Voltar ao menu principal
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Escolha invalida!\n");
                break;
        }
    } while (jogarNovamente != 3);
}

// Funcao principal
int main()
{
    struct Personagem personagens[6];
    int escolha, personagemEscolhido;
    int numPersonagens = 5;
    Personagens(personagens);

    printf("\n========================================\n");
    printf("  === Bem-vindo ao Velho Oeste RPG! ===\n");
    printf("========================================\n");

    // Menu inicial
    escolha = menuInicial();
    switch (escolha)
    {
    case 1:
        // Menu de selecao de personagens
        escolha = menuPersonagem();
        if (escolha >= 1 && escolha <= 5) {
            personagemEscolhido = escolha - 1;
        }
        else if (escolha == 6) {
            printf("\nCriando personagem adicional:\n");
            criarPersonagem(&personagens[numPersonagens]);
            personagemEscolhido = numPersonagens;
            numPersonagens++;
        }
        else {
            printf("Escolha invalida!\n");
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
                // Escolher oponente para batalha
                printf("\nEscolha o oponente para a batalha:\n");
                for (int i = 0; i < numPersonagens; i++) {
                    if (i != personagemEscolhido) {
                        printf("%d. %s (%s)\n", i + 1, personagens[i].nome, personagens[i].tipo);
                    }
                }

                int p2;
                printf("Escolha o oponente (1-%d): ", numPersonagens);
                scanf("%d", &p2);

                if (p2 >= 1 && p2 <= numPersonagens && p2 - 1 != personagemEscolhido) {
                    batalha(&personagens[personagemEscolhido], &personagens[p2 - 1]);
                }
                else {
                    printf("Escolha invalida!\n");
                }
                break;

            case 3:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Escolha invalida!\n");
            }
        } while (escolha != 3);
        break;

    case 2:
        printf("Saindo do jogo...\n");
        break;

    default:
        printf("Escolha invalida!\n");
    }

    return 0;
}