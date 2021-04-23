#include <iostream>
#include <iomanip>
using namespace std;

char getMedicationTypeFromUser();

char getSurgeryTypeFromUser();

class PatientAccount 
{
    double daily_rate;
protected:
    double charges1;
    double charges2;
    int numberOfDays;
public:
    PatientAccount(int n) 
    {
        daily_rate = 700;
        numberOfDays = n;
        charges1 = 0;
        charges2 = 0;
    }
    void displayCharges() 
    {
        double total = numberOfDays * daily_rate + charges1 + charges2;
        cout << "Patient Charges" << endl << endl ;
        cout << "Hospital: " << numberOfDays <<" days "<<
            " at "<< "$"<<daily_rate<<" = $"<<(daily_rate*numberOfDays)<<endl;
        cout << "Surgery Charge: " << setw(8)<<"$" << charges1 << endl;
        cout << "Pharmacy Charge: " << setw(7)<<"$"<< charges2<< endl;
        cout<<setw(30)<<"----------"<<endl;
        cout << "Total Charges: " << setw(8)<<"$"<< total << endl;
    }
    friend class Surgery;
    friend class Pharmacy;
};
class Surgery 
{
    double HEART, BRAIN, EYE, KNEE, MINOR;
public:
    Surgery() 
    {
        HEART = 12000;
        BRAIN = 28000;
        EYE = 1250;
        KNEE = 6000;
        MINOR = 600;
    }
    void setSurgeryCharges(PatientAccount& p, char type) 
    {
        if (type == '1') 
        {
            p.charges1 += MINOR;
        }
        else if (type == '2') 
        {
            p.charges1 += EYE;
        }
        else if (type == '3') 
        {
            p.charges1 += KNEE;
        }
        else if (type == '4') 
        {
            p.charges1 += HEART;
        }
        else if (type == '5') 
        {
            p.charges1 += BRAIN;
        }
        else {
            cout << "Invalid Surgery type " << endl;
        }
    }
};
class Pharmacy 
{
    double ASPIRIN, SLEEPINGPILLS, PAINPILLS, LOCALANESTHETIC, GENERALANESTHETIC;
public:
    Pharmacy() 
    {
        ASPIRIN = 10;
        SLEEPINGPILLS = 20;
        PAINPILLS = 50;
        LOCALANESTHETIC = 75;
        GENERALANESTHETIC = 300;
    }
    void setMedicationCharges(PatientAccount& p, char type) 
    {
        if (type == '1') 
        {
            p.charges2 += ASPIRIN;
        }
        else if (type == '2') 
        {
            p.charges2 += SLEEPINGPILLS;
        }
        else if (type == '3') 
        {
            p.charges2 += PAINPILLS;
        }
        else if (type == '4') 
        {
            p.charges2 += LOCALANESTHETIC;
        }
        else if (type == '5') 
        {
            p.charges2 += GENERALANESTHETIC;
        }
        else 
        {
            cout << "Invalid medication type " << endl;
        }
    }
};
int main() 
{
    Surgery surgery;
    Pharmacy pharmacy;
    int days;
    do//while (days>0)//true
    {
        //int days;
        char surgeryType;
        char medicationType;
        cout << "How many days was the patient in the hospital?: ";
        cin >> days;
        PatientAccount patient(days);
        cout << endl;
        cout << "Did the patient have surgery (Y/N)? ";
        char choice2;
        char choice3 = 'n';
        char choice4 = 'y';
        cin >> choice2;
        cout << endl;

        if (choice2 == 'y')
            {
                surgeryType = getSurgeryTypeFromUser();
                surgery.setSurgeryCharges(patient, surgeryType);
            }

        if (choice3 == 'n')
            {
                cout << "Did the patient receive medication (Y/N)? ";
                cin >> choice3;
                cout <<endl;
            }

        if (choice3 == 'y')
            {
            while (choice4 == 'y')
            {
                medicationType = getMedicationTypeFromUser();
                pharmacy.setMedicationCharges(patient, medicationType);
                cout << "Did the patient receive any other medication (Y/N)? ";
                cin >> choice4;
                cout<<endl;
            }
            }
        // medicationType = getMedicationTypeFromUser();
        // pharmacy.setMedicationCharges(patient, medicationType);
        patient.displayCharges();
        return 0;
    
    }while (days>0);
    
}
char getSurgeryTypeFromUser() 
{
    char surgeryType;
    cout << "Please enter surgery type" << endl << endl;
    cout << "1 - Minor surgery  $600" << endl;
    cout << "2 - Eye surgery   $1,250" << endl;
    cout << "3 - Knee replacement  $6,000" << endl;
    cout << "4 - Heart surgery  $12,000" << endl;
    cout << "5 - Brain surgery  $28,000" << endl;
    cin >> surgeryType;
    cout<<endl;
    if (surgeryType != '1' && surgeryType != '2' && surgeryType != '3' && surgeryType != '4' && surgeryType != '5') 
    {
        cout << "Invalid choice, try again..." << endl;
        return getSurgeryTypeFromUser();
    }
    else 
    {
        return surgeryType;
    }
}
char getMedicationTypeFromUser() 
{
    char medicationType;
    cout << "Please enter medication type" << endl << endl;
    cout << "1 - Aspirin  $10" << endl;
    cout << "2 - Sleeping Pills   $20" << endl;
    cout << "3 - Pain pills  $50" << endl;
    cout << "4 - Local anestheic  $75" << endl;
    cout << "5 - General anesthetic  $300" << endl;
    cin >> medicationType;
    cout<<endl;
    if (medicationType != '1' && medicationType != '2' && medicationType != '3' && medicationType != '4' && medicationType != '5')
    {
        cout << "Invalid choice, try again..." << endl;
        return getMedicationTypeFromUser();
    }
    else 
    {
        return medicationType;
    }
    return 0;
} 