/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-165-sde-2/
Suppose you have a list of 1 billion integers, find 1 million largest integers in this list. List can have repeatative elements, max memory limit is 1 million numbers
*/

164 R4_Q1
165 SDE1- R4_Q1

Refer External Sorting in NK
Idea of finding K largest elements using Min Heap of size K

Initialize a min heap of size k ( i = 1 -> k  gives a heap fo size k )
for i=K+1 -> n
	if ( a[i] > heap[0] )
		heap[0]=a[i]
		percolate_down()

Heap of size K contains K largest elements- This will include duplicates\
THe problem we need 1 million largest number and main memory size is 1 million, where to store the new variable that is to be read????

Also, to get rid of duplicates
Partition file of size 1,000,000,000 into 1000 chunks of 1,000,000
Sort each chunk in descending order and remove duplicates
Now do a k-way merge using max-heap as in case of external sorting and stop when we have popped 1,000,000 largest numbers

In detail:


http://stackoverflow.com/questions/17410399/finding-k-largest-elements-of-a-very-large-file-while-k-is-very-large
You can do this pretty easily with a standard merge type algorithm. Say you have 100 billion numbers and you want the top 10 billion. We'll say you can hold 1 billion numbers in memory at any time.

So you make a pass:
while not end of input
    read 1 billion numbers
    sort them in descending order
    save position of output file
    write sorted numbers to output file

You then have a file that contains 100 blocks of 1 billion numbers each. Each block is sorted in descending order. Now create a max heap. Add the first number of each block to the heap. You'll also have to add the block number or the number's position in the file so that you can read the next number.

Then:
while num_selected < 10 billion
    selected = heap.remove()
    ++num_selected
    write selected to output
    read next number from the selected block and place on heap

There's a small bit of complexity involved, keeping track of which block the number came from, but it's not too bad. The max heap never contains more than 100 items (basically, one item per block), so memory isn't an issue in the second pass. With a bit of work, you can avoid a lot of reads by creating a smallish buffer for each block so that you don't incur the cost of a disk read for every number that's selected. It's basically just a disk merge sort, but with an early out. Complexity of the first pass is b * (m log m), where b is the number of blocks and m is the number of items in a block. N, the total number of items in the file, is equal to b * m. Complexity of the second pass is k log b, where k is the number of items to select and b is the number of blocks.

