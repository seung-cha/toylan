#ifndef LEXER_COMP_NUMBER_H
#define LEXER_COMP_NUMBER_H

#include <sstream>
#include "lexer_component.h"
#include "cctype"

namespace LexerComponents
{
    /**
     * Handle int or real
     */
    class NumberComponent : public LexerComponent
    {
        Lexicons::Lexicon *GetLexicon(Scanner* scanner) override
        {
            if(!isdigit(scanner->currentChar))
            {
                CHAIN_RETURN;
            }

            std::ostringstream ss;
            lineNo = scanner->lineNo;
            charNo = scanner->charNo;
            
            while(isdigit(scanner->currentChar))
            {
                ss << scanner->currentChar;
                scanner->Seek();
            }

            int32_t value = static_cast<int32_t>(std::stoi(ss.str()));
            return new Lexicons::Int(value, lineNo, charNo);
        }

    };


}


#endif