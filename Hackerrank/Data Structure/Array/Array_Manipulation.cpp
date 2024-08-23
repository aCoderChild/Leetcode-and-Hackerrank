//Brute Force
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n, 0); //array must be initialised
    for (const auto& query : queries) {
      int a = query[0] - 1;
      int b = query[1] - 1;
      long k = (long) query[2];
      for (int i = a; i <= b; i++) {
          arr[i] += k;
      }  
    }
    long maximum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) maximum = arr[i];
    }
    return maximum;
}

//difference Array technique:
//Relative difference;
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> temp(n+1, 0);
    for (const auto& query : queries) {
        int a = query[0] - 1, b = query[1] - 1;
        long k = (long) query[2];
        temp[a] += k;
        if (b < n + 1) temp[b+1] -= k;
    }
    
    long current = 0, maximum = 0;
    for (int i = 0; i < n+1; i++) {
        current += temp[i];
        if (maximum < current) maximum = current;
    }
    return maximum;
}
