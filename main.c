#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Function declarations
void createFile();
void readFile();
void renameFile();
void deleteFile();

//Main Program
//#################################################################
int main() {
    int looping = 0;
    do {//system("cls");
    printf("\nFILE MANAGEMENT SYSTEM\n");
    printf("------------------------\n\n### OPTIONS ###\n\n");
    printf("1 - Create a File\n2 - Read a File's Content\n3 - Rename/Edit a File\n4 - Delete a File\n5 - Exit");
    printf("\nYour choice: ");
    int user_option;
    fflush(stdin);
    scanf(" %d", &user_option);
    switch (user_option)
    {
    case 1:
        createFile();
        looping = 1;
        break;
    case 2:
        readFile();
        looping = 1;
        break;
    case 3:
        renameFile();
        looping = 1;
        break;
    case 4:
        deleteFile();
        looping = 1;
        break;
    case 5:
        printf("\n\nExiting Program... Thanks for using me ;)");
        looping = 0;
        break;
    
    default:
        printf("\n\n!!!Please enter a valid option");
        looping = 1;
        break;
    }}while (looping != 0);
    return 0;
}
//##################################################################

//Function definitions

    //###### LOOP STATUS CODES ######
    //0 - Exit code
    //1 - Whole function is looping
    //2 - Option section alone is looping (Invalid option)

//Create/Override a file
void createFile() {
    int looping = 0;
    do {
    //system("cls");
    printf("\n\nFILE CREATION  (Limited to .txt files for now)\n");
    printf("---------------------------\n\n");
    char filename[50];
    printf("Enter a filename: ");
    fflush(stdin);
    gets(filename);
    sprintf(filename, "%s.txt", filename);
    FILE *create_file = fopen(filename, "r");
    if(create_file) {
        printf("\nOops! It seems the file already exists.\nYou can either:\n\n1 - Override the File\n2 - Cancel\n\n");
        printf("Your choice: ");
        int option;
        fflush(stdin);
        do {scanf(" %d", &option);
        switch (option)
        {
        case 1:
            printf("\n\nOverriding file...");
            create_file = fopen(filename, "w");
            fprintf(create_file, "This file was created using the File Management App\nDesigned by Vince Churchill\n");
            goto add_text;
            break;
        
        case 2: 
            printf("\n\nAlright!\nAborting mission...");
            break;

        default:
            printf("\n\nPlease enter a valid option");
            break;
        }}while (option < 1 && option > 2);
    } 
    else {
        create_file = fopen(filename, "w");
        fprintf(create_file, "This file was created using the File Management App\nDesigned by Vince Churchill\n");
        fclose(create_file);
        add_text:
        printf("\n\nFile successfully created!\n\nAdd some text?\n\n1 - YES\n2 - NO\n");
        int option;
        fflush(stdin);
        do {scanf(" %d", &option);
            switch (option)
            {
            case 1:
                printf("Enter the text to be added: \n");
                char text[1000];
                fflush(stdin);
                gets(text);
                create_file = fopen(filename, "w");
                fprintf(create_file, text);
                printf("\n\nText added successfully");
                break;

            case 2:
                printf("Alright! Closing file...");
            break;
            
            default:
                break;
            }
        }while (option < 1 && option > 2);
    }
    fclose(create_file);
    printf("\nWould you like to create another file?\n\n1 - YES\n2 - NO\n\n");
    int choice;
    printf("Your choice: ");
    fflush(stdin);
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
        printf("Okey Dokey! Let's do this again.");
        looping = 1;
        break;

    case 2:
        printf("Alright! Exiting Create mode...\n\n");
        looping = 0;
        break;
    
    default:
        printf("Please enter a valid option.");
        break;
    }}
    while (looping != 0);
}

//Read the content of a file
void readFile() {
    int looping = 0;
    int option = 0;
    int BUFFER = 1000;
    char buffer[BUFFER];

    do {
    //system("cls");
    printf("\n\nREAD A FILE\n");
    printf("--------------------\n\n");
    FILE *read_file;
    char filename[50];
    printf("Enter the file name (no extension needed): ");
    fflush(stdin);
    gets(filename);
    sprintf(filename, "%s.txt", filename);
    read_file = fopen(filename, "r");

    if (read_file == NULL) {
        do {printf("\nFile not found. Please make sure you entered the right name.\n\nTry again?");
        printf("\n\n1 - YES\n2 - NO\n\nYour choice: ");
        fflush(stdin);
        scanf(" %d", &option);
        switch (option)
        {
        case 1:
            printf("\n\nGoing back...");
            looping = 1;
            break;
        case 2:
            printf("\n\nAlright! Aborting mission...");
            looping = 0;
            break;
        
        default:
            printf("Please enter a valid option");
            looping = 2;
            break;
        }}while (looping == 2);
    }
    else {
    printf("\n\nReading file contents...\n\n");
    //system("cls");
    while (fgets(buffer, BUFFER, read_file) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(read_file);
    do {printf("\n\nFile contents read successfully.\n\nRead another file?");
    printf("\n1 - YES\n2 - NO\n\nYour choice: ");
    fflush(stdin);
    scanf(" %d", &option);
    switch (option)
    {
    case 1:
        printf("\n\nAlright. Here we go again...");
        looping = 1;
        break;
    case 2:
        printf("\n\nAlright. Exiting read mode...");
        looping = 0;
        break;
    
    default:
        printf("Please enter a valid option");
        looping = 2;
        break;
    }
    }while (looping == 2);}
    }while (looping == 1);
}

//Rename or edit the contents of a file
void renameFile() {
    int looping = 0, option;
    do {printf("\n\nFILE EDITING\n");
    printf("---------------------------");
    do {printf("\n\n1 - Edit a File\n2 - Rename a File\n3 - Go to main menu\n\nYour choice: ");
    fflush(stdin);
    scanf(" %d", &option);
    switch (option)
    {
    case 1:
        printf("This functionality isn't ready yet");
        looping = 1;
        break;
    case 2:
        int inner_loop = 0;
        do {printf("\nFILE RENAMING\n---------------------------\n\n");
        printf("Enter name of File to be renamed: ");
        char filename[50], new_filename[50];
        fflush(stdin);
        scanf(" %s", &filename);
        sprintf(filename, "%s.txt", filename);
        //Check if file exists
        FILE *rename_file;
        if (rename_file = fopen(filename, "r")) {
            fclose(rename_file);
            printf("\n\nEnter new file name: ");
            fflush(stdin);
            scanf(" %s", &new_filename);
            printf("\nRenaming File...");
            sprintf(new_filename, "%s.txt", new_filename);
            rename(filename, new_filename);
            if (rename(filename, new_filename))
            {
                printf("\n\nFile successfully renamed");
                do {printf("\n\nRename another file?\n\n1 - YES\n2 - NO\n\nYour choice: ");
                fflush(stdin);
                scanf(" %d", &option);
                switch (option)
                {
                case 1:
                    printf("Alright. Here we go again...");
                    inner_loop = 1;
                    break;
                case 2:
                    printf("Alright. Exiting Rename mode...");
                    inner_loop = 0;
                    looping = 1;
                    break;

                default:
                    printf("Please enter a valid option.");
                    inner_loop = 2;
                    break;
                }} while (inner_loop == 2);
        }}
        else {
            printf("\n\nFile not found. Please enter a valid name.");
            inner_loop = 1;
        }
        } while (inner_loop == 1);
        break;
        case 3:
            printf("\n\nReturning to Main menu...\n\n");
            looping = 0;
            break;

    default:
        printf("Please enter a valid option.");
        looping = 2;
        break;
        }} while (looping == 2);
    } while (looping == 1);
}

//Delete a file
void deleteFile() {
    int option, looping, deleted;
    char filename[50];
    do {printf("\n\nDELETE MODE\n--------------------------\n\nEnter name of file to be deleted (only .txt files for now): ");
    fflush(stdin);
    scanf(" %s", &filename);
    sprintf(filename, "%s.txt", filename);

    //Check if the file exists
    FILE *destroy_file;
    if (destroy_file = fopen(filename, "r")){
        fclose(destroy_file);
        do {printf("\n\nFile found. Go ahead with deletion?\n\n1 - YES\n2 - NO\n\nYour choice: ");
        fflush(stdin);
        scanf(" %d", &option);
        switch (option)
        {
        case 1:
            printf("\n\nDeleting file...\n");
            remove(filename);
            deleted = 1;
            if (deleted == 1) {
                do {printf("\nDeletion Successful\n\nDelete another file?\n\n1 - YES\n2 - NO\n\nYour choice: ");
                fflush(stdin);
                scanf(" %d", &option);
                switch (option)
                {
                case 1:
                    printf("Alright! Let's do this again...");
                    looping = 1;
                    break;

                case 2:
                    printf("Alright! Exiting delete mode...");
                    looping = 0;
                    break;
                
                default:
                    printf("\n\nInvalid option");
                    looping = 2;
                    break;
                }} while (looping == 2);
            }
            else {
                do {printf("\nSomething went wrong.\nTry again?\n\n1 - YES\n2 - NO\n\nYour choice: ");
                fflush(stdin);
                scanf(" %d", &option);
                switch (option)
                {
                case 1:
                    printf("Alright! Let's try again");
                    looping = 1;
                    break;

                case 2:
                    printf("Alright! Exiting Delete Mode...");
                    looping = 0;
                    break;
            
                default:
                    printf("Invalid Option");
                    looping = 2;
                    break;
                }} while (looping == 1);
            }
            break;

        case 2:
            printf("\nAlright! Aborting deletion...");
            looping = 0;
            break;

        default:
            printf("\nInvalid Option");
            looping = 2;
            break;
        }} while (looping == 2);
    }
    else {
        do {printf("\nFile Not Found. Would you like to try again?\n\n1 - YES\n2 - NO\n\nYour choice: ");
        fflush(stdin);
        scanf(" %d", &option);
        switch (option)
        {
        case 1:
            printf("Alright! Let's try this again...");
            looping = 1;
            break;

        case 2:
            printf("Alright! Aborting Delete mode...");
            looping = 0;
            break;
        
        default:
            printf("\nInvalid Option");
            looping = 2;
            break;
        }} while (looping == 2);
    }
    } while (looping == 1); //Nested switch cases in nested switch cases with if-else nested in do-while loops...yikes!
}