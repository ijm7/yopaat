#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <argp.h>

const char *argp_program_version = "yopaat 0.1.1-a";
const char *argp_program_bug_address = "<https://github.com/ijm7/inline-style-parser/issues>";
static char doc[] = "Tool for parsing inline HTML styles into CSS classes.";
static char args_doc[] = "[INPUT] [OUTPUT]";
static struct argp_option options[] =
{
    { "default", 'd', 0, 0, "Default operation."},
    { 0 }
};

struct arguments
{
    enum { DEFAULT } mode;
    char *args[2];
};

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

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char* argv[]);

#endif
