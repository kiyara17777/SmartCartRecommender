# 🛒 SmartCart Recommender

A beginner-friendly C++ console-based shopping cart system that allows users to register, browse products, add them to a cart, and receive basic product recommendations based on simple rules.

---

## 🚀 Features

- 👤 User Login and Registration (stored in `users.txt`)
- 🛍️ Browse products and prices
- ➕ Add products to a cart
- 📦 View cart contents and total cost
- 🎯 Get basic product recommendations
- 📁 File-based data handling (no database)

---

## 🗂️ Project Structure

```
SmartCartRecommender/
├── src/
│   └── main.cpp              # Main logic of the application
│
├── data/
│   ├── users.txt             # Registered users
│   ├── products.txt          # Product names
│   ├── prices.txt            # Product prices
│   ├── rules.txt             # Recommendation logic
│
├── .gitignore                # Ignores unnecessary files
└── README.md                 # You're reading it :)
```

---

## 🛠️ How to Run

### ▶️ Step 1: Compile the Code (using g++)
```bash
g++ src/main.cpp -o SmartCart
```

### ▶️ Step 2: Run the Program
```bash
./SmartCart
```

---

## 📁 Sample Data

### 📦 products.txt
```
Laptop
Phone
Headphones
```

### 💰 prices.txt
```
60000
20000
3000
```

### 🎯 rules.txt
```
Laptop -> Headphones
Phone -> Charger
```
---
## 📸 Demo

_📷 Screenshot coming soon in the next update..._

---
## 👩‍💻 Developer

**Kiyara Chandrawat**  
C++ Developer | Passionate about practical, beginner-friendly projects  
GitHub: [@kiyara17777](https://github.com/kiyara17777)

---
## 📌 Future Enhancements

- Switch from file-based storage to SQLite database
- Add a simple HTML/CSS frontend
- Integrate Python Flask backend for smarter logic
- Implement ML-based product recommendations
- Add user purchase history tracking
