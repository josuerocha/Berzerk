#include <Game.h>
#include <iostream>
using namespace std;

Game::Game(){

	animacaoInicial = AnimacaoInicial();
	level = Level(1);
	efeitoPassouFase = new AnimacaoPassouFase(0);
	efeitoMorte = new AnimacaoMorte();
	efeitoGameOver = new AnimacaoGameOver();
	menu = new MainMenu();

	fullscreen = false;
	animacaoMorte = false;
	passouDeFase = false;
	animacaoFinalFlag = false;

	this->faseAtual = 1;
	this->shoot = false;
	this->isPlaying = true;

	cout<<"LEFT CONSTRUCTOR" << endl;
}

void Game::Logica() {
	if ((level.getQtdInimigos() <= 0) && (player.getHP() > 0)) {
		passouDeFase = true;
		cout<< "LEVEL UP" << endl;
	}
	else {
		passouDeFase = false;
	}

}

Game::~Game(){

}

void Game::Initialize() {
	player = Player(Coord(100, 100), Dimensao(25, 25), 10, 100, Cor(1.0, 0.5, 0.0),3,50);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	shoot = 0;
}

void Game::AlteraTamanhoJanela(GLsizei w, GLsizei h){
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (left, right, bottom, top)
	if (w <= h){
		gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f*h / w);
		window.height = 600 * h / w;
	}
	else{
		gluOrtho2D(0.0f, 800.0f*w / h, 0.0f, 600.0f);
		window.width = 800 * w / h;
	}
	cout << "TAMANHO TELA " << w << "  " << h;
}

void Game::Display() {
	Logica();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	if (faseAtual >= 4 && passouDeFase) {
		animacaoFinal.Display();
		animacaoFinalFlag = true;
		animacaoFinal.Reshape(window.width,window.height);
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
		level.DesenhaFase();
		DisplayCharacters();
		ChecarColisoes();
	}
	else if (menu->emMenuPrincipal) {
		menu->Run();
		player.Reset();
	}

	if (passouDeFase && !animacaoMorte && !animacaoInicial.emAnimacao && !menu->emMenuPrincipal) {
		efeitoPassouFase->Display(faseAtual + 1);
		if(!efeitoPassouFase->isActive){
			faseAtual++;
			visualEffects.clear();
			level = Level(faseAtual + 1);
			player.setC(level.getPlayerPosition());
			passouDeFase = false;

			for(Projectile* p : friendlyProjectiles) {
				delete(p);
				p = NULL;
			}

			for(Projectile* p : enemyProjectiles) {
				delete(p);
				p = NULL;
			}

			for(EfeitosVisuais* e : visualEffects) {
				delete(e);
				e = NULL;
			}

			efeitoPassouFase->Reset();
			friendlyProjectiles.clear();
			enemyProjectiles.clear();
			visualEffects.clear();
		}
	}

	if ((!player.getIsActive()) && (player.getVidas() > 0) && !animacaoInicial.emAnimacao) {
		animacaoMorte = true;
		efeitoMorte->Display();
		if (!efeitoMorte->isActive) {
			level = Level(faseAtual + 1);
			visualEffects.clear();
			player.Reset();
			player.setC(level.getPlayerPosition());
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
			level = Level(1);
			score.Reset();
			visualEffects.clear();
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

void Game::DisplayCharacters() {
	DisplayEnemies();
	player.Display();
	DisplayProjectiles();
	DisplayEnemyProjectiles();
	DisplayVisualEfects();
	score.Display(player.getVidas());
	DisplayColetaveis();
}

void Game::setWindowValues() {
	window.width = 800;
	window.height = 600;
	window.title = "BERZERK";
	window.field_of_view_angle = 0;
	window.z_near = 1.0f;
	window.z_far = 100.0f;
}

void Game::DisplayProjectiles() {

	for(Projectile* p : friendlyProjectiles) {
		if (p->isActive()) {
			p->Display();
		}
	}
}

void Game::DisplayEnemyProjectiles() {
	for( Projectile* p : enemyProjectiles) {
		if (p->isActive()) {
			p->Display();
		}
	}
}

void Game::CheckMapBoundaries(){
	if (player.getC().x > window.width) {
		player.c.x = window.width;
	}
	if (player.getC().x < 0) {
		player.c.x = 0;
	}
	if (player.c.y > window.height) {
		player.c.y = window.height;
	}
	if (player.c.y < 0) {
		player.c.y = 0;
	}
}

void Game::MovePlayer() {

	if (keyBuffer[0] == true) { player.IncY(5, ChecarColisoesParedes(0,1)); }
	if (keyBuffer[1] == true) { player.IncY(-5, ChecarColisoesParedes(0,-1)); }
	if (keyBuffer[2] == true) { player.IncX(-5, ChecarColisoesParedes(-1,0)); }
	if (keyBuffer[3] == true) { player.IncX(5, ChecarColisoesParedes(1,0)); }
	if (keyBuffer[4] == true) { shoot = 1; keyBuffer[4] = false; }
	if (keyBuffer[5] == true) { shoot = 2; keyBuffer[5] = false; }
}

void Game::keyboardDown(unsigned char key, int x, int y) {
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
		//op��es
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

void Game::mouseMotion(int x, int y) {
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

void Game::MoveProjectiles() {
	MoveFriendlyProjectiles();
	MoveEnemyProjectiles();
}

void Game::MoveFriendlyProjectiles() {
	if (shoot == 1) {
		for (int i = 0; i < MAX_PROJECTILES; i++) {
			if (friendlyProjectiles.size() < MAX_PROJECTILES) {
				friendlyProjectiles.push_back(new Projectile(player.Centro(), Utilities::CalculaVetorUnitario(player.Centro(), mouse),Dimensao(5,5), 900, 10, PROJECTILE_VELOCITY, true,Cor(0,0,1)));
				score.incShots(1);
				break;
			}
			else if(!friendlyProjectiles[i]->isActive()){
				friendlyProjectiles[i]->c = player.c;
				friendlyProjectiles[i]->vetor = Utilities::CalculaVetorUnitario(player.Centro(), mouse);
				friendlyProjectiles[i]->alcance = 900;
				friendlyProjectiles[i]->dano = 10;
				friendlyProjectiles[i]->velocity = PROJECTILE_VELOCITY;
				friendlyProjectiles[i]->active = true;
				friendlyProjectiles[i]->d = Dimensao(5, 5);
				score.incShots(1);
				break;
			}
		}
	}
	if (shoot == 2 && (player.getTiros()>0)) {
		for (int i = 0; i < MAX_PROJECTILES; i++) {
			if (friendlyProjectiles.size() < MAX_PROJECTILES) {
				friendlyProjectiles.push_back(new Projectile(player.Centro(), Utilities::CalculaVetorUnitario(player.Centro(), mouse), Dimensao(20, 20), 900, 50, PROJECTILE_VELOCITY, true, Cor(0, 0, 1)));
				score.incShots(1);
				player.decTirosEspeciais();
				break;
			}
			else if (!friendlyProjectiles[i]->isActive()) {
				friendlyProjectiles[i]->c = player.c; friendlyProjectiles[i]->vetor = Utilities::CalculaVetorUnitario(player.Centro(), mouse); friendlyProjectiles[i]->alcance = 900; friendlyProjectiles[i]->dano = 50; friendlyProjectiles[i]->velocity = PROJECTILE_VELOCITY; friendlyProjectiles[i]->active = true; friendlyProjectiles[i]->d = Dimensao(20, 20);
				score.incShots(1);
				player.decTirosEspeciais();
				break;
			}
		}
	}
	shoot = 0;
	for( Projectile*  p : friendlyProjectiles) {
		if (p->isActive()) {
			p->c = Coord(p->c.x + (p->vetor.x * p->velocity),p->c.y + (p->vetor.y * p->velocity));
		}
		//Destruir projeteis distantes
		if (p->isActive() && (p->c.x > window.width || p->c.x < 0 || p->c.y > window.height || p->c.y < 0)) {
			p->Deactivate();
		}
	}
}

void Game::MoveEnemyProjectiles() {
	for(Projectile* projetil : enemyProjectiles) {
		if (projetil->isActive()) {
			projetil->c = Coord(projetil->c.x + (projetil->vetor.x * projetil->velocity),projetil->c.y + (projetil->vetor.y * projetil->velocity));
		}
		//Destruir projeteis distantes
		if (projetil->isActive() && (projetil->c.x > window.width || projetil->c.x < 0 || projetil->c.y > window.height || projetil->c.y < 0)) {
			projetil->Deactivate();
		}
	}
}

void Game::keyboardUp(unsigned char key, int x, int y) {
	//cout << "Regular key release: " << char(key) << ". Mouse (" << x << ',' << y << ')' << endl;
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

void Game::mouseClick(int button, int state, int x, int y) {

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

void Game::DisplayEnemies() {
	for(Enemy* enemy : level.vetorInimigos) {
		enemy->Display();
	}
}


void Game::moveEnemies() {

	for(Enemy* enemy : level.vetorInimigos) {
		if ((enemy->getIsActive())) {
			Coord playerCenter = player.Centro();
			Coord nova = enemy->FollowPlayer(&playerCenter);

			if (enemy->tipo == 5){
				enemy->Move(&nova, true);
			} else {
				BoundingBox *spriteInimigo = new BoundingBox(nova.x, nova.y, enemy->d.largura, enemy->d.altura);
				bool podeMover = true;
				for(Parede* parede : level.walls) {
					BoundingBox *spriteParede = new BoundingBox(parede->c.x, parede->c.y, parede->d.largura, parede->d.altura);
					podeMover = !Utilities::checkCollision(spriteInimigo, spriteParede);
					delete spriteParede;
					spriteParede = NULL;
					if (!podeMover) { break; }
				}
				enemy->Move(&nova, podeMover);

				delete spriteInimigo;
				spriteInimigo = NULL;
			}


		}
	}
}

bool Game::ChecarColisoesParedes(int variacaox, int variacaoy) {
	BoundingBox *jogador = new BoundingBox(player.c.x+ variacaox, player.c.y + variacaoy, player.d.largura, player.d.altura);
	bool podeMover = false;
	for (int i = 0; i < level.walls.size(); i++) {
		BoundingBox *parede = new BoundingBox(level.walls[i]->c.x, level.walls[i]->c.y, level.walls[i]->d.largura, level.walls[i]->d.altura);
		podeMover = !Utilities::checkCollision(jogador, parede);
		if (podeMover == false) break;
	}
	return podeMover;
}

void Game::ChecarColisoes() {
	ChecarColisoesProjeteisAmigos();
	ChecarColisoesProjeteisInimigos();
	ChecarColisoesInimigos();
	ChecaColisaoProjeteisParedes();
	moveEnemies();
	ChecarColisoesColetaveis();
}

void Game::ChecarColisoesProjeteisInimigos() {

	BoundingBox *spriteJogador = new BoundingBox(player.c.x , player.c.y , player.d.largura, player.d.altura);
	for(Projectile* projetilInimigo : enemyProjectiles) {
		if(projetilInimigo->isActive()){
			BoundingBox *spriteInimigo = new BoundingBox(projetilInimigo->c.x, projetilInimigo->c.y, projetilInimigo->d.largura, projetilInimigo->d.altura);
			if (Utilities::checkCollision(spriteJogador, spriteInimigo)) {
				visualEffects.push_back(new Explosao(player.Centro(), "pequena"));
				player.DecHP(projetilInimigo->dano);
			if(player.getHP() <= 0){
					player.Kill();
			}
				projetilInimigo->Deactivate();
			}
		}
	}
}

void Game::ChecarColisoesProjeteisAmigos() {
	for(Projectile* projetilAmigo : friendlyProjectiles) {
		if (projetilAmigo->isActive()){
			BoundingBox *spriteProjetil = new BoundingBox(projetilAmigo->c.x, projetilAmigo->c.y, projetilAmigo->d.largura, projetilAmigo->d.altura);
			for(Enemy* inimigo : level.vetorInimigos) {
				BoundingBox *spriteInimigo = new BoundingBox(inimigo->c.x, inimigo->c.y, inimigo->d.largura, inimigo->d.altura);
				if (projetilAmigo->isActive()){
					if (inimigo->getIsActive()) {
						if (Utilities::checkCollision(spriteProjetil, spriteInimigo)) {
							projetilAmigo->Deactivate();
							inimigo->DecHP(projetilAmigo->dano);
							score.IncHits(1);
							visualEffects.push_back(new Explosao(inimigo->Centro(), "pequena"));
							if (!inimigo->getIsActive()) {
								visualEffects.push_back(new Explosao(inimigo->Centro(),"media"));
								level.DecQtdInimigos();
								score.IncPontuacao(inimigo->getScoreWorth());
							}
						}
					}
			}
		}
	}
}
}

void Game::ChecarColisoesInimigos() {
	BoundingBox *spriteJogador = new BoundingBox(player.c.x, player.c.y, player.d.largura, player.d.altura);
	for(Enemy* enemy : level.vetorInimigos) {
		if (enemy->getIsActive()) {
			BoundingBox *spriteInimigo = new BoundingBox(enemy->c.x, enemy->c.y, enemy->d.largura, enemy->d.altura);
			if (Utilities::checkCollision(spriteJogador, spriteInimigo)) {
				visualEffects.push_back(new Explosao(player.Centro(), "grande"));
				player.Kill();
				enemy->Kill();
				delete (&enemy);
			}
			delete spriteInimigo;
			spriteInimigo = NULL;
		}
	}
	delete spriteJogador;
	spriteJogador = NULL;
}

void Game::EnemiesShoot() {
	contadorTempo++;
	if (contadorTempo % 10 == 0) {
		for(Enemy* enemy : level.vetorInimigos) {
		if (enemy->isActive){
			if (rand() % 10 < 1) {
				for (int i = 0; i < MAX_PROJECTILES; i++) {
					if (enemyProjectiles.size() < MAX_PROJECTILES) {
						enemyProjectiles.push_back(new Projectile(enemy->Centro(),
								Utilities::CalculaVetorUnitario(enemy->Centro(), player.Centro()),
								Dimensao(5, 5),
								900,
								10,
								PROJECTILE_VELOCITY,
								true,
								Cor(1, 0, 0)));
						break;
					}
					else if (!enemyProjectiles[i]->isActive()) {
						enemyProjectiles[i]->c = enemy->c;
						enemyProjectiles[i]->vetor = Utilities::CalculaVetorUnitario(enemy->Centro(), player.Centro());
						enemyProjectiles[i]->alcance = 900;
						enemyProjectiles[i]->dano = 10;
						enemyProjectiles[i]->velocity = PROJECTILE_VELOCITY;
						enemyProjectiles[i]->active = true;
						break;
					}
				}
			}
		}
		}
	}
}

void Game::DisplayVisualEfects() {
	for(EfeitosVisuais* efeito : visualEffects) {
		if(efeito->isActive)
		efeito->Display();
	}
}

void Game::ChecaColisaoProjeteisParedes() {
	for(Projectile* projetilAmigo : friendlyProjectiles) {
		if (projetilAmigo->isActive()) {
			BoundingBox *spriteProjetil = new BoundingBox(projetilAmigo->c.x, projetilAmigo->c.y, projetilAmigo->d.largura, projetilAmigo->d.altura);
			for (Parede* parede : level.walls){
				BoundingBox *spriteParede = new BoundingBox(parede->c.x, parede->c.y, parede->d.largura, parede->d.altura);
				bool colisao = Utilities::checkCollision(spriteProjetil, spriteParede);
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

	for(Projectile* projetilInimigo : enemyProjectiles) {
		if (projetilInimigo->isActive()) {
			BoundingBox *spriteProjetil = new BoundingBox(projetilInimigo->c.x, projetilInimigo->c.y, projetilInimigo->d.largura, projetilInimigo->d.altura);
			for (Parede* parede : level.walls) {
				BoundingBox *spriteParede = new BoundingBox(parede->c.x, parede->c.y, parede->d.largura, parede->d.altura);
				bool colisao = Utilities::checkCollision(spriteProjetil, spriteParede);
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

void Game::DisplayColetaveis() {
	for(Coletavel* coletavel : level.vetorColetaveis) {
		coletavel->Display();
	}
}

void Game::ChecarColisoesColetaveis() {
	BoundingBox *spriteJogador = new BoundingBox(player.c.x, player.c.y, player.d.largura, player.d.altura);
	for(Coletavel* coletavel : level.vetorColetaveis) {
		if (coletavel->active) {
			BoundingBox *spriteColetavel = new BoundingBox(coletavel->c.x, coletavel->c.y, coletavel->d.largura, coletavel->d.altura);
			if (Utilities::checkCollision(spriteJogador, spriteColetavel)) {
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


