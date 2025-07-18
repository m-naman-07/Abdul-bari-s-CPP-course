/*
🔹 1. What is an Array?
An array is a collection of elements of the same data type, stored contiguously in memory.
Each element is accessed by its index, starting from 0.

🔹 2. Array Declaration & Initialization
        int arr[5];       // Declares an array of 5 ints (default values are garbage)
        int arr2[5] = {1, 2, 3};    // Partial init → {1, 2, 3, 0, 0}
        int arr3[] = {1, 2, 3, 4};  // Compiler decides size → size = 4

🔹 3. Input/Output
        int n, arr[100];
        std::cin >> n;
    
        for(int i = 0; i < n; ++i)
            std::cin >> arr[i];

        for(int i = 0; i < n; ++i)
            std::cout << arr[i] << " ";

🔹 4. Array Bounds
❌ No bounds checking in C++:
        arr[1000] = 10;  // ❌ Undefined Behavior if size < 1000
✅ Always ensure size is sufficient and constant:
        const int N = 1e6 + 5;
        int arr[N];  // common in CP

❌ “No bounds checking in C++” — What does it mean?
In C++, when you access an element of an array using an index, the compiler does not automatically check whether that index is within the valid range of the array.
🔥 This means:
You can accidentally access memory outside the array — and the compiler won’t stop you.
🔍 Example:
        int arr[5] = {10, 20, 30, 40, 50};
        std::cout << arr[10];  // ❌ No error from compiler

What happens?
•This is undefined behavior (UB).
•You’re accessing memory that doesn’t belong to arr.
•Your program may:
•Print garbage 🗑
•Crash 💥
•Seem to work sometimes 😬

🧠 Why is this dangerous?
Because:
•You won’t get a compile-time error.
•You may get a runtime crash only sometimes, depending on memory layout.
•Can cause hard-to-debug bugs in CP and projects.


    
🔹 5. Best Practices in CP
Practice                                        Reason
Use const int N = 1e5+5;                        Safer sizing
Initialize with 0 using memset or loops         Avoid garbage values
Prefer std::vector for dynamic sizing           Flexible and safe
Use fast I/O for large inputs                   ios::sync_with_stdio(false);
Always check bounds manually                    Avoid TLE/Segmentation Fault

🔹 6. Memory in Arrays
	•	int arr[5] stores 5 integers contiguously
	•	Access time: O(1)
	•	Works great with loops and pointer arithmetic
        🧠 Where are arrays stored in C++?
                🔹 It depends on how the array is declared:
                
                ✅ 1. Stack Memory — for local arrays
                        int A[5] = {1, 2, 3, 4, 5};  // Local array
                •Stored in the stack.
        	•Fast allocation and deallocation.
        	•But size is limited (usually up to ~1MB total).
        	•Lifespan: ends when the function ends.

                ✅ 2. Heap Memory — for dynamically allocated arrays
                        int* A = new int[5];  // Dynamic array
                •Stored in the heap.
	        •Use new (or better: std::vector) for large or dynamic size.
	        •Must use delete[] to free memory.
	        •Lifespan: until explicitly deallocated.

                ✅ 3. Global / Static Memory — for global or static arrays
                        int A[1000000];       // Global array → stored in global/ static segment

                        void f() {
                                static int B[100];  // Static array → also global/static segment
                        }
                •Stored in the global/static segment of memory.
	        •Initialized to zero by default.
	        •Lifespan: entire program runtime.

❓ What does this do in C++:
                int A[5] = {10, 20, 30, 40, 50};
                std::cout << A;
🧠 Output:
This will not print the array elements.
🔸 Instead, it prints the memory address of the first element of the array A.
        For example, you might see something like:
                0x7ffeefbff5a0

💡 Why?
Because:
•A is actually a pointer to the first element: A == &A[0]
•std::cout doesn’t know how to print the entire array, so it just prints the pointer (memory address)

✅ Correct Way to Print the Array:(mentioned below)
*/
#include <iostream>

int main(){
        int n, arr[10];
        std::cout << "Enter number of elements (max " << 10<< "): ";
        std::cin >> n;
        /*
        here if we give n=7 and run the program it will give garbage values for non-entered elements like that at index [7],[8],[9].
        */
    
        for(int i = 0; i < n; ++i){
                std::cout<<"Enter element no. "<<i<<":";
                std::cin >> arr[i];
        }
        
        for(int i = 0; i < 10; ++i){
                std::cout << arr[i] << " ";

        }
        std::cout<<std::endl;
}
