#ifndef YOPAAT_H
#define YOPAAT_H
#define	ERR_NULL (-1)
#define ERR_INCORRECT_FILE (-2)
#define ERR_NO_FILE (-3)
#define ERR_UNEXPECTED_SYNTAX (-4)

#include <stdbool.h>
#include <argp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/queue.h>

const char *argp_program_version = "yopaat 0.1.4-a";
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

typedef struct style
{
    char *name;
    enum { ELEMENT, ID, CLASS } declaration_type;
    LIST_ENTRY(style) pointer;

    char *styles[];
} style;

typedef struct style_list
{
    style style;
    LIST_ENTRY(style_list) pointer;
} style_list;

enum { DEC_TYPE, SELECTOR, DECLARATION } css_section;

int main(int argc, char* argv[]);
static error_t parse_opt(int key, char *arg, struct argp_state *state);
int validate_args(struct arguments *arguments);
FILE* open_file(char *file_dir);
int close_file(FILE *file);
int analyse_css(char *file_dir, style_list *style_list);
char* read_file(FILE *file);
void append(char* s, char c);


#endif
