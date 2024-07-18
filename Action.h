#pragma once

#include <string>

class Action
{
private:
	std::string m_name = "NONE";	// Ex: jump, shoot, right
	std::string m_type = "NONE";		// Ex: End, Start

public:
	Action();
	Action(const std::string& name, const std::string& type);

	const std::string& actionName() const;
	const std::string& actionType() const;
};
