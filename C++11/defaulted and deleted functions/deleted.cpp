struct unique_resource {
    unique_resource() = default;
    unique_resource& operator=(unique_resource&) = delete;
    unique_resource(unique_resource&) = delete;
};

int main() {
    unique_resource resource;
    unique_resource other_resource(resource);
}
