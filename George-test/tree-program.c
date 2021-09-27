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
			printf("--Here is a help guide-- \n");
			printf("------------------------------------------------------------------------------------------------\n");
			printf("Please use command line arguments to operate program: \n");
			printf("Syntax for usage: ./asgn1 [OPTION]... <STDIN> \n \n");
            printf("-c FILENAME  checks spelling of words in file while printing timing and unknown information \n");
            printf("             this function cannot be used alongisde other arguments \n");
			printf("-d           strictly prints the depth of the tree to stdout \n");
			printf("-f FILENAME  write the dot output to file name instead of the default filename if -o is given \n");
            printf("-o           outputs a representation of the tree in dot form to the file 'tree-view.dot' \n");
			printf("-r           make the data structure a red black tree instead of a binary search tree\n");
			printf("-h           displays this message \n");
			printf("----------------------------------------------------------------------------------------------\n");
			exit(0);
			break;

			default :
			printf("\n --An error occured-- \n please use -h in the command line for help \n ");
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
    printf("Depth of tree is: %d\n", this_tree_depth);
}

/* -f argument */
if(dot_out_filename == 1 && output == 1){
    tree_output_dot_aux(t, unique_dotfile);
    tree_output_dot(t, unique_dotfile);
    fclose(unique_dotfile);
}
/* -o argument */
else if(output == 1 && dot_out_filename == 0){
    dotfile = fopen("tree-view.dot", "w");
    tree_output_dot_aux(t,dotfile); 
    tree_output_dot(t,dotfile);
    fclose(dotfile);
}

/* deallocation of asigned memory */
    tree_free(t);
    return EXIT_SUCCESS;
}
