#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class HealthDiary {
    private:
        string name;
        int age;
        string symptom;
        string medication;
        string notes;
        public:
        void inputData() {
            cout << "Enter Name: ";
            getline(cin, name);   // Takes full name input
            cout << "Enter Age: ";
            cin >> age;           // Takes age input
            cin.ignore();         // Clears input buffer after taking integer input
    
            cout << "Enter Symptom: ";
            getline(cin, symptom);  // Takes symptom description
            cout << "Enter Medication Taken: ";
            getline(cin, medication);  // Takes medication details
            cout << "Additional Notes: ";
            getline(cin, notes);   // Takes additional notes if any
        }
        void displayData() {
            cout << "\n----- Medical Report -----\n";
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Symptom: " << symptom << endl;
            cout << "Medication: " << medication << endl;
            cout << "Notes: " << notes << endl;
        }
        void saveData() {
            ofstream file;  // Object to write data to a file
            file.open("HealthReport.txt", ios::app);  // Open file in append mode
    
            file << "----- Medical Report -----\n";
            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "Symptom: " << symptom << endl;
            file << "Medication: " << medication << endl;
            file << "Notes: " << notes << endl;
            file << "--------------------------\n";
            
            file.close();  // Close the file
            cout << "\nData saved to HealthReport.txt successfully.\n";
        }
        int main() {
            HealthDiary diary;  // Create an object of HealthDiary class
            char choice;        // Choice for continuing the loop
            
            do {
                diary.inputData();    // Takes input from the user
                diary.displayData();  // Displays the entered data
                diary.saveData();     // Saves the data to a file
                
                cout << "\nDo you want to enter more records? (y/n): ";
                cin >> choice;        
                cin.ignore();  // Clear the buffer for next input
            } while (choice == 'y' || choice == 'Y');  // Continue if 'y' or 'Y'
        
            cout << "\nThank you for using the Health Diary System!\n";
            return 0;
        }
                        