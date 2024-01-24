

#include <iostream>
using namespace std;

/***********	C	L	A	S	S	****************
Class is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance(object) of that class.
A C++ class is like a blueprint for an object.
*/

//*******	E	M	P	T	Y	__________	C	L	A	S	S	************
/*
It is a class that does not contain any data members (e.g. int a, float b, char c, and string d, etc.) However, an empty class may contain member functions.
When we create an object of an empty class in a C++ program, it needs some memory to get stored, and the minimum amount of memory that can be reserved is 1 byte.
Hence empty class size is 1 Byte.
*/

class emptyClass {

	void emptyClassFunction() {
		cout << "Inside Empty class" << endl;
	}
};

class Student {
	/*******   A		C		C		E		S		S		-		M		O		D		I		F		I		E		R		S		************
	There are three types of access modifiers:
	1.Public: Members declared as public are accessible from any part of the program. They have no restrictions on their access.
	2.Private: Members declared as private are only accessible within the class. They cannot be accessed directly from outside the class or its derived classes.
	3.Protected: Members declared as protected are accessible within the class and its derived classes. They are similar to private members but can be accessed by subclasses.
	*/


	//By default, the members of a C++ class are private.

	int roll; //private
protected:
	char Gender;
public:
	string name;
	int Class;

	//Explicit methods called setter and getter need to be defined to work with private members of the class;

	//Setter
	void setRollNo(int roll) {
		this->roll = roll;
	}

	void setGender(char c) {
		this->Gender = c;
	}


	//Getter
	int getRollNo() {
		return this->roll;
	}
	int getGender() {
		return this->Gender;
	}

	/*   *************************	 C	O	N	S	T	R	U	C	T	O	R	S	 *************************
	* Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally.
	* Constructor can be defined inside the class declaration or outside the class declaration
	* Constructors do not return values; hence they do not have a return type.
	* Constructors can be overloaded.
	* Constructor can not be declared virtual
	* 
	* Types of constructor:
		• Default constructor
		• Parameterized constructor
		• Overloaded constructor
		• Constructor with default value
		• Copy constructor
		• Inline constructor
	*Constructor make implicit calls to new and delete operators during memory allocation.
	*When the parameterized constructor is defined and no default constructor is defined explicitly, the compiler will not implicitly call the default constructor and hence creating a simple object as "Student s;" , Will flash an error
	
	*/
	Student();  //Default Constructor declared here and defined outside class.

	Student(int roll, string name, int Class,char Gender) {
		this->roll = roll;
		this->name = name;
		this->Class = Class;
		this->Gender = Gender;
		cout << "Parameterized constructor called." << endl;
	}

	

	/*********************  C	O	P	Y _______	C	O	N	S	T	R	U	C	T	O		R	 *************
	* Copy constructor need not be defined explicitly if there are no other constructors defined in class.
	* Meaning, if there are no constructors defined and you try to copy one object into other, it'll still work, this is called implicit copy constructor.
	*/

	Student(Student& obj) {
		this->roll = obj.roll;
		this->name = obj.name;
		this->Class = obj.Class;
		this->Gender = obj.Gender;
		cout << "Copy constructor called" << endl;
	}

	
	/*****************	D		E	S	T	R	U	C	T	O	R	S	***********
	*	Destructor is another special member function that is called by the compiler when the scope of the object ends.
	*	Note: for static object creation destructor is called by default, but not called during dynamic object creation.
	*	It is not possible to define more than one destructor.
	*	Destructor  cannot be declared as static and const;
	*/
	~Student() {
		cout << "In destructor, scope of the object ends here.\n" << endl;
	}

	void changeNameOfStudent(string name) {
		cout << "Changing name of student to " << name << endl;
		/***************** T		H		I		S - KEYWORD *********************
		-> this is a pointer to current object of the class
		-> below line of code wont update name, to try uncomment and check , holds true only when u r using same parameter name here as that of the class variables, if u r using anything other than "name" then below line of code works
		 name = name;
		 >Below line will correctly update name of current object*/
		this->name = name;

	}

	//Below function has been declared here and defined outside the class. This is an example of defining class member functions outside the class.
	void displayStudentDetails();

	/* ************* F	R	I	E	N	D __________	C	L	A	S	S	  **********
	A friend class can access private and protected members of other classes in which it is declared as a friend*/
	friend class F;
};

//Constructor defined outside class
Student::Student() {
	cout << "Default constructor of Student class called.\n" << endl;
}

//Member function defined outside class
void Student:: displayStudentDetails () {
	cout << "Displaying details of students:" << endl;
	cout << "Name : " << this->name << endl;
	cout << "Class : " << this->Class << endl;
	cout << "RollNo : " << this->roll << endl;
	cout << "Gender : " << this->Gender << endl;
}


//Friend class declaration
class F {
public:
	void display(Student& t)
	{
		cout << "Demo inside Friend class: " << endl;
		cout << "The value of Private Variable = "
			<< t.roll << endl;
		cout << "The value of Protected Variable = "
			<< t.Gender << endl;
	}
};

int main()
{

	cout << "Size of empty class is " << sizeof(emptyClass) << endl;
	R:
	cout << "How do you want to create object:\n1:Static creation\n2:Dynamic creation\n3:To Exit"<<endl;
	int choice;
	cin >> choice;

	if (choice == 1) {
		//Static creation of object
		Student s1;
		s1.name = "Deepak";
		s1.Class = 12;
		s1.setRollNo(101);
		s1.setGender('M');
		s1.displayStudentDetails();

		s1.changeNameOfStudent("Pal");

		s1.displayStudentDetails();

		Student s2(102, "Palkumar", 11,'M');
		
		s2.displayStudentDetails();

		//Copying object two methods
		Student s3(s2);  //Method 1
		//Student s3 = s2;  //Method 2
		s3.displayStudentDetails();

		//Friend Class instance
		F fri;
		fri.display(s1);

		goto R;

	}
	else if(choice==2) {
		//Dynamic creation of object
		Student* s1 = new Student();
		(*s1).name = "Deepak";
		(*s1).Class = 12;
		(*s1).setRollNo(101);


		(*s1).changeNameOfStudent("DynamicDeepak");
		//another way to access
		s1->name = "Kumar";
		
		s1->displayStudentDetails();

		Student* s2 = new Student(103,"JIgnesh",10,'F');

		s2->displayStudentDetails();

		//Calling destrcutor manually;

		delete s1;
		delete s2;

		goto R;

		
	}
	else if(choice==3) {
		goto E;
	}
	else {
		cout << "Please enter valid choice" << endl;
		cin.get();
		system("cls");
		goto R;
	}

	E:
	cout << "This is the end of main class" << endl;
   return 0;

}


