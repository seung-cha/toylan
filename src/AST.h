#ifndef AST_H
#define AST_H

// Expressions
#include "ast/expr/expr.h"
#include "ast/expr/binary_expr.h"
#include "ast/expr/unary_expr.h"
#include "ast/expr/int_expr.h"
#include "ast/expr/real_expr.h"
#include "ast/expr/bool_expr.h"
#include "ast/expr/string_expr.h"

// Statements
#include "ast/stmt/stmt.h"

// Literals
#include "ast/literal/literal.h"
#include "ast/literal/int_literal.h"
#include "ast/literal/real_literal.h"
#include "ast/literal/string_literal.h"
#include "ast/literal/bool_literal.h"

// Types
#include "ast/type/type.h"
#include "ast/type/int_type.h"
#include "ast/type/real_type.h"
#include "ast/type/string_type.h"
#include "ast/type/bool_type.h"
#include "ast/type/void_type.h"

// Operators
#include "ast/op/operator.h"
#include "ast/op/assign_op.h"
#include "ast/op/add_op.h"
#include "ast/op/sub_op.h"
#include "ast/op/div_op.h"
#include "ast/op/mul_op.h"
#include "ast/op/mod_op.h"
#include "ast/op/post_unary_add_op.h"
#include "ast/op/post_unary_sub_op.h"
#include "ast/op/pre_unary_add_op.h"
#include "ast/op/post_unary_sub_op.h"

// Identifier
#include "ast/identifier.h"
#endif