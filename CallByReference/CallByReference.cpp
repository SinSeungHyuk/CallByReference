// CallByReference.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
using namespace std;

class Person {
public:
	Person(string name, string address) : name(name), address(address) {
		cout << "Person 생성자 호출\n";
	}
	Person(Person& p) {
		cout << "Person 복사생성자 호출\n";
		this->name = p.name;
		this->address = p.address;
	}
	virtual ~Person() { cout << "Person 소멸자 호출\n"; }

	virtual void getName() const { cout << "Person name : " << name << endl; }

protected:
	string name;
	string address;
};

class Student : public Person {
public:
	Student(string n, string add, string s_name, string s_add) :
		Person(n, add), schoolName(s_name), schoolAddress(s_add)
	{
		cout << "Student 생성자 호출\n";
	}
	Student(Student& s) : Person(s) {
		cout << "Student 복사생성자 호출\n";
		this->schoolName = s.schoolName;
		this->schoolAddress = s.schoolAddress;
	}
	~Student() { cout << "Student 소멸자 호출\n"; }
	string getSchoolName() const { return schoolName; }
	void getName() const { cout << "Student name : " << name << endl; }

private:
	string schoolName;
	string schoolAddress;
};

bool validateStudent(const Student& s) {
	string s_name = s.getSchoolName();

	if (s_name == "") return false;
	return true;
}

void printName(const Person& p) {
	p.getName();
}

int main()
{
    cout << "===== Student 오브젝트 생성 =====\n";
    Student kim("kim", "seoul", "A school", "seoul");
	Person* sin = new Student("sin", "kor", "B school", "kor");
    cout << "===== 오브젝트 생성 완료 =====\n\n";

    cout << "===== validateStudent 함수 호출 =====\n\n";
    bool kimOK = validateStudent(kim);

	cout << "===== getName 함수 호출 =====\n";
	printName(kim);
	printName(*sin);

    cout << "\n\n===== 메인 함수 종료 =====\n\n";

	unique_ptr<Person> uptr_Person(sin); // 힙 메모리 반환

    return 0;
}

