#include <iostream>
using namespace std;

class Student 
{
    public: 
    	char name[100];
        char course[100];
        double grades[10];
        int gradeCount;

        void input()
        {
            this->name;
            cin.ignore();
            cin.getline(name, 100);
            cin.getline(course, 100);
            cin >> gradeCount;
            for (int j = 0; j < gradeCount; ++j)
            {
                cin >> grades[j];
            }
        }

        void print()
        {
            cout << "Student name: " << name << endl;
            cout << "Course name: " << course << endl;
            cout << "Grades:\n";
            for (int j = 0; j < gradeCount; ++j)
            {
                cout << grades[j] << " ";
            }
            cout << "\n\n";
        }
        
        void printAddr() {
            cout << this << endl;
        }

        double getAverageGrade() {
            double avg = 0;
            for (int i = 0; i < gradeCount; ++i)
            {
                avg += grades[i];
            }
            return avg / gradeCount;
        }
};

int main()
{
    int n;
    cin >> n;

    Student students[10];

    // Въвеждане
    for (int i = 0; i < n; ++i)
    {
        students[i].input();
    }

    // Сравняване на адреси
    cout << students + 2 << endl;
    students[2].printAddr();
    students[3].printAddr();

    // Извеждане
    for (int i = 0; i < n; ++i)
    {
        cout << students[i].getAverageGrade() << endl;
        students[i].print();
    }
    return 0;
}
