#include <iostream>
#include <vector>

long long stairsCount(int n) {
    std::vector<long long> ways(n + 1, 0);

    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {
        long long oneStep = ways[i - 1];
        long long twoStep = (i - 2 >= 0) ? ways[i - 2] : 0;
        long long threeStep = (i - 3 >= 0) ? ways[i - 3] : 0;

        ways[i] = oneStep + twoStep + threeStep;
    }

    return ways[n];
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::cout << stairsCount(N) << std::endl;
    }

    return 0;
}
