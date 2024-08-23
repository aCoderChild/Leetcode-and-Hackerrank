class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //merge the two vectors
        vector<int> temp;
        for (const auto& i : nums1) {
            temp.push_back(i);
        }
        for (const auto& i : nums2) {
            temp.push_back(i);
        }
        sort(temp.begin(), temp.end());

        int n1 = (int) nums1.size();
        int n2 = (int) nums2.size();
        if ((n1 + n2) % 2 == 1) {
            return temp[(n1+n2) / 2];
        }
        else {
            return (((double)temp[(n1+n2) / 2 - 1] + temp[(n1+n2) / 2]) / 2);
        }
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int n1 = (int) nums1.size(), n2 = (int) nums2.size();
        int id1 = 0, id2 = 0;
        while (id1 < n1 && id2 < n2) {
            if (nums1[id1] < nums2[id2]) {
                temp.push_back(nums1[id1]);
                id1++;
            } else {
                temp.push_back(nums2[id2]);
                id2++;
            }
        }
        while (id1 < n1) {
            temp.push_back(nums1[id1]);
            id1++;
        }
        while (id2 < n2) {
            temp.push_back(nums2[id2]);
            id2++;
        }

        if ((n1 + n2) % 2 == 1) {
            return temp[(n1+n2) / 2];
        }
        else {
            return (((double)temp[(n1+n2) / 2 - 1] + temp[(n1+n2) / 2]) / 2);
        }
    }
};

//-----RECURSIVE APPROACH-----


