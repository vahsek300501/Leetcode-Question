class Solution {
public:
    bool ispal(string z)
    {
        int i=0;
        int j=z.size()-1;
        while(i<j)
        {
            if(z[i]!=z[j])
                return false;
           i++;
           j--; 
        }
        return true;
    }
    string breakPalindrome(string pal) {
        int n=pal.size();
        if(n==1)
           return "";
       string ans="zzzzzz";
      for(int i=0;i<n;i++)
      {
          for(char c='a';c<='z';c++)
          {
              if(c!=pal[i])
              {
                  string z=pal;
                  z[i]=c;
                  if(ispal(z))
                      continue;
                  else if(ans>z)
                      ans=z;
              }
          }
      }
        return ans;
    }
};