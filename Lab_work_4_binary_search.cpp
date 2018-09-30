# include <iostream>
# include <cstdlib>
# include <ctime>


template <typename T>
void selection_sort(T arr[], const int size) {
	for (int i = 0; i < size - 1; ++i) {
		int maxIndex = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[maxIndex]) {
				// Поехали отступы. Нужна табуляция.
				maxIndex = j;
			}
		}

		T tmp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = tmp;
	}
	// Вывод внутри функции не нужен.
}


int binarySearch(int arr[], const int size, const int value) {  // Не забывайте const.

	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int middle = (right + left) / 2;

		if (arr[middle] == value) {
			return middle;
		}
		else if (arr[middle] < value) {
			left = ++middle;
		}
		else {	// Проверку можно не добавлять. Это уже лишнее.
			right = --middle;
		}
	}
	return -1;
}


int main() {

	srand(time(NULL));

	const int SIZE = 9;

	int array[SIZE];

	for (int i = 0; i < SIZE; ++i) {
		array[i] = rand() % 100;
	}

	std::cout << "Array:" << "\t";

	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
	
	std::cout << "Selection sort array:" << "\t";
	selection_sort(array, SIZE);

	std::cout << std::endl;

	std::cout << " What number do you want to search?" << std::endl;
	int number = 0;
	std::cin >> number;

	std::cout << "Index of search element:" << "\t" << binarySearch(array, SIZE, number);

	std::cout << std::endl;

	system("pause");
	return 0;
}
