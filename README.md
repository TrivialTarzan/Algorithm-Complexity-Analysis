<h1 align="center">Algorithm Complexity Analysis</h1>
<h3 align="center">A University Project by TrivialTarzan</h3>

<h4 align="left">In this project, I measured the runtime of various algorithms using C++ and visualized the results using Python and Matplotlib. The algorithms analyzed include:</h4>

<ul>
  <li>Insertion Sort</li>
  <li>Selection Sort</li>
  <li>Jump Search</li>
  <li>Binary Search (Recursive)</li>
  <li>Binary Search (Iterative)</li>
  <li>Linear Search</li>
  <li>Cocktail Sort</li>
  <li>Bubble Sort</li>
</ul>

<h4 align="left">The results of the analysis are showcased in tables and graphs. The raw data for each algorithm is available in text files, allowing you to explore the performance of each algorithm in detail.</h4>

### Technologies Used

- <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> C++
- <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/python/python-original.svg" alt="python" width="40" height="40"/> Python
- <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/matplotlib/matplotlib-original.svg" alt="matplotlib" width="40" height="40"/> Matplotlib

### Project Overview

The goal of this project was to analyze and compare the runtime performance of different algorithms. The algorithms are implemented in C++ and measured their execution time on various input sizes. To visualize the results, I used Python and the Matplotlib library to create graphs that display the time complexity of each algorithm.

#### Algorithms Tested:
- **Insertion Sort**: a simple sorting algorithm that builds the final sorted array one item at a time by comparisons.
- **Selection Sort**: an algorithm that sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element.
- **Jump Search**: an algorithm that searches for an element in a sorted list by jumping ahead by a fixed number of steps.
- **Binary Search (Recursive)**: a recursive algorithm to find an element in a sorted list by repeatedly dividing the search range in half.
- **Binary Search (Iterative)**: a non-recursive version of Binary Search that also halves the search range iteratively.
- **Linear Search**: a simple algorithm that checks each element in a list one by one.
- **Cocktail Sort**: a variation of Bubble Sort that traverses through a given array in both directions.
- **Bubble Sort**: a simple sorting algorithm that repeatedly steps through the list, compares adjacent items, and swaps them if they are in the wrong order.

### Example Results

**Comparison of Execution Time: Insertion Sort Sort & Selection Sort**
Comparison of the execution time measurement of two sorting algorithms: Insert Sort and Select Sort for 10 array sizes: n = 1000, 7500, 15000, 45000, 90000, 135000, 180000, 210000, 305000, 400000 in three cases: optimistic, average, and pessimistic.

<h2 align="center">Execution Time Comparison Table</h2>
<p align="center"><img src="algorithm_results/Insert Sort and Select Sort/comparison_graph.png" alt="Comparison Graph" width="600" height="400"></p>

<h2 align="center">Execution Time Comparison Graph</h2>
<p align="center"><img src="algorithm_results/Insert Sort and Select Sort/execution_time_table.PNG" alt="Execution Time Table" width="600" height="400"></p>

**Comparison of Execution Time: Cocktail Sort & Bubble Sort**
Measurement of the execution time of the Cocktail Sort and Bubble Sort algorithms for 5 array sizes: n = 10, 100, 1000, 10000, 100000 in three variants: optimistic, average, and pessimistic.

<h2 align="center">Execution Time Graph</h2>
<p align="center"><img src="algorithm_results/Cocktail Sort/CocktailSort_and_BubbleSort2_comparison_graph.png" alt="Logo" width="600" height="400"></p>


