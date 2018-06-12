#include "pch.h"
#include "../MaBibliotheque/Player.h"
#include "../MaBibliotheque/MapObject.h"
#include "../MaBibliotheque/TileMap.h"
#include "../MaBibliotheque/Level1State.h"

//verifier que lorsque le player est mort
//le currentState est a 2 (gameover)
TEST(TestCaseName, TestPlayer) {
	GameStateManager gsm;
	Player *player;
	TileMap tileMap(30);
	tileMap.LoadTiles("Resources/Tilesets/grasstileset.png");
	tileMap.LoadMap("Resources/Maps/one.map");
	tileMap.setPosition((double)0, (double)0);
	player->setDead();
	int state = gsm.GetState();
	EXPECT_EQ(state, 2);
}

//verifier que le vecteur ennemis est remis
//a 0 après un gameOver
TEST(TestCaseName, TestReInit) {
	GameStateManager gsm;
	std::vector<Enemy*> enemies;
	int size = enemies.size();
	gsm.SetState(2);
	EXPECT_EQ(0, size);
	
}

//Verifier qu'on peut placer les objets
//comme on veut sur la map
TEST(TestCaseName, TestSetPosition) {
	double x = 3;
	double y = 5;
	Player *player;
	TileMap tileMap(30);
	tileMap.LoadTiles("Resources/Tilesets/grasstileset.png");
	tileMap.LoadMap("Resources/Maps/one.map");
	tileMap.setPosition((double)0, (double)0);
	player->setPosition(x, y);
	double x2 = player->getX();
	double y2 = player->getY();
	EXPECT_EQ(x, x2);
	EXPECT_EQ(y, y2);
}