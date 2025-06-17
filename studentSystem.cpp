

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
    std::string id;
    std::string name;
    float math;
    float english;
    float physics;
    float total;
};

class StudentSystem{
    private:
        std::vector<Student> students;
    public:
        void addStudent(){
            Student s;
            std::cout << "������ѧ����ѧ��: ";
            std::cin >> s.id;
            std::cout << "������ѧ��������: ";
            std::cin >> s.name;
            std::cout << "������ѧ������ѧ�ɼ�: ";
            std::cin >> s.math;
            std::cout << "������ѧ����Ӣ��ɼ�: ";
            std::cin >> s.english;
            std::cout << "������ѧ��������ɼ�: ";
            std::cin >> s.physics;
            s.total = s.math + s.english + s.physics;
            students.push_back(s);      // �൱��append()
        }

        void sortStudents(){
            std::sort(students.begin(),students.end(),[](const Student &a,const Student &b){
                return a.total > b.total;
            }); //lambda���ʽ
        };       

};


int main(){
    StudentSystem system;
    int choice;
    do{
        std::cout << "��ѡ�����: " << std::endl;
        std::cout << "1. ���ѧ��" << std::endl;
        std::cout << "2. ����ѧ��" << std::endl;
        std::cout << "0. �˳�" << std::endl;
        std::cin >> choice;
        switch(choice){
            case 1:
                system.addStudent();
                break;
            case 2:
                system.sortStudents();
                break;
            case 3:
                break;
            default:
                std::cout << "��Ч��ѡ��,����������" << std::endl;
        }
    }while (choice != 0); 
    return 0;
}