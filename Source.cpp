#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#pragma warning (disable:4996)
using namespace std;
#define NUMBER_OF_STUDENT 20
enum point {
	notpassed,passed,good,excellent
};
point Review(int k) {
	if (k < 60) return notpassed;
	else if ((k >= 60) && (k < 75)) return passed;
	else if ((k >= 75) && (k < 90)) return good;
	else if (k >= 90) return excellent;
	//return excellent;
}
/*class Student {
private :
	string name;
	int grade;
	point review;
public:
	Student();
	Student(string name, int grade,point review);
	~Student();
	string get_name();
	void set_name(string name);
	point get_review();
	void set_review( point review);
	int get_grade();
	void set_grade(int grade);
};
Student::Student(string name, int grade, point review) {
	this->name = name;
	this->grade = grade;
	this->review = review;
}
string Student::get_name() {
	return name;
}
void Student::set_name(string name) {
	this->name = name;
}
point Student::get_review() {
	return review;
}
void Student::set_review(point review) {
	this->review = review;
}
int Student::get_grade() {
	return grade;
}
void Student::set_grade(int grade) {
	this->grade = grade;
}
*/
class Teacher {
private:
	char** list_student;
	int* grades;
	point* reviews;
	int number_of_student;
public:
	//Teacher();
	Teacher(char** list_student,int* grades,point* reviews,int number_of_student);
	~Teacher();
	//void Review(char** list_student, int* grades);
	//int number_of_student;
	char** get_list_student();
	int* get_grades();
	point* get_reviews();
	int get_number_of_student();
	void Ask(const char* name_of_student,Teacher k);
};
Teacher::Teacher(char** list_student, int* grades,point* reviews,int number_of_student) {
	this->list_student = list_student;
	this->grades = grades;
	this->reviews = reviews;
	this->number_of_student = number_of_student;
}
Teacher :: ~Teacher() {

}
char** Teacher::get_list_student() {
	return list_student;
}
int* Teacher:: get_grades() {
	return grades;
}
point* Teacher :: get_reviews() {
	return reviews;
}
int Teacher:: get_number_of_student() {
	return number_of_student;
}
void Teacher::Ask(const char* name_of_student, Teacher k) {
	char** ask_list_student  = k.get_list_student();
	int* ask_grades = k.get_grades();
	point* ask_reviews = k.get_reviews();
	//cout << k.get_number_of_student() << endl;
	//cout << ask_list_student[1] << " " << ask_list_student[0] << endl;
	for (int i = 0; i < k.get_number_of_student(); i++) {
		if (strcmpi(name_of_student, ask_list_student[i]) == 0) {
			cout << ask_list_student[i] << " " << ask_grades[i] << " " << ask_reviews[i] << endl;
			break;
		}
		 if ((i==k.get_number_of_student()-1) && (strcmpi(name_of_student, ask_list_student[i]) != 0) ) {
			cout << "No student " << endl;
			break;
		}
	}
}
class Student {
private:
	char* name;
	int grade;
	point review;
public:
	Student();
	Student(char* name, int grade, point review);
	~Student();
	char* get_name();
	void set_name(char* name);
	point get_review();
	void set_review(point review);
	int get_grade();
	void set_grade(int grade);
};
Student::Student(char* name_1, int grade_1, point review_1) {
	//this->name = name;
	//this->grade = grade;
	//this->review = review;
	name = name_1;
	grade = grade_1;
	review = review_1;
}
Student::~Student() {

}
char* Student::get_name() {
	return name;
}
void Student::set_name(char* name) {
	this->name = name;
}
point Student::get_review() {
	return review;
}
void Student::set_review(point review) {
	this->review = review;
}
int Student::get_grade() {
	return grade;
}
void Student::set_grade(int grade) {
	this->grade = grade;
}
int main() {
	//Initalize
	int number_of_student;
	char** list_student = NULL;
	int* grades = NULL;
	point* reviews = NULL;
	cout << "Enter number of student:" << endl;
	cin >> number_of_student;
	cout << "Enter name and grade of students" << endl;
	//Input(list_student, grades, reviews, number_of_student);
	list_student = (char**)malloc(number_of_student * sizeof(char*));
	for (int i = 0; i < number_of_student; i++) {
		list_student[i] = (char*)malloc(20 * sizeof(char));
	}
	grades = (int*)malloc(number_of_student * sizeof(int));
	reviews = (point*)malloc(number_of_student * sizeof(point));
	for (int i = 0; i < number_of_student; i++) {
		cin >> list_student[i];
		cin >> grades[i];
		reviews[i] = Review(grades[i]);
		//cout << i << " " << list_student[i] << " " << grades[i] << " " << reviews[i] << endl;

	}
	Teacher s = Teacher(list_student, grades, reviews, number_of_student);
	 
	Student* stu = NULL;
	// Result table
	cout << "Result table" << endl;
	stu =(Student*)malloc(number_of_student * (sizeof(Student)));
	for (int i = 0; i < number_of_student; i++) {
		stu[i] = Student((list_student[i]),grades[i],reviews[i]);
		cout << stu[i].get_name() << " " << stu[i].get_grade() << " " << stu[i].get_review() << endl;
	}
	//Query
	 int number_query;
	 cout << "Enter number of queries:" << endl;
	 cin >> number_query;
	 while (number_query) {
		 char* t;
		 t = (char*)malloc(20 * sizeof(char));
		 cin >> t;
		 s.Ask(t,s);
		 number_query--;
		 free(t);
	 }
	free(stu);
	 free(list_student);
	 free(grades);
	 free(reviews);
}