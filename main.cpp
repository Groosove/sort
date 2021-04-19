#include <iostream>
#include <vector>
namespace ft {

	template <typename T>
	void swap(T *lhs, T *rhs) {
		T tmp = *lhs;
		*lhs = *rhs;
		*rhs = tmp;
	}
	template <typename T>
	void print_arr(T *arr, size_t size) {
		for (int i = 0; i < size; ++i)
			std::cout << arr[i];
		std::cout << std::endl;
	}
	template <typename T>
	void buble_sort(T* arr, size_t size) {
		for (int i = 0; i < size - 1; ++i)
			for (int j = 0; j < size - 1 - i; ++j)
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
	}
	template <typename T>
	void insertion_sort(T *arr, size_t size) {

		for (int i = 1, j = i - 1; i < size; i++) {
			T key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
	template <typename T>
	void choice_sort(T *arr, size_t size) {
		int min;
		for (int i = 0; i < size - 1; i++) {
			min = i;
			for (int j = i + 1; j < size; j++)
				if (arr[j] < arr[min])
					min = j;
			swap(&arr[i], &arr[min]);
		}
	}
	template <typename T>
	void count_sort(T* arr, size_t size) {
		T min = arr[0], max = arr[0];
		for (size_t i = 1; i < size; ++i) {
			if (arr[i] < min)
				min = arr[i];
			if (arr[i] > max)
				max = arr[i];
		}
	}
	template <typename T>
	clock_t check_time(T *&arr, size_t size, void (*f)(T *arr, size_t size)) {
		clock_t startTime = clock();
		f(arr, size);
		clock_t endTime = clock();
		print_arr(arr, 100);
		return endTime - startTime;

	}
}

int main(int argc, char **argv) {
	int *a = new int[100];
	int *b = new int[100];
	std::string c;
	std::time(0);
	for (int i = 'a'; i <= 'z'; ++i)
		std::cout << char(i);
	std::cout << std::endl << 'z' - 'a' << std::endl;

	for (int i = 0; i < 100; ++i) {
		a[i] = std::rand() % 10;
		b[i] = std::rand();
		c.push_back("abcdefghijklmnopqrstuvwxyz"[std::rand() % 26]);
	}
	std::cout << "Bubble sort; size = 100 - " << ft::check_time(a, 100, ft::choice_sort) << std::endl;
	return 0;
}
