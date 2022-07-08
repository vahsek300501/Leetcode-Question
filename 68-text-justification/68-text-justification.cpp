class Solution {
public:
    string createLine(vector<string> &words,int maxWidth){
        int wordLen = 0;
        for(auto &x : words){
            wordLen += (x.length());
        }
        int totalSpace = maxWidth - wordLen;
        if(words.size() == 1){
            return (words[0] + string(totalSpace,' '));
        }
        int spaceLen = totalSpace / (words.size()-1);
        int remSpace = totalSpace % (words.size()-1);
        
        string finLine;
        
        for(auto &word: words){
            int flag = 0;
            if(remSpace > 0){
                flag = 1;
                remSpace--;
            }
            finLine += (word + string(spaceLen + flag, ' '));
        }
        while(finLine.size() > 0 && finLine.back() == ' '){
            finLine.pop_back();
        }
        return finLine;
    }
    string createEndLine(vector<string> &words,int maxWidth){
        int wordLen = 0;
        for(auto &x : words){
            wordLen += (x.length());
        }
        int totalSpace = maxWidth - wordLen;
        
        if(words.size() == 1){
            return (words[0] + string(totalSpace,' '));
        }
        
        string finLine;
        for(auto &word: words){
            if(totalSpace > 0){
                finLine +=(word + string(1,' '));
                totalSpace--;
            }
            else{
                finLine +=(word);
            }
        }
        if(totalSpace > 0)
            finLine += string(totalSpace,' ');
        
        return finLine;
        
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> res;
        int curr = 0;
        vector<string> temp;
        for(auto word : words){
            if(curr == 0){
                curr += word.length();
                temp.push_back(word);
                continue;
            }
            if(curr + (word.length()+1) > maxWidth){
                res.push_back(temp);
                curr = word.length();
                temp.clear();
                temp.push_back(word);
            }
            else{
                curr += (word.length()+1);
                temp.push_back(word);
            }
        }
        if(temp.size() > 0){
                res.push_back(temp);
                curr = 0;
                temp.clear();
        }
        vector<string> ans;
        for(auto &x : res){
            ans.push_back(createLine(x,maxWidth));
        }
        ans.pop_back();
        ans.push_back(createEndLine(res.back(),maxWidth));
        return ans;
        
        
        
    }
};
