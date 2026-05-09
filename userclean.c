#include <string.h> 
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
/*
Name: Hannah Yabut 
Student ID: 3131432 
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
            return 0;
        }
        i++; // increments the indices 
    }
    return 1; // returns false if it does not contain the criteria
}

/*
purpose: checks if username is between 3-16 chars in length 
params: u_name 
return: True or False 
*/
int certain_len(const char *u_name)
{
    int len = strlen(u_name); 
    return len >=3 && len <= 16; // checks that it is between 3-16 chars 
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
    char *cleaned = malloc(input_len + 5);
    const char *pad = "user";

    if (cleaned == NULL) {
        return NULL;
    }

    int j = 0;
    int pad_k = 0;

    for (int i = 0; u_name[i] != '\0' && j < 16; i++) {
        unsigned char ch = (unsigned char)u_name[i];

        if (isupper(ch)) {
            cleaned[j] = tolower(ch);
            j++;
        } else if (isspace(ch)) {
            cleaned[j] = '_';
            j++;
        } else if (islower(ch) || isdigit(ch) || ch == '_') {
            cleaned[j] = ch;
            j++;
        }
        // invalid chars are skipped 
    }
     cleaned[j] = '\0';

    while (j < 3) {
        cleaned[j] = pad[pad_k];
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
    
    char *cleaned = clean_username(u_name); // calls function that cleans username and assigns cleaned as the cleaned username variable 
    if (cleaned == NULL)
        return; 
    if (valid_username(cleaned))
        printf("%s : %s\n", u_name, cleaned); // returns transformed usernames 
    else
        printf("invalid and unfixable\n"); // if not valid, prints out an error message 

    free(cleaned); // frees memory 
}


/*
purpose: removes newline and whitespaces/ trailing spaces and replaces them with a null char
params: input string 
return: None 
*/
void remove_nl(char *line)
{
    int len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len -1] == ' ' || line[len -1] == '\t' )) {
        line[len -1] = '\0'; // replaces with null char, [len - 1] since last index is null char 
        len--; // decrement through the lines to avoid looping forever 
    }
}

/*
purpose: parses through command line input or file and removes newlines and calls function that processes
usernames 
params: None 
return: 0
*/
int main(void) 
{
    char line[1024]; 
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        remove_nl(line); 
        process_username(line);
    }
    return 0; 
}