#include <stdio.h>  //  printf()
#include <unistd.h> //  getopt(), the short options.
#include <stdlib.h>


#define OPTIONS "eds:"
// -e: Encrypt stdin and print it to stdout. If neither -d nor -e are given on the command line, the default is to encrypt.
// -d: Decrypt stdin and print it to stdout. If neither -d nor -e are given on the command line, the default is to encrypt.
// -s #: The amount by which the characters are shifted. Must not be less than 0 and not greater then 95.

#ifdef NOISY_DEBUG
    # define NOISY_DEBUG_PRINT fprintf(stderr, "%s %s %d\n", __FILE__, __func__, __LINE__)
#else
    # define NOISY_DEBUG_PRINT
#endif

int enc(const char * input, const int shift_by);
int dec(const char * input, const int shift_by);


int main (int argc // # of command line args (argument-count.)
    , char *argv[] // array of strings of the command line arguments.
){
    // int opts;
    // int i_opt = -1;
    // int o_opt = 0;
    // double d_opt = 0.0;
    // char s_opt[100] = "";
    int flag;
    int shift = 0;
    {
        int opt = 0;
        while((opt = getopt(argc, argv, OPTIONS)) != -1)
        {
            switch (opt)
            {
                case 'e':
                    flag = 0;
                    break;
                case 'd':
                    flag = 1;
                    break;
                case 's':
                    shift = atoi(optarg);
                    if(shift < 0 || shift > 95){
                        fprintf(stderr, "Error: shift must be between 0 and 95\n");
                        return 1;
                    }

                    break;
                default:
                    printf(stderr, "Error: unknown option %c\n", optopt);
                    return 1;
            }

        }
    }
    printf("flag=%d, shift=%d" , flag, shift);
    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

}
