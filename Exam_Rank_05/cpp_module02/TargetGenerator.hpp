#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <iostream>
# include <string>
# include <map>

class ATarget;

class TargetGenerator
{
	private:
		std::map < std::string, ATarget *> targets;
		TargetGenerator(const TargetGenerator &src);
		TargetGenerator&operator=(const TargetGenerator &rhs);
	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *type);
		void	forgetTargetType(std::string const &type);
		ATarget	*createTarget(std::string const &type);
};
#endif
