# Experiences

The assignment was overall a challenging but rewarding experience for all the members of our team, and we learnt several valuable lessons while doing it. Documented herein is the thought process behind some of our key decisions, some difficulties and challenges we faced during the assignment, as well as how we overcame them.

#### The File Structure

We understand that ease in reading and maintenance of code is vital, and as such decided it was best to split the various functions into different files, each containing code relating to a particular class or type of task, so that code pertaining to a particular function would be much easier to find and debug. In the end, we ended up with the following source code files:

- **main.cpp:** for calling the various functions that carry out the given tasks in order
- **stack.cpp:** for the Stack class, which is our implementation of the Stack data structure
- **conversions.cpp:** for the functions which convert data of one form into another (in our case, infix expressions to prefix, and prefix expressions to a rooted parse tree)
- **parsetree.cpp:** for our ParseTree class, which forms the core of most of our functionality
- **utils.cpp:**  for miscellaneous utility functions that didn't fit in any other category

Moreover, we created a header file corresponding to each cpp source file in their own directory, so that our source code directory does not get cluttered.

#### Some Tools We Used

We employed the aid of various tools available online, in order to make both the development/debugging of our code, as well as the documentation and maintenance, easier. These tools are as follows:

- **Makefile:** arguably the tool that ties the whole project together. This allows us to compile and run various parts of our code with specific options, clean the binary files, run the rest of the tools in this list, and so on. Details on its usage are in the documentation.
- **Doxygen:** for generating documentation from our code
- **Flamegraph:** for visually depicting the request trace and service calls made during the program's runtime, to identify bottlenecks and inefficiencies
- **Valgrind:** for finding any potential memory leaks

Other than these, we used VSCode as our IDE of choice, Git/GitHub for version control, and the g++ compiler using C++20.

#### Problems We Faced

The biggest issue we faced during development was profiling our code for inefficiencies; as the tasks were not very computationally heavy, our timers would just say "0.00 seconds" for every task. We employed various tactics to get around this issue.

First, we wrote a python script to generate much longer propositional logic expressions than a human would be able to write (/scripts/generate_expression.py). Through fiddling with numbers as well as disabling the stack limit on our system, we were able to generate expressions millions of characters in length, so that execution of the code would take longer.

Second, we employed the use of an emulated system online, running a processor with a clockspeed of just 20MHz (able to turbo up to about 30MHz), to see how our code would perform running on a much weaker system.

The results obtained from these activities are documented and analyzed in the Analysis section.
