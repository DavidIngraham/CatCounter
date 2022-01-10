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
The Google Test framework is required to run unit tests. A docker environment is provided for running tests.

Running the test suits is simple:
```
cd catcounter
docker docker build -t catcounter_test . 
docker run -it catcounter_test
```

You can also run CatCounter directly after building the docker image using the following syntax:
```
docker run -it catcounter_test ./catcounter cli "kitty cats like catnip" --strict
```