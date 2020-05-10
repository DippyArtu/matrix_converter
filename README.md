---


---

<h2 id="matrix-converter">Matrix Converter</h2>
<p>This is a small utility program I wrote for my design project.</p>
<p>As an argument, this program will take a file, containing a 36x36 matrix, consisting of 1 (ones) and 0 (zeros), parse it to retrieve a list of 6 digit binary numbers, convert those numbers into decimal format and write it to the output file as a 6 6x6 matrices.</p>
<p>If <code>mean</code> is passed as a third argument to the program, it will find a mean of matrix values and write an result as a 6*6 matrix.</p>
<pre><code>Clarification:            									//for 6 6*6 matrices

res -- resulting matrix											//2d matrix
in --  input array of matrices										//3d matrix

res[i][j] = (in[n][i][1] + .... + in[n][i][6]) / 6							//mean value
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
</ul>

