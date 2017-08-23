#include "parser.h"
#include <stdbool.h>

int main(int argc, char* argv[])
{
    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    //printf ("ARG1 = %s\nARG2 = %s\n", arguments.args[0], arguments.args[1]);
    return 0;
}
