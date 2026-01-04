class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder res = new StringBuilder();
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            if (i < spaces.length && spaces[i] == j) {
                res.append(' ');
                i++;
            }
            res.append(s.charAt(j));
        }
        return res.toString();
    }
}