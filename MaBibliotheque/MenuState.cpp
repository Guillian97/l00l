#include "stdafx.h"
#include "MenuState.h"
#include <iostream>
#include "Constants.h"

MenuState::MenuState(GameStateManager& gsm) :gsm(gsm), background("Resources/Backgrounds/menubg.gif", 1) {
	Init(); //attention dangereux
	background.setVector(-1, 0);
}

void MenuState::Update(sf::RenderWindow * window, float frametime) {
	background.Update();
}

void MenuState::Draw(sf::RenderWindow * window) {
	background.Draw(window);
	window->draw(MenuHeader);
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

void MenuState::Init() {
	bgSprite.setTexture(bg);
	bgSprite.setPosition(bgx, bgy);
	bgSprite.setScale(WINWIDTH*WINSCALE / bgSprite.getGlobalBounds().width, WINHEIGHT*WINSCALE / bgSprite.getGlobalBounds().height);
	if (!font.loadFromFile("Resources/Secret.TTF")) {
		std::cout << "unable to load from file" << std::endl;
	}
	MenuHeader.setFont(font);
	MenuHeader.setString("Agent OO");
	MenuHeader.setCharacterSize(70);
	MenuHeader.setPosition(WINWIDTH*WINSCALE / 2 - MenuHeader.getGlobalBounds().width / 2, 80);
	MenuHeader.setFillColor(sf::Color(128, 0, 0));
	//affichage du texte
	int offset = 100;
	for (sf::Text *t : Options) {
		t->setPosition(WINWIDTH*WINSCALE / 2 - t->getGlobalBounds().width / 2, 100 + offset);
		t->setFillColor(sf::Color(40, 40, 40));
		offset += 50;
	}

}

void MenuState::KeyPressed(sf::Keyboard::Key key) {
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

void MenuState::KeyReleased(sf::Keyboard::Key key) {
}

void MenuState::selected() {
	if (currentChoice == 0) {
		gsm.SetState(GameStateManager::LEVEL1STATE);
		gsm.Init();
	}
	if (currentChoice == 1) {
		//Help
	}
	if (currentChoice == 2) {
		//Quit
	}
}


MenuState::~MenuState() {
}