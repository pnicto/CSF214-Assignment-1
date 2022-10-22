# Analysis

#### Specifications

A propositional logic formula with 1 million(repeated) atoms <br>

These are the specifications of the computer where the profiling and benchmarking has been done:<br>
OS: Ubuntu 22.04.1 LTS x86_64<br>
Kernel: 5.15.0-52-generic<br>
CPU: Intel i5-10210U (8) @ 4.200GHz<br>
GPU: Intel CometLake-U GT2 [UHD Graphics]<br>

#### Time taken to run

real	0m1.443s<br>
user	0m1.401s<br>
sys	0m0.037s<br>

**real** : wall clock time - time from start to finish of the call. This is all elapsed time including time slices used by other processes and time the process spends blocked (for example if it is waiting for I/O to complete).

**user** : amount of CPU time spent in user-mode code (outside the kernel) within the process. This is only actual CPU time used in executing the process. Other processes and time the process spends blocked do not count towards this figure.

**sys** : amount of CPU time spent in the kernel within the process. This means executing CPU time spent in system calls within the kernel, as opposed to library code, which is still running in user-space. Like 'user', this is only CPU time used by the process. See below for a brief description of kernel mode (also known as 'supervisor' mode) and the system call mechanism.

### Gprof profiling

#### Flat Profile

| % time | cumulative seconds | self seconds | calls   | self ms/call | total ms/call | name                                                                                                                                                                                                                                                                                                                                                                                                                       |
| ------ | ------------------ | ------------ | ------- | ------------ | ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 16.67  | 0.06               | 0.03         | 1       | 30.00        | 50.00         | #createParseTree (__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >*, __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >)                                                                                                                                                           |
| 5.56   | 0.13               | 0.01         | 666666  | 0.00         | 0.00          | Stack::push(char)                                                                                                                                                                                                                                                                                                                                                                                                          |
| 5.56   | 0.14               | 0.01         | 2       | 5.00         | 24.64         | void std::__reverse<__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::random_access_iterator_tag) |
| 5.56   | 0.15               | 0.01         | 1       | 10.00        | 19.90         | #inOrderTraversal(ParseTree*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*)                                                                                                                                                                                                                                                                                                            |
| 5.56   | 0.16               | 0.01         | 1       | 10.00        | 10.00         | ParseTree::~ParseTree()                                                                                                                                                                                                                                                                                                                                                                                                    |
| 0.00   | 0.18               | 0.00         | 1666670 | 0.00         | 0.00          | ParseTree::getLeftNode(ParseTree*)                                                                                                                                                                                                                                                                                                                                                                                         |
| 0.00   | 0.18               | 0.00         | 1666669 | 0.00         | 0.00          | ParseTree::getRightNode(ParseTree*)                                                                                                                                                                                                                                                                                                                                                                                        |
| 0.00   | 0.18               | 0.00         | 666679  | 0.00         | 0.00          | ParseTree::getValue()                                                                                                                                                                                                                                                                                                                                                                                                      |
| 0.00   | 0.18               | 0.00         | 666667  | 0.00         | 0.00          | ParseTree::ParseTree(char)                                                                                                                                                                                                                                                                                                                                                                                                 |
| 0.00   | 0.18               | 0.00         | 666667  | 0.00         | 0.00          | long long const& std::max<long long>(long long const&, long long const&)                                                                                                                                                                                                                                                                                                                                                   |
| 0.00   | 0.18               | 0.00         | 666666  | 0.00         | 0.00          | Stack::pop()                                                                                                                                                                                                                                                                                                                                                                                                               |
| 0.00   | 0.18               | 0.00         | 333333  | 0.00         | 0.00          | ParseTree::setLeftNode(ParseTree*)                                                                                                                                                                                                                                                                                                                                                                                         |
| 0.00   | 0.18               | 0.00         | 333333  | 0.00         | 0.00          | ParseTree::setRightNode(ParseTree*)                                                                                                                                                                                                                                                                                                                                                                                        |
| 0.00   | 0.18               | 0.00         | 19      | 0.00         | 0.00          | Stack::resizeArray()                                                                                                                                                                                                                                                                                                                                                                                                       |



<!-- TODO:Do this -->
#### Call Graph

| index | % time | self | children | called | name                                                                                                                                                                                       |
| ----- | ------ | ---- | -------- | ------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| [1]   | 100.0  | 0.00 | 0.18     |        | main [1]                                                                                                                                                                                   |
|       |        | 0.00 | 0.10     | 1/1    | #infixToPrefix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [2]                                                                                        |
|       |        | 0.00 | 0.05     | 1/1    | #prefixToParseTree(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [3]                                                                                    |
|       |        | 0.00 | 0.02     | 1/1    | #parseTreeToInfix[abi:cxx11](ParseTree*) [8]                                                                                                                                               |
|       |        | 0.01 | 0.00     | 1/1    | ParseTree::~ParseTree() [23]                                                                                                                                                               |
|       |        | 0.00 | 0.00     | 2/2    | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [35] |
|       |        | 0.00 | 0.00     | 1/2    | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string() [36]                                                                                       |
|       |        | 0.00 | 0.00     | 5/5    | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() [44]                                                                                      |
|       |        | 0.00 | 0.00     | 1/1    | evaluateTreeTruthValue(ParseTree*) [47]                                                                                                                                                    |
|       |        | 0.00 | 0.00     | 1/1    | getBinaryTreeHeight(ParseTree*) [184]                                                                                                                                                      |

Here is what the fields in each line mean:

**% time**
This is the percentage of the total execution time your program spent in this function.

**cumulative seconds**
This is the cumulative total number of seconds the computer spent executing this functions, plus the time spent in all the functions above this one in this table.

**self seconds**
This is the number of seconds accounted for by this function alone.

**calls**
This is the total number of times the function was called.

**self ms/call**
This represents the average number of milliseconds spent in this function per call.

**total ms/call**
This represents the average number of milliseconds spent in this function and its descendants per call.

**name**
This is the name of the function.

**children**
This is the total amount of time propagated into this function by its children.

### Valgrind profiling

#### Massif heap profile

| n   | time(i)     | total(B)   | useful-heap(B) | extra-heap(B) | stacks(B) |
| --- | ----------- | ---------- | -------------- | ------------- | --------- |
| 0   | 0           | 0          | 0              | 0             | 0         |
| 1   | 11,899,766  | 199,720    | 199,681        | 39            | 0         |
| 2   | 21,364,585  | 322,600    | 322,561        | 39            | 0         |
| 3   | 40,047,498  | 814,144    | 814,082        | 62            | 0         |
| 4   | 40,293,533  | 568,360    | 568,321        | 39            | 0         |
| 5   | 77,658,976  | 1,551,424  | 1,551,362      | 62            | 0         |
| 6   | 78,150,755  | 1,059,880  | 1,059,841      | 39            | 0         |
| 7   | 152,881,258 | 3,025,984  | 3,025,922      | 62            | 0         |
| 8   | 152,967,109 | 2,042,920  | 2,042,881      | 39            | 0         |
| 9   | 206,226,892 | 3,376,272  | 3,376,215      | 57            | 0         |
| 10  | 206,373,998 | 3,376,296  | 3,376,216      | 80            | 0         |
| 11  | 347,708,049 | 3,376,320  | 3,376,218      | 102           | 0         |
| 12  | 358,916,395 | 3,507,352  | 3,507,287      | 65            | 0         |
| 13  | 370,123,162 | 3,638,424  | 3,638,359      | 65            | 0         |
| 14  | 385,982,925 | 4,162,720  | 4,162,647      | 73            | 0         |
| 15  | 401,156,952 | 3,900,608  | 3,900,534      | 74            | 0         |
| 16  | 413,616,161 | 3,962,032  | 3,961,944      | 88            | 0         |
| 17  | 426,087,795 | 4,023,472  | 4,023,384      | 88            | 0         |
| 18  | 450,911,033 | 4,269,256  | 4,269,145      | 111           | 0         |
| 19  | 451,034,172 | 4,146,352  | 4,146,264      | 88            | 0         |
| 20  | 500,678,477 | 4,637,896  | 4,637,785      | 111           | 0         |
| 21  | 500,924,528 | 4,392,112  | 4,392,024      | 88            | 0         |
| 22  | 600,212,947 | 5,375,176  | 5,375,065      | 111           | 0         |
| 23  | 600,704,726 | 4,883,632  | 4,883,544      | 88            | 0         |
| 24  | 742,130,169 | 4,359,336  | 4,359,256      | 80            | 0         |
| 25  | 751,401,840 | 5,339,384  | 4,680,622      | 658,762       | 0         |
| 26  | 763,691,040 | 7,691,384  | 6,091,822      | 1,599,562     | 0         |
| 27  | 772,406,340 | 9,359,384  | 7,092,622      | 2,266,762     | 0         |
| 28  | 782,469,690 | 11,285,384 | 8,248,222      | 3,037,162     | 0         |
| 29  | 793,672,090 | 13,429,384 | 9,534,622      | 3,894,762     | 0         |
| 30  | 805,783,640 | 15,747,384 | 10,925,422     | 4,821,962     | 0         |
| 31  | 818,386,340 | 18,159,384 | 12,372,622     | 5,786,762     | 0         |
| 32  | 832,034,040 | 20,771,384 | 13,939,822     | 6,831,562     | 0         |
| 33  | 840,738,890 | 22,437,384 | 14,939,422     | 7,497,962     | 0         |
| 34  | 850,008,040 | 24,211,384 | 16,003,822     | 8,207,562     | 0         |
| 35  | 859,465,290 | 26,021,384 | 17,089,822     | 8,931,562     | 0         |
| 36  | 869,518,190 | 27,945,384 | 18,244,222     | 9,701,162     | 0         |
| 37  | 880,710,140 | 30,087,384 | 19,529,422     | 10,557,962    | 0         |
| 38  | 890,131,445 | 30,359,344 | 19,692,598     | 10,666,746    | 0         |