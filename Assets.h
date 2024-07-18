#pragma once
#include "Animation.h"
#include <SFML/Audio.hpp>

#include <map>

class Assets
{
private:
	std::map<std::string, sf::Texture>	m_textureMap;
	std::map<std::string, Animation>	m_animationMap;
	std::map<std::string, sf::Font>		m_fontMap;
	std::map<std::string, sf::SoundBuffer>	m_soundMap; 

	bool addTexture(const std::string& textureName, const std::string& path
		, bool smooth = true);

	bool addTexture(const std::string& textureName, const std::string& path
		, int posX, int posY, int width, int height
		, bool smooth = true);

	bool addFont(const std::string& fontName, const std::string& path);

	bool addAnimation(const std::string& animationName
		, const std::string & textureName, const size_t frameCont
		, const size_t duration);

	bool addSound(const std::string& soundName, const std::string& path);

public:
	Assets();

	const sf::Texture&	getTexture(const std::string& textureName)		const;
	const Animation&	getAnimation(const std::string& animationName)	const;
	const sf::Font&		getFont(const std::string& fontName)				const;
	const sf::SoundBuffer&	getSound(const std::string& soundName)			const;

	void loadFromFile(const std::string& filepath);

};