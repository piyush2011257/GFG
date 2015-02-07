http://www.geeksforgeeks.org/amazon-interview-experience-set-166-sde/
You have a list of program files, how will you decide which file to compile first and which later, what data structure you will use for storing these dependencies.


What does the question say?
Consider 2 files

test.cpp
#include<cstdio>

void func(int a )
{       printf("%d\n",a);       }

test1.cpp
#include<test>
#include<cstdio>
using namespace std;

int main()
{       printf("yeah\n");
        return 0;
}

Now if we do:
ccuser@CCHall:~$ g++ test1.cpp 
test1.cpp:1:15: fatal error: test: No such file or directory
 #include<test>
               ^
compilation terminated.

so we need to compile test first and then test1

Soluion-
http://www.careercup.com/question?id=5717669093310464
You are given a text file that has list of dependencies between (any) two projects in the soure code repository. Write an algorithm to determine the build order ie. which project needs to be build first, followed by which project..based on the dependencies.
Bonus point: If you can detect any circular dependencies and throw an exception if found.

EX: ProjectDependencies.txt
a -> b (means 'a' depends on 'b'..so 'b' needs to be built first and then 'a')
b -> c
b -> d
c -> d

Then the build order can be

d , c, b, a in that order

1. Read the file and build graph from its contents
2. Use DFS to check for cycles
3. If cycle is detected throw an exception
4. Else, apply topological sort on the graph
5. Print the result

Now how to get these dependencies?
We can determine dependencies by analyzing #include<tags>

Assume we have a list of all standard libraries available. Now check each tag in #include<tag> and check if it belongs to standard libraries.
If not then we have a dependency
FOr. e.g. in above 2 files
test1 has #include<test>

This gives dependency test -> test1 i.e. we need to compile test first and then test1
Thus we have a graph representing all the dependencies.
Ordering of compilation-
Topological Sort

Check for cyclic redudancy- Dfs to check cycle in directed graphs

