#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		SpellBook spellBook;
		Warlock();
		Warlock(const Warlock &src);
		Warlock&operator=(const Warlock &rhs);
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const	std::string &getName() const;
		const	std::string &getTitle() const;

		void	setTitle(const std::string &title);
		void	introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, ATarget const &target);
};
#endif
