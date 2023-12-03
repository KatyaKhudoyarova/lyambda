#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Students {
private:
    string name;
    string surname;
    double SerBal;
    vector<double> vec;

public:
    Students(string name, string surname, double SerBal) : name(name), surname(surname), SerBal(SerBal) {}

    void addGrade(double grade) {
        vec.push_back(grade);
    }

    void printBestStudent() const {
        if (vec.empty()) {
            cout << "No grades available for " << name << " " << surname << endl;
            return;
        }

        auto maxElement = max_element(vec.begin(), vec.end());

        if (maxElement != vec.end()) {
            cout << "The best grade for " << name << " " << surname << ": " << *maxElement << endl;
        }
    }

    double getMaxGrade() const {
        auto maxElement = max_element(vec.begin(), vec.end(),
                                      [](const int& a, const int& b) {
                                          return a < b;
                                      }
        );
        return (maxElement != vec.end()) ? *maxElement : -1;
    }

    string getFullName() const {
        return name + " " + surname;
    }
};

int main() {
    vector<Students> students;
    students.emplace_back("Katya", "Khudoyarova", 100);
    students[0].addGrade(99);
    students[0].addGrade(100);

    students.emplace_back("Olya", "Yamshanova", 95);
    students[1].addGrade(90);
    students[1].addGrade(95);

    students.emplace_back("Artem", "Shishkov", 60);
    students[2].addGrade(60);
    students[2].addGrade(50);

    students.emplace_back("Demid", "Fedorov", 99);
    students[3].addGrade(97);
    students[3].addGrade(99);

    double highestGrade = -1;
    Students* bestStudent = nullptr;

    for (auto &student : students) {
        student.printBestStudent();
        double maxGrade = student.getMaxGrade();
        if (maxGrade > highestGrade) {
            highestGrade = maxGrade;
            bestStudent = &student;
        }
    }

    if (bestStudent != nullptr) {
        cout<<"************************************************"<<endl;
        cout << "The student with the highest grade is: " << bestStudent->getFullName()<<" "<<highestGrade;

    } else {
        cout << "No student has grades available." << endl;
    }

    return 0;
}
