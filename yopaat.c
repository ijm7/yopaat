#include "yopaat.h"

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char* argv[])
{
    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    analyse_css(arguments.args[0]);
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

FILE* open_file(char *file_dir)
{
    FILE *file;
    file = fopen(file_dir, "a+");
    return file;
}

int close_file(FILE *file)
{
    return fclose(file);
}

int analyse_css(char *file_dir)
{
    // Check if the file is of type CSS.
    if (strlen(file_dir) < 5 || strcmp(&(file_dir[strlen(file_dir) - 4]), ".css") != 0)
    {
        printf("Bad file, does not contain CSS\n");
        return ERR_INCORRECT_FILE;
    }
    else
    {
        printf("CSS file found!\n");
        printf("Analysing...\n");
    }

    FILE* css_file = open_file(file_dir);
    char input[1000];
    read_file(css_file, input);
    /*int c;
    css_section = SELECTOR;
    if (css_file)
    {
        while ((c = getc(css_file)) != EOF)
        {
            switch (css_section)
            {
                case SELECTOR:
                printf("BRACKET FOUND");
                break;
                case DECLARATION:
                break;
            }
            putchar(c);
        }
        fclose(css_file);
    }*/
    return 0;
}

char* read_file(FILE *file, char* input)
{
    long c;
    fseek(file, 0, SEEK_END);
    int inputsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            strncat(input, (char*)c, 1000);
            printf("%s", input);
        }
        fclose(file);
    }
    return input;
}
