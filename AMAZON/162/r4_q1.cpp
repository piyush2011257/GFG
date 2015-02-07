162- R4_Q1
165- R4_Q1
String- Duplicate / COmpare / ANagram
External Sorting + Inplace Sort
External Sorting + Hashing
Hashing - Hash functions-	Sorted alphabets
				Each alphabet represents a prime 26th alphabet is 101. Use %1000000007 and use hashing collision resolution
				Count of letters
Trie / TST

http://www.geeksforgeeks.org/amazon-interview-experience-set-162/
Given 2 files find common words.
Both files are too large to be loaded in memory.


Lets first solve a simpler version- Duplicates in a large file
http://stackoverflow.com/questions/9215820/find-duplicates-in-large-file
http://stackoverflow.com/questions/3897295/find-duplicate-strings-in-a-large-file
http://www.careercup.com/question?id=5713445122998272

Split the file into N pieces. On each machine, load as much of the piece into memory as you can, and sort the strings. Write these chunks to mass storage on that machine. On each machine, merge the chunks into a single stream, and then merge the stream from each machine into a stream that contains all of the strings in sorted order. Compare each string with the previous. If they are the same, it is a duplicate.


External Sort
Lets say we have 1 GB RAM and 5 GB of file
Now how to find duplicate
-> At any moment we can load at max 1 GB of data.
-> Divide file into 5 chunks each of 1 GB
-> Sort each of the 1 GB chunk and remove duplicates and write to disk
-> Now we have each of the 5 chunks sorted ( without duplicates ) in the disk
-> Now use k-way merge sort for these 5 chunks
-> Load 1/5 GB of data from each chunk and use a k-way merge sort logic to merge these 5 files and list / remove duplicates
Alternately we can keep 200 MB for output buffer and instead of 1/5 GB -> 0.8/5 GB of data is loaded and when output buffer is full, flush it to standard I/O

In practice, it might provide better performance to make the output buffer larger and the input buffers slightly smaller.

http://en.wikipedia.org/wiki/External_sorting
External merge sort

One example of external sorting is the external merge sort algorithm, which sorts chunks that each fit in RAM, then merges the sorted chunks together. For example, for sorting 900 megabytes of data using only 100 megabytes of RAM:

    Read 100 MB of the data in main memory and sort by some conventional method, like quicksort.

    Write the sorted data to disk.

    Repeat steps 1 and 2 until all of the data is in sorted 100 MB chunks (there are 900MB / 100MB = 9 chunks), which now need to be merged into one single output file.

    Read the first 10 MB (= 100MB / (9 chunks + 1)) of each sorted chunk into input buffers in main memory and allocate the remaining 10 MB for an output buffer. (In practice, it might provide better performance to make the output buffer larger and the input buffers slightly smaller.)

    Perform a 9-way merge and store the result in the output buffer. Whenever the output buffer fills, write it to the final sorted file and empty it. 

When to load next set of data from each chunk?
Whenever any of the 9 input buffers empties, fill it with the next 10 MB of its associated 100 MB sorted chunk until no more data from the chunk is available. This is the key step that makes external merge sort work externally -- because the merge algorithm only makes one pass sequentially through each of the chunks, each chunk does not have to be loaded completely; rather, sequential parts of the chunk can be loaded as needed.

We need to take care of disk accesses as well !!

Of course, this can be sped up if we have more memory available. For example, using a hash set instead of a sorted array will use slightly more memory but also run a bit faster. O(nlogn) -> O(n) but needs extra memory

Now for finding duplicates in 2 files
Method 1-
extend the solution for 2 files.
sort each file and merge


Method 2-
Trie / TST usage
Let average length of words be L
26*26*...*26  ( L times )  -> Number of distinct words max of Length L
if 26^L fits into memory wee within range.
SIze of each node -> 1 char + 3 pointer variables ( 3*8) + 1 boolean is_Word -> 26 bytes per node
(26^L)*26 Bytes needed !!
Maintain a TST in the main memory and usin is_word marker we can check for duplicates.
E.g. My name is Piyush Raman Srivastava. I study in Indian Institute of Information Technology Jabalpur


Of
I	In	dian			( Space saving here )
		stitute
		formation
	I
	Is
Jabalpur
My
Name
Piyush
Raman
Srivastava
Technology

Build a TST and CHeck
Building TST- O(N*L)
N- no. of words
L- max length of word

Load chunks of file and add entry
Now for second file directly check is is_word == true
