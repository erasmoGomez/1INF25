# 1INF25 — Programación 2 👾

> *It works on my machine.*
> — Every programmer, moments before disaster.

Welcome to **Programación 2**.

This is where programming starts getting... interesting in C++.

You'll allocate memory.
You'll lose memory.
You'll dereference pointers.
You'll probably dereference the wrong pointer.

And eventually, you'll understand **why Java decided that maybe programmers shouldn't be trusted with memory.**

## 🧠 What is this course about?

Programación 2 is not just about learning more C++ syntax.

The goal is to understand what actually happens when we create objects, allocate memory, pass addresses around, build data structures and design software using **Object-Oriented Programming**.

We will start close to the machine with **C++** and progressively move toward higher-level abstractions with **Java**.

```text
C++
 │
 ├── Memory
 │    ├── Stack
 │    └── Heap
 │
 ├── Pointers
 │    ├── *
 │    ├── **
 │    └── void*   ← yes, we're going there
 │
 ├── Dynamic Memory
 │    ├── new
 │    └── delete
 │
 └── Object-Oriented Programming
      │
      ├── Classes & Objects
      ├── Encapsulation
      ├── Inheritance
      └── Polymorphism
              │
              ▼
            Java ☕
```


## 💀 Memory Management

At some point you will write:

```cpp
int *ptr = new int(42);
```

Congratulations.

You now own a tiny piece of memory.

Unfortunately...

**you are also responsible for it.**

```cpp
delete ptr;
```

Forget that line enough times and your program slowly becomes a memory-eating monster.

Throughout the course we'll explore:

* Stack vs. Heap
* Dynamic memory allocation
* Pointers and references
* Pointer arithmetic
* Double pointers
* Generic pointers (`void*`)
* Dynamic arrays
* Memory leaks
* Dangling pointers
* Segmentation faults 💥

And, most importantly:

> **Why did my program compile perfectly and still explode?**


## 👉 Pointers

Pointers tend to look terrifying at first.

```cpp
int x = 10;

int *p = &x;
int **pp = &p;
```

But underneath all the `*`, `&`, `**` and questionable life decisions, there is a simple idea:

**memory has addresses, and addresses are also data.**

Once that idea clicks, a lot of C++ suddenly starts making sense.


## 🕳️ The `void*` Arc

Eventually we reach one of C++'s more chaotic creatures:

```cpp
void *data;
```

It can point to...

```text
int
double
char
struct
object
???
```

It knows **where** something is.

It just doesn't know **what** it is.

That's your problem.

Good luck.


## 🧱 Object-Oriented Programming

After surviving manual memory management, we'll start building larger abstractions.

```cpp
class Programmer {
private:
    int coffee;

public:
    void debug();
    void cry();
};
```

We'll work with:

**Objects → Classes → Encapsulation → Inheritance → Polymorphism**

The goal is not simply to *use* classes.

It's to understand **why we use them and how objects behave in memory.**

---

## ☕ And then... Java

After spending enough time doing this:

```cpp
MyClass *obj = new MyClass();

delete obj;
```

Java enters the room:

```java
MyClass obj = new MyClass();
```

And that's it.

No `delete`.

The **Garbage Collector** handles memory management for you.

But now you'll understand what it is actually saving you from.


## 🎯 By the end of the course

You should be able to look at something like:

```cpp
void ***ptr;
```

and instead of immediately closing the IDE...

you'll stop and think:

> *Okay... what exactly is this pointing to?*

That's progress.


## 📂 Repository Structure

The repository contains material from different editions of **1INF25 — Programación 2**.

```text
1INF25/
│
├── 2023-1/
├── 2023-2/
├── 2024-1/
├── 2024-2/
├── 2025-1/
├── 2025-2/
├── 2026-1/
│
└── laboratorios_pasados/
```

Each semester may contain examples, exercises, laboratory material and other resources used during the course.


## ⚠️ A friendly warning

C++ will let you do many things.

That does **not** mean you should do them.

```cpp
int *ptr = nullptr;

*ptr = 10;
```

C++:

> Sure.

Operating System:

> **Segmentation fault.**


## 🧑‍💻 The Programmer's Evolution

```text
"What's a pointer?"
        ↓
"Okay, a pointer stores an address."
        ↓
"Wait... a pointer can point to another pointer?"
        ↓
"Why do I have a void***?"
        ↓
"I think I understand memory."
        ↓
SEGMENTATION FAULT
        ↓
"I do not understand memory."
        ↓
        ☕
       Java
```


## 🚀 Final Rule

When something doesn't work:

1. Read the compiler error.
2. Read it **again**.
3. Debug.
4. Check your pointers.
5. Check your memory.
6. Check your pointers again.
7. Do **not** randomly add `*` until it compiles.

> **Understand the memory. Understand the program.**

Welcome to **Programación 2**.
