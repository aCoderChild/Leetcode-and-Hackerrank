class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long sum = skill[0] + skill[n-1];
        long long ans = skill[0] * skill[n-1];
        for (int i = 1; i < n/2; i++) {
            if (skill[i] + skill[n-1-i] != sum) return -1;
            else ans += (skill[i] * skill[n-1-i]);
        }
        return ans;
    }
};

//better approach
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        long long ans = 0 ;
        int n = skill.size() ;
        
        // skill = [3,4]
        if( skill.size() == 3 ) return skill[0]*skill[1] ;
        // sort the skills 
        sort( skill.begin(), skill.end() );
        
        int i=n/2-1 ;
        int j=n/2 ;
        int sum = skill[i]+ skill[j];
        
        while( i>=0 && j<n ){
            
            int tmp = skill[i] + skill[j] ;
            
            // It is necessary to divide all the teams equally 
            if( tmp == sum ){
                // Calculate the chemistry 
                ans += skill[i]*skill[j] ;
            }
            else {
                // If we are not able to divide the teams equally 
                ans = 0;
                break ;
            }
            
            i--;
            j++;
        }
        
        if( ans == 0 ) return -1 ;
        
        return ans ;
    }
};