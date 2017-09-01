#include "yopaat.h"

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char* argv[])
{
    struct arguments arguments;
    style_list style_list;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    analyse_css(arguments.args[0], &style_list);
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

int analyse_css(char *file_dir, style_list *style_list)
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
    char * output = read_file(css_file); //MALLOC RETURN HERE, REMEMBER TO FREE
    css_section = DEC_TYPE;
    if (output)
    {
        unsigned i = 0;
        while(output[i] != '\0')
        {
            //I think it would be a good idea to make factory methods here for producing a certain type.
            //Or maybe send to method that can iterate entirely over reference to style and then return int with where we finished?
            //I think that is potentially the best idea!
            i++;
            switch (css_section)
            {
                case DEC_TYPE:
                if (output[i] == '#')
                {
                    style id;
                    id.name = "test\0";
                    printf("%s", id.name);
                }
                else if (output[i] == '.')
                {

                }
                else if (isalnum(output[i]) != 0)
                {

                }
                else
                {
                    return ERR_UNEXPECTED_SYNTAX;
                }
                break;
                case SELECTOR:
                break;
                case DECLARATION:
                break;
            }
        }
    }
    free(output);
    return 0;
}

char* read_file(FILE *file)
{
    int c;
    fseek(file, 0, SEEK_END);
    int inputsize = ftell(file);
    char * input = malloc(inputsize);
    fseek(file, 0, SEEK_SET);
    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            append(input, c);
        }
        printf("%s", input);
        fclose(file);
    }
    return input;
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
