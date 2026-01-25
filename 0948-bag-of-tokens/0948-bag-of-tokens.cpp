class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin() , tokens.end());

        int score = 0 , maxscore = 0;
        int i = 0 , j = n - 1;

        while(i <= j) {
            if(tokens[i] <= power) {
                power -= tokens[i];
                score++;
                maxscore = max(maxscore,  score);
                i++;
            }else if(score >= 1){
                power += tokens[j];
                score--;
                j--;
            }else{
                return maxscore;
            }
        }
        return maxscore;
    }
};