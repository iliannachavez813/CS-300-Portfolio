# CS-300-Portfolio
CS 300 Data Structures and Algorithms Portfolio

This repository includes my Project One analysis and Project Two C++ program from CS-300 at Southern New Hampshire University. These projects helped me understand how choosing a data structure can affect how a program works, especially when it comes to organizing and searching through information.

## What was the problem you were solving in the projects for this course?

For both projects, I was working on a program for ABC University that would help academic advisors access course information. The program needed to load course information from a file, display courses in alphanumeric order, and show individual courses along with their prerequisites. In Project One, I compared different data structures to figure out which would work best. In Project Two, I put what I learned into practice by creating the actual C++ program.

## How did you approach the problem? Consider why data structures are important to understand.

At first, I didn't realize how much of a difference choosing a data structure could make. I worked with vectors, hash tables, and binary search trees, and each had its own advantages. I compared how they handled loading, searching, and organizing information before deciding that a binary search tree would be a good choice for this project. What stood out to me was that there isn't always one right answer. It depends on what the program needs to do.

## How did you overcome any roadblocks you encountered while going through the activities or project?

I definitely ran into a few challenges throughout this course. Quicksort was one of the harder assignments for me, especially understanding how the pivot worked and how the values moved around. I also had moments when my code wouldn't compile, and I had to go back through it to figure out what I missed. Sometimes it was something as small as a bracket or a file issue. I learned to slow down, read the errors, and work through one problem at a time instead of changing everything at once.

## How has your work on this project expanded your approach to designing software and developing programs?

This course made me think more about planning before I start coding. Before, I was mostly focused on getting the program to work. Now I understand why it's important to think about how the information will be stored and how the program will use it. Writing pseudocode helped me organize my ideas before putting everything into C++. I also learned that the decisions I make early on can affect how easy or difficult the rest of the program becomes.

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

One thing I've been trying to improve is making my code easier to follow, not just for someone else but for myself when I come back to it later. I've learned to separate different tasks into functions, use meaningful names, and add comments where they are helpful. When I had to go back and fix parts of my assignments, I realized how much easier it was when my code was organized. I'm still learning, but I feel like I'm becoming more thoughtful about how I write programs instead of just focusing on getting them finished.

## Run-Time and Memory Analysis

For Project One, I compared three data structures:

Vector: Stores courses in a dynamic array. Searching takes O(n) time, and sorting is needed to display courses in order. Memory usage is O(n).

Hash Table: Provides fast average-case lookups, usually O(1), but does not automatically maintain course order. Memory usage is O(n), including the hash table's storage overhead.

Binary Search Tree: Supports O(log n) average-case searching when reasonably balanced and can print courses in order using an in-order traversal. Memory usage is O(n), including the additional pointers stored in each node.

Comparing these structures helped me understand that performance isn't just about speed. Memory usage and how the data needs to be organized also matter.
