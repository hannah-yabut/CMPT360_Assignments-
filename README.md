
# CMPT 360 - A

Name: Hannah Yabut & Ismael Robleh
Date: 05/10/2026

# Username Sanitizer Utility 

This assignment checks and validates usernames. If a username is invalid, it transforms a username to fit the validity criteria. 

# 1. Academic Integrity
I certify that this submission represents entirely my own work.

# 2. Overview

# 3. Build
Compile scripts --> make all

# 4. Run
Manual tests --> make run
Automatic tests predefined in Makefile --> make check

# 5. Solution logic 
- Used multiple helper functions for the different validity requirements
- Also created helper functions that call each validity requirement functions to check overall validity 
- Created clean_username to transform usernames so they become valid 
- Created process_username which is designed to print out invalid, valid, or transformed usernames in the right format and also clears memory using free()

# 6. Status
The program works correctly throughout all the different test cases

# 7. Notes / Assumptions (Optional)
I have made the assumption that spaces in front and at the end of the input must be removed given that it was provided in the expected.txt where the input ( Admin 42 ) --> admin_42. Also I have made the assumption that the version used to compile this program is GCC-11 given thats the current version of the student remote servers at MacEwan.
