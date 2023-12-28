#include<iostream>
#include<stdexcept>
#include "Database.h"

using namespace std;

namespace Records {
	Employee& Database::addEmployee(const string& firstName,
		const string& lastName) {
		Employee theEmployee(firstName, lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);
		
		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Database::getEmployee(int employeeNumber) {
		for (int i = 0; i < mEmployees.size(); i++) {
			if (mEmployees[i].getEmployeeNumber() == employeeNumber) {
				return mEmployees[i];
			}
		}
		throw logic_error("No employee found.");
	}

	Employee& Database::getEmployee(const string& firstName,
		const string& lastName) {
		for (int i = 0; i < mEmployees.size(); i++) {
			if (mEmployees[i].getFirstName() == firstName &&
				mEmployees[i].getLastName() == lastName) {
				return mEmployees[i];
			}
		}
		throw logic_error("No employee found.");
	}

	void Database::displayAll() const {
		for (const auto& employee : mEmployees) {
			employee.display();
		}
	}

	void Database::displayCurrent() const {
		for (const auto& employee : mEmployees) {
			if (employee.isHired()) {
				employee.display();
			}
		}
	}

	void Database::displayFormer() const {
		for (const auto& employee : mEmployees) {
			if (!employee.isHired()) {
				employee.display();
			}
		}
	}
}