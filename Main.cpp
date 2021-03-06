#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>


int main()
{
	// ------------------ game setup --------------------------------
	// make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);

	// seed our random number generation
	srand(time(NULL));

	// create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	// create sprite at centre the sprite on the screen
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;
	sf::Time timetillSignal = sf::seconds(signalTimeLowerLimit);
	sf::Time timesinceSignal = sf::seconds(0.0f);





	// game loop
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{

			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					//we did
					int range = (int)(signalTimeUpperLimit - signalTimeLowerLimit);
					float signalSeconds = rand() % range + signalTimeLowerLimit;
					timetillSignal = sf::seconds(signalSeconds);
				}
			}
			// Process events

			// Update game state

			// timer
			sf::Time frameTime = gameClock.restart();

			timetillSignal = timetillSignal - frameTime;
			
			if (timetillSignal.asSeconds() <= 0.0f)
			{
				buttonSprite.setColor(sf::Color::Green);
			}
		
			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();  // close the game window
			}
		}


		// Update game state

		gameWindow.clear(sf::Color::Black);


		// draw
		gameWindow.draw(buttonSprite);




		gameWindow.display();


		
	}


	return 0;
}


