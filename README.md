# Lab 2

<img align="right" width="200px" src="./media/timsort.gif">

> "Bentley Rules"

In this lab you are going to implement and time some sorting algorithms, including Timsort in C++.

# Implementation Logistics

- You may use whatever operating system, IDE, or tools for completing this assignment.
	- However, my instructions will usually be using the command-line, and that is what I will most easily be able to assist you with.
- In the future there may be restrictions on what tools you may use, so please review the logistics each time.

# Resources to help

Provided below are a list of curated resources to help you complete the tasks below. Consult them (read them, or do ctrl+f for keywords) if you get stuck.

1. https://www.youtube.com/watch?v=fHNmRkzxHWs
	- Chandler Carruth "Efficiency with Algorithms, Performance with Data Structures"
2. https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399
	- Timsort algorithm reference.

# Task 1 - Timsort

In this lab, you are going to implement and time insertion sort, mergesort, and Timsort on a set of [data.txt](./data.txt) in [sort.cpp](./sort.cpp). Note: You may need to add additional headers for your imlpementations.

This lab will also serve as a light self-guided tour into C++. You are free to organize the project in any way that you like, so long as I can compile with: `g++ -std=c++14 sort.cpp -o sort`

You can toggle several things in this submission:
- The resolution of the timer (currently in nanoseconds)
- The data type of 'data' (currently assummed you will treat it as an integer)
- The amount of data in 'data.txt' if you would like to add more or less.

# Task 2 - Introduction to Performance

Watch the following talk, [Efficiency with Algorithms, Performance with Data Structures](https://www.youtube.com/watch?v=fHNmRkzxHWs) and answer the questions in [exercise.md](./exercise.md)

## Testing

I will look at your [exercise.md](./exercise.md) to make sure you have filled out the answers.

# Submission/Deliverables

- A completed [exercise.md](./exercise.md).
- A completed implementation of [sort.cpp](./sort.cpp)

### Submission

- Commit all of your files to github, including any additional files you create.
- Do not commit any binary files unless told to do so.
- Do not commit any 'data' files generated when executing a binary.

# Rubric

You (and any partner(s)) will receive the same grade from a scale of 0-2. Both partners should commit the same code.

- 0 for no work completed by the deadline
- 1 for some work completed, but something is not working properly
- 2 for a completed lab (with possible 'going further' options completed)

# Going Further

An optional task(if any) that will reinforce your learning throughout the semester--this is not graded.

1. Look up more of Chandler Carruth's talks--he is an expert in the LLVM framework which we will be using.

# F.A.Q. (Instructor Anticipated Questions)

1. Q: Do we just modify the exercises.md?
- A: Yes
2: Q: Can I separate out my class into multiple files?
- A: Sure, you can amke a sort.h file if you like.
