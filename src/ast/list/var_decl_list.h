#ifndef AST_VAR_DECL_LIST_H
#define AST_VAR_DECL_LIST_H

#include "list.h"
#include "../expr/expr.h"
#include "../identifier.h"
#include <memory>

namespace ASTs
{
    class VarDeclList : public List
    {
        public:
        VarDeclList(Expr *expr, List *next) : expr{expr}, next{next}
        {

        }

        void Visit(Visitor *visitor) override
        {
            visitor->VisitVarDeclList(this);
        }

        void Print(int ident) override
        {
            PrintIdent(ident);
            std::cout << "<Variable Declaration List>" << std::endl;
            expr->Print(ident + 1);
            next->Print(ident); 
        }

        std::unique_ptr<Expr> expr;
        std::unique_ptr<List> next;
    };
}

#endif