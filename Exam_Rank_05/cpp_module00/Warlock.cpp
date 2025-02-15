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
}


const	std::string &Warlock::getName() const
{
	return this->name;
}

const	std::string &Warlock::getTitle() const
{
	return this->title;
}

void	Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", "  << this->title << "!" << std::endl;
}
