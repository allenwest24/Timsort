// Compile with: g++ -std=c++14 sort.cpp -o sort 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <chrono> // For timing

using namespace std;

// A C++ class
class Sort{
    public:
    int numbers[16384];
    
    // The constructor
    Sort(std:: string filename){
        // Read in a file of data
	ifstream myfile;
        myfile.open(filename);
        string line;
        int curr = 0;
        while (getline(myfile, line)) {
                numbers[curr] = stoi(line);
                curr += 1;
        }
    }

    // Destructor
    ~Sort(){
    }

    void insertionsortHelper(int arr[], int left, int right) {
	int ii, jj, key;
        for (ii = left + 1; ii <= right; ii++) {
            key = arr[ii];
            jj = ii - 1;
            while (jj >= 0 && arr[jj] > key) {
                arr[jj + 1] = arr[jj];
                jj -=  1;
            }
            arr[jj + 1] = key;
        }

    }

    // insertionsort
    void insertionsort(int arr[], int left, int right){
        auto start = std::chrono::steady_clock::now();    
	insertionsortHelper(arr, left, right);
        auto end = std::chrono::steady_clock::now();
        std::cout << "Elapsed time in nanoseconds : " 
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
		<< " ns" << std::endl;
    }

    void merge(int arr[], int left, int middle, int right) {
    	int ii, jj, kk;
    	int n1 = middle - left + 1;
    	int n2 =  right - middle;
    	int leftTemp[n1], rightTemp[n2];
    	for (ii = 0; ii < n1; ii++) {
            leftTemp[ii] = arr[left + ii];
    	}
    	for (jj = 0; jj < n2; jj++) {
            rightTemp[jj] = arr[middle + 1 + jj];
    	}
    	ii = 0;
    	jj = 0;
    	kk = left;
        while (ii < n1 && jj < n2) {
            if (leftTemp[ii] <= rightTemp[jj]) {
            	arr[kk] = leftTemp[ii];
            	ii++;
            }
            else {
                arr[kk] = rightTemp[jj];
                jj++;
            }
            kk++;
        }
        while (ii < n1) {
            arr[kk] = leftTemp[ii];
            ii++;
            kk++;
        }
        while (jj < n2) {
            arr[kk] = rightTemp[jj];
            jj++;
            kk++;
        }
    }

    void mergesortHelper(int arr[], int left, int right) {
	if (left < right) {
            int middle = left + (right - left) / 2;
            mergesortHelper(arr, left, middle);
            mergesortHelper(arr, middle + 1, right);
            merge(arr, left, middle, right);
        }
    }


    // mergesort
    void mergesort() {
        auto start = std::chrono::steady_clock::now();    
        mergesortHelper(this->numbers, 0, 9999);
        auto end = std::chrono::steady_clock::now();
        std::cout << "Elapsed time in nanoseconds : " 
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
		<< " ns" << std::endl;
    }

    // timsort
    void timsort() {
        auto start = std::chrono::steady_clock::now();
    	for (int ii = 0; ii < 1000; ii+=625) {
            insertionsortHelper(this->numbers, ii, min(ii+624, 10000));
        }
        for (int size = 625; size < 10000; size = 2*size) {
            for (int left = 0; left < 10000; left += 2*size) {
                int mid = left + size - 1;
                int right = min((left + 2*size - 1), (10000-1));
                merge(this->numbers, left, mid, right);
            }
        }
        auto end = std::chrono::steady_clock::now();
        std::cout << "Elapsed time in nanoseconds : " 
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
		<< " ns" << std::endl;
    }
};




int main(){

    Sort s1("data.txt");
    Sort s2("data.txt");
    Sort s3("data.txt");

    s1.insertionsort(s1.numbers, 0, 10000);
    s2.mergesort();
    s3.timsort();

    return 0;
}
