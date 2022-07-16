/*
CLI to create and delete files

COMMANDS:

new <file list> - creates the files given
delete <file list> - delete the files given
help - show the help message

Examples of the commands

new file_1 file_2 file_3 -> creates three files
delete file_1 -> deletes one file

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// COMMANDS

void help() {
    printf("\tCreate files cli\n\n");
    printf("Try one of the next commands:\n\n");
    printf("new <file list> - creates the files given\n");
    printf("delete <file list> - delete the files given\n");
}

int main(int argc, char **argv) {
    if (argc <= 1 || strcmp(argv[1], "help") == 0) {
        help();
        return 0;
    }
    
    if (strcmp(argv[1], "new") == 0 && argc > 2) {
        for (int i = 2; i < argc; i++) {
            printf("Files to create: %s\n", argv[i]);
            FILE *file = fopen(argv[i], "w");
            fclose(file);

        }
        return 0;
    }

    if (strcmp(argv[1], "delete") == 0 && argc > 2) {
        printf("Deleting files...\n");
        for (int i = 2; i < argc; i++) {
            printf("Files to delete: %s\n", argv[i]);
            if (remove(argv[i]) != 0) {
                printf("Error deleting the file: %s\n", argv[i]);
            } else {
                printf("File %s sucessfully deleted\n", argv[i]);
            }
        }
    }
}