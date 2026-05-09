# Username Sanitizer Utility 

This assignment checks and validates usernames. If a username is invalid, it transforms a username to fit the validity criteria. 

## Solution logic 
- Used multiple helper functions for the different validity requirements
- Also created helper functions that call each validity requirement functions to check overall validity 
- Created clean_username to transform usernames so they become valid 
- Created process_username which is designed to print out invalid, valid, or transformed usernames in the right format and also clears memory using free()

## Compilation instructions
- The program should compile in terminal with the command: make 

## Running the program (example command)
echo "username" | ./userclean 

## Academic integrity statement 
"I certify that this submission represents entirely my own work.”