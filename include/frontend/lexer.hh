#ifndef LEXER_HH
#define LEXER_HH

#include <string>
#include <vector>

namespace frontend {
    struct lexer
    {
        std::vector<std::string> tokens;

        lexer(std::string const& input);
        ~lexer() = default;
    };
}

#endif // LEXER_HH