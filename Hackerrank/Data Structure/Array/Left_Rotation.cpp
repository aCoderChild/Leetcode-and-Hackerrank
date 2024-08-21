vector<int> rotateLeft(int d, vector<int> arr) {
    int n = (int) arr.size();
    vector<int> newarr(n); //need to assign the size of the vector
    for (int i = 0; i < n; i++) {
        newarr[i] = arr[(i+d) % n];
    }
    return newarr;
}