# Grep
implement a Grep using C++


###### Name:           Xinying Guo
###### UserName:       XINYING


### Purpose of the program
```
The purpose of the program is implement a grep. 
Store all the word of specific 
directory to a hash table and find them by Quering
```
### Acknowledgements
```
Thanks for StackOver flow for providing me 
information of debugging and hash table

Thanks for STL library provide me biuld list and 
provide hash function.

Thanks for Comp15 TA give me a simpler metho to parse 
srting to strip off non-alphabetic characters. 
```
### files and description:

```
Word.cpp
Word.h  :  

I defined the Word class to store word and information need to 
display implemented function to  display the word.

Hash.cpp 
Hash.h :  

In this file, I create a hash table with 
function of inderting and finding

Indexing.cpp 
Indexing.h : 

In this file, I create the interface to connect hash table
and word class. The indexing class taking charge of storing 
data read from file to hash table. The indexing class switch 
all word to lower case and using hash function to map them 
to hash table. So that the word with same character but 
different case can store to the same chain of hash table. 
This helps the hash table to find quickly when user use 
insensitive search.

gerp.cpp::  
This is the driver of the program.
This calss is for recieving command from command line and 
searching the word from hash table. When the word was being
recieved, it can print out the directory, which line and the 
contex of the line.
```

### DataStructure
```
In this program, I choose to use hash table with chain to 
implement the program.

In hash table, I used list(double linked list) 
as bucket of the hash table. 

In the word class, I used list(double linked list) 
to store directory and line of the word. 
For traverse tree, I used FSTree to traverse directory.

```

### Algorithm used:
```
hash function
*************************************************************
Details and explanation of how you tested the 
various parts of your classes and the program as a whole:

I test the word class first, I test the consructors, 
mutator and accessor.
Then I tested function to traverse list location. 
Then I test whether it can display the word. 

I test hash class secound, I test insertion functions 
and and find founction. 
I also test the constructor and memory leak of hash class. 

Then I test indexing class. 
I test whether it can read directory and biuld 
fstree using treetreaverse function in phase 1. 
Then I test read in word 
class and print out the word being read. 
Then I test push to hashing function
which used the already tested function 
insert() in hash function. 
Then I combine them and test whether it can read 
file from the being traversed directory. 
And test whether the indexing class can help find the element 
in hash table. 

Then I test gerp class. I test the string 
processing function which is implemented successful in phase 1. 
Then I test whether it can cin with correct sequence 
and distinguish sensitive and insensitive search. 

Then I tried to use gerp to run tinydata 
and check memory leak. after success, 
I tried smallGutenberg, and test memory leak.
Checking mediumGutenberg failed. 

```
