#include "lexer.hh"

frontend::lexer::lexer(std::string const& input){
    std::string token;
    for(auto c : input){
        if(c == ' '){
            if(token.size() > 0){
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token.push_back(c);
        }
    }
    if(token.size() > 0){
        tokens.push_back(token);
    }
}