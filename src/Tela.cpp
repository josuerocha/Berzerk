#include "Tela.h"
#include <iostream>
using namespace std;
Tela::Tela()
{	
	animacaoInicial = AnimacaoInicial();
	fase = Level(1);
	efeitoPassouFase = new AnimacaoPassouFase(0);
	efeitoMorte = new AnimacaoMorte();
	efeitoGameOver = new AnimacaoGameOver();
	menu = new MainMenu();
	fullscreen = false;
	animacaoMorte = false;
	passouDeFase = false;
	animacaoFinalFlag = false;

}

void Tela::Logica() {
	if (fase.getQtdInimigos() <= 0 & player.getHP() >0) {
		passouDeFase = true;
	}
	else {
		passouDeFase = false;
	}

}

Tela::~Tela()
{
}

void Tela::Initialize() {
	player = Player(Coord(100, 100), Dimensao(25, 25), 10, 100, Cor(1.0, 0.5, 0.0),3,50);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	shoot = 0;
}

void Tela::AlteraTamanhoJanela(GLsizei w, GLsizei h)
{	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h){
		gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f*h / w);
		janela.height = 600 * h / w;
	}
	else{
		gluOrtho2D(0.0f, 800.0f*w / h, 0.0f, 600.0f);
		janela.width = 800 * w / h;
	}
	cout << "TAMANHO TELA " << w << "  " << h;
}

void Tela::Display() {
	Logica();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	if (faseAtual >= 4 && passouDeFase) {
		animacaoFinal.Display();
		animacaoFinalFlag = true;
		animacaoFinal.Reshape(janela.width,janela.height);
		if (animacaoFinal.isActive) {
			animacaoFinal.Reset();
			menu->emMenu = true;
			animacaoFinalFlag = false;
			menu->emMenuPrincipal = true;
		}
	}
	if (animacaoInicial.emAnimacao ){
		bool flagIniciaMenu = animacaoInicial.Run();
		if (flagIniciaMenu) {
			menu->emJogo = false;
			menu->inicia = false;
			menu->emMenu = true;
			menu->emMenuPrincipal = true;
			animacaoInicial.emAnimacao = false;
		}
	}

	if(!menu->emMenuPrincipal && !passouDeFase && !animacaoMorte && !animacaoInicial.emAnimacao && !animacaoFinalFlag){
		fase.DesenhaFase();
		DisplayCharacters();
		ChecarColisoes();
	}
	else if (menu->emMenuPrincipal) {
		menu->Run();
		player.Reset();
	}
	if (passouDeFase && !animacaoMorte && !animacaoInicial.emAnimacao && !menu->emMenuPrincipal) {
		efeitoPassouFase->Display(faseAtual + 2);
		if(!efeitoPassouFase->isActive){
			faseAtual++;
			vetorEfeitosVisuais.clear();
			fase = Level(faseAtual + 1);
			player.setC(fase.getPlayerPosition());
			passouDeFase = false;

			for(int i=0; i<vetorProjeteisAmigos.size(); i++) {
				delete(vetorProjeteisAmigos[i]);
				vetorProjeteisAmigos[i] = NULL;
			}

			for(int i=0; i<vetorProjeteisInimigos.size(); i++) {
				delete(vetorProjeteisInimigos[i]);
				vetorProjeteisInimigos[i] = NULL;
			}

			for(int i=0; vetorEfeitosVisuais.size(); i++) {
				delete(vetorEfeitosVisuais[i]);
				vetorEfeitosVisuais[i] = NULL;
			}

			efeitoPassouFase->Reset();
			vetorProjeteisAmigos.clear();
			vetorProjeteisInimigos.clear();
			vetorEfeitosVisuais.clear();
		}
	}

	if ((!player.getIsActive()) && (player.getVidas() > 0) && !animacaoInicial.emAnimacao) {
		animacaoMorte = true;
		efeitoMorte->Display();
		if (!efeitoMorte->isActive) {
			fase = Level(faseAtual + 1);
			vetorEfeitosVisuais.clear();
			player.Reset();
			player.setC(fase.getPlayerPosition());
			player.isActive = true;
			animacaoMorte = false;
			efeitoMorte->Reset();
		}
	}

	if (!player.getIsActive() && (player.getVidas() <= 0) && !animacaoInicial.emAnimacao) {
		efeitoGameOver->Display();
		if (!efeitoGameOver->isActive) {
			player.IncHP(100);
			player.isActive = true;
			fase = Level(1);
			score.Reset();
			vetorEfeitosVisuais.clear();
			menu = new MainMenu();
			menu->emMenuPrincipal = true;
			menu->emMenu = true;
			menu->desenharMenuButton = true;
			faseAtual = 0;
			efeitoGameOver->Reset();
			player.ResetVidas();
		}
	}
	glutSwapBuffers();
}

void Tela::DisplayCharacters() {
	DisplayEnemies();
	player.Display();
	DisplayProjectiles();
	DisplayEnemyProjectiles();
	DisplayVisualEfects();
	score.Display(player.getVidas());
	DisplayColetaveis();
}

void Tela::setWindowValues() {
	janela.width = 800;
	janela.height = 600;
	janela.title = "BERZERK";
	janela.field_of_view_angle = 0;
	janela.z_near = 1.0f;
	janela.z_far = 100.0f;
}

void Tela::DisplayProjectiles() {

	for(int i=0; i<vetorProjeteisAmigos.size(); i++) {
		if (vetorProjeteisAmigos[i]->getIsActive()) {
			vetorProjeteisAmigos[i]->Display();
		}
	}
}

void Tela::DisplayEnemyProjectiles() {
	for(int i=0; i<vetorProjeteisInimigos.size(); i++) {
		if (vetorProjeteisInimigos[i]->getIsActive()) {
			vetorProjeteisInimigos[i]->Display();
		}
	}
}

void Tela::CheckMapBoundaries(){
	if (player.getC().x > janela.width) {
		player.c.x = janela.width;
	}
	if (player.getC().x < 0) {
		player.c.x = 0;
	}
	if (player.c.y > janela.height) {
		player.c.y = janela.height;
	}
	if (player.c.y < 0) {
		player.c.y = 0;
	}
}

void Tela::MovePlayer() {

	if (keyBuffer[0] == true) { player.IncY(5, ChecarColisoesParedes(0,1)); }
	if (keyBuffer[1] == true) { player.IncY(-5, ChecarColisoesParedes(0,-1)); }
	if (keyBuffer[2] == true) { player.IncX(-5, ChecarColisoesParedes(-1,0)); }
	if (keyBuffer[3] == true) { player.IncX(5, ChecarColisoesParedes(1,0)); }
	if (keyBuffer[4] == true) { shoot = 1; keyBuffer[4] = false; }
	if (keyBuffer[5] == true) { shoot = 2; keyBuffer[5] = false; }
}

void Tela::keyboardDown(unsigned char key, int x, int y) {
	cout << "Tecla regular pressionada: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;

	switch (key) {
	case 'Q':
	case 'q':
	case  27:   // ESC
		exit(0);
		break;
	case CAPSUP:
	case UP:
		keyBuffer[0] = true;
		break;
	case CAPSDOWN:
	case DOWN:
		keyBuffer[1] = true;
		break;
	case CAPSLEFT:
	case LEFT:
		keyBuffer[2] = true;
		break;
	case CAPSRIGHT:
	case RIGHT:
		keyBuffer[3] = true;
		break;
	case 'c':
		cout << player.getC().x << " " << player.getC().y;
		break;
	//backspace
	case 8:
			if(menu->opcaoMenuButton){
			menu->emMenu = true;
			menu->opcao = false;
			menu->inicia = false;
			menu->desenharMenuButton = true;
			menu->iniciarMenuButton = false;
			menu->opcaoMenuButton = false;
		}
		break;
		//enter
	case 13 :
		if(animacaoInicial.emAnimacao){
			animacaoInicial.emAnimacao = false;
			menu->desenharMenuButton = true;
			menu->emMenuPrincipal = true;
			menu->emMenu = true;
			menu->emJogo = false;
			menu->inicia = false;
		}

		else if (menu->emMenu) {
			menu->emJogo = true;
			menu->inicia = true;
			menu->emMenu = false;
			menu->emMenuPrincipal = false;
			menu->iniciarMenuButton = true;
			menu->desenharMenuButton = false;
			menu->opcaoMenuButton = false;
			}
		break;
		//opções
	case 'O':
	case 'o':	
			if (menu->emMenu) {
				menu->emMenu = false;
				menu->opcao = true;
				menu->inicia = false;
				menu->iniciarMenuButton = false;
				menu->desenharMenuButton = false;
				menu->opcaoMenuButton = true;
			}
	break;
	case 'F':
	case 'f':
		if (!fullscreen) {
			glutFullScreen();
			fullscreen = true;
		}
		else if (fullscreen) {
			glutReshapeWindow(800, 600);
			glutPositionWindow(270, 80);
			fullscreen = false;
		}
		break;
	}
	cout << "POSICAO X: " << x << "POSICAO Y: " << y << endl;
}

void Tela::mouseMotion(int x, int y) {
	if (keyBuffer[4]) {
		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
		glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		winZ = 0;

		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
		mouse = Coord(worldX, worldY);
		cout << "Mouse moveu para (" << mouse.x << ',' << mouse.y << ')' << endl;
	}
}

void Tela::MoveProjectiles() {
	MoveFriendlyProjectiles();
	MoveEnemyProjectiles();
}

void Tela::MoveFriendlyProjectiles() {
	if (shoot == 1) {
		for (int i = 0; i < MAX_PROJECTILES; i++) {
			if (vetorProjeteisAmigos.size() < MAX_PROJECTILES) {
				vetorProjeteisAmigos.push_back(new Projectile(player.Centro(), FuncoesExtra::CalculaVetorUnitario(player.Centro(), mouse),Dimensao(5,5), 900, 10, PROJECTILE_VELOCITY, true,Cor(0,0,1)));
				score.IncTiros(1);
				break;
			}
			else if(!vetorProjeteisAmigos[i]->isActive){
				vetorProjeteisAmigos[i]->c = player.c; vetorProjeteisAmigos[i]->vetor = FuncoesExtra::CalculaVetorUnitario(player.Centro(), mouse); vetorProjeteisAmigos[i]->alcance = 900; vetorProjeteisAmigos[i]->dano = 10; vetorProjeteisAmigos[i]->velocity = PROJECTILE_VELOCITY; vetorProjeteisAmigos[i]->isActive = true; vetorProjeteisAmigos[i]->d = Dimensao(5, 5);
				score.IncTiros(1);
				break;
			}
		}
	}
	if (shoot == 2 && (player.getTiros()>0)) {
		for (int i = 0; i < MAX_PROJECTILES; i++) {
			if (vetorProjeteisAmigos.size() < MAX_PROJECTILES) {
				vetorProjeteisAmigos.push_back(new Projectile(player.Centro(), FuncoesExtra::CalculaVetorUnitario(player.Centro(), mouse), Dimensao(20, 20), 900, 50, PROJECTILE_VELOCITY, true, Cor(0, 0, 1)));
				score.IncTiros(1);
				player.decTirosEspeciais();
				break;
			}
			else if (!vetorProjeteisAmigos[i]->isActive) {
				vetorProjeteisAmigos[i]->c = player.c; vetorProjeteisAmigos[i]->vetor = FuncoesExtra::CalculaVetorUnitario(player.Centro(), mouse); vetorProjeteisAmigos[i]->alcance = 900; vetorProjeteisAmigos[i]->dano = 50; vetorProjeteisAmigos[i]->velocity = PROJECTILE_VELOCITY; vetorProjeteisAmigos[i]->isActive = true; vetorProjeteisAmigos[i]->d = Dimensao(20, 20);
				score.IncTiros(1);
				player.decTirosEspeciais();
				break;
			}
		}
	}
	shoot = 0;
	for(int i=0; i<vetorProjeteisAmigos.size(); i++) {
		if (vetorProjeteisAmigos[i]->isActive) {
			vetorProjeteisAmigos[i]->c = Coord(vetorProjeteisAmigos[i]->c.x + (vetorProjeteisAmigos[i]->vetor.x * vetorProjeteisAmigos[i]->velocity),vetorProjeteisAmigos[i]->c.y + (vetorProjeteisAmigos[i]->vetor.y * vetorProjeteisAmigos[i]->velocity));
		}
		//Destruir projeteis distantes
		if (vetorProjeteisAmigos[i]->isActive == 1 && (vetorProjeteisAmigos[i]->c.x > janela.width || vetorProjeteisAmigos[i]->c.x < 0 || vetorProjeteisAmigos[i]->c.y > janela.height || vetorProjeteisAmigos[i]->c.y < 0)) {
			vetorProjeteisAmigos[i]->Deactivate();
		}
	}
}

void Tela::MoveEnemyProjectiles() {
	for(int i=0; i<vetorProjeteisInimigos.size(); i++) {
		if (vetorProjeteisInimigos[i]->isActive) {
			vetorProjeteisInimigos[i]->c = Coord(vetorProjeteisInimigos[i]->c.x + (vetorProjeteisInimigos[i]->vetor.x * vetorProjeteisInimigos[i]->velocity),vetorProjeteisInimigos[i]->c.y + (vetorProjeteisInimigos[i]->vetor.y * vetorProjeteisInimigos[i]->velocity));
		}
		//Destruir projeteis distantes
		if (vetorProjeteisInimigos[i]->isActive == 1 && (vetorProjeteisInimigos[i]->c.x > janela.width || vetorProjeteisInimigos[i]->c.x < 0 || vetorProjeteisInimigos[i]->c.y > janela.height || vetorProjeteisInimigos[i]->c.y < 0)) {
			vetorProjeteisInimigos[i]->Deactivate();
		}
	}
}

void Tela::keyboardUp(unsigned char key, int x, int y) {
	cout << "Tecla regular solta: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
	switch (key) {
	case UP:
		keyBuffer[0] = false;
		break;
	case DOWN:
		keyBuffer[1] = false;
		break;
	case LEFT:
		keyBuffer[2] = false;
		break;
	case RIGHT:
		keyBuffer[3] = false;
		break;
	}
}

void Tela::mouseClick(int button, int state, int x, int y) {

	if (state == GLUT_DOWN) {
		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
		glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		winZ = 0;

		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

		if (button == 0) {this->shoot = 1; keyBuffer[4] = true;}
		else if (button == 2) { this->shoot = 2; keyBuffer[5] = true;}
		mouse = (Coord(worldX, worldY));
		if (menu->emMenuPrincipal) {
			menu->clickAtivo = true;
			menu->mouse = mouse;
		}
		cout << "Mouse click: " << button << ". Posicao (" << mouse.x << ',' << mouse.y << ')' << endl;
	}
	else
	{
		keyBuffer[4] = false;
		shoot = 0 ;
	}
}

bool Tela::ChecaColisao(BoundingBox *quadrado1, BoundingBox *quadrado2) {
	int esquerda1, direita1, cima1, baixo1;
	int esquerda2, direita2, cima2, baixo2;
	esquerda1 = quadrado1->x;
	direita1 = quadrado1->x + quadrado1->largura;
	cima1 = quadrado1->y;
	baixo1 = quadrado1->y + quadrado1->altura;
	esquerda2 = quadrado2->x;
	direita2 = quadrado2->x + quadrado2->largura;
	 cima2 = quadrado2->y;
	 baixo2 = quadrado2->y + quadrado2->altura;
	if (esquerda1 > direita2){
		return false; // (não colisão)
	}
	if (direita1 < esquerda2){
		return false; // (não colisão)
	}
	if (cima1 > baixo2) {
		return false; // (não colisão)
	}
	if (baixo1 < cima2){
		return false; // (não colisão)
	}			  /*do contrário (COLISÃO)*/
	return true;
}

void Tela::DisplayEnemies() {
	for(int i=0; i<fase.vetorInimigos.size(); i++) {
		fase.vetorInimigos[i]->Display();
	}
}


void Tela::ChecaColisaoInimigosParedes() {
	bool podeMover = true;
	for(int i=0; i<fase.vetorInimigos.size(); i++) {
		if ((fase.vetorInimigos[i]->getIsActive())) {
		Coord nova = fase.vetorInimigos[i]->FollowPlayer(&player.Centro());
		BoundingBox *spriteInimigo = new BoundingBox(nova.x, nova.y, fase.vetorInimigos[i]->d.largura, fase.vetorInimigos[i]->d.altura);
		for(int i=0; i<fase.vetorParede.size(); i++) {
			BoundingBox *spriteParede = new BoundingBox(fase.vetorParede[i]->c.x, fase.vetorParede[i]->c.y, fase.vetorParede[i]->d.largura, fase.vetorParede[i]->d.altura);
			podeMover = !ChecaColisao(spriteInimigo, spriteParede);
			delete spriteParede;
			spriteParede = NULL;
			if (!podeMover) { break; }
		}
		if (inimigo->tipo == 5){
		inimigo->Move(&nova, true);
		}
		else {
		inimigo->Move(&nova, podeMover);
		}
		delete spriteInimigo;
		spriteInimigo = NULL;
		}
	}
}

bool Tela::ChecarColisoesParedes(int variacaox, int variacaoy) {
	BoundingBox *jogador = new BoundingBox(player.c.x+ variacaox, player.c.y + variacaoy, player.d.largura, player.d.altura);
	bool podeMover = false;
	for (int i = 0; i < fase.vetorParede.size(); i++) {
		BoundingBox *parede = new BoundingBox(fase.vetorParede[i]->c.x, fase.vetorParede[i]->c.y, fase.vetorParede[i]->d.largura, fase.vetorParede[i]->d.altura);
		podeMover = !ChecaColisao(jogador, parede);
		if (podeMover == false) break;
	}
	return podeMover;
}

void Tela::ChecarColisoes() {
	ChecarColisoesProjeteisAmigos();
	ChecarColisoesProjeteisInimigos();
	ChecarColisoesInimigos();
	ChecaColisaoProjeteisParedes();
	ChecaColisaoInimigosParedes();
	ChecarColisoesColetaveis();
}

void Tela::ChecarColisoesProjeteisInimigos() {

	BoundingBox *spriteJogador = new BoundingBox(player.c.x , player.c.y , player.d.largura, player.d.altura);
	for each(Projectile* projetilInimigo in vetorProjeteisInimigos) {
		if(projetilInimigo->getIsActive()){
			BoundingBox *spriteInimigo = new BoundingBox(projetilInimigo->c.x, projetilInimigo->c.y, projetilInimigo->d.largura, projetilInimigo->d.altura);
			if (ChecaColisao(spriteJogador, spriteInimigo)) {
				vetorEfeitosVisuais.push_back(new Explosao(player.Centro(), "pequena"));
				player.DecHP(projetilInimigo->dano);
			if(player.getHP() <= 0){
					player.Kill();
			}
				projetilInimigo->Deactivate();
			}
		}
	}
}

void Tela::ChecarColisoesProjeteisAmigos() {
	for each(Projectile* projetilAmigo in vetorProjeteisAmigos) {
		if (projetilAmigo->getIsActive()){
			BoundingBox *spriteProjetil = new BoundingBox(projetilAmigo->c.x, projetilAmigo->c.y, projetilAmigo->d.largura, projetilAmigo->d.altura);
			for each(Enemy* inimigo in fase.vetorInimigos) {
				BoundingBox *spriteInimigo = new BoundingBox(inimigo->c.x, inimigo->c.y, inimigo->d.largura, inimigo->d.altura);
				if (projetilAmigo->getIsActive()){
					if (inimigo->getIsActive()) {
						if (ChecaColisao(spriteProjetil, spriteInimigo)) {
							projetilAmigo->Deactivate();
							inimigo->DecHP(projetilAmigo->dano);
							score.IncHits(1);
							vetorEfeitosVisuais.push_back(new Explosao(inimigo->Centro(), "pequena"));
							if (!inimigo->getIsActive()) {
								vetorEfeitosVisuais.push_back(new Explosao(inimigo->Centro(),"media"));
								fase.DecQtdInimigos();
								score.IncPontuacao(inimigo->getScoreWorth());
							}
						}
					}
			}
		}
	}
}
}

void Tela::ChecarColisoesInimigos() {
	BoundingBox *spriteJogador = new BoundingBox(player.c.x, player.c.y, player.d.largura, player.d.altura);
	for each(Enemy* enemy in fase.vetorInimigos) {
		if (enemy->getIsActive()) {
			BoundingBox *spriteInimigo = new BoundingBox(enemy->c.x, enemy->c.y, enemy->d.largura, enemy->d.altura);
			if (ChecaColisao(spriteJogador, spriteInimigo)) {
				vetorEfeitosVisuais.push_back(new Explosao(player.Centro(), "grande"));
				player.Kill();
				enemy->Kill();
				delete enemy;
				enemy = NULL;
			}
			delete spriteInimigo;
			spriteInimigo = NULL;
		}
	}
	delete spriteJogador;
	spriteJogador = NULL;
}

void Tela::EnemiesShoot() {
	contadorTempo++;
	if (contadorTempo % 10 == 0) {
		for each(Enemy* enemy in fase.vetorInimigos) {
		if (enemy->getIsActive()){
			if (rand() % 10 < 1) {
				for (int i = 0; i < MAX_PROJECTILES; i++) {
					if (vetorProjeteisInimigos.size() < MAX_PROJECTILES) {
						vetorProjeteisInimigos.push_back(new Projectile(enemy->Centro(), FuncoesExtra::CalculaVetorUnitario(enemy->Centro(), player.Centro()), Dimensao(5, 5), 900, 10, PROJECTILE_VELOCITY, true, Cor(1, 0, 0)));
						break;
					}
					else if (!vetorProjeteisInimigos[i]->getIsActive()) {
						vetorProjeteisInimigos[i]->c = enemy->c; vetorProjeteisInimigos[i]->vetor = FuncoesExtra::CalculaVetorUnitario(enemy->Centro(), player.Centro()); vetorProjeteisInimigos[i]->alcance = 900; vetorProjeteisInimigos[i]->dano = 10; vetorProjeteisInimigos[i]->velocity = PROJECTILE_VELOCITY; vetorProjeteisInimigos[i]->isActive = true;
						break;
					}
				}
			}
		}
		}
	}
}

void Tela::DisplayVisualEfects() {
	for each(EfeitosVisuais* efeito in vetorEfeitosVisuais) {
		if(efeito->isActive)
		efeito->Display();
	}
}

void Tela::ChecaColisaoProjeteisParedes() {
	for each(Projectile* projetilAmigo in vetorProjeteisAmigos) {
		if (projetilAmigo->getIsActive()) {
			BoundingBox *spriteProjetil = new BoundingBox(projetilAmigo->c.x, projetilAmigo->c.y, projetilAmigo->d.largura, projetilAmigo->d.altura);
			for each (Parede* parede in fase.vetorParede){
				BoundingBox *spriteParede = new BoundingBox(parede->c.x, parede->c.y, parede->d.largura, parede->d.altura);
				bool colisao = ChecaColisao(spriteProjetil, spriteParede);
				if (colisao == true) {
					projetilAmigo->Deactivate();
					break;
				}
				delete spriteParede;
				spriteParede = NULL;
			}
			delete spriteProjetil;
			spriteProjetil = NULL;
		}
	}

	for each(Projectile* projetilInimigo in vetorProjeteisInimigos) {
		if (projetilInimigo->getIsActive()) {
			BoundingBox *spriteProjetil = new BoundingBox(projetilInimigo->c.x, projetilInimigo->c.y, projetilInimigo->d.largura, projetilInimigo->d.altura);
			for each (Parede* parede in fase.vetorParede) {
				BoundingBox *spriteParede = new BoundingBox(parede->c.x, parede->c.y, parede->d.largura, parede->d.altura);
				bool colisao = ChecaColisao(spriteProjetil, spriteParede);
				if (colisao == true) {
					projetilInimigo->Deactivate();
					break;
				}
				delete spriteParede;
				spriteParede = NULL;
			}
			delete spriteProjetil;
			spriteProjetil = NULL;
		}
	}
}

void Tela::DisplayColetaveis() {
	for each(Coletavel* coletavel in fase.vetorColetaveis) {
		coletavel->Display();
	}
}

void Tela::ChecarColisoesColetaveis() {
	BoundingBox *spriteJogador = new BoundingBox(player.c.x, player.c.y, player.d.largura, player.d.altura);
	for each(Coletavel* coletavel in fase.vetorColetaveis) {
		if (coletavel->active) {
			BoundingBox *spriteColetavel = new BoundingBox(coletavel->c.x, coletavel->c.y, coletavel->d.largura, coletavel->d.altura);
			if (ChecaColisao(spriteJogador, spriteColetavel)) {
				player.onMedikitCollectAction(coletavel->getCura());
				coletavel->Dispose();
			}
			delete spriteColetavel;
			spriteColetavel = NULL;
		}
	}
	delete spriteJogador;
	spriteJogador = NULL;
}


