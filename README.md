# CatCounter
CatCounter counts "cat"s. 

Use it to find the number of occurences of the word "cat" in your string or text file.

Usage:
   catcounter \<mode> \<input> [options]

Mode: 
   "help": display this help message.
   "cli": provide your string in the "input" field.
   "file: provide the path of your text file in the "input" field

Settings: 
   "--strict": Will only find the "cat" separated by whitespace.
   "--case-sensitive": Will only find lowercase "cat"s.

Examples:
   catcounter arg "calico cats are a cat above" --strict
   catcounter file ./test/test_file.txt --case-sensitive
   )"""

# Building
Catcounter has no dependenices outside of the std lib. Use the included makefile to build with GCC.
```
git clone git@github.com:DavidIngraham/CatCounter.git
cd catcounter
make
```

# Running Tests