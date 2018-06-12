#include "stdafx.h"
#include "GameOverState.h"
#include <iostream>
#include "Constants.h"

GameOverState::GameOverState(GameStateManager& gsm) :gsm(gsm), background("Resources/Backgrounds/gameoverbg.gif", 1) { //change bg later
	Init();
	background.setVector(-1, 0);
}

void GameOverState::Update(sf::RenderWindow * window, float frametime) {
	background.Update();
}

void GameOverState::Draw(sf::RenderWindow * window) {
	background.Draw(window);
	window->draw(GOHeader);
	for (int i = 0; i < Options.size(); i++) {
		if (i == currentChoice) {
			Options.at(i)->setFillColor(sf::Color::Black);
		}
		else {
			Options.at(i)->setFillColor(sf::Color::Red);
		}
		window->draw(*Options.at(i));
	}
}

void GameOverState::Init() {
	bgSprite.setTexture(bg);
	bgSprite.setPosition(bgx, bgy);
	bgSprite.setScale(WINWIDTH*WINSCALE / bgSprite.getGlobalBounds().width, WINHEIGHT*WINSCALE / bgSprite.getGlobalBounds().height);
	if (!font.loadFromFile("Resources/Secret.TTF")) {
		std::cout << "unable to load from file" << std::endl;
	}
	GOHeader.setFont(font);
	GOHeader.setString("Mission Failed");
	GOHeader.setCharacterSize(70);
	GOHeader.setPosition(WINWIDTH*WINSCALE / 2 - GOHeader.getGlobalBounds().width / 2, 80);
	GOHeader.setFillColor(sf::Color(128, 0, 0));
	//affichage du texte
	int offset = 100;
	for (sf::Text *t : Options) {
		t->setPosition(WINWIDTH*WINSCALE / 2 - t->getGlobalBounds().width / 2, 100 + offset);
		t->setFillColor(sf::Color(40, 40, 40));
		offset += 50;
	}

}

void GameOverState::KeyPressed(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Up) {
		currentChoice--;
		if (currentChoice < 0) {
			currentChoice = Options.size() - 1;
		}
	}
	if (key == sf::Keyboard::Down) {
		currentChoice++;
		if (currentChoice > Options.size() - 1) {
			currentChoice = 0;
		}
	}
	if (key == sf::Keyboard::Return) {
		selected();
	}
}

void GameOverState::KeyReleased(sf::Keyboard::Key key) {
}

void GameOverState::selected() {
	if (currentChoice == 0) {
		//restart level
		gsm.SetState(GameStateManager::LEVEL1STATE);
		gsm.Init();
	}
	if (currentChoice == 1) {
		//Quit
		gsm.SetState(GameStateManager::MENUSTATE);
	}

}


GameOverState::~GameOverState() {
}
