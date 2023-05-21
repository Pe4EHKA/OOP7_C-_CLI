#pragma once
#include <assert.h>

generic<typename T>
ref class MyStorage {
private:
    int size;
    cli::array<T>^ data;

public:
    MyStorage() : size(0), data(nullptr) {}

    MyStorage(int size) : size(size) {
        assert(size >= 0);
        if (size > 0) {
            data = gcnew cli::array<T>(size);
        }
    }

    ~MyStorage() {
        delete data;
    }

    void clear() {
        data = nullptr;
        size = 0;
    }

    int get_size() {
        return size;
    }

    T% operator[] (int index) {
        assert(size >= 0 && index < size);
        return data[index];
    }

    void resize(int new_size) {
        if (new_size == size) {
            return;
        }
        if (new_size <= 0) {
            clear();
            return;
        }
        cli::array<T>^ new_data = gcnew cli::array<T>(new_size);
        if (size > 0) {
            int num_of_copies = new_size > size ? size : new_size;
            for (int i = 0; i < num_of_copies; ++i) {
                new_data[i] = data[i];
            }
        }
        delete data;
        data = new_data;
        size = new_size;
    }

    void reallocate(int new_size) {
        clear();
        if (new_size <= 0) {
            return;
        }
        data = gcnew cli::array<T>(new_size);
        size = new_size;
    }

    void insert_by_index(T element, int index) {
        assert(index >= 0 && index <= size);
        cli::array<T>^ new_data = gcnew cli::array<T>(size + 1);
        for (int i = 0; i < index; ++i) {
            new_data[i] = data[i];
        }
        new_data[index] = element;
        for (int i = index; i < size; ++i) {
            new_data[i + 1] = data[i];
        }
        delete data;
        data = new_data;
        ++size;
    }

    void remove_by_index(int index) {
        assert(index >= 0 && index < size);
        if (size == 1) {
            clear();
            return;
        }
        cli::array<T>^ new_data = gcnew cli::array<T>(size - 1);
        for (int i = 0; i < index; ++i) {
            new_data[i] = data[i];
        }
        for (int i = index + 1; i < size; ++i) {
            new_data[i - 1] = data[i];
        }
        delete data;
        data = new_data;
        --size;
    }

    void remove_element(T element) {
        if (size == 1) {
            if (data[0]->Equals(element)) {
                clear();
                return;
            }
            else {
                throw gcnew System::ArgumentException("Element doesn't exist");
            }
        }

        bool found = false;
        int index_delete = 0;
        cli::array<T>^ new_data = gcnew cli::array<T>(size - 1);

        for (int i = 0; i < size; ++i) {
            if (data[i]->Equals(element)) {
                found = true;
                index_delete = i;
                break;
            }
        }
        if (found) {
            for (int i = 0; i < index_delete; ++i) {
                new_data[i] = data[i];
            }

            for (int i = index_delete; i < size - 1; ++i) {
                new_data[i] = data[i + 1];
            }

            delete data;
            data = new_data;
            --size;
        }
        else {
            delete new_data;
            throw gcnew System::ArgumentException("Element doesn't exist");
        }
    }

    void push_front(T element) {
        insert_by_index(element, 0);
    }

    void push_back(T element) {
        insert_by_index(element, size);
    }

    T pop(int index) {
        assert(index >= 0 && index <= size);

        T to_return = data[index];

        if (size == 1) {
            clear();
            return to_return;
        }

        cli::array<T>^ new_data = gcnew cli::array<T>(size - 1);

        for (int i = 0; i < index; ++i) {
            new_data[i] = data[i];
        }

        for (int i = index + 1; i < size; ++i) {
            new_data[i - 1] = data[i];
        }

        delete data;
        data = new_data;
        --size;

        return to_return;
    }

    bool empty() {
        return size == 0;
    }

};