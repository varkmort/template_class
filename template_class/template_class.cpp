#include <iostream>
#include <array>

template <typename Type, const int _size>
class MyClass{
public:
	
	Type &operator[](int i) {
		return data_[i];
	}

	const Type &operator[](int i)const {
		return data_[i];
	}

	auto at(int i) -> Type & {
		return data_[i];
	}

	auto at(int i)const -> const Type & {
		return data_[i];
	}

	int size()const {
		return size_;
	}

	class iterator {
	public:
		iterator() = delete;
		iterator(Type *data):data_(data){ }

		iterator &operator++() {
			data_++;
			return *this;
		}

		iterator &operator++(int) {
			iterator tmp(*this);
			data_++;
			return tmp;
		}

		bool operator==(const iterator &obj)const {
			return this->data_ == obj.data_;
		}

		bool operator!=(const iterator &obj)const {
			return ! this->operator==(obj);
			//такой стиль применим если условия проверки 
			//содержат чложные условия или вызовы функций
		}

		Type &operator*() {
			return *data_;
		}

	private:
		Type *data_;
	};

	iterator begin() {
		return iterator(data_);
	}

	iterator end() {
		return iterator(data_ + size_);
	}

private:
	Type data_[_size];
	const int size_{ _size };
};

void f01(MyClass<int, 10> a) {
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << ' ';
	}
}


int main(){ 
	MyClass<int, 10> a;
	for (size_t i = 0; i < a.size(); i++) {
		a[i]= i + 1;
	}
	f01(a);

	int arr[10];
	for (size_t i = 0; i < std::size(arr); i++) {
		arr[i] = i + 1;
	}
	std::cout << '\n';
	for (int &el: arr) {
		std::cout << el << ' ';
	}

	std::array<int, 10> arrObj;
	for (size_t i = 0; i < std::size(arrObj); i++) {
		arrObj[i] = i + 10;
	}
	std::cout << '\n';
	for (const auto &el : arrObj) {
		std::cout << el << ' ';
	}
	std::cout << '\n';
	for (std::array<int,10>::iterator it = arrObj.begin();
		 it != arrObj.end();
		 ++it
		 ) {
		const auto &el = *it;
		std::cout << el << ' ';
		

	}

	std::cout << '\n';
	for (const auto &el : a) {
		std::cout << el << ' ';
	}

	return 0;
}