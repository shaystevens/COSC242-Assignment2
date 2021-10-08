/**
 * asgn2.c
 *
 * PURPOSE - The main file, uses a tree to perform a number of tasks. By
 * default, words are read from stdin and added to your tree before being
 * printed out alongside their frequencies to stdout.
 *
 * AUTHORS - Madison Wong, George Churton, Shay Stevens
 */

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mylib.h"
#include "tree.h"

/**
 * Prints out the keys/words and how many times they were input into the tree.
 *
 * @param freq - int, how many times a key/word were put into the tree.
 * @param word - char *, the words inputted into the tree.
 */
static void print_info(int freq, char *word) {
    printf("%-4d %s\n", freq, word);
}

/**
 * Prints out a helpful messsage on what the program does, showing what
 * arguments you can enter in the command line and what they do.
 *
 * @param x - int, to determine if help message called due to -h option given
 * or because invalid option given.
 */
static void help_message(int x){
    if(x == 0){
        fprintf(stdout, "Usage: ./asgn2 [OPTION]... <STDIN>\n\n");
        fprintf(stdout, "Perform various operations using a binary tree.  "
                "By default, words\n");
        fprintf(stdout, "are read from stdin and added to the tree, before"
                " being printed out\n");
        fprintf(stdout, "alongside their frequencies to stdout.\n\n");
        fprintf(stdout, " -c FILENAME  Check spelling of words in FILENAME"
                " using words\n");
        fprintf(stdout, "              read from stdin as the dictionary."
                "  Print timing\n");
        fprintf(stdout, "              info & unknown words to stderr "
                "(ignore -d & -o)\n");
        fprintf(stdout, " -d           Only print the tree depth"
                " (ignore -o)\n");
        fprintf(stdout, " -f FILENAME  Write DOT output to FILENAME (if -o "
                "given)\n");
        fprintf(stdout, " -o           Output the tree in DOT form to file"
                " 'tree-view.dot' \n");
        fprintf(stdout, " -r           Make the tree an RBT (the default"
                " is a BST)\n\n");
        fprintf(stdout, " -h           Print this message\n\n");
    }else{
        fprintf(stderr, "Usage: ./asgn2 [OPTION]... <STDIN>\n\n");
        fprintf(stderr, "Perform various operations using a binary tree.  "
                "By default, words\n");
        fprintf(stderr, "are read from stdin and added to the tree, before"
                " being printed out\n");
        fprintf(stderr, "alongside their frequencies to stdout.\n\n");
        fprintf(stderr, " -c FILENAME  Check spelling of words in FILENAME"
                " using words\n");
        fprintf(stderr, "              read from stdin as the dictionary."
                "  Print timing\n");
        fprintf(stderr, "              info & unknown words to stderr "
                "(ignore -d & -o)\n");
        fprintf(stderr, " -d           Only print the tree depth"
                " (ignore -o)\n");
        fprintf(stderr, " -f FILENAME  Write DOT output to FILENAME (if -o "
                "given)\n");
        fprintf(stderr, " -o           Output the tree in DOT form to file"
                " 'tree-view.dot' \n");
        fprintf(stderr, " -r           Make the tree an RBT (the default"
                " is a BST)\n\n");
        fprintf(stderr, " -h           Print this message\n\n");
    } 
}

/**
 * Main part of the program, which reads inputs from stdin and changes the
 * program's output. Creates a tree using tree type (default is a BST).
 *
 * @param argc - int, number of arguments.
 * @param argv - char **, the arguments.
 *
 * @return int, EXIT_SUCCESS if program is successful, or EXIT_FAILURE.
 */
int main(int argc, char **argv){

    /* Initialising and declaring variables */
    tree t;
    int unknown_words = 0;
    clock_t fillStart, fillEnd, searchStart, searchEnd;
    double fillTime, searchTime;
    char word[256];
    const char *optstring = "dorhf:c:";

    FILE *filename = NULL;
    FILE *dotfile;
    
    /* Used to store which options were given on the command line */
    int option = 0;
    int print_depth_flag = 0;
    int check_file = 0;
    int output = 0;
    int this_tree_depth;
    char *changed_dotfile_name = "";
    
    static type_t tree_type = BST;

    /* Use getopt to get arguments from the command line */
    if (argc > 0){
        while ((option = getopt(argc, argv, optstring)) != EOF) {
            switch (option) {
                case 'c':
                    if(NULL == (filename = fopen(optarg, "r"))){
                        fprintf(stderr, "Can't open file '%s' using mode r.\n", optarg);
                        return EXIT_FAILURE;
                    }
                    check_file = 1;
                    break;

                case 'd': 
                    print_depth_flag = 1;
                    break;

                case 'f':                   
                    /* dot_out_filename = 1;*/
                    changed_dotfile_name = optarg;
                    break;

                case 'o':
                    output = 1;
                    break;	

                case 'r':
                    tree_type = RBT;
                    break;

                case 'h':
                    help_message(0);
                    return EXIT_SUCCESS;
                    break;

                default:
                    help_message(1);
                    return EXIT_SUCCESS;
                    break;
            }
        }
    }

    t = tree_new(tree_type);

    fillStart = clock();
    /*fill work*/
    while (getword(word, sizeof word, stdin) != EOF){
        t = tree_insert(t, word);
    }
    fillEnd = clock();

    /* -c argument */
    if(check_file == 1){
        searchStart = clock();       
        /*search work*/
        while (getword(word, sizeof word, filename) != EOF){
            if(tree_search(t, word) != 1){
                unknown_words++;
                fprintf(stdout, "%s\n", word);
            }
        }
        searchEnd = clock();
        /* Print results int a table to stderr */
        fillTime = ((double) (fillEnd -  fillStart))/CLOCKS_PER_SEC;
        searchTime = ((double) (searchEnd - searchStart))/CLOCKS_PER_SEC;
        fprintf(stderr, "Fill time     : %f\n", fillTime);
        fprintf(stderr, "Search time   : %f\n", searchTime);
        fprintf(stderr, "Unknown words = %d\n", unknown_words);
    }

    /* -d argument */
    else if(print_depth_flag == 1){
        this_tree_depth = tree_depth(t);
        fprintf(stdout, "%d\n", this_tree_depth);
    } 
       
    /* -o argument */
    else if(output == 1){
        if (strcmp(changed_dotfile_name, "") != 0){
            /* -f argument */
            dotfile = fopen(changed_dotfile_name, "w");
            fprintf(stdout, "Creating dot file '%s'\n", changed_dotfile_name);
        } else {
            /* Without -f argument */
            dotfile = fopen("tree-view.dot", "w");
            fprintf(stdout, "Creating dot file 'tree-view.dot'\n");            
        }
        tree_output_dot(t, dotfile);
        fclose(dotfile);
    }

    /* Normal printing of tree with frequencies */
    else {
        tree_preorder(t, print_info);
    }

    /* Deallocation of assigned memory */
    tree_free(t);
    return EXIT_SUCCESS;
}
