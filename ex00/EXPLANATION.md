# Ex00: BraiiiiiiinnnzzzZ - Evaluation Guide

## ✅ Verification Against Evaluation Sheet

### Makefile and tests:
- ✅ Makefile compiles with appropriate flags (`-Wall -Wextra -Werror -std=c++98`)
- ✅ Main tests the exercise

### Zombie Class:
- ✅ Private name attribute
- ✅ Constructor that takes a string
- ✅ `announce()` prints: `"<name>: BraiiiiiiinnnzzzZ..."`
- ✅ Destructor prints debug message with zombie name

### newZombie:
- ✅ Allocates Zombie on the heap using `new`
- ✅ Returns `Zombie*`
- ✅ Zombie announces itself correctly
- ✅ Zombie is deleted with `delete` before program ends

### randomChump:
- ✅ Creates Zombie on the stack
- ✅ Makes it announce itself
- ✅ Zombie is automatically destroyed when function ends

---

## 📝 How to Explain to the Evaluator

### 1. What This Exercise Teaches:

*"This exercise teaches us the fundamental difference between stack and heap memory allocation in C++, and when to use each one."*

### 2. Stack vs Heap Allocation:

**Stack Allocation** (like in `randomChump`):
- **Automatic memory management** - no need to manually delete
- **Faster** - just moves the stack pointer
- **Limited lifetime** - object dies when function scope ends
- **Limited size** - stack is smaller
- **Example:** `Zombie z(name);` - destroyed automatically at `}`

**Heap Allocation** (like in `newZombie`):
- **Manual memory management** - must use `delete`
- **Slower** - requires system calls
- **Persistent lifetime** - survives beyond function scope
- **Larger capacity** - heap is much bigger
- **Example:** `Zombie* z = new Zombie(name);` - persists until `delete z;`

### 3. Design Decisions Justification:

**Why `newZombie` uses heap allocation:**
```
"I used heap allocation in newZombie because the function needs to RETURN 
the zombie to the caller. If I created it on the stack, it would be destroyed 
immediately when the function returns, and we'd return a pointer to dead memory. 
The heap allocation lets the zombie persist after the function ends, so the 
caller can use it and delete it later."
```

**Why `randomChump` uses stack allocation:**
```
"I used stack allocation in randomChump because the zombie only needs to 
exist during the function call - it announces itself and then it's done. 
There's no need to keep it alive afterward. Stack allocation is perfect 
here because it's faster and automatically cleaned up when the function ends. 
No memory leaks possible!"
```

### 4. Demonstrating Understanding:

Run the program:
```bash
make && ./Zombie
```

Expected output:
```
StackZombie: BraiiiiiiinnnzzzZ...
StackZombie is destroyed          ← destroyed when randomChump() ends
HeapZombie: BraiiiiiiinnnzzzZ...
HeapZombie is destroyed           ← destroyed only when we call delete
```

**Explain:** *"Notice how StackZombie is destroyed immediately after announcing, but HeapZombie persists until we explicitly delete it. This demonstrates the lifetime difference between stack and heap objects."*

---

## 🔍 Stack Pointer Explanation:

When you create a stack variable, the CPU literally just:
1. **Moves the stack pointer register (ESP/RSP)** down by the object's size
2. Calls the constructor (in C++)
3. When the scope ends, calls destructor and moves the pointer back up

**Example:**
```
Stack before:  [data][data][data] ← Stack Pointer (SP)
Create object: [data][data][data][Zombie] ← SP moved down
End scope:     [data][data][data] ← SP moved back up (object "gone")
```

It's just **ONE assembly instruction** to allocate! Super fast.

Heap allocation requires:
- System calls to memory allocator
- Finding free memory block
- Bookkeeping for tracking allocation
- Much slower (100-1000x slower)

---

## 🆚 C vs C++ Comparison:

### In C Language:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
} Zombie;

// Equivalent to newZombie (HEAP allocation)
Zombie* newZombie(const char* name) {
    Zombie* z = malloc(sizeof(Zombie));  // Manual heap allocation
    strcpy(z->name, name);
    printf("%s: BraiiiiiiinnnzzzZ...\n", z->name);
    return z;
}

// Equivalent to randomChump (STACK allocation)
void randomChump(const char* name) {
    Zombie z;  // Stack allocation
    strcpy(z.name, name);
    printf("%s: BraiiiiiiinnnzzzZ...\n", z.name);
    // z automatically "destroyed" when function ends
    // (no destructor in C, just memory freed)
}

int main() {
    randomChump("StackZombie");  // Stack - automatic cleanup
    
    Zombie* heap_z = newZombie("HeapZombie");  // Heap - manual cleanup
    free(heap_z);  // YOU must remember to free!
    
    return 0;
}
```

### Key Differences C vs C++:

| Aspect | C | C++ |
|--------|---|-----|
| **Heap Allocation** | `malloc(size)` | `new Type(args)` |
| **Heap Deallocation** | `free(ptr)` | `delete ptr` |
| **Constructors** | ❌ None - manual init | ✅ Automatic |
| **Destructors** | ❌ None - manual cleanup | ✅ Automatic cleanup |
| **Type Safety** | `malloc` returns `void*` | `new` returns typed pointer |
| **Initialization** | Manual (strcpy, etc.) | Constructor handles it |
| **Cleanup** | Manual | Destructor handles it |

---

## 💡 Why C++ is Better Here:

**In C:**
```c
Zombie* z = malloc(sizeof(Zombie));
strcpy(z->name, name);  // You must remember to initialize
// ... use it ...
free(z);  // You must remember to free
```

**In C++:**
```cpp
Zombie* z = new Zombie(name);  // Constructor initializes automatically
// ... use it ...
delete z;  // Destructor cleans up automatically + frees memory
```

The C++ destructor message (`"<name> is destroyed"`) happens automatically - you can't do that in C without manually calling a cleanup function before `free()`.

---

## 🎯 Key Points for Evaluation:

1. **Memory Safety:** No memory leaks (heap zombie is deleted)
2. **Proper Usage:** Stack for temporary, heap for persistent objects
3. **Resource Management:** Destructor provides debugging feedback
4. **Scope Understanding:** Stack objects die automatically, heap objects need manual deletion
