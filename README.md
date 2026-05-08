# CMPT 360 - A

Name: Ismael Robleh
ID: 3149556
Date: 05/05/2026

# 1. Academic Integrity
I certify that this submission represents entirely my own work.

# 2. Overview
The program uses dynamic memory allocation in safe manner, freeing all allocated memory after its use. 
The goal is to try to fix invalid inputs and produce a clean, valid username if it possible, while flagging when an input is deemed unredeemable.
Finally displaying the difference between the original input and the valid input or yield invalid input.

# 3. Build
Compile scripts --> make all


# 4. Run
Manual tests --> make run
Automatic tests predefined in Makefile --> make check
Automatic tests by comparing files --> make generate then make compare

# 5. Logic Summary
The program reads usernames from the standard input and attempts to validate and transform it gradually into a valid username if it fails the verification.
The process goes as follows:
1. Dynamically reads input from standard input and removes trailing new lines
2. Preserves the original input entered by the user to print later
3. Removing all leading and trailing spaces from the input
4. Check if the trimmed string is valid according to all of the following rules: between 3 and 16 characters, first character is a lowercase letter, the username only contains letters, digits, and underscores, and finally if the username is not admin or root.
5A. If true, then print the original username and the valid username
5B. If false, then check if the string/username contains at least 1 writable character
6B. Apply a variety of transformation rules consisting of: setting all letters to lowercase, replacing all whitespaces characters with underscores, removing all characters that are not (digits, letters, or underscores), appending characters of the string "user" until the username is at least 3 characters long, or truncating the username to at most 16 characters.
7B. Check if the tranformed string is valid according to all of the previous established rules in 4
8C. If true, then print original username and transformed string
9D. If false, then print original username and state that the username is unfixable and invalid
10. Free the allocated memory for the original string
11. Free the allocated memory for the input


# 6. Status
The program works correctly throughout all the different test cases

# 6. Notes / Assumptions (Optional)
I have made the assumption that spaces in front and at the end of the input must be removed given that it was provided in the expected.txt where the input ( Admin 42 ) --> admin_42. Also I have made the assumption that the version used to compile this program is GCC-11 given thats the current version of the student remote servers at MacEwan.
