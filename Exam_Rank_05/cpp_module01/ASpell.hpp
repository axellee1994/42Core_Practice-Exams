#pragma once
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include "ATarget.hpp"
# include <iostream>
# include <string>

class ATarget;

class ASpell
{
	protected:
		std::string	name;
		std::string	effects;
	public:
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &src);
		ASpell&operator=(const ASpell &rhs);
		virtual ~ASpell();

		const	std::string &getName() const;
		const	std::string &getEffects() const;

		virtual ASpell *clone() const = 0;
		void	launch(ATarget const &target) const;
};
#endif
