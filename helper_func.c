#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>
int file_validation(char *str)
{
    if (strstr(str, ".c") == NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}

int is_operator(char ch)
{
    for (int i = 0; i < 14; i++)
    {
        if (ch == operators[i])
        {
            return i + SUCCESS;
        }
    }
    return FAILURE;
}

int is_symbol(char ch)
{
    for (int i = 0; i < 9 - 1; i++)
    {
        if (ch == symbols[i])
        {
            return SUCCESS + i;
        }
    }
    return FAILURE;
}

int tokenize(char *str)
{
    int length = 0;
    int temp = 0;
    for (int i = 0; str[i]; i++)
    {   if(str[i]=='#')
        {
            while (str[i] && str[i] != '\n')
            {
                i++;
                length++;
            }
            word_is(str + (i - length), length);
        }
        else if (temp=is_operator(str[i]))
        {
            word_is(str + (i - length), length);
            printf("%-5c : %s Operator\n", str[i], operators_names[temp - 1]);
            length = 0;
        }
        else if (temp=is_symbol(str[i]))
        {
            word_is(str + (i - length), length);
            printf("%-5c : %s symbol\n", str[i], symbols_names[temp - 1]);
            length = 0;
        }
        else if (str[i] == ' ' || str[i]=='\n')
        {
            word_is(str + (i - length), length);
            length = 0;
        }
        else
        {
            length++;
        }
    }
    if (length > 0)
    {
        word_is(str + (strlen(str) - length), length);
    }
}

int is_reserved_keyword(char *str)
{
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(res_keyword_data[i], str) == 0)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}

int is_reserved_keyword_non_data(char *str)
{
    for (int i = 0; i < 14; i++)
    {
        if (strcmp(res_keyword_non_data[i], str) == 0)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}

int is_integer_constant(char *str)
{
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
        {
            return FAILURE;
        }
        str++;
    }
    return SUCCESS;
}

int is_valid_identifier(char *str)
{
    if (str[0] >= '0' && str[0] <= '9')
    {
        return FAILURE;
    }
    for (int i = 0; str[i]; i++)
    {
        if (is_operator(str[i]))
        {
            return FAILURE;
        }
        else if (is_symbol(str[i]))
        {
            return FAILURE;
        }
        else if (str[i] == '@' || str[i] == '?' || str[i] == '$')
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}

int is_real_constant(char *str, int n)
{
    int count = 0;
    int dot_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
        else if (str[i] == '.')
        {
            dot_count++;
            if (count > 0)
                count = 0;
            else
                return FAILURE;
        }
        else
        {
            return FAILURE;
        }
    }
    return count > 0 && dot_count == 1 ? SUCCESS : FAILURE;
}

int is_string_literal(char *str,int n)
{
    if(str[0]=='"' && str[n-1]=='"')
    {
        return SUCCESS;
    }
    return FAILURE;
}

int is_char_constant(char *str,int n)
{
    if(n==3)
    {
        if(str[0]==39 && str[2]==39)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}
void word_is(char *str1, int n)
{
    if (n == 0)
    {
        return;
    }

    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++)
    {
        str[i] = str1[i];
    }
    str[n] = '\0';
    if(str[0]=='#')
    {
        printf("%-5.5s : ", str);
        printf("Pre-processor directive\n");
        return;
    }
    else if (is_reserved_keyword(str))
    {
        printf("%-5.5s : ", str);
        printf("Reserved keyword\n");
        return;
    }
    else if (is_reserved_keyword_non_data(str))
    {
        printf("%-5.5s : ", str);
        printf("Reserved keyword Non data\n");
        return;
    }
    else if (is_integer_constant(str))
    {
        printf("%-5.5s : ", str);
        printf("%s\n", "Integral constant");
    }
    else if ( is_real_constant(str, n))
    {
        printf("%-5.5s : ", str);
        printf("%s\n", "Real(Float) constant");
    }
    else if (is_string_literal(str,n))
    {
        printf("%-5.5s : ", str);
        printf("%s\n", "String literal");
    }
    else if ( is_char_constant(str,n))
    {
        printf("%-5.5s : ", str);
        printf("%s\n", "Character constant");
    }
    else
    {
        if (is_valid_identifier(str))
        {
            printf("%-5.5s : ", str);
            printf("Identifier\n");
        }
        else
        {
            printf("%-5.5s : ", str);
            printf(" Not A valid Identifier\n");
        }
    }
}
