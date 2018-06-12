#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Background.h"

class GameOverState : public GameState {
public:
	class GameStateManager& gsm;
	GameOverState(class GameStateManager& gsm);
	void Update(sf::RenderWindow* window, float frametime);
	void Draw(sf::RenderWindow* window);
	void Init();
	void KeyPressed(sf::Keyboard::Key key);
	void KeyReleased(sf::Keyboard::Key key);
	void selected();
	~GameOverState();
private:
	sf::Texture bg;
	sf::Sprite bgSprite;
	Background background;
	double bgx = 0, bgy = 0;
	int currentChoice = 0;
	sf::Font font;
	std::vector<sf::Text*> Options = {
		new sf::Text("Restart",font),
		new sf::Text("Quit",font),
	};
	sf::Text GOHeader;

};

