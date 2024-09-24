#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>
# include <string>
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		std::map < std::string, ASpell *> SpellBook;
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
		void	forgetSpell(std::string SpellName);
		void	launchSpell(std::string SpellName, ATarget const &target);
};
#endif
