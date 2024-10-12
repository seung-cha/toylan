#ifndef AST_EXPR_STMT_H
#define AST_EXPR_STMT_H

#include "stmt.h"
#include "../expr/expr.h"
#include<memory>

namespace ASTs
{
    class ExprStmt : public Stmt
    {
        public:
        ExprStmt(Expr *expr) : expr{expr}
        {

        }

        std::unique_ptr<Expr> expr;
    };
}


#endif