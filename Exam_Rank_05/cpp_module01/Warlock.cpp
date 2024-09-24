#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &src)
{
	*this = src;
}

Warlock	&Warlock::operator=(const Warlock &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return *this;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	for (std::map < std::string, ASpell *>::iterator it=SpellBook.begin(); it != SpellBook.end(); ++it)
	{
		delete it->second;
	}
	SpellBook.clear();
}

const	std::string &Warlock::getName() const
{
	return this->name;
}

const	std::string &Warlock::getTitle() const
{
	return this->title;
}

void	Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell  *spell)
{
	if (spell)
	{
		if (SpellBook.find(spell->getName()) == SpellBook.end())
		{
			SpellBook[spell->getName()] = spell->clone();
		}
	}
}

void	Warlock::forgetSpell(std::string SpellName)
{
	std::map < std::string, ASpell *>::iterator it=SpellBook.find(SpellName);
	if (it != SpellBook.end())
	{
		delete it->second;
		SpellBook.erase(it);
	}
}

void	Warlock::launchSpell(std::string SpellName, ATarget const &target)
{
	std::map < std::string, ASpell *>::iterator it=SpellBook.find(SpellName);
	if (it != SpellBook.end())
	{
		it->second->launch(target);
	}
}
