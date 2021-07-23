struct Base {
    virtual void foo();
};

struct A: Base {
    void foo() final; // Base::foo is overriden and A::foo is the final override
    void bar() final; // Error: bar cannot be final as it is non-virtual
};

struct B final: A { // struct B is final
    void foo() override;    // Error: foo cannot be overriden as it is final in A
};

struct C: B {};
