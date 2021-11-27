#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Students{
protected:
    string colums[6]={"id", "surname", "name", "patronymic", "age", "class"};
    vector<int> ids;
    vector<string> surname;
    vector<string> name;
    vector<string> patronymic;
    vector<int> age;
    vector<string> group;
    void load(string surname, string name, string patronymic, int age, string group){
        int id;
        if(this->ids.size()){
            id=this->ids[this->ids.size()-1]+1;
        }else{
            id=0;
            this->ids.push_back(id);
            this->surname.push_back(surname);
            this->name.push_back(name);
            this->patronymic.push_back(patronymic);
            this->age.push_back(age);
            this->group.push_back(group);
        }
    }
public:


    void load_data_students(string s){
        try{
            ifstream test;
            test.open(s.c_str());
            string s;
            int count=0;
            while(!test.eof()){
                cin >> s;
                count++;
            }
            if(count%6==0){
                ifstream fin;
                fin.open(s.c_str());
                while(!fin.eof()){
                    string surname, name, patronymic, group;
                    int age;
                    fin >> surname >> name >> patronymic >> age >> group;
                    load( surname, name, patronymic, age, group);
                }
                fin.close();
            }
        }catch(...){}

    }
    void set_data_students(string surname, string name, string patronymic, int age, string group){
        load( surname, name, patronymic, age, group);
    }
    Students(string s){
        load_data_students(s);
    }
    Students(vector<string> surname, vector<string> name, vector<string> patronymic, vector<int> age, vector<string> group){
        try{
            if(surname.size()==name.size() && surname.size()==patronymic.size() && surname.size()==age.size() && surname.size()==group.size()){
                for(int i=0;i<surname.size();i++){
                    set_data_students(surname[i], name[i], patronymic[i], age[i], group[i]);
                }
            }
        }catch(...){}
    }
    void clear(){
        this->ids.clear();
        this->surname.clear();
        this->name.clear();
        this->patronymic.clear();
        this->age.clear();
        this->group.clear();
    }
    void view(){
        for(int i=0;i<6;i++){
            cout.setf(ios::left);
            if(i==0 || i==4 || i==5){
                cout.width(5);
            }else{
                cout.width(20);
            }
            cout <<colums[i];
        }
        cout << endl;
        for(int i=0;i<this->ids.size();i++){
            cout.setf(ios::left);
            cout.width(5);
            cout << this->ids[i];
            cout.setf(ios::left);
            cout.width(20);
            cout << this->surname[i];
            cout.setf(ios::left);
            cout.width(20);
            cout << name[i];
            cout.setf(ios::left);
            cout.width(20);
            cout << patronymic[i];
            cout.setf(ios::left);
            cout.width(5);
            cout << this->age[i];
            cout.setf(ios::left);
            cout.width(5);
            cout << this->group[i];
            cout << endl;
       }
    }
    void clear_string(int number_string){
        vector<int> ids;
        vector<string> surname;
        vector<string> name;
        vector<string> patronymic;
        vector<int> age;
        vector<string> group;
        for(int i=0;i<this->ids.size();i++){
            if(i+1!=number_string){

            }
        }
    }
};

class DataBase{
};

