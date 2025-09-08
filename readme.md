# 📊 Expense Tracker (C++ CLI Project)

A simple **Command-Line Expense Tracker** written in **C++17**.  
This project demonstrates practical use of **structs, vectors, file I/O, string parsing, formatted output, and menu-driven programming** in C++.

---

## 🚀 Features

- ➕ Add new expense (date, category, amount, note)  
- 📜 List all expenses in a clean tabular format  
- 📅 View **monthly summary** (e.g., total for 2025-09)  
- 🗂️ View **category-wise summary** (e.g., total spent on Food)  
- ❌ Delete expense by ID  
- 💾 Save and Load data from `expenses.txt` (file persistence)  
- ✅ Handles invalid input gracefully  

---

## 🛠️ Tech Used

- **Language:** C++17  
- **Concepts Demonstrated:**
  - `struct` for modeling data  
  - `vector` for dynamic storage  
  - File I/O (`ifstream`, `ofstream`)  
  - String parsing with `stringstream`  
  - `iomanip` for formatted output  
  - Input validation & error handling  
  - Menu-driven interface (console)  

---

## 📂 Project Structure

```

expense\_tracker.cpp   # Main source code
expenses.txt          # Data file (created at runtime)
README.md             # Documentation

````

---

## ▶️ How to Run

### **Compile**
```bash
g++ -std=c++17 expense_tracker.cpp -o expense_tracker
````

### **Run**

```bash
./expense_tracker
```

(Windows users: run `expense_tracker.exe` instead.)

---

## 💡 Example Usage

```
Welcome to CLI Expense Tracker!

Menu:
1. Add expense
2. List all expenses
3. Monthly summary (YYYY-MM)
4. Category summary
5. Delete expense by ID
6. Save to file
7. Save & Exit
0. Exit without saving

Choose: 1
Enter date (YYYY-MM-DD): 2025-09-08
Enter category: Food
Enter amount: 120.50
Enter note: Lunch with friends

Expense added with ID 1.
```

---

## 📖 Sample Data File (`expenses.txt`)

```
1|2025-09-08|Food|120.50|Lunch with friends
2|2025-09-08|Travel|50.00|Bus ticket
```

---

## 🎓 What This Project Demonstrates (For Interviewers)

* **Problem-Solving:** Designed a program to manage personal expenses efficiently.
* **C++ Fundamentals:** Mastery of data structures (`struct`, `vector`), loops, conditionals.
* **Persistence:** Implemented saving & loading using text files.
* **Data Processing:** Summaries based on **month** and **category**.
* **Clean Code Practices:** Error handling, formatted output, modular functions.
* **Extensibility:** Can be extended to support editing, sorting, or exporting to CSV/JSON.

---

## 🔮 Possible Extensions

* Validate date format (`YYYY-MM-DD`).
* Support **sorting** (by date, amount, category).
* Add **editing** existing entries.
* Export data to CSV/Excel/JSON.
* Connect with a GUI framework (Qt) or Web/Mobile frontend.

---

## 👨‍💻 Author

**Harshit Singh**

* 🎓 B.Tech (Artificial Intelligence & Machine Learning), B.Sc (Mathematics & Physics)
* 💻 Skills: C++, Python, AI/ML, Backend (Node.js/Express), Frontend (React, Flutter)
* 📬 Email: [lifeaspirant24@gmail.com](mailto:lifeaspirant24@gmail.com)
* 🌐 GitHub: [github.com/Rosrt](https://github.com/Rosrt)

---

```

---

👉 Harshit, I made this README **interviewer-friendly** by:  
- Highlighting **C++ concepts you used**.  
- Showing **practical problem-solving** skills.  
- Adding a **clear run guide** for users.  

Would you like me to also make a **short “Key Interview Talking Points” section** (like a cheat sheet) so you can confidently explain this project in interviews?
```
