// Standard libraries for I/O, data structures, functional operations, and ranges
#include<iostream>
#include<vector>
#include<numeric>  // For std::accumulate
#include<ranges>   // For C++20 ranges and views
//#include <algorithm>

// Demonstrates the use of ranges::views::transform with std::accumulate
// Takes a vector of integers and computes the sum of their squares
void demo_accumulate(const std::vector<int> &nums){

    std::cout<<"\n--- Accumulate Walkthrough ---\n";

    // Use ranges::views::transform to create a view that squares each element
    // The pipe operator (|) chains the vector through the transform operation
    auto squared = nums | std::views::transform([](int x) { return x * x; });
    
    // Use std::accumulate to sum the squared values
    // Initial value is 0, and the lambda adds each squared value to the running sum
    int sum_of_squares = std::accumulate(squared.begin(), squared.end(), 0,
        [](int sum ,int x )-> int{
            // Log each step of the accumulation process
            std::cout<<"Add " << x << " to sum ("<< sum <<")\n";
            return sum + x;
        });

    std::cout<<"Sum of Squares: " << sum_of_squares << "\n";
    

}

int main (){
    // Test vector with values 1 through 5
    std::vector<int> nums = {1,2,3,4,5};

    // Call the demonstration function
    demo_accumulate(nums);

    return 0;
}