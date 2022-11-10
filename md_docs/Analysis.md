# Analysis

#### Specifications

A propositional logic formula with 1 million(repeated) atoms <br>

These are the specifications of the computer where the profiling and benchmarking has been done:<br>
OS: Ubuntu 22.04.1 LTS x86_64<br>
Kernel: 5.15.0-52-generic<br>
CPU: Intel i5-10210U (8) @ 4.200GHz<br>
GPU: Intel CometLake-U GT2 [UHD Graphics]<br>

#### Time taken to run

**real**	0m1.443s<br>
**user**	0m1.401s<br>
**sys**	0m0.037s<br>

**real** : wall clock time - time from start to finish of the call. This is all elapsed time including time slices used by other processes and time the process spends blocked (for example if it is waiting for I/O to complete).

**user** : amount of CPU time spent in user-mode code (outside the kernel) within the process. This is only actual CPU time used in executing the process. Other processes and time the process spends blocked do not count towards this figure.

**sys** : amount of CPU time spent in the kernel within the process. This means executing CPU time spent in system calls within the kernel, as opposed to library code, which is still running in user-space. Like 'user', this is only CPU time used by the process. See below for a brief description of kernel mode (also known as 'supervisor' mode) and the system call mechanism.

### Gprof profiling

Preferably view the following data as a txt file for convenience they are [linked](https://pastebin.com/3PNDXPVD) for ease of access and complete log.

We have represented the data for functions we have created/used, removing the ones which are related to the C++ API. As for call graphs accounting the length of the log we couldn't show all of it.


#### Flat Profile

| % time | cumulative seconds | self seconds | calls   | self ms/call | total ms/call | name                                                                                                                                                                                                                                                                                                                                                                                                                       |
| ------ | ------------------ | ------------ | ------- | ------------ | ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 16.67  | 0.06               | 0.03         | 1       | 30.00        | 50.00         | createParseTree (__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >*, __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >)                                                                                                                                                            |
| 5.56   | 0.13               | 0.01         | 666666  | 0.00         | 0.00          | Stack::push(char)                                                                                                                                                                                                                                                                                                                                                                                                          |
| 5.56   | 0.14               | 0.01         | 2       | 5.00         | 24.64         | void std::__reverse<__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::random_access_iterator_tag) |
| 5.56   | 0.15               | 0.01         | 1       | 10.00        | 19.90         | ParseTree::inOrderTraversal(ParseTree*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*)                                                                                                                                                                                                                                                                                                  |
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



#### Call Graph

| index | % time | self | children | called          | name                                                                                                                                                                                                                                                                                                                                                                                        |
| ----- | ------ | ---- | -------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [1]   | 100.0  | 0.00 | 0.18     |                 | main [1]                                                                                                                                                                                                                                                                                                                                                                                    |
|       |        | 0.00 | 0.10     | 1/1             | infixToPrefix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [2]                                                                                                                                                                                                                                                                                          |
|       |        | 0.00 | 0.05     | 1/1             | prefixToParseTree(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [3]                                                                                                                                                                                                                                                                                      |
|       |        | 0.00 | 0.02     | 1/1             | parseTreeToInfix[abi:cxx11](ParseTree*) [8]                                                                                                                                                                                                                                                                                                                                                 |
|       |        | 0.01 | 0.00     | 1/1             | ParseTree::~ParseTree() [23]                                                                                                                                                                                                                                                                                                                                                                |
|       |        | 0.00 | 0.00     | 2/2             | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [35]                                                                                                                                                                                                  |
|       |        | 0.00 | 0.00     | 1/2             | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string() [36]                                                                                                                                                                                                                                                                                        |
|       |        | 0.00 | 0.00     | 5/5             | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() [44]                                                                                                                                                                                                                                                                                       |
|       |        | 0.00 | 0.00     | 1/1             | evaluateTreeTruthValue(ParseTree*) [47]                                                                                                                                                                                                                                                                                                                                                     |
|       |        | 0.00 | 0.00     | 1/1             | getBinaryTreeHeight(ParseTree*) [184]                                                                                                                                                                                                                                                                                                                                                       |
|       |        | 0.00 | 0.10     | 1/1             | main [1]                                                                                                                                                                                                                                                                                                                                                                                    |
| [2]   | 53.3   | 0.00 | 0.10     | 1               | infixToPrefix(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) [2]                                                                                                                                                                                                                                                                                          |
|       |        | 0.00 | 0.05     | 2/2             | void std::reverse<__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >) [5] |
|       |        | 0.02 | 0.00     | 1333334/2000003 | bool __gnu_cxx::operator==<char*, char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(__gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > const&, __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > const&) [7]  |
|       |        | 0.01 | 0.00     | 666666/666666   | Stack::push(char) [22]                                                                                                                                                                                                                                                                                                                                                                      |
|       |        | 0.00 | 0.01     | 666667/666667   | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::operator+=(char) [24]                                                                                                                                                                                                                                                                                      |
|       |        | 0.01 | 0.00     | 1333333/2333332 | __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::operator++() [14]                                                                                                                                                                                                                                                    |
|       |        | 0.00 | 0.00     | 1/2             | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string() [36]                                                                                                                                                                                                                                                                                        |
|       |        | 0.00 | 0.00     | 3/4             | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::end() [49]                                                                                                                                                                                                                                                                                                 |
|       |        | 0.00 | 0.00     | 3/4             | std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::begin() [50]                                                                                                                                                                                                                                                                                               |
|       |        | 0.00 | 0.00     | 1333333/4666665 | __gnu_cxx::__normal_iterator<char*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::operator*() const [59]                                                                                                                                                                                                                                               |
|       |        | 0.00 | 0.00     | 666666/666666   | Stack::pop() [71]                                                                                                                                                                                                                                                                                                                                                                           |
|       |        | 0.00 | 0.00     | 1/1             | Stack::Stack() [189]                                                                                                                                                                                                                                                                                                                                                                        |
|       |        | 0.00 | 0.00     | 1/1             | Stack::~Stack() [190]                                                                                                                                                                                                                                                                                                                                                                       |


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

 | n   | time(i)       | total(B)   | useful-heap(B) | extra-heap(B) | stacks(B)  |
 | --- | ------------- | ---------- | -------------- | ------------- | ---------- |
 | 0   | 0             | 0          | 0              | 0             | 0          |
 | 1   | 27,282,309    | 324,200    | 323,585        | 47            | 568        |
 | 2   | 46,830,642    | 569,960    | 569,345        | 47            | 568        |
 | 3   | 66,837,831    | 569,960    | 569,345        | 47            | 568        |
 | 4   | 80,387,733    | 1,061,496  | 1,060,865      | 47            | 584        |
 | 5   | 103,245,413   | 1,061,480  | 1,060,865      | 47            | 568        |
 | 6   | 128,354,498   | 1,061,480  | 1,060,865      | 47            | 568        |
 | 7   | 151,754,874   | 2,044,552  | 2,043,905      | 47            | 600        |
 | 8   | 170,813,209   | 2,044,552  | 2,043,905      | 47            | 600        |
 | 9   | 197,502,733   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 10  | 212,466,853   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 11  | 227,430,973   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 12  | 242,395,093   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 13  | 257,359,213   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 14  | 273,084,197   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 15  | 287,432,298   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 16  | 301,780,399   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 17  | 316,128,500   | 3,378,024  | 3,377,240      | 88            | 696        |
 | 18  | 332,885,867   | 3,443,424  | 3,442,775      | 73            | 576        |
 | 19  | 361,411,805   | 4,164,488  | 4,163,671      | 81            | 736        |
 | 20  | 382,313,539   | 3,933,096  | 3,932,248      | 96            | 752        |
 | 21  | 396,661,618   | 3,963,784  | 3,962,968      | 96            | 720        |
 | 22  | 425,052,151   | 4,271,296  | 4,270,169      | 119           | 1,008      |
 | 23  | 441,791,592   | 4,147,952  | 4,147,288      | 96            | 568        |
 | 24  | 465,705,086   | 4,148,048  | 4,147,288      | 96            | 664        |
 | 25  | 491,894,523   | 4,393,928  | 4,393,048      | 96            | 784        |
 | 26  | 515,808,001   | 4,393,712  | 4,393,048      | 96            | 568        |
 | 27  | 533,743,118   | 4,393,864  | 4,393,048      | 96            | 720        |
 | 28  | 551,678,244   | 4,393,808  | 4,393,048      | 96            | 664        |
 | 29  | 571,773,477   | 5,377,216  | 5,376,089      | 119           | 1,008      |
 | 30  | 583,730,220   | 4,885,232  | 4,884,568      | 96            | 568        |
 | 31  | 607,643,695   | 4,885,280  | 4,884,568      | 96            | 616        |
 | 32  | 625,578,805   | 4,885,272  | 4,884,568      | 96            | 608        |
 | 33  | 637,535,546   | 4,885,232  | 4,884,568      | 96            | 568        |
 | 34  | 655,470,653   | 4,885,408  | 4,884,568      | 96            | 744        |
 | 35  | 673,405,769   | 4,885,312  | 4,884,568      | 96            | 648        |
 | 36  | 685,362,512   | 4,885,312  | 4,884,568      | 96            | 648        |
 | 37  | 703,297,619   | 4,885,360  | 4,884,568      | 96            | 696        |
 | 38  | 720,511,539   | 9,113,912  | 5,171,654      | 985,474       | 2,956,784  |
 | 39  | 733,935,525   | 14,991,096 | 6,774,518      | 2,054,066     | 6,162,512  |
 | 40  | 756,012,223   | 24,656,544 | 9,410,558      | 3,811,426     | 11,434,560 |
 | 41  | 777,130,702   | 33,902,392 | 11,932,166     | 5,492,498     | 16,477,728 |
 | 42  | 792,320,461   | 40,552,688 | 13,745,870     | 6,701,634     | 20,105,184 |
 | 43  | 808,307,008   | 47,551,720 | 15,654,710     | 7,974,194     | 23,922,816 |
 | 44  | 827,052,055   | 55,758,560 | 17,892,926     | 9,466,338     | 28,399,296 |
 | 45  | 841,784,487   | 62,208,552 | 19,652,006     | 10,639,058    | 31,917,488 |
 | 46  | 860,915,209   | 30,951,752 | 19,088,395     | 10,666,813    | 1,196,544  |
 | 47  | 880,045,939   | 33,139,216 | 19,149,835     | 10,666,813    | 3,322,568  |
 | 48  | 889,611,302   | 34,314,936 | 19,272,715     | 10,666,813    | 4,375,408  |
 | 49  | 908,742,024   | 36,447,888 | 19,272,715     | 10,666,813    | 6,508,360  |
 | 50  | 918,307,391   | 37,514,384 | 19,272,715     | 10,666,813    | 7,574,856  |
 | 51  | 927,872,760   | 38,799,312 | 19,518,475     | 10,666,813    | 8,614,024  |
 | 52  | 937,438,138   | 39,865,752 | 19,518,475     | 10,666,813    | 9,680,464  |
 | 53  | 947,003,503   | 40,932,240 | 19,518,475     | 10,666,813    | 10,746,952 |
 | 54  | 956,568,877   | 41,998,968 | 19,518,475     | 10,666,813    | 11,813,680 |
 | 55  | 966,134,247   | 43,065,360 | 19,518,475     | 10,666,813    | 12,880,072 |
 | 56  | 975,699,613   | 44,131,992 | 19,518,475     | 10,666,813    | 13,946,704 |
 | 57  | 985,264,981   | 45,198,352 | 19,518,475     | 10,666,813    | 15,013,064 |
 | 58  | 994,830,352   | 46,701,520 | 20,009,995     | 10,666,813    | 16,024,712 |
 | 59  | 1,004,395,719 | 47,768,016 | 20,009,995     | 10,666,813    | 17,091,208 |
 | 60  | 1,013,961,083 | 48,834,712 | 20,009,995     | 10,666,813    | 18,157,904 |
 | 61  | 1,023,526,446 | 49,901,136 | 20,009,995     | 10,666,813    | 19,224,328 |
 | 62  | 1,033,091,812 | 50,967,768 | 20,009,995     | 10,666,813    | 20,290,960 |
 | 63  | 1,042,657,178 | 48,648,408 | 20,009,995     | 10,666,813    | 17,971,600 |
 | 64  | 1,052,222,550 | 45,149,536 | 20,009,995     | 10,666,813    | 14,472,728 |
 | 65  | 1,061,787,924 | 43,956,016 | 20,009,995     | 10,666,813    | 13,279,208 |
 | 66  | 1,071,353,295 | 40,955,104 | 20,009,995     | 10,666,813    | 10,278,296 |
 | 67  | 1,080,918,658 | 37,954,152 | 20,009,995     | 10,666,813    | 7,277,344  |
 | 68  | 1,090,484,030 | 34,953,328 | 20,009,995     | 10,666,813    | 4,276,520  |
 | 69  | 1,100,049,399 | 31,952,416 | 20,009,995     | 10,666,813    | 1,275,608  |
 | 70  | 1,109,614,764 | 31,284,776 | 18,187,435     | 9,451,725     | 3,645,616  |
 | 71  | 1,119,180,138 | 32,347,616 | 14,998,963     | 7,326,077     | 10,022,576 |
 | 72  | 1,128,745,509 | 31,795,008 | 11,587,555     | 5,051,805     | 15,155,648 |
 | 73  | 1,138,310,873 | 7,037,496  | 4,835,539      | 550,461       | 1,651,496  |

<br>

```
    MB
59.33^                                                     #
     |                                                     #
     |                                                     #
     |                                                    @#
     |                                                    @#          :@
     |                                                   @@#        :::@
     |                                                   @@#       ::::@::
     |                                                  @@@#     ::::::@::
     |                                                  @@@#    :@:::::@:::
     |                                                  @@@#  :::@:::::@:::
     |                                                 @@@@# ::::@:::::@:::::@
     |                                                 @@@@#:::::@:::::@:::::@
     |                                                 @@@@#:::::@:::::@:::::@
     |                                               @@@@@@#:::::@:::::@:::::@
     |                                               @ @@@@#:::::@:::::@:::::@
     |                                               @ @@@@#:::::@:::::@:::::@
     |                                              @@ @@@@#:::::@:::::@:::::@
     |                                              @@ @@@@#:::::@:::::@:::::@
     |                                             @@@ @@@@#:::::@:::::@:::::@
     |            ::::@:@:::@@::@::::::@::@::::::::@@@ @@@@#:::::@:::::@:::::@
   0 +----------------------------------------------------------------------->Gi
     0                                                                   1.060
```
### Flame graph

![flame graph](./../logs/flame.svg)

Click [here](./../logs/flame.svg) to view interactively.