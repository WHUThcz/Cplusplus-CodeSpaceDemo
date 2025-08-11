#include <iostream>
#include<string>
// #include <cstdlib> // For system("pause") and system("cls")
using namespace std;
#define MAX 1000

void showMenu()
{
    cout << "1. Add Person" << endl;
    cout << "2. Delete Person" << endl;
    cout << "3. Modify Person" << endl;
    cout << "4. Search Person" << endl;
    cout << "5. Show All Persons" << endl;
    cout << "6. Clear Persons" << endl;
    cout << "7. Exit" << endl;
}
struct Person {
    string name;
    int sex;
    int age;
    string address;
    string phoneNumber;
};

struct AddressBook {
    Person persons[MAX];
    int count;
};

void AddPerson(AddressBook &book) {

    if (book.count >= MAX) {
        cout << "Address book is full!" << endl;
        return;
    }
    Person newPerson;
    int sex;
    cout << "Enter name: "<<endl;
    cin >> newPerson.name;
    while(true){    
        cout << "Enter sex,1:man 2:woman"<<endl;
        cin >> sex;
        if(!(sex==1||sex==2)){
            cout << "Invalid, please enter again." << endl;
            continue;
        }
        newPerson.sex = sex;
        break;
    }
    cout << "Enter age: "<<endl;
    cin >> newPerson.age;
    cout << "Enter address: "<<endl;
    cin >> newPerson.address;
    cout << "Enter phone number: "<<endl;
    cin >> newPerson.phoneNumber;

    book.persons[book.count] = newPerson;
    book.count++;
    cout << "Person added successfully." << endl;
}

void ClearPersons(AddressBook &book) {
    book.count = 0;     //逻辑清空
    cout << "All persons cleared successfully." << endl;
}

void ShowAllPersons(AddressBook &book) {
    if (book.count == 0) {
        cout << "No persons in the address book." << endl;
        return;
    }
    cout << "List of all persons:" << endl;
    for (int i = 0; i < book.count; i++) {
        cout << "Name: " << book.persons[i].name << ",";
        if(book.persons[i].sex == 1) {cout << "男"; }
        else {cout << "女";}
        cout << ", Age: " << book.persons[i].age 
             << ", Address: " << book.persons[i].address 
             << ", Phone Number: " << book.persons[i].phoneNumber << endl;
    }
    cout << "Total persons: " << book.count << endl;
}

int exitPerson(AddressBook &book) {
    int model;
    while (true)
    {
        cout << "Select model: 1 name 2 address 3 phonenumber" << endl;
        cin >> model;
        if (model < 1 || model > 3) {
        cout << "Invalid model selected." << endl;
        continue;
        }
        break;
    }
    string name, address, phoneNumber;;
    switch (model)
    {
    case 1:
        cout << "Enter name to search: ";
        cin >> name;
        for (int i = 0; i < book.count; i++) {
            if (book.persons[i].name == name) {
                cout << "Found: " << book.persons[i].name << ", "
                     << (book.persons[i].sex == 1 ? "男" : "女") << ", "
                     << book.persons[i].age << ", "
                     << book.persons[i].address << ", "
                     << book.persons[i].phoneNumber << endl;
                return i;
            }else {
                cout << "Person not found." << endl;
                return -1;
            }
        }
        break;
    case 2:
        cout << "Enter address to search: ";
        cin >> name;
        for (int i = 0; i < book.count; i++) {
            if (book.persons[i].address == address) {
                cout << "Found: " << book.persons[i].name << ", "
                     << (book.persons[i].sex == 1 ? "男" : "女") << ", "
                     << book.persons[i].age << ", "
                     << book.persons[i].address << ", "
                     << book.persons[i].phoneNumber << endl;
                return i;
            }else {
                cout << "Person not found." << endl;
                return -1;
            }
        }
        break;
    case 3:
        cout << "Enter phonenumber to search: ";
        cin >> name;
        for (int i = 0; i < book.count; i++) {
            if (book.persons[i].phoneNumber == phoneNumber) {
                cout << "Found: " << book.persons[i].name << ", "
                     << (book.persons[i].sex == 1 ? "男" : "女") << ", "
                     << book.persons[i].age << ", "
                     << book.persons[i].address << ", "
                     << book.persons[i].phoneNumber << endl;
                return i;
            }else {
                cout << "Person not found." << endl;
                return -1;
            }
        }
        break;
    default:
        return -1;
    }
}
int isExist(AddressBook * abs, string name)
{
    for (int i = 0; i < abs->count; i++) {
        if (abs->persons[i].name == name) {
            return i; // Return the index of the person if found
        }
    }
    return -1; // Return -1 if not found
}
        

void ModifyPerson(AddressBook &book) {
    if (book.count == 0) {
        cout << "No persons to modify." << endl;
        return;
    }
    string name;
    cout << "Enter the name of the person to modify: ";
    cin >> name;
    int index = isExist(&book, name);
    if (index == -1) {
        cout << "Person not found." << endl;
        return;
    }
    Person &person = book.persons[index];
    cout << "Modifying person: " << person.name << endl;
    cout << "Enter new name (or press Enter to keep current): ";
    string newName;
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, newName);
    book.persons[index].name = newName;
    cout << "Enter new sex: 1 man 2 woman: "<< endl;
    int sex;
    while(true){    
        cout << "Enter sex,1:man 2:woman"<<endl;
        cin >> sex;
        if(!(sex==1||sex==2)){
            cout << "Invalid, please enter again." << endl;
            continue;
        }
        book.persons[index].sex = sex;
        break;
    }
    cout << "Enter new age: "<<endl;
    int age;
    cin >> age;
    book.persons[index].age = age;
    cout << "Enter new address: "<<endl;
    string address;
    cin >> address;
    book.persons[index].address = address;
    cout << "Enter new phone number: "<<endl;
    string phoneNumber;
    cin >> phoneNumber;
    book.persons[index].phoneNumber = phoneNumber;
    cout << "Person modified successfully." << endl;

}
void DeletePerson(AddressBook &book) {
    if (book.count == 0) {
        cout << "No persons to delete." << endl;
        return;
    }
    string name;
    cout << "Enter the name of the person to delete: ";
    cin >> name;
    int index = isExist(&book, name);
    if (index == -1) {
        cout << "Person not found." << endl;
        return;
    }
    // Shift persons to remove the person at index
    for (int i = index; i < book.count - 1; i++) {
        book.persons[i] = book.persons[i + 1];
    }
    book.count--;
    cout << "Person deleted successfully." << endl;
    cout << "Remaining persons: " << book.count << endl;
}
int main() {
    AddressBook book;
    book.count = 0;
    int choice;
    
    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Add Person selected." << endl;
                AddPerson(book);
                // Add person logic here
                cout << "Person added successfully." << endl;
                break;
            case 2:
                cout << "Delete Person selected." << endl;
                DeletePerson(book);

                break;
            case 3:
                cout << "Modify Person selected." << endl;
                ModifyPerson(book);
                break;
            case 4:
                cout << "Search Person selected." << endl;
                exitPerson(book);
                break;
            case 5:
                cout << "Show All Persons selected." << endl;
                ShowAllPersons(book);
                break;
            case 6:
                cout << "Clear Persons selected." << endl;
                ClearPersons(book);
                break;
            case 7:
                cout << "Exiting program." << endl;
                cout << "Program exited successfully." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

