Assignment: Object-Oriented Programming with C++
Topic: Inheritance, Polymorphism, and Dynamic Binding
Objective:
The goal of this assignment is to create a C++ program that applies the principles of object-oriented programming such as inheritance, polymorphism, and dynamic binding. This program will be used for unit conversions and precise calculations involving body metrics and speed.
Detailed Requirements:
Part 1: Base Class Converter
Your first task is to build a base class named Converter. This class will include the following virtual member functions:
1.	virtual double toMetric(double value): This function takes a value in the imperial unit and converts it into its metric counterpart.
2.	virtual double toImperial(double value): This function does the opposite. It takes a value in the metric system and converts it to its imperial equivalent.
3.	virtual void description() const: This function prints a concise description of the converter class, which will specify the kind of conversions it performs.
Part 2: Derived Classes WeightConverter, DistanceConverter, and HeightConverter
Next, create three classes, WeightConverter, DistanceConverter, and HeightConverter, that inherit from the Converter base class. These classes will be responsible for weight, distance, and height conversions respectively:
1.	double toMetric(double value) override: This function should take the provided value in imperial units and convert it to its metric equivalent.
2.	double toImperial(double value) override: Similarly, this function should take the provided value in metric units and convert it to its imperial equivalent.
3.	void description() const override: This function should print a description detailing the specific functionality of each converter class.
Part 3: Base Class Calculator
Next, design a base class called Calculator that contains the following member functions:
1.	virtual double calculate(double val1, double val2) = 0: This function should take two numerical inputs and compute a calculation based on them. The exact nature of this calculation will depend on the derived classes.
2.	void printResult(double result): This function should take the computed result and print it in a user-friendly manner.
3.	virtual void description() const: This function should print a description detailing the specific functionality of each calculator class.
4.	protected virtual std::string interpretResult(double result) = 0: This function should take a result value and return an interpretation. The interpretation should be in a form that is easy for users to understand and relevant to the computation that has been performed.
Part 4: Derived Class BMICalculator
Now, develop a derived class BMICalculator that inherits from the Calculator base class. This class should contain the following functions:
1.	double calculate(double weight, double height) override: This function should calculate the Body Mass Index (BMI) based on the provided weight and height.
2.	protected std::string interpretResult(double result) override: This function should provide a health-related interpretation of the BMI result. It could be categorizing the result into underweight, normal weight, overweight, and obese based on standard BMI categories.
3.	void description() const override: This function should print a description of the BMICalculator class's specific functionality.
Part 5: Derived Class SpeedCalculator
Next, design a derived class named SpeedCalculator that inherits from the Calculator base class. Implement the following functions:
1.	double calculate(double distance, double time) override: This function should calculate speed by dividing the given distance by time.
2.	protected std::string interpretResult(double result) override: This function should provide an interpretation of the speed result. It could contextualize the result with typical speeds for walking, running, biking, or driving, for example.
3.	void description() const override: This function should print a description of the SpeedCalculator class's specific functionality.
Part 6: Implement User Interaction
Finally, in your main() function, implement a user interface to interact with the above classes. To make the program more user-friendly, ask the user for their preferred unit system (imperial or metric) at the beginning and use this information throughout the program. The interface should:
1.	Prompt the user to choose their preferred unit system: metric (kilograms and meters) or imperial (pounds and feet).
2.	Ask the user to input their weight and height in their chosen unit system.
3.	If the user has chosen the imperial system, instantiate a WeightConverter object and a HeightConverter object. Use these objects to convert the user's weight and height to the metric system for further calculations.
4.	Instantiate a BMICalculator object. Use this object to calculate the user's BMI. Print the resulting value and provide a meaningful interpretation.
5.	Ask the user for a distance and time. If the user has chosen the imperial system, use the DistanceConverter object to convert the distance to the metric system for further calculations.
6.	Instantiate a SpeedCalculator object. Use this object to calculate the user's speed. Print the resulting value and provide a meaningful interpretation. If the user has chosen the imperial system, convert the resulting speed back to imperial units for the output.
7.	After each calculation, ask the user if they want to perform another calculation. If not, thank them and terminate the program.
Submission Guidelines:
1.	Make sure your code compiles without any errors and runs as expected.
2.	Use comments throughout your code to explain what each class and method does. Your comments should be concise but comprehensive.
3.	Make sure your implementation adheres to the principles of inheritance, polymorphism, and dynamic binding.
4.	Submit your source code files (.cpp and .h files) through the designated submission portal before the deadline.
Remember, the goal is to not only write code that works but also to design and structure your program in a way that showcases your understanding of object-oriented programming in C++. Best of luck!

