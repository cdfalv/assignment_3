#include "Animation.h"
#include "Vec2.h"

Animation::Animation()
{
}

Animation::Animation(const std::string& name, const sf::Texture& texture)
	: Animation(name, texture, 1, 0)
{
}

Animation::Animation(const std::string& name, const sf::Texture& texture,
	size_t keyframesCount, size_t duration)
	: m_name(name)
	, m_sprite(texture)
	, m_keyframesCount(keyframesCount)
	, m_currentKeyFrame(0)
	, m_duration(duration)
{
	m_size = Vec2(
					(float)texture.getSize().x / keyframesCount,
					(float)texture.getSize().y
			);
	m_sprite.setOrigin(m_size.x / 2.0f, m_size.y / 2.0f);
	m_sprite.setTextureRect(sf::IntRect(m_currentKeyFrame * m_size.x, 0,
							m_size.x, m_size.y));
}

sf::Sprite& Animation::getSprite()
{
	return m_sprite;
}

const std::string& Animation::getName() const
{
	return m_name;
}

const Vec2& Animation::getSize() const
{
	return m_size;
}

void Animation::update()
{
	m_gameFrames++;
	m_currentKeyFrame = (m_gameFrames / m_duration) % m_keyframesCount;
	m_sprite.setTextureRect(sf::IntRect(m_currentKeyFrame * m_size.x, 0,
									m_size.x, m_size.y));
}

bool Animation::hasEnded() const
{
	return (m_gameFrames > m_duration && m_currentKeyFrame == 0) ? true : false;
}