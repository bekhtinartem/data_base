#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/*
string to_string(int value){
    string s="";
    while(value!=0){
        s=char(48+value%10) +s;
        value/=10;
    }
    return s;
}*/

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
        }
        this->ids.push_back(id);
        this->surname.push_back(surname);
        this->name.push_back(name);
        this->patronymic.push_back(patronymic);
        this->age.push_back(age);
        this->group.push_back(group);

    }
public:


    void load_data_students(string s){
            ifstream test;
            test.open(s.c_str());
            string s1;
            int count=0;
            while(!test.eof()){
                cin >> s1;
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
    void delete_string(int number_string){
        vector<int> ids;
        vector<string> surname;
        vector<string> name;
        vector<string> patronymic;
        vector<int> age;
        vector<string> group;
        int counter=0;
        for(int i=0;i<this->ids.size();i++){
            if(i+1!=number_string){
                ids.push_back(counter);
                surname.push_back(this->surname[i]);
                name.push_back(this->name[i]);
                patronymic.push_back(this->patronymic[i]);
                age.push_back(this->age[i]);
                group.push_back(this->group[i]);
                counter++;
            }
        }
        this->ids=ids;
        this->surname=surname;
        this->name=name;
        this->patronymic=patronymic;
        this->age=age;
        this->group=group;
    }
    vector<int> get_data(int start, int count, string category){
        vector<int> out;
        if(category=="id" || category=="age"){
            for(int i=start-1;i<this->ids.size() && i<start+count;i++){
                if(category=="id"){
                    out.push_back(this->ids[i]);
                }else{
                    out.push_back(this->age[i]);
                }
            }
        }
        return out;
    }
    vector<string> get_line(int start, int count, string category){
        vector<string> out;
        if(category=="surname" || category=="name" || category=="patronymic" || category=="class"){
            for(int i=start-1;i<this->ids.size() && i<start+count;i++){
                if(category=="surname"){
                    out.push_back(this->surname[i]);
                }
                if(category=="name"){
                    out.push_back(this->name[i]);
                }
                if(category=="patronymic"){
                    out.push_back(this->patronymic[i]);
                }

                if(category=="class"){
                    out.push_back(this->group[i]);
                }
            }

        }
        return out;
    }

};
class Items{
protected:
    string colums_second[2]={"id", "name"};
    vector<int> ids;
    vector<string> name;
    void load(string name){
        int id;
        if(this->ids.size()){
            id=this->ids[this->ids.size()-1]+1;
        }else{
            id=0;
        }
        this->ids.push_back(id);
        this->name.push_back(name);
    }
public:
    void load_data_items(string s){
        try{
            ifstream test;
            test.open(s.c_str());
            string s1;
            while(!test.eof()){
                cin >> s1;
                load(s1);
            }
        }catch(...){}

    }
    void set_data_items(string name){
        load(name);
    }
    Items(string s){
        load_data_items(s);
    }
    Items(vector<string> name){
        try{
            for(int i=0;i<name.size();i++){
                set_data_items(name[i]);
            }
        }catch(...){}
    }
    void clear(){
        this->ids.clear();
        this->name.clear();
    }
    void view(){
        for(int i=0;i<2;i++){
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
            cout << name[i];
            cout << endl;
       }
    }
    void delete_string(int number_string){
        vector<int> ids;
        vector<string> name;
        int counter=0;
        for(int i=0;i<this->ids.size();i++){
            if(i+1!=number_string){
                ids.push_back(counter);
                name.push_back(this->name[i]);
                counter++;
            }
        }
        this->ids=ids;
        this->name=name;
    }
    vector<int> get_data(int start, int count){
        vector<int> out;
        for(int i=start-1;i<this->ids.size() && i<start+count;i++){
            out.push_back(this->ids[i]);
        }
        return out;
    }
    vector<string> get_line(int start, int count){
        vector<string> out;
        for(int i=start-1;i<this->ids.size() && i<start+count;i++){
            out.push_back(this->name[i]);
        }
        return out;
    }

};
class Appraisals{
protected:
    string colums[4]={"id", "id_st", "id_it", "appr"};
    vector<int> ids;
    vector<int> ids_students;
    vector<int> ids_items;
    vector<int> appraisals;
    void load(int ids_students, int ids_items,int appraisals ){
        int id;
        if(this->ids.size()){
            id=this->ids[this->ids.size()-1]+1;
        }else{
            id=0;
        }
        this->ids.push_back(id);
        this->ids_students.push_back(ids_students);
        this->ids_items.push_back(ids_items);
        this->appraisals.push_back(appraisals);
    }
};

class DataBase{
};

