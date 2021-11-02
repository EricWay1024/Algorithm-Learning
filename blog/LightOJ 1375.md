# LightOJ 1375

$$
\begin{align}
\sum_{i<n} [i, n] &= \sum_{i<n} \frac{i}{(i,n)} \cdot \frac{n}{(i,n)} \cdot (i,n) \\
&=\sum_{d \mid n,\\ d < n} \sum_{d \mid i, \\ (\frac id, \frac nd)=1,\\ i<n} \frac id \cdot \frac nd \cdot d \\
&=\sum_{d \mid n, \\ d < n} \sum_{(j,d)=1,\\j<d} j \cdot n \\
&= n \cdot \sum _{d \mid n} \frac{d \cdot \phi(d)}{2}
\end{align}
$$

