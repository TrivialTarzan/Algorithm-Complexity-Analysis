# Algorithm-Complexity-Analysis

Time Complexity Benchmark

Overview

This repository contains an analysis of the runtime complexity of various sorting and searching algorithms. The project was conducted as part of a university research assignment to study and compare the performance of different algorithms under various conditions.

Algorithms Tested

The following algorithms were implemented in C++ and benchmarked:

Sorting Algorithms

Insertion Sort

Selection Sort

Cocktail Sort

Bubble Sort

Searching Algorithms

Jump Search

Binary Search (Recursive)

Binary Search (Iterative)

Linear Search

Data Visualization

To better illustrate the performance differences, the results have been presented in:

Tables – showcasing execution times for different input sizes.

Graphs – generated using Python and the matplotlib library.

Repository Structure

📂 Time-Complexity-Benchmark
├── 📂 code/                 # C++ implementations of algorithms
├── 📂 data/                 # Raw text files containing benchmark results
├── 📂 graphs/               # Python-generated graphs visualizing results
├── 📜 results.xlsx          # Summarized benchmark data in Excel format
├── 📜 README.md             # Project documentation

How to Use

Clone the repository:

git clone https://github.com/your-username/Time-Complexity-Benchmark.git

Navigate to the project directory:

cd Time-Complexity-Benchmark

Compile and run the C++ benchmarking program:

g++ -o benchmark benchmark.cpp && ./benchmark

Use Python to generate graphs from the collected data:

python generate_graphs.py

Dependencies

Ensure you have the following installed:

C++ Compiler (GCC, Clang, or MSVC)

Python 3.x

Matplotlib (pip install matplotlib)

License

This project is open-source and available under the MIT License.

Acknowledgments

This project was developed as part of a university research initiative focused on analyzing the time complexity of fundamental algorithms. Special thanks to faculty mentors for their guidance.
