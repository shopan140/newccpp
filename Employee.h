#pragma once
#include <string>
namespace Records {
	const int kDefaultStartingSalary = 3000;

	class Employee {

	public:
		Employee() = default; // default constructor
		Employee(const std::string& firstName,
			const std::string& lastName); // special constructor

		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire();
		void fire();
		void display() const;
		
		// getters and setters
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber = -1;
		int mSalary = kDefaultStartingSalary;
		bool mHired = false;
	};
}