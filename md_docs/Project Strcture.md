# Project Structure

We understand that ease in reading and maintenance of code is vital, and as such decided it was best to split the various functions into different files, each containing code relating to a particular class or type of task, so that code pertaining to a particular function would be much easier to find and debug. In the end, we ended up with the following source code files:

- **main.cpp:** for calling the various functions that carry out the given tasks in order
- **stack.cpp:** for the Stack class, which is our implementation of the Stack data structure
- **conversions.cpp:** for the functions which convert data of one form into another (in our case, infix expressions to prefix, and prefix expressions to a rooted parse tree)
- **parsetree.cpp:** for our ParseTree class, which forms the core of most of our functionality
- **utils.cpp:**  for miscellaneous utility functions that didn't fit in any other category

Moreover, we created a header file corresponding to each cpp source file in their own directory, so that our source code directory does not get cluttered.

We also decided to use another directory for the output namely the `./build`.

`./md_docs` is another directory for markdown docs which provides doxygen to generate html files on the fly.

`./scripts` directory has the script we used to generate the propositional logic formula for analyzing the code whose logs can be found in `./analysis` directory.

Tree view of the project:


```
CSF214-Assignment-1
├── analysis
│   ├── 1m.log
│   ├── 1m.massif.log
│   ├── 1m.memcheck.log
│   ├── 1m.potato.log
│   ├── 1m.svg
│   └── 1m.time.log
├── build
│   ├── conversions.o
│   ├── main
│   ├── main.o
│   ├── parsetree.o
│   ├── stack.o
│   ├── tree.o
│   └── utils.o
├── docs
│   └── index.html
├── Doxyfile
├── include
│   ├── conversions.h
│   ├── main.h
│   ├── parsetree.h
│   ├── stack.h
│   └── utils.h
├── Makefile
├── md_docs
│   ├── Analysis.md
│   ├── Experiences.md
│   ├── Main.md
│   └── Project Structure.md
├── README.md
├── scripts
│   └── generate_expression.py
└── src
    ├── conversions.cpp
    ├── main.cpp
    ├── parsetree.cpp
    ├── stack.cpp
    └── utils.cpp
```