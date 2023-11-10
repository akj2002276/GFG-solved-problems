<h2><a href="https://www.geeksforgeeks.org/problems/number-of-distinct-words-with-k-maximum-contiguous-vowels--141631/1?page=3&difficulty=Hard&sortBy=difficulty">Number of distinct words with K maximum contiguous vowels</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels.&nbsp;</span></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 2</span>
<span style="font-size:18px">K = 0</span>
<span style="font-size:18px"><strong>Output:</strong>
441
</span><span style="font-size:18px"><strong>Explanation:</strong>
Total of 441 unique words are possible
of length 2 that will have K( =0) vowels
together, e.g. "bc", "cd", "df", etc are
valid words while "ab" (with 1 vowel) is
not a valid word.</span>

</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 1</span>
<span style="font-size:18px">K = 1</span>
<span style="font-size:18px"><strong>Output:</strong>
26</span>
<span style="font-size:18px"><strong>Explanation:</strong>
All the english alphabets including</span>
<span style="font-size:18px">vowels and consonants; as atmost K( =1)
vowel can be taken.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong>&nbsp;&nbsp;<br>
You don't need to read input or print anything. Your task is to complete the function <strong>kvowelwords</strong>()&nbsp;which takes an Integer N, an intege K and returns the total number of words of size N with atmost K vowels. As the answer maybe to large please <strong>return answer modulo 1000000007</strong>.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N*K)<br>
<strong>Expected Auxiliary Space:</strong> O(N*K)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 1000</span><br>
<span style="font-size:18px">0 ≤ K ≤ N</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;