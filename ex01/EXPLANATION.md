# Ex01: Moar brainz! - Evaluation Guide

## ✅ Verification Against Evaluation Sheet

### Makefile and tests:
- ✅ Makefile compiles with appropriate flags (`-Wall -Wextra -Werror -std=c++98`)
- ✅ Main tests the exercise

### zombieHorde:
- ✅ Zombie Class has default constructor
- ✅ `zombieHorde()` function prototype: `Zombie* zombieHorde(int N, std::string name);`
- ✅ Allocates N zombies on the heap explicitly using `new[]`
- ✅ After allocation, initializes objects to set their name
- ✅ Returns pointer to the first zombie
- ✅ Tests in main prove all previous points
- ✅ Calling `announce()` on all zombies works
- ✅ All zombies are deleted at the same time in main using `delete[]`

---

## 📝 How to Explain to the Evaluator

### 1. What This Exercise Teaches:

*"This exercise teaches us how to allocate arrays of objects on the heap in C++, and the importance of default constructors when working with arrays. It also demonstrates the difference between `new` vs `new[]` and `delete` vs `delete[]`."*

### 2. Key Concepts:

**Default Constructor:**
```cpp
Zombie::Zombie() { }
```
- **Required** when allocating arrays with `new[]`
- Arrays are created first with default constructor, then initialized
- Without default constructor, `new Zombie[N]` won't compile

**Array Allocation on Heap:**
```cpp
Zombie* horde = new Zombie[N];  // Allocates N zombies
```
- Creates N consecutive Zombie objects in memory
- All constructed with default constructor first
- Must use `delete[]` (not `delete`) to free

**Two-Step Initialization:**
```cpp
Zombie* horde = new Zombie[N];  // Step 1: Allocate with default constructor
for (int i = 0; i < N; i++)
    horde[i].setName(name);     // Step 2: Initialize each object
```

### 3. Design Decisions Justification:

**Why I added a default constructor:**
```
"I added a default constructor because when you allocate an array with new[], 
C++ needs to construct each object. Unlike a parameterized constructor, you 
can't pass arguments to each element during array allocation. So the default 
constructor creates 'blank' zombies, then I use setName() to initialize them 
afterward."
```

**Why I added setName():**
```
"I added setName() because the zombies are first created with the default 
constructor (which doesn't take parameters). After the array is allocated, 
I need a way to set each zombie's name. This is a common pattern: 
allocate first, then initialize."
```

**Why delete[] instead of delete:**
```
"I used delete[] instead of delete because I allocated an array with new[]. 
The delete[] operator knows it's an array and will call the destructor for 
EACH zombie in the array, then free all the memory. Using delete (without []) 
would only destroy the first zombie and cause memory leaks and undefined 
behavior."
```

### 4. Demonstrating Understanding:

Run the program:
```bash
make && ./Zombie
```

Expected output:
```
A zombie is born.
A zombie is born.
A zombie is born.
A zombie is born.
A zombie is born.
HordeZombie: BraiiiiiiinnnzzzZ...
HordeZombie: BraiiiiiiinnnzzzZ...
HordeZombie: BraiiiiiiinnnzzzZ...
HordeZombie: BraiiiiiiinnnzzzZ...
HordeZombie: BraiiiiiiinnnzzzZ...
HordeZombie is destroyed
HordeZombie is destroyed
HordeZombie is destroyed
HordeZombie is destroyed
HordeZombie is destroyed
```

**Explain:** *"Notice 5 zombies are born first (default constructor), then I set their names, they all announce, and finally when I call delete[], all 5 are destroyed properly. No memory leaks!"*

---

## 🆚 Comparison with C:

### In C:
```c
// Allocate array of structs
Zombie* horde = malloc(N * sizeof(Zombie));

// Manual initialization - NO automatic constructors
for (int i = 0; i < N; i++) {
    strcpy(horde[i].name, name);
}

// Manual cleanup - NO automatic destructors
for (int i = 0; i < N; i++) {
    // Manual cleanup if needed
}
free(horde);  // Just one free() call
```

### In C++:
```cpp
// Allocate array of objects - default constructor called N times
Zombie* horde = new Zombie[N];

// Initialize each object
for (int i = 0; i < N; i++) {
    horde[i].setName(name);
}

// Cleanup - destructor called N times automatically
delete[] horde;
```

**Key difference:** C++ calls constructors/destructors automatically for each array element!

---

## 🔑 Important Points:

### new vs new[]:
- `new Zombie(name)` → allocates **ONE** object → use `delete`
- `new Zombie[N]` → allocates **ARRAY** of N objects → use `delete[]`

### Memory Layout:
```
new Zombie[5]:
[Zombie][Zombie][Zombie][Zombie][Zombie]  ← Contiguous memory
   ↑
   Returns pointer to first element
```

### Common Mistake to Avoid:
```cpp
Zombie* horde = new Zombie[N];
delete horde;   // ❌ WRONG! Memory leak + undefined behavior
delete[] horde; // ✅ CORRECT! Destroys all N zombies
```

### Why Array Allocation Matters:
1. **Contiguous Memory:** All objects stored next to each other
2. **Cache Efficiency:** Better CPU cache performance
3. **Single Allocation:** More efficient than allocating N times individually
4. **Batch Operations:** Can loop through and operate on all objects

---

## 🎯 Key Takeaways for Evaluation:

1. **Default Constructor Required:** Arrays need default constructors
2. **Two-Step Process:** Allocate with default constructor, then initialize
3. **Proper Cleanup:** `delete[]` for arrays, not `delete`
4. **Memory Management:** All zombies properly destroyed, no leaks
5. **Array Access:** Can access array elements with `horde[i]`

---

## 💡 Real-World Applications:

This pattern is used in:
- **Game Development:** Managing arrays of entities, enemies, bullets
- **Databases:** Loading multiple records into memory
- **Graphics:** Vertex arrays, particle systems
- **Networking:** Connection pools, packet buffers
