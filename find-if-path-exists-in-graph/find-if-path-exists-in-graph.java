class Solution {

public boolean dfs(int start, int end, Map<Integer, List<Integer>> graph, Set<Integer> visited) {
    if(start == end) return true;
    
    visited.add(start);
    
    for(int i : graph.get(start)) {
        if(!visited.contains(i))
             if(dfs(i,end, graph, visited)) 
                 return true;
    }
    return false;
}

public boolean validPath(int n, int[][] edges, int start, int end) {
    Set<Integer> visited = new  HashSet<>();
    
    Map<Integer,List<Integer>> graph = new HashMap<>();
    
    for(int i = 0; i < n; i++ ) {
        graph.put(i, new ArrayList<>());
    }
    
    for(int[] pair : edges) {
        graph.get(pair[0]).add(pair[1]);
        graph.get(pair[1]).add(pair[0]);
    }
    
    return dfs(start, end, graph, visited);
}
}