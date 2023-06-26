#include "Array.h"
#include <iostream>

int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  
  Array test_1(3);
  test_1[0] = 'a';
  test_1[1] = 'b';
  test_1[2] = 'c';

  Array test_2(test_1);

  Array test_3(5, 'v');

  Array test_4(10);
  test_4[0] = 'a';
  test_4[1] = 'b';
  test_4[2] = 'c';
  test_4[3] = 'd';
  test_4[4] = 'e';
  
  Array test_5(20);

  // Testing constructors, [], and get function
  std::cout << "Constructor w/ 1 argument" << std::endl;
  for(int i = 0; i < 3; i++) {std::cout << test_1[i] << std::endl;}
  std::cout << std::endl;
  std::cout << "Constructor w/ 2 argument" << std::endl;
  for(int i = 0; i < 5; i++) {std::cout << test_3.get(i) << std::endl;}
  std::cout << std::endl;
  std::cout << "Copy constructor" << std::endl;
  for(int i = 0; i < 3; i++) {std::cout << test_2[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;

  // Testing [] for const arrays
  std::cout << "[] for const arrays test" << std::endl;
  //const Array test_9(10);
  //test_9[0] = 'a';

  // Testing equality and inequality
  std::cout << "Equality and inequality test" << std::endl;
  bool result = test_1 == test_2;
  std::cout << result << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  // Testing set function
  std::cout << "Set function test" << std::endl;
  std::cout << "Value before function: " << test_2[1] << std::endl;
  test_2.set(1, 'z');
  std::cout << "Value after function: " << test_2[1] << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  // Testing size and max_size functions
  std::cout << "size and max_size functions test" << std::endl;
  std::cout << "size function: " << test_4.size() << std::endl;
  std::cout << "max_size after function: " << test_4.max_size() << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  // Testing resize function
  std::cout << "Resize function test" << std::endl;
  std::cout << "Before resize: " << std::endl;
  for(int i = 0; i < test_3.size(); i++) {std::cout << test_3[i] << std::endl;}
  std::cout << "Max size: " << test_3.size() << " " << "Cur size: " << test_3.size() << std::endl;
  std::cout << "After resize: " << std::endl;
  test_3.resize(10);
  for(int i = 0; i < test_3.size(); i++) {std::cout << test_3[i] << std::endl;}
  std::cout << "Max size: " << test_3.max_size() << " " << "Cur size: " << test_3.size() << std::endl;
  std::cout << "After resize: " << std::endl;
  test_3.resize(8);
  for(int i = 0; i < test_3.size(); i++) {std::cout << test_3[i] << std::endl;}
  std::cout << "Max size: " << test_3.max_size() << " " << "Cur size: " << test_3.size() << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  // Testing find function
  std::cout << "Find function test" << std::endl;
  std::cout << "Result: " << test_4.find('c') << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  // Testing find w/ start index function
  std::cout << "Find w/ start index function test"  << std::endl;
  std::cout << "Result: " << test_4.find('d', 1) << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  // Testing fill function
  std::cout << "Fill function test" << std::endl;
  test_5.fill('z');
  for(int i = 0; i <test_5.size(); i++) {std::cout << test_5[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;

  //Testing = operator
  std::cout << "= operator test" << std::endl;
  std::cout << "Test array 5: " << std::endl;
  std::cout << "Max size: " << test_5.max_size() << " " << "Cur size: " << test_5.size() << std::endl;
  for(int i = 0; i <test_5.size(); i++) {std::cout << test_5[i] << std::endl;}
  Array test_6;
  test_6 = test_5;
  std::cout << "Test array 6: " << std::endl;
  std::cout << "Max size: " << test_6.max_size() << " " << "Cur size: " << test_6.size() << std::endl;
  for(int i = 0; i <test_6.size(); i++) {std::cout << test_6[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;

  //Testing max_size_ and cur_size_
  std::cout << "Size and max_size functions test" << std::endl;
  std::cout << test_1.max_size() << "and" << test_1.size() << std::endl;
  std::cout << test_2.max_size() << "and" << test_2.size() << std::endl;
  std::cout << test_3.max_size() << "and" << test_3.size() << std::endl;
  std::cout << test_4.max_size() << "and" << test_4.size() << std::endl;
  std::cout << test_5.max_size() << "and" << test_5.size() << std::endl;
  std::cout << test_6.max_size() << "and" << test_6.size() << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  //Testing shrink function
  std::cout << "Shrink function test" << std::endl;
  std::cout << "Before shrink: " << std::endl;
  std::cout << "Max size: " << test_4.max_size() << " " << "Cur size: " << test_4.size() << std::endl;
  for(int i = 0; i <test_4.size(); i++) {std::cout << test_4[i] << std::endl;}
  test_4.shrink();
  std::cout << "Max size: " << test_4.max_size() << " " << "Cur size: " << test_4.size() << std::endl;
  for(int i = 0; i <test_4.size(); i++) {std::cout << test_4[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;

  //Testing reverse function
  std::cout << "Reverse function test" << std::endl;
  std::cout << "Before reverse: " << std::endl;
  for(int i = 0; i <test_4.size(); i++) {std::cout << test_4[i] << std::endl;}
  test_4.reverse();
  std::cout << "After reverse: " << std::endl;
  for(int i = 0; i <test_4.size(); i++) {std::cout << test_4[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;

  //Testing slice w/ 1 parameter function
  Array test_7(10);
  test_7[0] = 'a';
  test_7[1] = 'b';
  test_7[2] = 'c';
  test_7[3] = 'd';
  test_7[4] = 'e';
  test_7[5] = 'f';
  test_7[6] = 'g';
  test_7[7] = 'h';
  test_7[8] = 'i';
  test_7[9] = 'j';
  std::cout << "Slice w/ 1 parameter function test" << std::endl;
  std::cout << "Before slice: " << std::endl;
  for(int i = 0; i <test_7.size(); i++) {std::cout << test_7[i] << std::endl;}
  Array test_8 = test_7.slice(3);
  std::cout << "After slice: " << std::endl;
  for (size_t i = 0; i < test_8.size(); i++) {std::cout << test_8[i] << std::endl;}
  std::cout << "Changing value in original array: " << std::endl;
  test_7[6] = 'z';
  std::cout << "Before slice: " << std::endl;
  for(int i = 0; i <test_7.size(); i++) {std::cout << test_7[i] << std::endl;}
  std::cout << "After slice: " << std::endl;
  for (size_t i = 0; i < test_8.size(); i++) {std::cout << test_8[i] << std::endl;}
  std::cout << "Changing value in copied array: " << std::endl;
  test_8[2] = 'y';
  std::cout << "Before slice: " << std::endl;
  for(int i = 0; i <test_7.size(); i++) {std::cout << test_7[i] << std::endl;}
  std::cout << "After slice: " << std::endl;
  for (size_t i = 0; i < test_8.size(); i++) {std::cout << test_8[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;
  
  // Array test_10(3);
  // test_10[0] = 'a';
  // test_10[1] = 'b';
  // test_10[2] = 'c';

  // std::cout << "Memory locations: " << std::endl;
  // std::cout << "Array 1: " << &test_1 << " " << &test_1.data_ << std::endl;
  // std::cout << "Array 2: " << &test_2 << " " << &test_2.data_ << std::endl;
  // std::cout << "Array 3: " << &test_3 << " " << &test_3.data_ << std::endl;
  // std::cout << "Array 4: " << &test_4 << " " << &test_4.data_ << std::endl;
  // std::cout << "Array 5: " << &test_5 << " " << &test_5.data_ << std::endl;
  // std::cout << "Array 6: " << &test_6 << " " << &test_6.data_ << std::endl;
  // std::cout << "Array 7: " << &test_7 << " " << &test_7.data_ << std::endl;
  // std::cout << "Array 8: " << &test_8 << " " << &test_8.data_ << std::endl;
  // //std::cout << "Array 9: " << &test_9 << " " << &test_9.data_ << std::endl;
  // std::cout << "Array 10: " << &test_10 << " " << &test_10.data_ << std::endl;
  // std::cout << "---------------------------------------" << std::endl;

  //Testing slice w/ 2 parameters function
  Array test_10(10);
  test_10[0] = 'a';
  test_10[1] = 'b';
  test_10[2] = 'c';
  test_10[3] = 'd';
  test_10[4] = 'e';
  test_10[5] = 'f';
  test_10[6] = 'g';
  test_10[7] = 'h';
  test_10[8] = 'i';
  test_10[9] = 'j';
  std::cout << "Slice w/ 2 parameters function test" << std::endl;
  std::cout << "Before slice: " << std::endl;
  for(int i = 0; i <test_10.size(); i++) {std::cout << test_10[i] << std::endl;}
  Array test_11 = test_10.slice(2, 8);
  std::cout << "After slice: " << std::endl;
  for (size_t i = 0; i < test_11.size(); i++) {std::cout << test_11[i] << std::endl;}
  std::cout << "Changing value in original array: " << std::endl;
  test_10[6] = 'z';
  std::cout << "Before slice: " << std::endl;
  for(int i = 0; i <test_10.size(); i++) {std::cout << test_10[i] << std::endl;}
  std::cout << "After slice: " << std::endl;
  for (size_t i = 0; i < test_11.size(); i++) {std::cout << test_11[i] << std::endl;}
  std::cout << "Changing value in copied array: " << std::endl;
  test_11[4] = 'y';
  std::cout << "Before slice: " << std::endl;
  for(int i = 0; i <test_10.size(); i++) {std::cout << test_10[i] << std::endl;}
  std::cout << "After slice: " << std::endl;
  for (size_t i = 0; i < test_11.size(); i++) {std::cout << test_11[i] << std::endl;}
  std::cout << "---------------------------------------" << std::endl;

  std::cout << "---------------------------------------" << std::endl;
  std::cout << "END OF DRIVER CODE" << std::endl;
  std::cout << "---------------------------------------" << std::endl;

  return 0;
}
