#include "Array.h"
#include<iostream>
Array::Array (void)
: max_size_ (10), cur_size_ (0)
{
    data_ = new char[max_size_];
}

Array::Array (size_t length)
: max_size_ (length), cur_size_ (length)
{
    data_ = new char[cur_size_];
}

Array::Array (size_t length, char fill)
: max_size_ (length), cur_size_ (length)
{
    data_ = new char[cur_size_];

    for(int i = 0; i < cur_size_; i++) {data_[i] = fill;}
}

Array::Array (const Array & array)
: max_size_ (array.max_size_), cur_size_ (array.cur_size_)
{
    this->data_ = new char[this->max_size_];
    
    for(int i = 0; i < this->cur_size_; i++) {this->data_[i] = array.data_[i];}
}

Array::~Array (void)
{      
    delete[] data_;
}

const Array & Array::operator = (const Array & rhs)
{
    if (this != &rhs)
    {
        if (this->cur_size_ > rhs.cur_size_)
        {
            this->cur_size_ = rhs.cur_size_;
        }
        else if (this->cur_size_ < rhs.cur_size_)
        {
            delete [] this->data_;
            this->max_size_ = rhs.max_size_;
            this->cur_size_ = rhs.cur_size_;
            this->data_ = new char[this->max_size_];
        }
        
        for (size_t i = 0; i < cur_size_; i++){
            this->data_[i] = rhs.data_[i];
        }
    }

    return *this;
}

char & Array::operator [] (size_t index)
{
    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    return data_[index];
}

const char & Array::operator [] (size_t index) const
{
    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    return data_[index];
}

char Array::get (size_t index) const
{
    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    return data_[index];
}

void Array::set (size_t index, char value)
{
    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    data_[index] = value;
}

void Array::resize (size_t new_size)
{
    if (new_size < this->cur_size_)
    {
        this->cur_size_ = new_size;
    }

    if (new_size > this->cur_size_)
    {
        char* temp = new char[new_size];

        for (size_t i = 0; i < cur_size_; i++) {temp[i] = this->data_[i];}
        
        delete[] data_;
        data_ = temp;
        temp = nullptr;
        this->cur_size_ = new_size;

        if (new_size > this->max_size_) {this->max_size_ = new_size;}
    }
}

int Array::find (char ch) const
{
    int pos = -1;

    for (int i = 0; i < cur_size_; i++)
    {
        if (this->data_[i] == ch) {pos = i;}        
    }
    return pos;
}

int Array::find (char ch, size_t start) const
{
    if (start > this->cur_size_) {throw "out_of_range";}
    
    int start_index = start;
    int pos = -1;

    for (int i = start_index; i < cur_size_; i++)
    {
        if (this->data_[i] == ch) {pos = i;}        
    }
    return pos;
}

bool Array::operator == (const Array & rhs) const
{
    if (this == &rhs) {return true;}
    
    if (this->cur_size_ != rhs.cur_size_) {return false;}
    
    for (size_t i = 0; i < cur_size_; i++)
    {
        if (this->data_[i] != rhs.data_[i]) {return false;}
    }

    return true;
}

bool Array::operator != (const Array & rhs) const
{
    return !(*this == rhs);
}

void Array::fill (char ch)
{
    for (int i = 0; i < cur_size_; i++) {this->data_[i] = ch;}
}

void Array::shrink (void)
{
    if (cur_size_ < max_size_)
    {
        int j = 0;
        char* temp = new char[cur_size_];
        for (int i = 0; i < cur_size_; i++)
        {
            temp[i] = data_[i];
        }
        delete[] data_;
        data_ = temp;
        temp = nullptr;
        max_size_ = cur_size_;
    }
}

void Array::reverse (void)
{
    int start = 0;
    int end = cur_size_ - 1;
    char temp;

    while (start < end)
    {
        temp = data_[start];
        data_[start] = data_[end];
        data_[end] = temp;
        start++;
        end--;
    }
}

Array Array::slice (size_t begin) const
{
    int req_size = (cur_size_ - 1) - begin;
    Array new_arr(req_size);

    // // The following code returns a deep copy and no malloc error on program termination
    // for (size_t i = 0; i < this->cur_size_; i++) {new_arr.data_[i] = this->data_[begin + i];}

    // The following code returns a shallow copy, but results in a malloc error on program termination
    delete[] new_arr.data_;
    new_arr.data_ = &data_[begin];

    return new_arr;
}

Array Array::slice (size_t begin, size_t end) const
{
    int req_size = end - begin;
    Array new_arr(req_size);

    // // The following code returns a deep copy and no malloc error on program termination
    // for (size_t i = 0; i < end; i++) {new_arr.data_[i] = this->data_[begin + i];}

    // The following code returns a shallow copy, but results in a malloc error on program termination
    delete[] new_arr.data_;
    new_arr.data_ = &data_[begin];

    return new_arr;
}
