bool compare(string a, string b) {
     int lena = (int) a.length();
     int lenb = (int) b.length();
     if (lena != lenb) return false;
     
     for (int i = 0; i < lena; i++) {
         if (a[i] != b[i]) return false;
     }
     return true;
 }

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    int n = (int) queries.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = 0;
        for (int j = 0; j < (int) stringList.size(); j++) {
            if (compare(stringList[j], queries[i])) res[i]++;
        }
    }
    return res;
}