#pragma once

#include "Animation.h"
#include  "Vec2.h"

class Component
{
public:
	bool has = false;
};

class CTransform : public Component
{
public:
	Vec2 prePos		= { 0.0f, 0.0f };
	Vec2 pos		= { 0.0f, 0.0f };
	Vec2 velocity	= { 0.0f, 0.0f };
	Vec2 scale		= { 1.0f, 1.0f };
	float angle		= 0.0f;

	CTransform()
	{
	}

	CTransform(const Vec2& p)
		: pos(p)
	{
	}

	CTransform(const Vec2& _p, const Vec2& _velocity, const Vec2 _scale,
		float _angle)
		: pos(_p)
		, prePos(_p)
		, velocity(_velocity)
		, scale(_scale)
		, angle(_angle)
	{
	}
};

class CInput : public Component
{
public:
	bool up			= false;
	bool down		= false;
	bool left		= false;
	bool right		= false;
	bool shoot		= false;
	bool canshoot	= false;
	bool canjump	= false;

	CInput()
	{
	}
};

class CLifespan : public Component
{
};

class CAnimation : public Component
{
public:
	Animation animation;
	bool repeat = false;

	CAnimation()
	{
	}

	CAnimation(const Animation& _animation, bool _repeat)
			: animation(_animation)
			, repeat(_repeat)
	{
	}
};

class CGravity : public Component
{
public:
	float gravity = 0.0f;

	CGravity()
	{
	}

	CGravity(float g)
		: gravity(g)
	{
	}
};

class CState : public Component
{
public:
	std::string state = "None";	
	
	CState()
	{
	}

	CState(const std::string& _state)
		: state(_state)
	{
	}
};

class CBoundingBox : public Component
{
public:
	Vec2 size;
	Vec2 halfSize;

	CBoundingBox()
	{
	}

	CBoundingBox(const Vec2& _size)
		: size(_size)
		, halfSize(_size / 2.0f)
	{
	}
};
