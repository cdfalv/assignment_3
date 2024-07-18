#include "assets.h"

#include <fstream>
#include <iostream>


Assets::Assets()
{
}

bool Assets::addTexture(const std::string& textureName, const std::string& path
	, bool smooth)
{
	sf::Texture texture;

	if (!texture.loadFromFile(path))
	{
		std::cerr << "failed to load texture: " << textureName
			<< " " << path << std::endl;
		return false;
	}

	texture.setSmooth(smooth);
	m_textureMap[textureName] = texture;
	return true;
}

bool Assets::addTexture(const std::string& textureName, const std::string& path
	, int posX, int posY, int width, int height, bool smooth)
{
	sf::Texture texture;

	if(!texture.loadFromFile(path, sf::IntRect(posX, posY, width, height)))
	{
		std::cerr << "Failed to load texture" << textureName << " " <<
			path << std::endl;

		return false;
	}

	texture.setSmooth(smooth);
	m_textureMap[textureName] = texture;
	return true;

}

bool Assets::addFont(const std::string& fontName, const std::string& path)
{
	sf::Font font;

	if (!font.loadFromFile(path))
	{
		std::cerr << "Failed to load font" << fontName << " " <<
			path << std::endl;
		return false;
	}

	m_fontMap[fontName] = font;
}

bool Assets::addAnimation(const std::string& animationName
						, const std::string& textureName
						, const size_t keyframesCount
						, const size_t duration )

{
	const auto& texture = getTexture(textureName);
	m_animationMap[animationName] = Animation(
		animationName, texture, keyframesCount, duration
		);
	return true;
}

bool Assets::addSound(const std::string& soundName, const std::string& path)
{
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile(path))
	{
		std::cerr << "Failed to sound" << soundName << " " <<
			path << std::endl;
		return false;
	}

	m_soundMap[soundName] = buffer;
	return true;
}

const sf::Texture& Assets::getTexture(const std::string& textureName) const //<--  if this const is present m_map[] gives error

{
	//TODO: handle not found case

	return m_textureMap.at(textureName);
	//return m_textureMap[textureName];
}

const Animation& Assets::getAnimation(const std::string& animationName) const
{
	//TODO: handle not found case

	return m_animationMap.at(animationName);
}

const sf::Font& Assets::getFont(const std::string& fontName) const
{
	//TODO: handle not found case

	return m_fontMap.at(fontName);
}

const sf::SoundBuffer& Assets::getSound(const std::string& soundName) const
{
	// TODO: handle not found case;

	return m_soundMap.at(soundName);
}

void Assets::loadFromFile(const std::string& filePath)
{
	std::ifstream fin(filePath);
	std::string token;

	while (fin.good())
	{
		fin >> token;
		if (token == "texture")
		{
			std::string name, path;
			int X, Y, width, height;
			bool smooth;
			// have to be modified
			// it's taking x,y etc as inpupt
			// it should also work if only name and path is given
			fin >> name >> path >> X >> Y >> width >> height >> smooth;
			if (!addTexture(name, path, X, Y, width, height, smooth))
			{
				// TODO: hanlde error
			}
		}

		else if (token == "Animation")
		{
			std::string name, textureName;
			int keyframesCount, duration;

			fin >> name >> textureName >> keyframesCount >> duration;
			if (!addAnimation(name, textureName, keyframesCount, duration))
			{
				// TODO: handle error
			}
		}

		else if (token == "Font")
		{
			std::string name, path;
			fin >> name >> path;

			if (!addFont(name, path))
			{
				// TODO: handle error
			}
		}

		else if (token == "sound")
		{
			std::string name, path;
			fin >> name >> path;

			if (!addSound(name, path))
			{
				//TODO: handle error
			}
		}
	}

}