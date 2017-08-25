#ifndef PARSER_H
#define PARSER_H
#define	ERR_NULL (-1)

#include <stdbool.h>
#include <argp.h>
#include <stdio.h>


const char *argp_program_version = "yopaat 0.1.3-a";
const char *argp_program_bug_address = "<https://github.com/ijm7/yopaat/issues>";
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

int main(int argc, char* argv[]);
static error_t parse_opt(int key, char *arg, struct argp_state *state);
int validate_args(struct arguments *arguments);
FILE* open_file(char* file_dir);
int close_file(FILE* file);


#endif
