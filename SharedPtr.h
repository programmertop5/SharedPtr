#pragma once
template<typename T>
class SharedPtr
{
private:
	T* ptr;
	int* ref_count;
public:
	SharedPtr(T* p = nullptr) :ptr(p) {
		if (p) {
			ref_count = new int(1);
		}
		else {
			ref_count = nullptr;
		}
	}
	SharedPtr(const SharedPtr<T>& other) {
		ptr = other.ptr;
		ref_count = other.ref_count;
		if (ref_count) {
			(*ref_count)++;
		}
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& other) {
		if (this == &other)return *this;
		if (ref_count) {
			(*ref_count)--;
			if (*ref_count = 0) {
				delete ptr;
				delete ref_count;
			}
		}
		ptr = other.ptr;
		ref_count = other.ref_count;
		if (ref_count) {
			(*ref_count)++;
		}
	}
	~SharedPtr() {
		if (ref_count) {
			(*ref_count)--;
			if (*ref_count == 0) {
				delete ptr;
				delete ref_count;
			}
		}
	}
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
	int use_count()const {
		if (ref_count != nullptr) {
			return *ref_count;
		}
		else {
			return 0;
		}
	}
};


