#ifndef AST_ARG_LIST_H
#define AST_ARG_LIST_H

#include "list.h"
#include "arg.h"
#include <memory>

namespace ASTs
{
    class ArgList : public List
    {
        public:
        ArgList(Arg *arg, ArgList *next) : arg{arg}, next{next}
        {

        }
        
        std::unique_ptr<Arg> arg;
        std::unique_ptr<ArgList> next;
        

    };
}

#endif