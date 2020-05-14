---


---

<h2 id="matrix-converter">Matrix Converter</h2>
<p>This is a small utility program I wrote for my design project.</p>
<p>As an argument, this program will take a file, containing a <em><strong>36x36</strong></em> matrix, consisting of 1 (ones) and 0 (zeros), parse it to retrieve a list of 6 digit binary numbers, convert those numbers into decimal format and write it to the output file as a 6 <em><strong>6x6</strong></em> matrices.</p>
<ul>
<li>If <code>mean</code> is passed as a third argument to the program, it will find a mean of matrix values and write an result as a 6*6 matrix.</li>
</ul>
<p><em><strong>Clarification:</strong></em>	<br>
<em>for 6 6x6 matrices</em></p>
<pre><code>res -- resulting matrix													//2d matrix
in --  input array of matrices											//3d matrix

res[i][j] = ((in[n][i][1] + .... + in[n][i][6]) / 6)					//mean value
</code></pre>
<ul>
<li>if <code>distrib</code> is passed as a third argument to the program, it will create a <strong>6x7</strong> “frequency distribution” matrix of values at intervals of <strong>30</strong> – how many <strong>1’s</strong> are there per each <strong>30</strong> values.</li>
</ul>
<p><em><strong>Clarification:</strong></em><br>
<em>for interval of 5 and 2x5 matrix</em></p>
<pre><code>An input of:

							1 0 1 1 0
							0 0 1 0 1
				
Would yield a resulting:

							3 
							2
</code></pre>
<h2 id="how-to-use">How to use</h2>
<ul>
<li>
<p>Compile the program (make sure the script has approporiate permissions)</p>
<pre><code> ./compile
</code></pre>
</li>
<li>
<p>Run the program</p>
<pre><code> ./matrix_converter *input file* [mean]
</code></pre>
</li>
<li>
<p>Results will be written into the <em>result.txt</em> file</p>
</li>
<li>
<p>Results with the <code>mean</code> parameter will be writter into the <em>results_mean.txt</em> file</p>
</li>
<li>
<p>Results with the <code>distrib</code> parameter will be writter into the <em>results_distrib</em>.<strong>fdf</strong> file</p>
</li>
</ul>
<h3 id="p.s.">P.S.</h3>
<ul>
<li>
<p>The digits in the <em><strong>input</strong></em> matrix should be divided by <em>spaces</em>, with no extra spaces of symbols at the end of the line</p>
<pre><code> Example:
 
 			0 1 1
 			1 0 1
 			0 0 0
</code></pre>
</li>
<li>
<p>Only <em><strong>36x36</strong></em> input matrix is valid</p>
</li>
<li>
<p>Apart from basic argument error checking, there isn’t a proper error handling system (file content, map validity etc.), so if the program crashes, you have most likely supplied an incorrect input matrix.</p>
</li>
</ul>
<p>goodnote</p>

