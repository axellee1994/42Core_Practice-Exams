#include "ATarget.hpp"

ATarget::ATarget(const std::string type) : type(type)
{
}

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget	&ATarget::operator=(const ATarget &rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

ATarget::~ATarget()
{
}

const	std::string &ATarget::getType()const
{
	return this->type;
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}


