class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length();
        int m = b.length();
        
        int i=n-1,j=m-1,c=0,sum=0;
        string s="";
        
        while(i>=0||j>=0){
            
            sum = (i>=0?a[i]-'0':0)+(j>=0?b[j]-'0':0)+c;
            if(sum==3){
                sum=1;
                c=1;
            }
            else if(sum==2){
                sum=0;
                c=1;
            }
            else{
                c=0;
            }
            s = (char)(sum+'0')+s;
            i--;
            j--;
            
        }
        if(c==1){
            s="1"+s;
        }
        return s;       
        
    }
};