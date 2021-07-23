struct Foo {
    Foo(char x, int y) { }
    Foo(int y): Foo('a', y)/*, my_favorite_letter('c') - Error. Delegating constructor must appear alone*/
    {
        my_favorite_letter = 'c'; // OK
    }
private:
    char my_favorite_letter;
};

int main() {}
