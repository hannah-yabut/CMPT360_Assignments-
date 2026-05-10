# CMPT 360 - A - Username Sanitizer Utility

Name: Hannah Yabut & Ismael Robleh
Date: 05/10/2026

## Academic Integrity
I certify that this submission represents entirely my own work.

## Overview
This assignment checks and validates usernames. If a username is invalid, it transforms a username to fit the validity criteria. 

## Build
To compile scripts use: "make all"

## Run
- To run manual test use: "make run"
- To run automatic pre-established test cases use: "make check"
- To check memory leaks use: "make valgrind" or "make vg"

## Solution logic 
- Used multiple helper functions for the different validity requirements
- Also created helper functions that call each validity requirement functions to check overall validity 
- Created clean_username to transform usernames so they become valid 
- Created process_username which is designed to print out invalid, valid, or transformed usernames in the right format and also clears memory using free()

## Status
The program works correctly throughout all the different test cases

## Notes / Assumptions (Optional)
I have made the assumption that spaces in front and at the end of the input must be removed given that it was provided in the expected.txt where the input ( Admin 42 ) --> admin_42.
Also to run the Valgrind command, the input file name must be "input.txt"