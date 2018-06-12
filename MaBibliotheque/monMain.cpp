#include "stdafx.h"
#include "monMain.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <iostream>
#include "../MaBibliotheque/Constants.h"
#include "../MaBibliotheque/GameStateManager.h"
#include "SFML/Window.hpp"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <locale>

int monMain(int argc, char** argv)
{
	GameStateManager gsm;
	sf::RenderWindow window(sf::VideoMode(WINWIDTH * WINSCALE, WINHEIGHT * WINSCALE), "Agent 00");
	sf::Clock clock;
	window.setFramerateLimit(90);
	//gsm.Init();

	//LOAD GAME MUSIC
	sf::Music gameMusic;
	if (!gameMusic.openFromFile("Resources/Music/mission.ogg")) {
		std::cerr << "No music file found!" << std::endl;
	}

	//LOAD GAME MUSIC
	gameMusic.play();

	//GAME CLOCK & TIMER
	sf::Clock clock2;
	int chrono = 40;
	int countdown = 40;

	sf::Font timerFont;
	if (!timerFont.loadFromFile("Resources/GOTHIC.ttf")) {
		std::cerr << "No font file found!" << std::endl;
	}

	//convert countdown to a string
	std::string countdownString;
	std::ostringstream convert;
	convert << countdown;
	countdownString = convert.str();

	//LOAD FONT AND TEXT
	sf::Text timerText;
	timerText.setFont(timerFont);
	timerText.setString(countdownString);
	timerText.setPosition(10, 0);
	timerText.setCharacterSize(40);


	//open window
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				gsm.KeyPressed(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased) {
				gsm.KeyReleased(event.key.code);
			}
		}

		int state = gsm.GetState();
		if (gsm.GetState() == GameStateManager::GAMEOVERSTATE) {
			countdown = chrono;
		}

		//TIMER
		int timer = clock2.getElapsedTime().asSeconds();
		std::cout << timer << std::endl;

		if (timer > 0 && state == 1) {
			countdown--;
			timerText.setString(std::to_string(countdown));
			clock2.restart();

		}

		if (countdown == 0) {
			gsm.SetState(GameStateManager::GAMEOVERSTATE);
		}


		//draw everything on screen

		float frametime = clock.getElapsedTime().asMilliseconds();
		window.clear(sf::Color(255, 255, 255));
		gsm.Update(&window, frametime);
		gsm.Draw(&window);
		window.draw(timerText);
		window.display();
		clock.restart();

	}
	return 0;
}