class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        int count_1 = 0, count_2 = 0, ele_1 = -1, ele_2 = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(ele_2 == nums[i])
                count_2++;
            
            else if(ele_1 == nums[i])
                count_1++;
            
            else if(count_1 == 0)
            {
                ele_1 = nums[i];
                count_1 = count_1 + 1;
            }
            
            else if(count_2 == 0)
            {
                ele_2 = nums[i];
                count_2 = count_2 + 1;
            }
            
            else
            {
                count_1--;
                count_2--;
            }
            cout<<ele_1<<" "<<ele_2<<endl;
        }
       // cout<<ele_1<<" "<<ele_2<<"\n";
        
        count_1 = 0, count_2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(ele_1 == nums[i])
                count_1++;
            
            else if(ele_2 == nums[i])
                count_2++;
        }
        
        //cout<<ele_1<<" "<<count_1<<" "<<ele_2<<" "<<count_2;
        int n=nums.size();
        if(count_1>n/3)
            ans.push_back(ele_1);
        
        if(count_2>n/3)
            ans.push_back(ele_2);
        return ans;
    }
};