Program 1 instructions
This assignment is adapted from one that is included with the COMPSCI 424 zyBook. I've extended it and made it mostly auto-gradable.

Project objective
Compare the performance of process creation and destruction when implemented with and without linked lists.

 

Description
Version 1
Version 1 of the process creation hierarchy uses linked lists to keep track of child processes. In Version 1, each process's control block (PCB) contains

a pointer to its parent process and
a linked list of pointers to 0 or more child processes.
For the purposes of performance evaluation, the PCBs are simplified as follows:

All PCBs are implemented as an array of size n.
Each process is referred to by the PCB index, 0 through n-1.
Each PCB is a structure consisting of only the two fields:
parent: a PCB index corresponding to the process's creator
children: a pointer to a linked list, where each list element contains the PCB index of one child process
The necessary functions are simplified as follows:

create(p) represents the create function executed by process PCB[p]. The function creates a new child process PCB[q] of process PCB[p] by performing the following tasks:
allocate a free PCB[q]
record the parent's index, p, in PCB[q]
initialize the list of children of PCB[q] as empty
create a new link containing the child's index q and appends the link to the linked list of PCB[p]
destroy(p) represents the destroy function executed by process PCB[p]. The function recursively destroys all descendant processes (child, grandchild, etc.) of process PCB[p] by performing the following tasks:
for each element q on the linked list of children of PCB[p]:
destroy(q) /* recursively destroy all descendants */
free PCB[q]
deallocate the element q from the linked list
 

Version 2
Version 2 of the same process creation hierarchy uses no linked lists. Instead, each PCB contains the 4 integer fields parent, first_child, younger_sibling, and older_sibling, as described in the subsection "Avoiding linked lists". Here is the relevant text from our zyBook, section 2.3.

Linked lists require dynamic memory management, which is costly. The Linux OS has pioneered an approach that eliminates this overhead.

Instead of a separate linked list anchored in the parent's PCB, the links are distributed over the child PCBs such that each points to the immediate younger sibling and immediate older sibling. The original 2 fields, parent and children, in the PCB of a process p are replaced by 4 new fields:

parent: points to p's single parent as before
first_child: points to p's first child
younger_sibling: points to the sibling of p created immediately following p
older_sibling: points to the sibling of p created immediately prior to p
This implementation requires no dynamic memory management.

Screenshot of Participation Activity 2.3.10 from the COMPSCI 424 zyBook.
 

Assignment
Write a program in Java, C++, C, or Python that provides the following structure and functionality.

If needed, implement separate classes for process control blocks (PCBs) for Version 1 and Version 2, described in the Description section, following the guidance in the Description section.
Implement Version 1 and Version 2 of the process creation hierarchy, described in the Description section, as separate classes or objects. Both version must provide the following functions or methods.
create(int parentPid)
Allocates and initializes a free PCB object from the array of PCB objects
For version 1, inserts the newly allocated PCB object into parentPid's list of children
For version 2, connects the newly allocated PCB object to parentPid and, if it has siblings, its sibling process(es)
If parentPid is not in the process hierarchy, do nothing; your code may return an error code or message in this case, but it should not halt
destroy(int targetPid)
Recursively destroys all descendants of targetPid and marks their PCBs as "free" in the PCB list (i.e., deallocates them)
For version 1, removes targetPid from its parent's list of children
For version 2, adjusts connections within the hierarchy graph as needed to re-connect the graph
If targetPid is not in the process hierarchy, do nothing; your code may return an error code or message in this case, but it should not halt
showProcessTree()
Recursively traverse the process creation hierarchy graph, printing information about each process as you go.
The output must follow the format in this example.
Process 0: parent is -1 and children are 1 2
Process 1: parent is 0 and children are 3
Process 2: parent is 0 and has no children
Process 3: parent is 1 and has no children
For Process 1 in this example, child is 3 is an allowed alternative to children are 3.
Output may be returned to the calling function or sent directly to standard output using println, cout, printf, or similar: your choice.
Write a main method or function that provides the following workflow.
Ask the user to enter commands of the form "create N", "destroy N", or "end", where N is an integer between 0 and 15.
While the user has not typed "end", continue accepting commands. Add each command to a list of actions to take while you run the simulation.
Hint: the commands could be stored as a list of (string, int) pairs, or you might think of another way to store them.
When the user types "end" (or optionally any word that is not "create" or "destroy"), stop accepting commands and complete the following steps.
Create an object of the Version 1 class and an object of the Version 2 class.
Run the command sequence once with the Version 1 object, calling its showProcessTree method after each command to show the changes in the tree after each command.
Repeat step 5, but with Version 2.
Store the current system time in a variable, then run the command sequence 200 times with Version 1. After this, store the new current system time in a second variable. Subtract the start time from the end time to get the Version 1 running time, then display the Version 1 running time.
Repeat step 7, but with Version 2.
 

Built-in timing functions for each supported language (Java, C, C++, Python) will be posted on the Program 1 Canvas assignment page.

You will submit your assignment using GitHub Classroom. More information will be posted on Thursday night, Feb. 9, or Friday, Feb. 10.

Your program will be graded on completeness and correct implementation. See the rubric that will be posted on Canvas.
