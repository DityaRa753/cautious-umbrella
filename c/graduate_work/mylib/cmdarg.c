#include <stdio.h>
#include "string_compare.c"
#include "size_file.c"
// argv -> *array -> **elem
// for (int i = 0; i < argc; i++) {
//     printf("[%d]\n", argv+i);
// }
// I'm don't know how right transfer* strings...
/*
code 1 - no arguments;
code 2 - calling help;
code 3 - ...
*/
char* STR_ERR = "use --help or -h or -? for help.\n"; // shouldn't change.

// int bitcoding(char** argv) 
// {
//     if (!argv) {
//         printf("Missing arument -e [DIGIT]\n\t%s\n", STR_ERR);
//         return 1;
//     } else {
//         if (!strcmp1(argv, "1") || !strcmp1(argv, "2") || !strcmp1(argv, "4") || !strcmp1(argv, "8"))
//             return 0;
//         else {
//             printf("There is no such degree or string's has been input!\n\t%s\n", STR_ERR);
//             return 1;
//         }
//     }
// }
// possigle bug when entered message not in quotes! **********************
int cmdarg(int argc, char** argv, int* file_txt, int* ibmp, int* obmp) {
    if (argc <= 1) {
        printf("syntax err: program called with no arguments.\n\t%s \n", STR_ERR);
        return -1;
    }
    // checking first element
    if (!strcmp1(argv[1], "--help") || !strcmp1(argv[1], "-h") || !strcmp1(argv[1], "-?")) {
        printf("This is manual. There are available commands:\n"); //TODO: fill help command
        printf(" -e or --encode\t\tWrite message to .bmp.file\n");
        printf(" -d or --decode\t\tReads an encoded message from a .bmp\n");
        printf(" -M\t\t\tPath to file(.txt) with message\n");
        printf(" -m\t\t\tMessage, just a string.\n");
        printf(" -pi\t\t\tPath to input .bmp file\n");
        printf(" -po\t\t\tPath to output .bmp file\n\t\t\tAdditional argument,can be empty,\n\t\t\toutput image will be in the current\n\t\t\tdir and have name \"output.bmp\".\n");
        printf("--encode [DIGIT] -M [PATH] -p [PATH]\n");
        printf("[DIGIT] -> 1/2/4/8\tDegree protect\n");
        printf("[PATH]  -> Absolute or relative path\n");
        printf("EXAMPLE:\n-e 2 -m \"message\" -pi ~/check.bmp -po ~/dir/\tEncodes message into .bmp, with degree's power.\n");
        return -1;
    }
    else if (!strcmp1(argv[1], "-e") || !strcmp1(argv[1], "--encode")) {
        // check GIDIT
        if (!argv[2]) {
            printf("Missing [DIGIT] in key ' -e [DIGIT] ' \n\t%s\n", STR_ERR);
            return -1;
        }
        else if (strcmp1(argv[2], "1") && strcmp1(argv[2], "2") && strcmp1(argv[2], "4") && strcmp1(argv[2], "8")) {
            printf("Entered ' %s ', must be one of the following digits: 1/2/4/8.\n\t%s\n", argv[2], STR_ERR);
            return -1;
        }
        // check -m or -M argument
        char m_or_M;
        if (!argv[3]) {
            printf("Missing | -m | or | -M | argument!\n\t%s\n", STR_ERR);
            return -1;
        }
        else {
            if (!strcmp1(argv[3], "-m")) {
                if (!argv[4]) {
                    printf("Missing text message(text).\n\t%s\n", STR_ERR);
                    return -1;
                }
                else
                    m_or_M = 0;
            }
            else if (!strcmp1(argv[3], "-M")) {
                if (!argv[4]) {
                    printf("Missing path to file with text(message).\n\t%s\n", STR_ERR);
                    return -1;
                }
                else {
                    *file_txt = open(argv[4], O_RDWR);
                    // checking file for exists
                    if (*file_txt == -1) {
                        perror(argv[4]);
                        return -1;
                    }
                    else
                        m_or_M = 1;
                    // for a non-working version with FILE* -> fopen()
                    // else {
                    //     int c = getc(*file_txt) != EOF; // checking a file for directory or file
                    //     if (!c) {
                    //         printf("Is a directory. Specify path to file with text.\n");
                    //         fclose(*file_txt);
                    //         return -1;
                    //     }
                    // }
                    // I know that this is a file.
                }
            }
            else {
                printf("There ' %s ' is no such command!\n\t%s\n", argv[3], STR_ERR);
                return -1;
            }
        }
        // check input file
        if (!argv[5]) {
            printf("Missing | -pi | argument.\n\t%s\n", STR_ERR);
            return -1;
        }
        else {
            if (!strcmp1(argv[5], "-pi")) {
                if (!argv[6]) {
                    printf("Missing path to input .bmp file.\n");
                    return -1;
                }
                else {
                    // image should open in binary mode! TODO: need check mode!
                    *ibmp = open(argv[6], O_RDONLY); // use ONLY O_RDWR because it shows that it is a directory when read.
                    if (*ibmp == -1) {
                        perror(argv[6]);
                        return -1;
                    }
                    // check size file.
                    if (m_or_M) {
                        // key -M
                        if (availableSize(*argv[2] - '0', 0, *file_txt, *ibmp)) {
                            printf("Length message from file, doesn't fit wtih ' %s ' encoding. Chose another -e [DIGIT]\n\t%s\n", argv[2], STR_ERR);
                            return -1;
                        }
                    }
                    // maybe erorr if name input bmp equal output bmp!! 
                    else {
                        // key -m
                        if (availableSize(*argv[2] - '0', lenstr(argv[4]), 0, *ibmp)) {
                            printf("With this encoding ' %s ', length of the message doesn't fit into the picture. Chose another -e [DIGIT]\n\t%s\n", argv[2], STR_ERR);
                            return -1;
                        }
                    }
                    // for a non-working version with FILE* -> fopen()
                    // else {
                    //     int c = getc(*ibmp) != EOF;
                    //     if (!c) {
                    //         printf("Is a directory. Specify path to file with text.\n");
                    //         fclose(*ibmp);
                    //         return -1;
                    //     }
                    //     // I know the file exists
                    // }
                }
            }
            else {
                printf("There ' %s ' is no such argument.\n\t%s\n", argv[5], STR_ERR);
                return -1;
            }
        }
        // check output file or directory.
        if (!argv[7]) {
            *obmp = creat("output.bmp", S_IRWXU);
            // *obmp = open("output.bmp", O_RDWR | O_TRUNC, S_IRWXU); does not work, although it did work...
            if (*obmp == -1) {
                printf("Can't create 'output.bmp' file!\n");
                return -1;
            }
        }
        else {
            // means check output directory, that is not a file and it exists.
            if (!strcmp1(argv[7], "-po")) {
                if (!argv[8]) {
                    printf("Missing path to output directory.\n");
                    return -1;
                }
                else {
                    // It seems ok, I don't know how to improve this check.
                    // also binary recodring mode!
                    *obmp = creat(argv[8], S_IRWXU);
                    // *obmp = open(argv[8], O_RDWR | O_TRUNC, S_IRWXU); does not work, although it did work...
                    if (*obmp == -1) {
                        printf("Can't create '%s' file...\n", argv[8]);
                        return -1;
                        // printf("\"%s\" is a directory! You fogot to enter the file name or tried create a dir.\n", argv[8]);
                        // don't close file stream because happened segmentation fault.
                    }
                }
            }
            else {
                printf("There ' %s ' is no such argument.\n\t%s\n", argv[7], STR_ERR);
                return -1;
            }
        }
        return 1;
    }
    else if (!strcmp1(argv[1], "-d") || !strcmp1(argv[1], "--decode")) {
        return 2;
    }
    else {
        printf("No such argument!\n\t%s\n", STR_ERR);
        return -1;
    }
}


// char* a;
    // char* b;
    // a = g;
    // b = h;
    // while (*a == *b) {
    //     if (*a == 0 && *b == 0) {
    //         printf("zero equal\n");
    //     }
    //     printf("%c %c\n", *a, *b);
    //     a++;
    //     b++;
    // }
// if (argc <= 1) {
//         printf("syntax : \n\t%s --help or \n\t./p --add [a] [b]\n", argv[0]);
//         return 0;
//     }
//     if (!strcmp(argv[1], "--help")) {/*  */
//         printf("You requested help message.\n");
//     }
//     else if (!strcmp(argv[1], "--add")) {
//         if (argc <= 3) {
//             printf("'--add' operation request two parameters.\n");
//         }
//         else {
//             int a, b;
//             if (sscanf(argv[2], "%d", &a) != 1 || sscanf(argv[3], "%d", &b) != 1) {
//                 printf("'--add' operation request two integer parameters.\n");
//             }
//             else {
//                 printf("%d + %d = %d\n", a, b, a + b);
//             }
//         }
//     }
//     else {
//         printf("Unknown parameters: '%s'. Type %s --help for help.\n", argv[1], argv[0]);
//     }
