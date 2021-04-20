#include <iostream>
#include <vector>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED   "\033[31m"
namespace ft {
	int getRandomNumber(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	template <typename T>
	void swap(T *lhs, T *rhs) {
		T tmp = *lhs;
		*lhs = *rhs;
		*rhs = tmp;
	}
	template <typename T>
	void print_arr(T *arr, size_t size) {
		for (size_t i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	template <typename T>
	bool check_arr(T *arr, size_t size) {
		for (size_t i = 0; i < size - 1; ++i)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}
	template <typename T>
	void buble_sort(T* arr, size_t size) {
		for (size_t i = 0; i < size - 1; ++i)
			for (size_t j = 0; j < size - 1 - i; ++j)
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
	}
	template <typename T>
	void insertion_sort(T *arr, size_t size) {
		for (size_t i = 1; i < size; i++) {
			T key = arr[i];
			int j = static_cast<int>(i - 1);
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
		}
	}
	template <typename T>
	void choice_sort(T *arr, size_t size) {
		int min;
		for (size_t i = 0; i < size - 1; i++) {
			min = i;
			for (size_t j = i + 1; j < size; j++)
				if (arr[j] < arr[min])
					min = j;
			swap(&arr[i], &arr[min]);
		}
	}
	template <typename T>
	int getMax(T *arr, size_t size) {
		T max = arr[0];
		for (int i = 1; i < size; i++)
			if (arr[i] > max)
				max = arr[i];
		return max;
	}
	template <typename T>
	void count_sort(T* arr, size_t size) {
		T min, max;
		max = min = arr[0];
		for (size_t i = 1; i < size; i++) {
			if (arr[i] < min)
				min = arr[i];
			if (arr[i] > max)
				max = arr[i];
		}
		size_t count_size = max - min + 1;
		T *counts = new T[count_size];
		std::memset(counts, 0, count_size - 1);
		for (size_t i = 0; i < size; i++)
			counts[arr[i] - min]++;
		size_t index = 0;
		for (size_t i = 0; i < count_size; i++)
			for (size_t j = 0; j < counts[i]; j++)
				arr[index++] = i + min;
	}
	template <typename T>
	void shell_sort(T *arr, size_t size) {
		for (size_t gap = size / 2; gap > 0; gap /= 2) {
			for (size_t i = gap; i < size; i += 1) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];
				arr[j] = temp;
			}
		}
	}
	template <typename T>
	void merge(T *arr, int lhs, int index, int rhs) {
		int r1 = index - lhs + 1;
		int r2 = rhs - index;
		int L[r1], R[r2];
		for (int i = 0; i < r1; i++)
			L[i] = arr[lhs + i];
		for (int j = 0; j < r2; j++)
			R[j] = arr[index + 1 + j];
		int i = 0;
		int j = 0;
		int k = lhs;

		while (i < r1 && j < r2)
			arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
		while (i < r1)
			arr[k++] = L[i++];
		while (j < r2)
			arr[k++] = R[j++];
	}
	template <typename T>
	void mergeSort(T *arr, int lhs, int rhs) {
		if(lhs >= rhs) return;
		int index = lhs + (rhs - lhs) / 2;
		mergeSort(arr, lhs, index);
		mergeSort(arr, index + 1, rhs);
		merge(arr, lhs, index, rhs);
	}

	template <typename T>
	void merge_sort(T *arr, size_t size) {
		mergeSort(arr, 0, size - 1);
	}
	template <typename T>
	void heapify(T *arr, int size, size_t index) {
		size_t largest = index;
		size_t lhs = 2 * index + 1;
		size_t rhs = 2 * index + 2;
		if (lhs < size && arr[lhs] > arr[largest])
			largest = lhs;
		if (rhs < size && arr[rhs] > arr[largest])
			largest = rhs;
		if (largest != index) {
			swap(&arr[index], &arr[largest]);
			heapify(arr, size, largest);
		}
	}

	template <typename T>
	void heap_sort(T* arr, size_t size) {
		for (int i = static_cast<int>(size / 2 - 1); i >= 0; --i)
			heapify(arr, size, i);
		for (int i = static_cast<int>(size - 1); i > 0; --i) {
			swap(&arr[0], &arr[i]);
			heapify(arr, i, 0);
		}
	}

	template <typename T>
	void countSort(T* arr, int n, int exp) {
		int output[n];
		int i, count[10];

		std::memset(count, 0, sizeof (count));
		for (i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}
		for (i = 0; i < n; i++)
			arr[i] = output[i];
	}
	template <typename T>
	void radix_sort(T *arr, size_t size) {
		int m = getMax(arr, size);
		for (int exp = 1; m / exp > 0; exp *= 10)
			countSort(arr, size, exp);
	}
	template <typename T>
	clock_t check_time(T *arr, size_t size, void (*f)(T *, size_t)) {
		clock_t startTime = clock();
		f(arr, size);
		clock_t endTime = clock();
		std::cout << (check_arr(arr, 100) ? GREEN"[OK]" RESET : RED"[KO]" RESET) << std::endl;
		return endTime - startTime;
	}

}

int *create_int_arr(size_t size, int flags) {
	int *arr = new int[size];
	char *c = new char[size];
	for (int i = 0; i < size; ++i)
		arr[i] = (!flags) ? ft::getRandomNumber(0, 9) : rand();
	return arr;
}

char *create_char_arr(size_t size) {
	char *c = new char[size];
	for (int i = 0; i < size; ++i) {
		c[i] = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
	}
	return c;
}

int main() {
	/* Size = 100 */
	std::cout << "Bubble sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::buble_sort) << std::endl;
	std::cout << "Insertion sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::insertion_sort) << std::endl;
	std::cout << "Choice sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::choice_sort) << std::endl;
	std::cout << "Count sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::count_sort) << std::endl;
	std::cout << "Shell sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::shell_sort) << std::endl;
	std::cout << "Merge sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::merge_sort) << std::endl;
	std::cout << "Heap sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::heap_sort) << std::endl;
	std::cout << "Radix sort; size = 100 - " << ft::check_time(create_int_arr(100, 0), 100, ft::radix_sort) << std::endl;
	/* Size = 1000 */
	std::cout << "Bubble sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::buble_sort) << std::endl;
	std::cout << "Insertion sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::insertion_sort) << std::endl;
	std::cout << "Choice sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::choice_sort) << std::endl;
	std::cout << "Count sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::count_sort) << std::endl;
	std::cout << "Shell sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::shell_sort) << std::endl;
	std::cout << "Merge sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::merge_sort) << std::endl;
	std::cout << "Heap sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::heap_sort) << std::endl;
	std::cout << "Radix sort; size = 1000 - " << ft::check_time(create_int_arr(1000, 0), 100, ft::radix_sort) << std::endl;
	/* Size = 10000 */
	std::cout << "Bubble sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::buble_sort) << std::endl;
	std::cout << "Insertion sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::insertion_sort) << std::endl;
	std::cout << "Choice sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::choice_sort) << std::endl;
	std::cout << "Count sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::count_sort) << std::endl;
	std::cout << "Shell sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::shell_sort) << std::endl;
	std::cout << "Merge sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::merge_sort) << std::endl;
	std::cout << "Heap sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::heap_sort) << std::endl;
	std::cout << "Radix sort; size = 10000 - " << ft::check_time(create_int_arr(10000, 0), 100, ft::radix_sort) << std::endl;
	/* Size = 100000 */
	std::cout << "Bubble sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::buble_sort) << std::endl;
	std::cout << "Insertion sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::insertion_sort) << std::endl;
	std::cout << "Choice sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::choice_sort) << std::endl;
	std::cout << "Count sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::count_sort) << std::endl;
	std::cout << "Shell sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::shell_sort) << std::endl;
	std::cout << "Merge sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::merge_sort) << std::endl;
	std::cout << "Heap sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::heap_sort) << std::endl;
	std::cout << "Radix sort; size = 100000 - " << ft::check_time(create_int_arr(100000, 0), 100, ft::radix_sort) << std::endl;
	/* Size = 1_000_000 */
	std::cout << "Bubble sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::buble_sort) << std::endl;
	std::cout << "Insertion sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::insertion_sort) << std::endl;
	std::cout << "Choice sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::choice_sort) << std::endl;
	std::cout << "Count sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::count_sort) << std::endl;
	std::cout << "Shell sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::shell_sort) << std::endl;
	std::cout << "Merge sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::merge_sort) << std::endl;
	std::cout << "Heap sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::heap_sort) << std::endl;
	std::cout << "Radix sort; size = 1000000 - " << ft::check_time(create_int_arr(1000000, 0), 100, ft::radix_sort) << std::endl;
	return 0;
}
