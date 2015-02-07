External Sorting
Q2. Given a dump of items sold in a file (not organized), give the top n items sold. Eg. the file looks like:
< item1 sold >
< item2 sold >
< item1 sold >
< item9 sold >
Also, there might be same items sold but they might have different names because of different vendors. So you also need to count them together (Hint: Use ids of the items).

Q2. Given a dictionary like text file, find n top occurring words in it i.e. n words whose count is the maximum. Hint: Use Hashing and Min-Heap.

http://www.careercup.com/question?id=4072082

How to sort a 1000 GB file with ram size is 4 GB only. Which algorithm or data structure we need to use to sort these files? 

Assuming that they wanted a algorithmic approach,

Use: a two pass approach
First pass chunk sorting:
1. Load chunks of 4 GB data in memory and do an in place sort (Merge Sort or Quick Sort).
2. Write the chunk back to the same place on disk
3. Repeat 250 times (until end of file or all data is consumed)

Second Phases "merge":
Now you have a choice to merge, what is going to be your "Bucket size" which will govern the N in a N-way-merge. (This gets real tricky, real fast)
In this case we have 250 chunks of 4 GB each,
One way to do this is,
1. Load first 8.192 MB from each of 250 chunks (250*8.192 MB = 2GB) this is our input buffer and rest of the 4 GB is our output buffer
2. Do a 250 ways merge on this 250 sorted bins / buckets
3. When any of the 250 bins is empty load it with the next 8.192 MB from the associated chunks
4. When Output buffer of 2 GB is full - write out the buffer to the external storage.

Additional passes might be necessary to ensure all the numbers are sorted.

Heapsort would be an example of an in-place sort, but it's not very appropriate for files. The trick with manipulating files is that you want to read and write to them in a contiguous way because disk seeks are slow. Heapsort accesses data in a highly non-contiguous way as you move up and down the heap, so it's not a great choice.

Quicksort might be a good fit in this case. The main challenge of quicksort is the in-place partitioning of an array with respect to a pivot, which is something that can be done without much random access of the file. You write elements starting from the front and elements starting from the back in a contiguous way (buffer up values in memory until you have enough of them to write). Quicksort isn't really 100% in-place, requiring something like O(log N) memory, but that's a very small amount even for large N.

Quicksort does have shortcomings like degenerate cases that potentially take O(N^2) time. If you don't want to use random pivots to avoid degenerate cases, it's possible to choose the median as the pivot. There are linear-time median-selection algorithms like "median of medians", which can also be done with only logarithmic extra memory.
