struct A {
    virtual void foo();
    void bar();
};

struct B: A {
    void foo() const override; // Error: B::foo does not override A::foo

    void foo() override;    // OK: B::foo overrides A::foo
    void bar() override;    // Error: A::bar is not virtual
};

int main() {}
