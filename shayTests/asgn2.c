#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"
#include "tree.h"

static void print_info(int freq, char *word) {
    printf("%-4d %s\n", freq, word);
}

static void help_message(int x, char **optarg){
    if(x == 0){
        fprintf(stdout, "Usage: ./asgn2 [OPTION]... <STDIN>\n\n");
        fprintf(stdout, "Perform various operations using a binary tree.  "
                + "By default, words\n");
        fprintf(stdout, "are read from stdin and added to the tree, before"
                + " being printed out\n");
        fprintf(stdout, "alongside their frequencies to stdout.\n\n");
        fprintf(stdout, " -c FILENAME  Check spelling of words in FILENAME"
                + "using words\n");
        fprintf(stdout, "              read from stdin as the dictionary."
                + "  Print timing\n");
        fprintf(stdout, " -d           Only print the tree depth"
                + " (ignore -o)\n");
        fprintf(stdout, " -f FILENAME  Write DOT output to FILENAME (if -o "
                + "given)\n");
        fprintf(stdout, " -o           outputs a representation of the tree"
                + " in dot form to the file 'tree-view.dot' \n");
        fprintf(stdout, " -r           Make the tree an RBT (the default"
                + " is a BST)\n\n");
        fprintf(stdout, " -h           print this message.\n\n");
    }else{
        fprintf(stderr, "./asgn2: inavlid option -- '%s'\n", optarg);
        fprintf(stderr, "Usage: ./asgn2 [OPTION]... <STDIN>\n\n");
        fprintf(stderr, "Perform various operations using a binary tree.  "
                + "By default, words\n");
        fprintf(stderr, "are read from stdin and added to the tree, "
                + "before being printed out\n");
        fprintf(stderr, "alongside their frequencies to stdout.\n\n");
        fprintf(stderr, " -c FILENAME  Check spelling of words in "
                + "FILENAME using words\n");
        fprintf(stderr, "              read from stdin as the dictionary.  "
                + "Print timing\n");
        fprintf(stderr, "              info & unknown words to stderr"
                + " (ignore -d & -o)\n");
        fprintf(stderr, " -d           Only print the tree depth "
                + "(ignore -o)\n");
        fprintf(stderr, " -f FILENAME  Write DOT output to FILENAME "
                + "(if -o given)\n");
        fprintf(stderr, " -o           outputs a representation of the tree "
                + "in dot form to the file 'tree-view.dot' \n");
        fprintf(stderr, " -r           Make the tree an RBT (the default "
                + "is a BST)\n\n");
        fprintf(stderr, " -h           print this message.\n\n");
    } 
}

int main(int argc, char **argv){
    /*Initialising and declearing variables */
    const char *optstring = "dorh:f:c";
    FILE *filename;
    FILE *dotfile;
    FILE *unique_dotfile;
    
    int i;
    int option = 0;
    int print_depth_flag = 0;
    int check_file = 0;
    int dot_out_filename = 0;
    int output = 0;
    int this_tree_depth;
    
    static type_t tree_type;
    tree_type = BST;
    tree t;

    /* Working with the command line through the C language getopt libary function  */
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case'c':
                check_file = 1;
                filename = fopen(optarg, "r");
                break;

            case'd': 
                print_depth_flag = 1;
                break;

            case'f':
                dot_out_filename = 1;
                unique_dotfile = fopen(optarg, "w"); 
                break;

            case'o':
                output = 1;
                break;	

            case 'r':
                tree_type = RBT;
                break;

            case 'h' :
                help_message(0);
                return EXIT_SUCCESS;
                break;

            default :
                help_message(1);
                return EXIT_FAILURE;
                break;
        }
    }

    if(check_file == 1 && print_depth_flag == 0 && output == 0){
        /* check spelling of words in filename ....*/
    }


    /* -d argument */
    if(print_depth_flag == 1){
        this_tree_depth = tree_depth(t);
        printf("%d\n", this_tree_depth);
    }

    /* -f argument */
    if(dot_out_filename == 1 && output == 1){
        tree_output_dot(t, unique_dotfile);
        fclose(unique_dotfile);
    }
    /* -o argument */
    else if(output == 1 && dot_out_filename == 0){
        dotfile = fopen("tree-view.dot", "w");
        tree_output_dot(t,dotfile);
        fclose(dotfile);
    }

    /* deallocation of asigned memory */
    tree_free(t);
    return EXIT_SUCCESS;
}
