#ifndef LEXER_H
#define LEXER_H

#include "vector.h"
#include <stddef.h>

typedef enum
{
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_STRING_LITERAL,
    TOKEN_SYMBOL,
    TOKEN_UNKNOWN
} TokenType;

typedef enum
{
    STATE_DEFAULT,
    STATE_IDENTIFIER,
    STATE_STRING,
    STATE_COMMENT_SINGLE,
    STATE_COMMENT_MULTI
}LexerState;

typedef struct
{
    char *text;
    TokenType type;
    int line_number;
}TokenRecord;

void scan_file(const char *file_path, struct vector *token_vector);

#endif