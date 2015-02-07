/*
http://www.geeksforgeeks.org/amazon-interview-experience-set-169-sde-2/
.Given a million list of co-ordinates in the form of longitude and latitude just as Google maps .How will you print closest k cities to a given location .
*/
http://stackoverflow.com/questions/9202315/algorithm-to-find-100-closest-stars-to-the-origin
Q: There is a file containing more than a million points (x,y) each of which represents a star. There is a planet earth at (a,b). Now, the task is to build an algorithm that would return the 100 closest stars to earth. What would be the time and space complexities of your algorithm.

This question has been asked many times in various interviews. I tried looking up the answers but could not find a satisfactory one.

One way to do it which I thought might be using a max heap of size 100. Calculate distances for each star and check if the distance is lesser than the root of the max heap. If yes, replace it with the root and call heapify.

In above solution, complexity- O(NlogK) time and O(logK) space
Now if lets say entire N array cannot fit into memory
So keep K sized space for finding minimum k and load Size-K sized buffer of input data
For each input data set try thenormal method on max heap and after the data exhausts, load another set of Size-k sized data and repeat the step.
At the end we have k sized heap storing minimum distance elements

Complexity-
O(S-K)logK*{N/(S-K)} -> O(NlogK)

METHOD 2-

You can actually do this in time O(n) and space O(k), where k is the number of closest points that you want, by using a very clever trick.

The selection problem is as follows: Given an array of elements and some index i, rearrange the elements of the array such that the ith element is in the right place, all elements smaller than the ith element are to the left, and all elements greater than the ith element are to the right. For example, given the array

40  10  00  30  20

If I tried to select based on index 2 (zero-indexed), one result might be

10  00  20  40  30

Since the element at index 2 (20) is in the right place, the elements to the left are smaller than 20, and the elements to the left are greater than 20.

It turns out that since this is a less strict requirement than actually sorting the array, it's possible to do this in time O(n), where n is the number of elements of the array. Doing so requires some complex algorithms like the median-of-medians algorithm, but is indeed O(n) time.

So how do you use this here? One option is to load all n elements from the file into an array, then use the selection algorithm to select the top k in O(n) time and O(n) space (here, k = 100).

But you can actually do better than this! For any constant k that you'd like, maintain a buffer of 2k elements. Load 2k elements from the file into the array, then use the selection algorithm to rearrange it so that the smallest k elements are in the left half of the array and the largest are in the right, then discard the largest k elements (they can't be any of the k closest points). Now, load k more elements from the file into the buffer and do this selection again, and repeat this until you've processed every line of the file. Each time you do a selection you discard the largest k elements in the buffer and retain the k closest points you've seen so far. Consequently, at the very end, you can select the top k elements one last time and find the top k.

What's the complexity of the new approach? Well, you're using O(k) memory for the buffer and the selection algorithm. You end up calling select on a buffer of size O(k) a total of O(n / k) times, since you call select after reading k new elements. Since select on a buffer of size O(k) takes time O(k), the total runtime here is O(n + k). If k = O(n) (a reasonable assumption), this takes time O(n), space O(k).


S- size of memory if loading S sized data into the memory and then doing sleection algorithm for K
O(S)N/(S-K) -> O(N) still

O(S) + O(S-K)*(N-S)/(S-K)	-> O(N) still

To this I would add one more optimization. Before adding a new element to the buffer, discard if it is larger than the k'th largest found in previous iterations. And in this "larger than" test, you can first check whether any single coordinate is larger before you test the actual distance. This doesn't change the big-O at all, but it avoids a lot of distance calculations, and the square root operation is fairly slow. So you get a better constant.
You can always avoid the sqrt operation, since sqrt is a monotonic function. Points that minimize distance also minimize distance squared (the square cancels out the sqrt
