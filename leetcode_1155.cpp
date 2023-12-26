class Solution {
private:
    int modulo = 1e9 + 7;
    int find_ways(int n, int k, int target, int index, int currSum, vector<vector<int> >& dp){
        if(index == n){
            return currSum == target;
        }

        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }

        int way = 0;
        for(int i = 1; i <= min(k, target - currSum); i++){
            way = (way + find_ways(n, k, target, index + 1, currSum + i, dp))%modulo;
        }

        return dp[index][currSum] = way;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int> > dp(n+1, vector<int>(target+1, -1));
        return find_ways(n,k, target, 0, 0, dp);
    }
};

int main(){
    Solution s;
    int way = s.numRollsToTarget(1,6,3);
    cout << "ways: " << way << endl;

    return 0; 
}
