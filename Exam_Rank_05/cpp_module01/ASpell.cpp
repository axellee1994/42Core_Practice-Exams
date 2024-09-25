#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : name(name), effects(effects)
{
}

ASpell::ASpell(const ASpell &src)
{
	*this = src;
}

ASpell	&ASpell::operator=(const ASpell &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->effects = rhs.effects;
	}
	return *this;
}

ASpell::~ASpell()
{
}

const	std::string &ASpell::getName() const
{
	return this->name;
}

const	std::string &ASpell::getEffects() const
{
	return this->effects;
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}
