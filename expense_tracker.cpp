#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Expense {
    int id;
    string date;      // format: YYYY-MM-DD
    string category;
    double amount;
    string note;
};

void loadExpenses(const string &filename, vector<Expense> &expenses, int &nextId) {
    ifstream fin(filename);
    if (!fin) {
        nextId = 1;
        return; // no file yet
    }
    string line;
    int maxId = 0;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, date, category, amountStr, note;
        if (!getline(ss, idStr, '|')) continue;
        if (!getline(ss, date, '|')) continue;
        if (!getline(ss, category, '|')) continue;
        if (!getline(ss, amountStr, '|')) continue;
        if (!getline(ss, note)) note = "";
        try {
            Expense e;
            e.id = stoi(idStr);
            e.date = date;
            e.category = category;
            e.amount = stod(amountStr);
            e.note = note;
            expenses.push_back(e);
            if (e.id > maxId) maxId = e.id;
        } catch (...) {
            // skip malformed line
        }
    }
    nextId = maxId + 1;
}

void saveExpenses(const string &filename, const vector<Expense> &expenses) {
    ofstream fout(filename);
    for (const auto &e : expenses) {
        // We use '|' as a safe delimiter to avoid comma issues in notes.
        fout << e.id << '|' << e.date << '|' << e.category << '|' 
             << fixed << setprecision(2) << e.amount << '|' << e.note << '\n';
    }
}

void listExpenses(const vector<Expense> &expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }
    cout << left << setw(5) << "ID" 
         << setw(12) << "Date" 
         << setw(15) << "Category" 
         << setw(10) << "Amount" 
         << "Note\n";
    cout << string(60, '-') << '\n';
    for (const auto &e : expenses) {
        cout << left << setw(5) << e.id 
             << setw(12) << e.date 
             << setw(15) << e.category 
             << setw(10) << fixed << setprecision(2) << e.amount 
             << e.note << '\n';
    }
}

void addExpense(vector<Expense> &expenses, int &nextId) {
    Expense e;
    e.id = nextId++;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> e.date;
    cout << "Enter category (e.g., food, travel): ";
    cin >> ws; // eat whitespace
    getline(cin, e.category);
    cout << "Enter amount: ";
    while (!(cin >> e.amount)) {
        cout << "Please enter a valid number for amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush rest
    cout << "Enter note (optional): ";
    getline(cin, e.note);
    expenses.push_back(e);
    cout << "Expense added with ID " << e.id << ".\n";
}

void monthlySummary(const vector<Expense> &expenses) {
    cout << "Enter month to summarize (YYYY-MM): ";
    string month;
    cin >> month;
    double total = 0.0;
    int count = 0;
    for (const auto &e : expenses) {
        if (e.date.size() >= 7 && e.date.substr(0, 7) == month) {
            total += e.amount;
            count++;
        }
    }
    cout << "Entries: " << count << ", Total for " << month << " = " 
         << fixed << setprecision(2) << total << '\n';
}

void categorySummary(const vector<Expense> &expenses) {
    cout << "Enter category to summarize: ";
    string cat;
    cin >> ws;
    getline(cin, cat);
    double total = 0.0;
    int count = 0;
    for (const auto &e : expenses) {
        if (e.category == cat) {
            total += e.amount;
            count++;
        }
    }
    cout << "Entries: " << count << ", Total for category \"" << cat << "\" = " 
         << fixed << setprecision(2) << total << '\n';
}

void deleteExpense(vector<Expense> &expenses) {
    cout << "Enter ID to delete: ";
    int id;
    if (!(cin >> id)) {
        cout << "Invalid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    auto it = remove_if(expenses.begin(), expenses.end(),
                        [id](const Expense &e) { return e.id == id; });
    if (it != expenses.end()) {
        expenses.erase(it, expenses.end());
        cout << "Expense with ID " << id << " deleted (if existed).\n";
    } else {
        cout << "No expense with that ID found.\n";
    }
}

int main() {
    vector<Expense> expenses;
    int nextId = 1;
    const string filename = "expenses.txt";
    bool dirty = false; // tracks unsaved changes

    loadExpenses(filename, expenses, nextId);
    cout << "Welcome to CLI Expense Tracker!\n";
    while (true) {
        cout << "\nMenu:\n"
             << "1. Add expense\n"
             << "2. List all expenses\n"
             << "3. Monthly summary (YYYY-MM)\n"
             << "4. Category summary\n"
             << "5. Delete expense by ID\n"
             << "6. Save to file\n"
             << "7. Save & Exit\n"
             << "0. Exit without saving\n"
             << "Choose: ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1:
                addExpense(expenses, nextId);
                dirty = true;
                break;
            case 2:
                listExpenses(expenses);
                break;
            case 3:
                monthlySummary(expenses);
                break;
            case 4:
                categorySummary(expenses);
                break;
            case 5:
                deleteExpense(expenses);
                dirty = true;
                break;
            case 6:
                saveExpenses(filename, expenses);
                dirty = false;
                cout << "Saved to " << filename << '\n';
                break;
            case 7:
                saveExpenses(filename, expenses);
                cout << "Saved. Exiting.\n";
                return 0;
            case 0:
                if (dirty) {
                    cout << "You have unsaved changes. Are you sure you want to exit? (y/n): ";
                    char c; cin >> c;
                    if (c == 'y' || c == 'Y') return 0;
                } else {
                    return 0;
                }
                break;
            default:
                cout << "Unknown option.\n";
        }
    }
    return 0;
}
