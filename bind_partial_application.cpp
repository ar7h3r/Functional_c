#include <iostream>
#include <functional> // For std::bind and std::placeholders

int multiply (int x, int y) {
    return x * y;
}

void demo_bind(){

    std::cout<<"\n--- Bind Walkthrough ---\n";
    // Create a new function by binding the first argument of multiply to 10

    auto five_times= std::bind(multiply, std::placeholders::_1, 5);

    int result = five_times(10);
    std ::cout<< "10 multiplied by 5: " << result << "\n";
}

int main(){

    demo_bind();
    return 0;
}