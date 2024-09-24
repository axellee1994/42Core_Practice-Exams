#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell*> spells;
        SpellBook(const SpellBook &src);
        SpellBook& operator=(const SpellBook &rhs);
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string &spellName);
        ASpell* createSpell(const std::string &spellName);
};

#endif