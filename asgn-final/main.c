#include "tree.h"
#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>

/* This method will print out a word with its respective frequency to present */
static void  print_info(int freq, char *word) {
    printf("%-4d %s\n", freq, word);
}

/* This is our main function which creates a new tree defaulted to 
   binary search trees, by default strings are read in from stdin and added to the tree before being printed out alongside their frequencies to stdout.
   Commands are available for the user to specify and do other things to the program. This function will deallocate all memory before finishing.
   @param argc : number of command line arguments.
   @param argv: an array of strings that holds the command line arguments.
   @return: the exit status of the program, either EXIT_SUCCESS or EXIT FALIURE

*/
int main(int argc, char **argv) {
    char in[256];
    FILE *fp = NULL, *fp2 = NULL;
    char option;
    const char *optstring = "c:df:orh";
    int cflag = 0, dflag = 0, oflag = 0, rflag = 0, fflag = 0;
    clock_t start1, end1, start2, end2;
    int unknown = 0;
    tree b ;

    

    /* switch statement processes command line arguments*/
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'c':
                cflag = 1;
                if (NULL == (fp = fopen(optarg, "r"))) {
                    fprintf(stderr, "%s: can’t find file %s\n", argv[0], argv[optind]);
                    return EXIT_FAILURE;
                }
                dflag = -1;
                oflag = -1;
                break;
            case 'd':
                if (dflag != -1) {
                    dflag = 1;
                }
                break;
            case 'f':
                fflag = 1;
                if (NULL == (fp2 = fopen(optarg, "w"))) {
                    fprintf(stderr, "%s: can’t find file %s\n", argv[0], argv[optind]);
                    return EXIT_FAILURE;
                }
                break;
                
            case 'o':
                if (oflag != -1) {
                    oflag = 1;
                }
                break;
            case 'r':
                rflag = 1;
                break;
            case 'h':
                printf("Usage: ./sample-asgn [OPTION]... <STDIN>\n\n");
                printf("Perform various operations using a binary tree.  By default, words\n");
                printf("are read from stdin and added to the tree, before being printed out\n");
                printf("alongside their frequencies to stdout.\n\n");
                printf(" -c FILENAME  Check spelling of words in FILENAME using words\n");
                printf("              read from stdin as the dictionary.  Print timing\n");
                printf("              info & unknown words to stderr (ignore -d & -o)\n");
                printf(" -d           Only print the tree depth (ignore -o)\n");
                printf(" -f FILENAME  Write DOT output to FILENAME (if -o given)\n");
                printf(" -o           Output the tree in DOT form to file 'tree-view.dot'\n");
                printf(" -r           Make the tree an RBT (the default is a BST)\n\n");
                printf(" -h           Print this message\n");
                return EXIT_SUCCESS;
                break;
            default:
                return EXIT_FAILURE;
                break;
        }
    }
    
    start1 = clock();
    if(rflag == 1){
        b = tree_new(BST);
    } else {
        b = tree_new(RBT);
    }
    tree_colour_flip(b);
    /* reads in inputs from standard in as words*/
    while (getword(in, sizeof in, stdin) != EOF) {
        b = tree_insert(b, in);
    }
    end1 = clock();
    
    /* If the -c augment is passed, the following if sequence is followed. Since d and o flags are dependent on it, the appear in an else if*/
    start2 = clock();
    if(cflag == 1){
        while (getword(in, sizeof in, fp) != EOF) {
            if (tree_search(b, in) == 0){
                fprintf(stdout, "%2s\n", in);
                unknown += 1;
            }
        }
        end2 = clock();
        fprintf(stderr, "Fill Time: %f\n", (end1 - start1) / (double) CLOCKS_PER_SEC);
        fprintf(stderr, "Search Time: %f\n", (end2 - start2) / (double) CLOCKS_PER_SEC);
        fprintf(stderr, "Unknown words: %d\n", unknown);
    }
    else if (dflag == 1 || oflag == 1) {
        if (dflag == 1) {
            fprintf(stdout, "%d\n", tree_depth(b));
        }
        if (oflag == 1 && fflag == 0) {
            fp2 = fopen("tree_view.dot", "w");
            tree_output_dot(b, fp2);
            fclose(fp2);
        } else if(oflag == 1 && fflag == 1){
            tree_output_dot(b, fp2);
            fclose(fp2);
        }
    } else {
        tree_preorder(b, print_info);
    }
    tree_free(b);

    if(fp != NULL){
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
