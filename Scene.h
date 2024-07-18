#pragma once

#include "Action.h"
#include "Entity.h"
#include "GameEngine.h"

#include <map>
#include <memory>

class GameEngine; // Resolve circular depenency

using ActionMap = std::map<int, std::string>;

//typedef std::map<int, std::string> ActionMap;

class Scene
{
protected:
	GameEngine*		m_game			= nullptr;
	//std::shared_ptr<GameEngine> m_game = nullptr;
	uint64_t		m_currentFrame	= 0;
	bool			m_hasEnded		= false;
	bool			m_paused		= false;
	ActionMap		m_actionMap;


public:
	Scene();
	Scene(GameEngine* game);

	virtual void update()							= 0; //pure virtual funton
	virtual void onEnd()							= 0; // are difine like this
	virtual void sRender()							= 0; // virtual fnc() = 0
	virtual void sDoAction(const Action& action)	= 0;

	const ActionMap& getActionMap() const;

	void registerAction(int inputKey, const std::string& actionName);
	void setPaused(bool paused);
};
