# Process-Scheduling

We started by implementing the Round Robin scheduler which uses an ArrayList and keeps
processes on a queue and cycles through them, granting each process a small fixed amount of
time on the CPU before pausing it and moving on to the next process. We implemented the
generic ArrayList and tested it thoroughly. We also implemented the LinkedList as it is the basis
of a more efficient and time saving scheduler the Fast Round Robin. We then checked for any
significant memory leaks using Valgrind and tried to get rid of them. We also checked the
coverage using gcov to make sure a significant part of what we wrote was being used and it met
the minimum coverage requirements. The program can be tested by writing ‘make’ and then
once it is done we follow by writing ‘./ArrayList_TEST’ or ./LinkedList_TEST’. We also
implemented the simulation to see the differences in the times taken which can be run by typing
‘./schedulism 10 1000 1000000’.

In the Round Robin scheduler, I/O bound processes tend to get fairly little CPU time and spend
a lot of time waiting, which causes frustration for users. Therefore, we implemented the
Completely Fair Scheduler, which handles this problem in an elegant manner. The idea is to
maintain a container of processes sorted by how much CPU time they have been given so far
and to always pick the process with the least CPU time. This way, if an I/O-bound process uses
the CPU for a short time and then blocks when it unblocks it will still be close to the front and
can use the CPU when it needs it. We use a Binary Search Tree to accomplish this. We
implemented the Binary Search tree and then checked for any significant memory leaks using
Valgrind and tried to get rid of them. We also checked the coverage using gcov to make sure a
significant part of what we wrote was being used and it met the minimum coverage
requirements. The program can be tested by writing ‘make’ and then once it is done we follow
by writing ‘./BSTMultimap_TEST’. The simulation can also be run in a similar manner to the
Round Robin. Looking at that we can see that it is faster on average.

Completely Fair Scheduler using a binary search tree improves a lot of I/O-bound processes but
at great overhead cost. The scheduler constantly removes nodes from the “left side” of the tree
and inserts them on the “right side,” causing a severe imbalance in the BST, making insertion
and removal more like O(n) than O(log n). Therefore, we implement a multimap using a
red-black tree. This was we are able to come up with the Fast Completely Fair Scheduler which
is more efficient than all of the previous schedulers we had. We implemented the red black tree
and then checked for any significant memory leaks using Valgrind and tried to get rid of them.
We also checked the coverage using gcov to make sure a significant part of what we wrote was
being used and it met the minimum coverage requirements. The program can be tested by
writing ‘make’ and then once it is done we follow by writing ‘./RBTMultimap_TEST’. The
simulation can also be run in a similar manner to the Round Robin. Looking at that we can see
that it is faster on average than all of the previous ones.
