class Solution {
public:
    string longestPalindrome(string s) {
         string str;
        int res=0;
        string s1=s;
        string s2=s;
        reverse(s2.begin(), s2.end());
        int m=s1.size();
        int n=s2.size();
        int t[m+1][n+1];
		//initialization
        for(int i=0; i<m+1; i++)
            for(int j=0; j<n+1; j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        
        //filing t matrix keep checking when last compared is equal that is the point of doubt and we will do some 
		//calculation or something 
		
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                    if(res<t[i][j])
                    {
                        string temp=s.substr(i-t[i][j],t[i][j]);
                        string temp2=temp;
                        reverse(temp2.begin(), temp2.end());
                        if(temp==temp2) //we just want to check if matched substring is palindrome or not
                        {
                        res=t[i][j];
                        str=temp;
                        }
                    }
                }
                else
                    t[i][j]=0;
            }
        return str;
        
        
    }
};