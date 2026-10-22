#define FAILURE 0
#define SUCCESS 1

static char *res_keyword_data[] = {"const", "volatile", "auto", "static", "int", "register", "extern",
                                   "unsigned", "short", "long", "long long", "float", "struct",
                                   "enum", "union", "void", "typedef", "char","double","signed"};

static char *res_keyword_non_data[] = {"continue", "switch", "break", "case", "for", "while", "do", "goto",
                                       "default", "if", "else if", "else", "sizeof","return"};

static char operators[] = {'+', '-', '*', '/', '%', '~', '!', '&', '|', '^', '<', '>', '=', '\0'};
static char operators_names[14][15] = {
    "Addition",
    "subtraction",
    "multiplicat",
    "division",
    "modulas",
    "bitwise Not",
    "logical not",
    "bitwise and",
    "bitwise or",
    "bitwise xor",
    "Relational",
    "Relational",
    "Assignment",
};

static char symbols[] = {'{', '}', '[', ']', '(', ')', ':', ';', '\0'};
static char symbols_names[8][19] = {"open curly ", "close curly", "open square","close square","open round brace","close round brace","colon","semicolon"};
int file_validation(char *str);
int is_operator(char ch);
int is_symbol(char ch);
int tokenize(char *str);
int is_reserved_keyword(char *str);
int is_reserved_keyword_non_data(char *str);
void word_is(char *str, int n);
int is_integer_constant(char *str);