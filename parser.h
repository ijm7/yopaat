#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <argp.h>

const char *argp_program_version = "inline-style-parser in-dev";
const char *argp_program_bug_address = "<https://github.com/ijm7/inline-style-parser/issues>";
static char doc[] = "Tool for parsing inline HTML styles into CSS classes.";
static char args_doc[] = "inline-style-parser [-OPTIONS] [INPUT] [OUTPUT]";
static struct argp_option options[] = {
    { "default", 'd', 0, 0, "Default operation."},
    { "word", 'w', 0, 0, "Compare words instead of characters."},
    { "nocase", 'i', 0, 0, "Compare case insensitive instead of case sensitive."},
    { 0 }
};

struct arguments {
    enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode;
    bool isCaseInsensitive;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    lineswitch (key) {
    case 'l': arguments->mode = LINE_MODE; break;
    case 'w': arguments->mode = WORD_MODE; break;
    case 'i': arguments->isCaseInsensitive = true; break;
    case ARGP_KEY_ARG: return 0;
    default: return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, const char* argv[]);

#endif
