#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "Level1State.h"
#include "GameOverState.h"
#include "WinState.h"


class GameStateManager {
public:
	static const int MENUSTATE = 0;
	static const int LEVEL1STATE = 1;
	static const int GAMEOVERSTATE = 2;
	static const int WINSTATE = 3;

	GameStateManager();

	void SetState(int state);
	int GetState();
	void Update(sf::RenderWindow* window, float frametime);
	void Draw(sf::RenderWindow* window);
	void Init();
	void KeyPressed(sf::Keyboard::Key key);
	void KeyReleased(sf::Keyboard::Key key);

	~GameStateManager();
protected:
	std::vector<GameState*> States;
	int currentState;
};
