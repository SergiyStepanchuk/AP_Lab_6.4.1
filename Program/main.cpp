// Lab_6_4_1
#include <iostream>
#include <iomanip>
using namespace std;

void draw_line(int size, const char& c = '-') {
	for (--size; size >= 0; size--)
		cout << c;
	cout << endl;
}

template <typename T>
double myrand(const T& min, const T& max) {
	return (T)(rand()) / RAND_MAX * (max - min) + min;
}

template <typename T>
void full_mass(T* mass, int size, const T* dia) {
	for (--size; size >= 0; size--)
		mass[size] = myrand<T>(dia[0], dia[1]);
}

template <typename T>
void draw_mass(const T* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	for (int i = 0; i < size; i++)
		cout << "|" << setw(c_space - 1) << mass[i];
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

double sum_dod(double* mass, int size) {
	double sum = 0;
	for (--size; size >= 0; size--)
		if (mass[size] > 0)
			sum += mass[size];
	return sum;
}

int min_(double* mass, int size) {
	int min_i = 0;
	for (--size; size > 0; --size)
		if (mass[min_i] > mass[size])
			min_i = size;
	return min_i;
}

double sum(double* mass, int size) {
	double sum = 0;
	for (--size; size >= 0; size--)
		sum += mass[size];
	return sum;
}

void sort_half(double* mass, const int &size) {
	for (int i = 0; i < size - 1; i+=2) { // бульбашка
		for (int j = 0; j < size - i - 1; j+=2) {
			if (j < size - i - 2)
				if (mass[j] > mass[j + 2])
					swap(mass[j], mass[j + 2]);

			if (j > 0)
				if (mass[j-1] > mass[j + 1])
					swap(mass[j-1], mass[j + 1]);
		}
	}
}

void main() {
	srand(time(NULL));
	const int c_space = 6; // кількість містя яке виділяєьбся на одну комірку массиву, при виводі в консоль
	double dia[2]; // діапазон, n
	int n;

	cout << "n = "; cin >> n;
	cout << "dia start = "; cin >> dia[0];
	cout << "dia end = "; cin >> dia[1];
	cout.precision(2);

	double* mass = new double[n];
	full_mass<double>(mass, n, dia);
	draw_mass(mass, n, c_space);
	
	cout.precision(10);
	
	cout << "1.1 sum dod: " << sum_dod(mass, n) << endl;
	cout << "1.2 min index: " << min_(mass, n) << endl;
	cout << "1.2 sum to min: " << sum(mass, min_(mass, n)) << endl;
	cout << "2. sort_half" << endl;
	cout.precision(2);
	sort_half(mass, n);
	draw_mass(mass, n, c_space);

	delete[] mass;
}