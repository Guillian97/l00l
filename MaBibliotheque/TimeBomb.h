#pragma once
#include "Enemy.h"

class TimeBomb : public Enemy {
public:
	TimeBomb(TileMap& tm);
	void getNextPosition();
	void Update(float frametime);
	void Draw(sf::RenderWindow *window);
	~TimeBomb();
private:
	std::vector<sf::IntRect*> sprites;
	sf::Sprite *s;
	sf::Texture *t;
	sf::IntRect *rect;
	Animation animation;
};


