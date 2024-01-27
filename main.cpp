#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//string specializare;

// bool check(pair<string,string> doctor){
//    return doctor.second == specializare;
// }

struct Problem
{
        string name, speciality;
};

struct Doctor
{
    string name, speciality;
};

Problem currentProblem;

bool matchesSpeciality(Doctor& doctor)
{
    return doctor.speciality == currentProblem.speciality;
}

int main()
{
    ifstream inFile("HandsOn-Input.txt");
    vector<Problem> problems;
    vector<Doctor> doctors;
    int no_problems, no_doctors;
    string name, speciality;

    

    //vector<pair<string,string>> doctors;
    //vector<pair<string, string>> doctorsProblems;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        cout << name << ' ' << speciality << '\n';
        problems.push_back({name, speciality});
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        cout << name << ' ' << speciality << '\n';
        doctors.push_back({name, speciality});
    }

    for (Problem problem : problems)
    {
       currentProblem = problem;
       auto doctor = find_if(doctors.begin(), doctors.end(), matchesSpeciality);
       if (doctor != doctors.end())
       {
        cout << doctor->name << ' ' << currentProblem.name << "\n";
            doctors.erase(doctor);
       }

       
    }
    

    return 0;
}

