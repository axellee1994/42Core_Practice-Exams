#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}


TargetGenerator::~TargetGenerator()
{
	for (std::map < std::string, ATarget *>::iterator it=targets.begin(); it != targets.end(); ++it)
	{
		delete it->second;
	}
	targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *type)
{
	if (type)
	{
		if (targets.find(type->getType()) == targets.end())
		{
			targets[type->getType()] = type->clone();
		}
	}
}

void	TargetGenerator::forgetTargetType(std::string const &type)
{
	std::map < std::string, ATarget *>::iterator it=targets.find(type);
	if (it != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}

ATarget	*TargetGenerator::createTarget(std::string const &type)
{
	std::map < std::string, ATarget *>::iterator it=targets.find(type);
	if (it != targets.end())
	{
		return (it->second->clone());
	}
	return NULL;
}
