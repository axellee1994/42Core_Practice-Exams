#pragma once
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;
	public:
		ATarget(const std::string type);
		ATarget(const ATarget &src);
		ATarget &operator=(const ATarget &rhs);
		virtual ~ATarget();

		const std::string &getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(ASpell const &spell) const;
};
#endif
