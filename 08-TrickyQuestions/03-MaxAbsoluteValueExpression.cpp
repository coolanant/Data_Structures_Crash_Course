// Given two arrays of integers with equal lengths, return the maximum value of:
// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
    
// a1[i] + a2[i] + i
// a1[i] - a2[i] + i
// -a1[i] + a2[i] + i
// -a1[i] - a2[i] + i

int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    int maxDist = 0;
    for(int p: {1, -1}){
        for(int q: {1, -1}){
            int maxVal = INT_MIN;
            int minVal = INT_MAX;
            for(int i = 0; i < arr1.size(); ++i){
                int val = arr1[i] * p + arr2[i] * q + i;
                maxVal = max(maxVal, val);
                minVal = min(minVal, val);
            }
            maxDist = max(maxDist, maxVal - minVal);
        }
    }
    return maxDist;        
}