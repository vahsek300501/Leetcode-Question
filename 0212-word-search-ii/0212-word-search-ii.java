class Solution {
    
     HashMap<String,Integer> map=new HashMap<>();
     Set<String> ans=new HashSet<>();
    int max=-1;
    
    public List<String> findWords(char[][] board, String[] words) {
       
        for(int i=0;i<words.length;i++){
            map.put(words[i],1);
            max=Math.max(max,words[i].length());
        }
        
        
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                boolean[][] visited=new boolean[board.length][board[i].length];
                check(i,j,"",board,visited);
            }
        }
        return new ArrayList<>(ans);
    }
        
        
        
        public void check(int i,int j,String str,char[][] board,boolean[][] visited){
            if(i<0 || j<0 || i>=board.length || j>=board[i].length || visited[i][j]==true || str.length()>=max) return;
             
            visited[i][j]=true;   
            str+=board[i][j];
            //System.out.println(str);
            
            if(map.containsKey(str)){
                ans.add(str);
                // System.out.println(str);
                
            }
            
            check(i-1,j,str,board,visited);
            check(i+1,j,str,board,visited);
            check(i,j-1,str,board,visited);
            check(i,j+1,str,board,visited);
            
            str=str.substring(0, str.length() - 1);
            
            visited[i][j]=false;
        }
    }