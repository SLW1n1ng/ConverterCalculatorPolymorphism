Health Converter Calculator
==========================

This project is an implementation of a Health Converter Calculator 
that applies the principles of object-oriented programming,
including inheritance, polymorphism, and dynamic binding.
The calculator allows users to perform unit conversions and 
precise calculations involving body metrics and speed.

Features
--------

- Supports two unit systems: metric and imperial.
- Converts weight, height, and distance between metric and imperial units.
- Calculates Body Mass Index (BMI) based on weight and height inputs.
- Calculates speed based on distance and time inputs.
- Provides interpretations and meaningful descriptions of the calculated results.

Classes
-------

The project consists of the following classes:

1. `Converter` (Base Class):
   - Virtual member functions: `toMetric`, `toImperial`, `description`.
   - Derived classes: `WeightConverter`, `DistanceConverter`, `HeightConverter`.

2. `Calculator` (Base Class):
   - Virtual member functions: `calculate`, `printResult`, `description`, `interpretResult`.
   - Derived classes: `BMICalculator`, `SpeedCalculator`.

Project Title: Unit Conversion and Calculation System

Overview:
This project is a command-line application that provides various unit conversion
and calculation functionalities. It is built using Object-Oriented Programming
(OOP) principles, making effective use of dynamic binding and static binding.

OOP Principles:
The project follows the principles of encapsulation, inheritance, and polymorphism.
It uses classes and objects to encapsulate related data and behavior.
Inheritance is employed to create specialized classes, such as WeightConverter, 
DistanceConverter, BMICalculator, and SpeedCalculator, inheriting common functionality
from the base Converter and Calculator classes. Polymorphism is achieved through 
the use of virtual functions, allowing different implementations
to be invoked based on the actual type of objects.

Dynamic Binding:
Dynamic binding is used in the project through virtual functions. 
The base Converter and Calculator classes declare virtual functions 
like toMetric, toImperial, calculate, and description. 
This enables dynamic binding when these functions are called on objects
of derived classes. For example, a WeightConverter object dynamically
binds the toMetric and toImperial functions based on the actual type of the object.

Static Binding:
Static binding occurs in the project for non-virtual member functions.
The description function in Converter and Calculator classes uses static binding,
as the specific function to call is determined at compile-time based on the static type of the object.

Code Organization:
The project is organized into multiple source files, each responsible
for a specific component or functionality. The clearInputBuffer, displaymenu,
getunitsysteminput, getuserinputforvariable, doesuserwanttocontinue, 
and getmenuinput files handle user input and interaction. The Converter 
and Calculator classes provide the base functionality, while specialized converter
(WeightConverter, DistanceConverter) and calculators (BMICalculator, SpeedCalculator) extend the base classes.

Usage
-----

To use the Health Converter Calculator, follow these steps:

1. Run the program.
2. Choose your preferred unit system (metric or imperial) when prompted.
3. Enter your weight and height in the chosen unit system.
4. If the chosen unit system is imperial, the weight and height will be converted to metric.
5. The program will calculate your BMI using the provided weight and height.
6. The BMI result will be displayed, along with a meaningful interpretation.
7. If the unit system is imperial, the program will ask for a distance and time.
8. The distance will be converted to metric if necessary.
9. The program will calculate the speed based on the distance and time.
10. The speed result will be displayed, along with a meaningful interpretation.
11. If the unit system is imperial, the speed will be converted back to imperial units.
12. After each calculation, the program will ask if you want to perform another calculation.
13. If you choose not to continue, the program will terminate.

Dependencies
------------

The project does not have any external dependencies. 
It is implemented in C++ using standard libraries.

Contributing
------------

Contributions to the Health Converter Calculator project are welcome. 
If you encounter any issues or have suggestions for improvements, 
please feel free to submit a pull request or open an issue on the GitHub repository.

License
-------

This project is licensed under the Visual Studio.
