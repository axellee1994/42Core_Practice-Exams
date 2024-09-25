#pragma once
#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include "ASpell.hpp"
# include <iostream>
# include <map>
# include <string>

class ASpell;

class SpellBook
{
	private:
		std::map < std::string, ASpell *> spells;
		SpellBook(const SpellBook &src);
		SpellBook&operator=(const SpellBook &rhs);
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spellName);
		ASpell *createSpell(std::string const &spellName);
};
#endif
