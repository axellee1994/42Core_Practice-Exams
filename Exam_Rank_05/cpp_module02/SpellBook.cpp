#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::SpellBook(const SpellBook &src)
{
	*this = src;
}

SpellBook &SpellBook::operator=(const SpellBook &rhs)
{
	if (this != &rhs)
	{
		spells = rhs.spells;
	}
	return *this;
}

SpellBook::~SpellBook()
{
	for(std::map < std::string, ASpell *>::iterator it=spells.begin(); it != spells.end(); ++it)
	{
		delete it->second;
	}
	spells.clear();
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (spells.find(spell->getName()) == spells.end())
		{
			spells[spell->getName()] = spell->clone();
		}
	}
}

void	SpellBook::forgetSpell(std::string const &SpellName)
{
	std::map < std::string, ASpell *>::iterator it = spells.find(SpellName);
	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}

ASpell	*SpellBook::createSpell(std::string const &SpellName)
{
	std::map < std::string, ASpell *>::iterator it = spells.find(SpellName);
	if (it != spells.end())
	{
		return it->second->clone();
	}
	return NULL;
};	
