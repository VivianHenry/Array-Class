<h1>Array Class</h1>

The goal of this programming assignment is to provide a refresher for programming abstract data types (ADTs) in C++ by designing and implementing a standard array class for characters (char). The design and function declarations are provided in the header file (Array.h). The function definitions are provided in Array.cpp. The code used to test the implementation is provided in driver.cpp.

Included files:
<ul>
  <li>Array.cpp
  <li>Array.h
  <li>Array.inl
  <li>Array.mpc
  <li>driver.cpp
</ul>

<h3>Notes</h3>
Two implementations have been provided for both slice functions. One implementation returns a true shallow copy but results in a malloc error upon the termintaion of the main{} function. The second implementation (commented out) does not result in a malloc error but returns a deep copy.
