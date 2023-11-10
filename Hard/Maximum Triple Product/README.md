<h2><a href="https://www.geeksforgeeks.org/problems/maximum-triple-product/1?page=10&difficulty=Hard&sortBy=difficulty">Maximum Triple Product</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">You are given an array <strong>arr</strong>&nbsp;of <strong>N</strong> integers. You need to find the <strong>maximum&nbsp;</strong>score of an array.</span></p>

<p><span style="font-size:18px">The score of an array is calculated as follows.</span></p>

<ul>
	<li><span style="font-size:18px">Choose an integer<strong> i</strong>, <strong>1&lt;=i&lt;=size of current array</strong> and add <strong>a[i-1] * a[i] * a[i+1]</strong> to the score.</span></li>
	<li><span style="font-size:18px">Delete <strong>a[i],</strong>&nbsp;on deleting a[i],&nbsp;<strong>i-1 and i+1</strong> become adjacent. i.e <strong>i+1</strong> becomes <strong>i</strong> and size of an array <strong>shrinks.</strong></span></li>
	<li><span style="font-size:18px">Repeat the process till the size of an array becomes <strong>0</strong>.</span></li>
</ul>

<p><span style="font-size:18px"><strong>Note:</strong>&nbsp; Assume an extra <strong>1</strong> at each boundary.</span></p>

<p>&nbsp;</p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<div style="background:#eeeeee; border:1px solid #cccccc; padding:5px 10px">
<p><span style="font-size:18px"><strong>Input:</strong></span><br>
<span style="font-size:18px">N =&nbsp;2<br>
arr = { 5, 10 }<br>
<br>
<strong>Output:&nbsp;</strong><br>
60<br>
<br>
<strong>Explanation:</strong></span></p>

<p><span style="font-size:18px">F</span><span style="font-size:18px">irst choose i=1</span><span style="font-size:18px">, Score = 1*5*10<br>
Then choose i=1, Score+= 1*10*1,<br>
Total = 60</span></p>
</div>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<div style="background:#eeeeee; border:1px solid #cccccc; padding:5px 10px">
<p><span style="font-size:18px"><strong>Input:</strong></span><br>
<span style="font-size:18px">N = 5<br>
arr = { 1, 2, 3, 4, 5&nbsp;}<br>
<br>
<strong>Output:&nbsp;</strong><br>
110</span></p>
</div>

<p><span style="font-size:18px"><strong>Your Task:</strong></span><br>
<span style="font-size:18px">You do not need to read input or print anything. Your task is to complete the function<strong> maxProductSum()</strong>&nbsp;which takes the value <strong>N</strong> and the array as input parameters and returns <strong>maximum score of an array.</strong></span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N<sup>3</sup>)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N<sup>2</sup></span><span style="font-size:18px">)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 100<br>
1 ≤ arr[i] ≤ 100000</span></p>
</div>