#include <iostream>
#include <fstream>

long long y[500000000];

long long hoarePartition(long long left, long long right) {
    long long i = left - 1, j = right + 1;
    long long pivot = y[right - 1]; // As my tutor said, choosing the right most pivot is treated as random

    while (i < j) {
        do {
            i++;
        } while (y[i] < pivot);

        do {
            j--;
        } while (y[j] > pivot);

        if (i < j) {
            long long temp = y[i];
            y[i] = y[j];
            y[j] = temp;
        }
    }
    return j;
}

long long randomizedSelect(long long p, long long r, long long i) {

    if (p == r) {
        return y[p];
    }

    long long q = hoarePartition(p, r);

    long long k = q - p + 1;

    if (i == k) {
        return y[q];
    } else if (i < k) {
        return randomizedSelect(p, q - 1, i);
    } else {
        return randomizedSelect(q + 1, r, i - k);
    }
}

int main(int argc, char *argv[]) {
    // Start reading data
    std::cout << "Loading txt data, please wait..." << std::endl;
    std::ifstream f(argv[1]);
    long long skip[1];
    long long yMax, xMax, n;
    f >> yMax >> xMax >> n;
    for (long long i = 0; i < n; i++) {
        f >> skip[0] >> y[i];
    }
    f.close();
    std::cout << "Data loading done, starts finding the best rail position" << std::endl;
    // finish reading data

    // My algorithms start
    long long y_r = randomizedSelect(0, n - 1, n / 2); // put result in y_r
    // My algorithms end
    std::cout << "The best light rail position (yr) is: " << y_r << std::endl;

    return 0;
}




