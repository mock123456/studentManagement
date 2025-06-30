

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "odd.h"
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
            std::cout << "请输入学生的学号: ";
            std::cin >> s.id;
            std::cout << "请输入学生的姓名: ";
            std::cin >> s.name;
            std::cout << "请输入学生的数学成绩: ";
            std::cin >> s.math;
            std::cout << "请输入学生的英语成绩: ";
            std::cin >> s.english;
            std::cout << "请输入学生的物理成绩: ";
            std::cin >> s.physics;
            s.total = s.math + s.english + s.physics;
            students.push_back(s);      // 相当于append()
        }

        void sortStudents(){
            std::sort(students.begin(),students.end(),[](const Student &a,const Student &b){
                return a.total > b.total;
            }); //lambda表达式
        };
        void judgeOdd() {
            printf("请输入一个整数:");
            std::cin >> n;
            std::cout << "是否是奇数: " << isOdd(n) << std::endl;
        };

};


int main(){
    StudentSystem system;
    int choice;
    do{
        std::cout << "请选择操作: " << std::endl;
        std::cout << "1. 添加学生" << std::endl;
        std::cout << "2. 排序学生" << std::endl;
        std::cout << "3. 判断是否是奇数" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cin >> choice;
        switch(choice){
            case 0:
                break;
            case 1:
                system.addStudent();
                break;
            case 2:
                system.sortStudents();
                break;
            case 3:
                system.judgeOdd();
            default:
                std::cout << "无效的选择,请重新输入" << std::endl;
        }
    }while (choice != 0); 
    return 0;
}