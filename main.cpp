#include <iostream>
#include <vector>

void push_to_train(std::vector<int>& train, int& pass_num) {
	std::cout << "Input passenger number (<= 20)" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "for wagon # " << i << ":";
		std::cin >> pass_num;
		train.push_back(pass_num);
	}
}

void sort_selection(std::vector<int>& vec, std::vector<int>& sort_index) {
	std::vector<int> sort;
	for (int i = 0; i < vec.size(); i++) {
		sort.push_back(vec[i]);
	}
	if (!sort.empty()) {
		int ind = 0;
		for (int i = 0; i < sort.size(); i++) {
			int max = 0;
			for (int j = 0; j < sort.size(); j++) {
				if (sort[j] >= max) {
					max = sort[j];
					ind = j;
				}
			}
			sort_index.push_back(ind);
			sort[ind] = -1;
		}
	}

}

void display_train(std::vector<int>& vec, std::vector<int>& sort_index) {
	int pass_sum = 0;
	for (int i = 0; i < 10; i++) {
		std::cout << "Wagon #" << sort_index[i] << " - " << vec[sort_index[i]] << " passengers" << std::endl;
		pass_sum += vec[sort_index[i]];
	}
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Total passengers on a train = " << pass_sum << std::endl;
}

#define INPUT_PASS(vec, pass) (push_to_train((vec), (pass)))
#define MAX_PASS(vec, sort_index) (sort_selection(vec, sort_index))
#define DISPLAY_PASS(vec, index_vec) (display_train(vec, index_vec))


int main() {
	std::vector<int> train_vec;
	std::vector<int> sort_index;
	int pass_num;
	INPUT_PASS(train_vec, pass_num);
	std::cout << "---------------------------------" << std::endl;
	MAX_PASS(train_vec, sort_index);
	DISPLAY_PASS(train_vec, sort_index);

}
