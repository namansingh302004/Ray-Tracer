#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Dog
{
public:
    string name;
    Dog(string n = "Doggo") : name(n) {}
    void bark()
    {
        cout << name << " says Woof\n";
    }
};

int main()
{
    // 1. Vector (dynamic array)
    // Can store any number of integers; no need to declare a fixed size upfront.
    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // 2. Why pointers?
    // Pointers allow allocating objects dynamically on the heap at runtime.
    // Instead of stack allocation:
    //   Dog dog;
    //   dog.bark();
    //
    // Heap allocation:
    Dog *dog = new Dog();
    dog->bark();

    // 3. The problem with 'new'
    // Manual allocation requires manual deallocation via 'delete dog;'.
    // Forgetting to deallocate leads to a memory leak.

    // 4. The problem with ownership and multiple raw pointers
    Dog *person1 = dog;
    Dog *person2 = dog;

    // Both pointers reference the same memory address:
    //
    //           ┌──────────────┐
    // person1 ─>│              │
    //           │     Dog      │
    // person2 ─>│              │
    //           └──────────────┘
    //
    // If both call delete:
    //   delete person1;
    //   delete person2; // Undefined behavior (double free error)
    // If neither calls delete:
    //   Memory leak

    // 5. Solution: std::shared_ptr
    // A smart pointer that handles memory automatically using reference counting.
    // As long as at least one shared_ptr is pointing to the object, it stays alive.

    // Always prefer make_shared over 'new' (it does 1 single heap allocation for both object + ref counter)
    shared_ptr<Dog> p1 = make_shared<Dog>("Buddy");

    // use_count() tells you how many pointers are sharing this object
    cout << "Ref count (p1): " << p1.use_count() << "\n"; // 1

    {
        // Copying increments the internal reference count
        shared_ptr<Dog> p2 = p1;

        //           ┌──────────────┐
        // p1 ──────>│ ControlBlock │
        //           │ ref_count: 2 │───> [ Dog: Buddy ]
        // p2 ──────>│              │
        //           └──────────────┘

        cout << "Inside scope ref count: " << p1.use_count() << "\n"; // 2

        p2->bark(); // Use just like a normal pointer
        (*p2).bark();
    }
    // p2 goes out of scope here -> ref count drops back to 1.
    // Dog is NOT deleted yet because p1 still holds it!

    cout << "After scope ref count: " << p1.use_count() << "\n"; // 1

    // Access raw address if some legacy C-style API expects a raw pointer:
    Dog *rawDog = p1.get(); // Never call delete on rawDog!

    // Resetting manually detaches early
    p1.reset();
    // ref count hits 0 -> Buddy is automatically deleted right here!

    // 6. Gotchas to remember:
    // - Never make two independent shared_ptrs from the same raw pointer:
    //     Dog* raw = new Dog();
    //     shared_ptr<Dog> sp1(raw);
    //     shared_ptr<Dog> sp2(raw); // BAD! 2 separate control blocks -> double free crash!
    // - Circular references: If Object A points to B with shared_ptr, and B points back to A,
    //   ref count never hits 0 (memory leak). That's where std::weak_ptr comes in.

    return 0;
}