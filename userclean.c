#define _GNU_SOURCE
#include <string.h> 
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
/*
Name: Hannah Yabut & Ismael Robleh
Student ID: 3131432 & 3149556
May 10, 2026 
checks if a username is valid, if it can be transformed it transforms the username 
*/

/*
purpose: checks if a username is admin or root 
params: u_name 
return: True or False 
*/
int is_reserved_name(const char *u_name) 
{
    return strcmp(u_name, "root") == 0 || strcmp(u_name, "admin") == 0; 
}

/*
purpose: checks if a username starts with a lowercase 
params: u_name 
return: True or False 
*/
int starts_lowercase(const char *u_name)
{
    return islower(u_name[0]);
}

/*
purpose: checks if a username has only lowercase letters, digits, or underscores 
params: u_name 
return: True or False 
*/
int specific_chars(const char *u_name)
{
    int i = 0; 
    // checks the entire username until the null char for the characters 
    while (u_name[i] != '\0') {
        if (!islower(u_name[i]) && !isdigit(u_name[i]) && u_name[i] != '_') {
            return 0; // return false if it fails 1 or more 
        }
        i++; // increments the indices 
    }
    return 1; // returns true if it meets all criteria 
}

/*
purpose: checks if username is between 3-16 chars in length 
params: u_name 
return: True or False 
*/
int certain_len(const char *u_name)
{
    int len = strlen(u_name); 
    return len >= 3 && len <= 16; // checks that it is between 3-16 chars 
}

/*
purpose: calls helper functinos to check if a username is valid 
params: u_name 
return: 0 or 1 
*/
int valid_username(const char *u_name)
{
    return !is_reserved_name(u_name) &&
           starts_lowercase(u_name) &&
           specific_chars(u_name) &&
           certain_len(u_name);
}

/*
purpose: cleans username with the given transformation criteria such as uppercase to lowercase, 
removing whitespace and any chars that isn't letters, underscores, or numbers. Also making sure 
that they are between 3-16 in length 
params: u_name 
return: cleaned u_name 
*/
char *clean_username(const char *u_name)
{
    int input_len = strlen(u_name);
    char *cleaned = malloc(input_len + 5); //Try to allocate memory with a size of the sum of the 2 strings (username + user + 1)
    const char *pad = "user";

    if (cleaned == NULL) {
        fprintf(stderr, "Memory allocation failed for cleaned!");
        exit(1);
    }

    int j = 0; // initialized indexing of cleaned username 
    int pad_k = 0; // initialized padding for usernames < 3 

    // keeps cleaning the username as long as its less than 16 
    for (int i = 0; u_name[i] != '\0' && j < 16; i++) {
        unsigned char ch = (unsigned char)u_name[i];

        if (isupper(ch)) {
            cleaned[j] = tolower(ch); // if username is capitalized -> lowercase 
            j++;
        } else if (isspace(ch)) {
            cleaned[j] = '_'; // if there is a space it changes to an underscore 
            j++;
        } else if (islower(ch) || isdigit(ch) || ch == '_') {
            cleaned[j] = ch; // the username does not need changing 
            j++;
        }
    }
     cleaned[j] = '\0'; 

    while (j < 3) {
        cleaned[j] = pad[pad_k]; // if username < 3 it pads the string "user" until the length is 3 
        j++; 
        pad_k++;
        cleaned[j] = '\0';
    }
    return cleaned;
}


/*
purpose: prints out corresponding print out mesages for each instance and frees memory
params: u_name 
return: None 
*/
void process_username(const char *u_name) 
{
    if (valid_username(u_name)) {
        printf("%s : %s\n", u_name, u_name); // prints valid string usernames
        return; 
    }

    int username_length = strlen(u_name);
    
    if (username_length > 0) {
        char* cleaned = clean_username(u_name); // calls function that cleans username and assigns cleaned as the cleaned username variable 
        if (cleaned == NULL)
            return;
        if (valid_username(cleaned))
            printf("%s : %s\n", u_name, cleaned); // returns transformed usernames 
        else
            printf("%s : invalid and unfixable\n", u_name); // if not valid, prints out an error message 

        free(cleaned); // frees memory 
    }
    else
        printf("%s : invalid and unfixable\n", u_name); // if not valid, prints out an error message 
}


/*
purpose: removes newline and whitespaces/ trailing spaces and replaces them with a null char
params: input string 
return: None 
*/
void remove_nl(char *line)
{
    int len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == ' ' || line[len - 1] == '\t' )) {
        line[len -1] = '\0'; // replaces with null char, [len - 1] since last index is null char 
        len--; // decrement through the lines to avoid looping forever 
    }
}

/*
    Purpose: Remove leading and trailing spaces from the string. Spaces inside are preserved.
    Parameters:
        char* line the string to trim;
        int length its original length .
    Return: None
*/
void remove_whitespaces_start_end(char* line, int length)
{
    //Iterates through the input and only keeps non whitespace characters or whitespace characters not located at the start or end of the string and discards the rest
    int j = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] != ' ' || (line[i] == ' ' && i > 0 && i < length - 1))
        {
            line[j++] = line[i];
        }
    }
    line[j] = '\0';
}

/*
    Purpose: Read from stdin continuously removing newlines, whitespaces, and valdifying the username.
    Parameters: None
    Return: None
*/
int main(void) 
{
    char* line = NULL;
    size_t length = 0;
    ssize_t num_read;

    //Read from standard input until reached EOF
    while ((num_read = getline(&line, &length, stdin)) != EOF)
    {
        remove_nl(line); //Remove unnecessary characters (newlines, tabs)
        remove_whitespaces_start_end(line, length); //Remove white spaces from start and end of username
        process_username(line); //validifying username
    }

    //Must free the memory at the end of the input stream
    free(line);

    //Avoid dangling pointers
    line = NULL;

    return 0;
}