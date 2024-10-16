#include <iostream>
#include <cassert>
#include <string.h>
#include "scanner.h"
#include "lexer.h"
#include "lexemes.h"
#include "parser.h"


int main(int argc, char** argv)
{
    if(argc <= 1)
    {
        std::cout << "Usage: " << argv[0] << " [source_file] --flags" << std::endl;
        std::cout << "Type --help or -h for more detail." << std::endl;
        return EXIT_SUCCESS;
    }

    bool lexer_verbose = false;
    bool lexer_no_err = false;
    bool parser_no_err = false;
    bool draw_ast = false;

    for(int i = 0; i < argc; i++)
    {
        char const* str = argv[i];
        // Print help
        if(strcmp(str, "--help") == 0 || strcmp(str, "-h") == 0)
        {
            std::cout << "\n\nUsage: " << argv[0] << 
            " [source_file] --flags\n" 
            "--flags can be any of the following:\n\n"
            "--lexer-verbose    Print lexemes obtained by lexer\n"
            "--lexer-no-err           Fail on obtaining error lexeme\n"
            "--parser-no-err       Fail if source file is syntactically ill-formed\n"
            "--ast          Print Abstract Syntax Tree"<< std::endl;

            return EXIT_SUCCESS;
        }

        if(strcmp(str, "--lexer-verbose") == 0)
        {
            lexer_verbose = true;
        }
        else if(strcmp(str, "--lexer-no-err") == 0)
        {
            lexer_no_err = true;
        }
        else if(strcmp(str, "--parser-no-err") == 0)
        {
            parser_no_err = true;
        }
        else if(strcmp(str, "--ast") == 0)
        {
            draw_ast = true;
        }
    }

    Scanner scanner{argv[1]};

    if(!scanner.IsReady())
    {
        std::cout << "Scanner failed to open the file. Perhaps it is invalid?" << std::endl;
        return EXIT_FAILURE;
    }


    Lexer lexer{&scanner};
    Lexicons::Lexicon* lex = nullptr;

    if(lexer_verbose)
    {
        lexer.Verbose();
    }

    if(lexer_no_err)
    {
        const auto lexemes = lexer.Lexemes();

        for(auto& lexeme : lexemes)
        {
            if(lexeme->Id == Lexicons::Lexicon::ERR)
            {
                std::cout << "Error lexeme detected!" << std::endl;
                std::cout << lexeme->Verbose() << std::endl;
                return EXIT_FAILURE;
            }
        }
    }


    Parser parser{&lexer};

    for(const auto& str : parser.ErrorMsgs())
    {
        std::cout << str << std::endl;
    }

    if(parser_no_err && parser.ErrorMsgs().size() > 0)
    {
        return EXIT_FAILURE;
    }

    if(draw_ast)
    {
        parser.program->Print(0);   
    }


    return EXIT_SUCCESS;
}