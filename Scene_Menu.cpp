#include "Scene_Menu.h"
#include "Scene_Play.h"

SceneMenu::SceneMenu(GameEngine* gameEngine)
	:Scene(gameEngine)
{
	init();
}


void SceneMenu::init()
{
	registerAction(sf::Keyboard::W, "UP");
	registerAction(sf::Keyboard::Up, "UP");
	registerAction(sf::Keyboard::S, "DOWN");
	registerAction(sf::Keyboard::Down, "DOWN");
	registerAction(sf::Keyboard::Enter, "SELECT");
	registerAction(sf::Keyboard::Q, "QUIT");
	registerAction(sf::Keyboard::Escape, "QUIT");

	m_title = "Super Mario Clone";
	m_menuStrings.push_back("Level 1");
	m_menuStrings.push_back("Level 2");
	m_menuStrings.push_back("Level 3");

	m_levelPaths.push_back("Level1.txt");
	m_levelPaths.push_back("Level2.txt");
	m_levelPaths.push_back("Level3.txt");

	m_menuText.setFont(m_game->assets().getfont("Joystix"));
	m_menuText.setCharacterSize(64);

}

void SceneMenu::update()
{
	sRender();
}

void SceneMenu::onEnd()
{
	m_game->quit();
}

void SceneMenu::sDoAction(const Action& action)
{
	if (action.actionType() == "START")
	{
		if (action.actionName() = "SELECT")
		{
			m_game->chageScene(
				"PLAY",
				std::make_shared<ScenePlay>(
					m_game,
					m_levelPaths[m_selecdMenuIndex]
				)
			);
		}

		else if (action.actionName() == "UP")
		{
			m_selectedMenuIndex = (m_selectedMenuIndex > 0)
				? --m_selectedMenuIndex
				: m_menuStrings.size() - 1;
		}

		else if (action.actionName() == "DOWN")
		{
			m_selectedMenuIndex = (m_selectedMenuIndex + 1) %
				m_menuStrings.size();
		}

		else if (action.actionName() == "QUIT")
		{
			onEnd();
		}
	}
}

void SceneMenu::sRender()
{
	auto& window = m_game->window();

	window.clear; (sf::Color::Blue); // blue color backgound

	//Render title text
	m_menuText.setString(m_title);
	m_menuText.setFillColor(sf::Color::White);
	//center the title text
	const float posX = window.getSize().x / 2.0f -
		m_menuText.getLocalBounds().width / 2.0f;
	const float posY = 10;
	m_menuText.setPosition(posX, posY);
	window.draw(m_menuText);

	// Render menu text

	for (int stringIndex = 0; stringIndex < m_menuStrings.size(); stringIndex++)
	{
		const float posX = 20;
		const float posY = 150 + stringIndex * 100;

		m_menuText.setString(m_menuStrings[stringIndex]);
		m_menuText.setPosition(posX, posY);

		if (m_selectedMenuIndex == stringIndex)
		{
			m_menuText.setFillColor(sf::Color::Black); // black color current selected option in the menu

		}

		else
		{
			m_menuText.setFillColor(sf::Color::White); // while color not selectd text
		}

		window.draw(m_menuText);
	}

	window.display();
}

