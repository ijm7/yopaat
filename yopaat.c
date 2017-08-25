#include "yopaat.h"

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char* argv[])
{
    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    //printf ("ARG1 = %s\nARG2 = %s\n", arguments.args[0], arguments.args[1]);
    return 0;
}

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state -> input;
    switch (key)
    {
        case 'd': arguments -> mode = DEFAULT; break;
        case ARGP_KEY_ARG:
            if (state -> arg_num >= 2) { argp_usage(state); }
            arguments -> args[state -> arg_num] = arg;
            break;
        case ARGP_KEY_END:
            if (state -> arg_num < 2) { argp_usage(state); }
            break;
        default: return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

int validate_args(struct arguments *arguments)
{
    return 0;
}

FILE* open_file(char* file_dir)
{
    FILE *file;
    file = fopen(file_arg, "a+");
    return file;
}

int close_file(FILE* file)
{
    return fclose*(file);
}
