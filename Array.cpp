// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include<iostream>
Array::Array (void)
: max_size_ (10), cur_size_ (0)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// ANSWER As per suggestion, I have initialized the member variables in the base member
// inititalization section of the constructor on its own line.
{
    // COMMENT The current size of the array for the default constuctor is 0.
    // ANSWER The current size of the array for the default constructor has been
    // made to 0. The error was an oversight. 

    data_ = new char[max_size_];
}

Array::Array (size_t length)
: max_size_ (length), cur_size_ (length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// ANSWER As per suggestion, I have initialized the member variables in the base member
// inititalization section of the constructor on its own line.
{
    data_ = new char[cur_size_];
}

Array::Array (size_t length, char fill)
: max_size_ (length), cur_size_ (length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// ANSWER As per suggestion, I have initialized the member variables in the base member
// inititalization section of the constructor on its own line.
{
    data_ = new char[cur_size_];

    for(int i = 0; i < cur_size_; i++) {data_[i] = fill;}
}

Array::Array (const Array & array)
: max_size_ (array.max_size_), cur_size_ (array.cur_size_)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// ANSWER As per suggestion, I have initialized the member variables in the base member
// inititalization section of the constructor on its own line.
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
    // COMMENT This is not how you check for self-assignment.
    // ANSWER I realized a mere value check was not the correct approach and thus
    // *this != rhs has been replaced with this != &rhs
    
    if (this != &rhs)
    {
        // COMMENT You should only change the allocation size of this array is not
        // large enough to hold rhs.
        // ANSWER Allocation size is only changed if the size of the array is not large
        // enough to hold the rhs. If it is large enough, only the value of cur_size_ is
        // changed to equate the data that is assigned and read from the lhs.

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
    // COMMENT You are not throwing the correct exception type.
    // ANSWER I learned the correct exception type to throw and thus changed
    // throw "out_of_range" to throw std::out_of_range("Invalid index")
    
    // COMMENT size_t can never be less than 0
    // ANSWER index < 0 condition has been removed

    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    return data_[index];
}

const char & Array::operator [] (size_t index) const
{
    // COMMENT You are not throwing the correct exception type.
    // ANSWER I learned the correct exception type to throw and thus changed
    // throw "out_of_range" to throw std::out_of_range("Invalid index")
    
    // COMMENT size_t can never be less than 0
    // ANSWER index < 0 condition has been removed

    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    return data_[index];
}

char Array::get (size_t index) const
{
    // COMMENT You are not throwing the correct exception type.
    // ANSWER I learned the correct exception type to throw and thus changed
    // throw "out_of_range" to throw std::out_of_range("Invalid index")
    
    // COMMENT size_t can never be less than 0
    // ANSWER index < 0 condition has been removed

    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    return data_[index];
}

void Array::set (size_t index, char value)
{
    // COMMENT You are not throwing the correct exception type.
    // ANSWER I learned the correct exception type to throw and thus changed
    // throw "out_of_range" to throw std::out_of_range("Invalid index")
    
    // COMMENT size_t can never be less than 0
    // ANSWER index < 0 condition has been removed

    if (index >= this->cur_size_) {throw std::out_of_range("Invalid index");}
    data_[index] = value;
}

void Array::resize (size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    // ANSWER The first conditional block below has been modified based on the comment. If the
    // new size is smaller than the current size, cur_size_ has merely been updated to reflect
    // the new size.
    
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
    // COMMENT Check for self comparison first.
    // ANSWER As suggested, I have added a self comparison check to compare
    // memory locations, as well.

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
    // COMMENT There is no need to create a copy of the array to reverse its contents
    // ANSWER While I understand that creating a copy is more intensive approach, I only 
    // went with that approach in order to practice and solifidy my understanding of pointer
    // management, since I am new to the language. As advised, I have switched out that approach
    // with the in-place approach.

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