#include "stdafx.h"
#include "WinState.h"
#include <iostream>
#include "Constants.h"

WinState::WinState(GameStateManager& gsm) :gsm(gsm), background("Resources/Backgrounds/winbg.gif", 1) { //change bg later
	Init();
	background.setVector(-1, 0);
}

void WinState::Update(sf::RenderWindow * window, float frametime) {
	background.Update();
}

void WinState::Draw(sf::RenderWindow * window) {
	background.Draw(window);
	window->draw(WinHeader);
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

void WinState::Init() {
	bgSprite.setTexture(bg);
	bgSprite.setPosition(bgx, bgy);
	bgSprite.setScale(WINWIDTH*WINSCALE / bgSprite.getGlobalBounds().width, WINHEIGHT*WINSCALE / bgSprite.getGlobalBounds().height);
	if (!font.loadFromFile("Resources/Secret.TTF")) {
		std::cout << "unable to load from file" << std::endl;
	}
	WinHeader.setFont(font);
	WinHeader.setString("Mission Complete");
	WinHeader.setCharacterSize(70);
	WinHeader.setPosition(WINWIDTH*WINSCALE / 2 - WinHeader.getGlobalBounds().width / 2, 80);
	WinHeader.setFillColor(sf::Color(128, 0, 0));
	//affichage du texte
	int offset = 100;
	for (sf::Text *t : Options) {
		t->setPosition(WINWIDTH*WINSCALE / 2 - t->getGlobalBounds().width / 2, 100 + offset);
		t->setFillColor(sf::Color(40, 40, 40));
		offset += 50;
	}

}

void WinState::KeyPressed(sf::Keyboard::Key key) {
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

void WinState::KeyReleased(sf::Keyboard::Key key) {
}

void WinState::selected() {
	if (currentChoice == 0) {
		//next level: not available yet
		gsm.SetState(GameStateManager::MENUSTATE);
	}
	if (currentChoice == 1) {
		//Quit (back to menu)
		gsm.SetState(GameStateManager::MENUSTATE);
	}

}

WinState::~WinState()
{
}
