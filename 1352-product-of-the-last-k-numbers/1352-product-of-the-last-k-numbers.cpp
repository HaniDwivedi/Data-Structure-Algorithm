class ProductOfNumbers {
private:
    vector<int> stream;

public:
    ProductOfNumbers() {}
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        int n = stream.size();
        for (int i = n - k; i < n; i++) {
            product *= stream[i];
        }
        return product;
    }
};