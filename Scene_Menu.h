#pragma once

#include "Scene.h"

#include <vector>
#include <SFML/Graphics.hpp>

using vecString = std::vector<std::string>;

class SceneMenu : public Scene
{
private:
	std::string			m_title;
	vecString			m_menuStrings;
	vecString			m_levelPaths;
	sf::Text			m_menuText;
	size_t				m_selectedMenuIndex = 0;

	void init();

	void onEnd()							override; // override keyword
	void update()							override;// used so other person
	void sRender()							override;// can understand it 
	void sDoAction(const Action& action)	override;// clearly --> https://www.youtube.com/watch?v=_wqhcEegmN4

public:
	SceneMenu(GameEngine* gameEngine);

};