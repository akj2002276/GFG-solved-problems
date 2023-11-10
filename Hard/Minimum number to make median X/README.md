<h2><a href="https://www.geeksforgeeks.org/problems/minimum-number-to-make-median-x3029/1?page=1&difficulty=Hard&sortBy=difficulty">Minimum number to make median X</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Given an unsorted array <strong>arr[]</strong> of<strong> distinct integers</strong>&nbsp;and size <strong>n</strong>, and an element <strong>x</strong>, you need to find the <strong>Minimum Number of Elements</strong> required to be added to this array so the new median of array becomes x.<br>
Median of array is middle element of array in its sorted form.<br>
<strong>Note:</strong> For odd number of elements n it is the element at position (n-1)/2. For even number of elements n, it is (arr[n/2] + arr[(n/2) - 1])/2.</span></p>

<p><span style="font-size:20px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:20px"><strong>Input:
</strong>n = 6 , x = 30
arr[] = {10, 20, 30, 100, 150, 200}
<strong>Output:
</strong>1
<strong>Explanation:</strong>
Only 1 element before 30 is required
to be added to the array, to make median
of array 30.
</span></pre>

<p><br>
<span style="font-size:20px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:20px"><strong>Input:
</strong>n = 5, x = 50
arr[] = {10, 20, 30, 100, 150} <strong>
Output:
</strong>1 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:20px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>minimumAppend()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(num)</strong>, an integer <strong>x</strong>&nbsp;and return the find total number of elements to be added to an array so that the new median becomes equal to <strong>x</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:20px"><strong>Expected Time Complexity:</strong>&nbsp;O(n).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><br>
<span style="font-size:20px"><strong>Constraints:</strong><br>
1 &lt;= <strong>n</strong> &lt;= 10<sup>6</sup><br>
1 &lt;= <strong>x</strong> &lt;= 10<sup>6</sup><br>
1 &lt;= <strong>arr[i]</strong> &lt;= 10<sup>6</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;