class Solution {
    private boolean isVowel(char c) {
        char lowerCaseChar = Character.toLowerCase(c);
        return (lowerCaseChar=='a' || lowerCaseChar=='e' || lowerCaseChar=='i' || lowerCaseChar=='o' || lowerCaseChar=='u');
    }
    public String reverseVowels(String s) {
        int i = 0, j = s.length()-1;
        StringBuilder outputReverseVowel = new StringBuilder(s);
        while(i<j) {
            if(isVowel(s.charAt(i)) && !isVowel(s.charAt(j))) {
                j--;
                continue;
            } else if(!isVowel(s.charAt(i)) && isVowel(s.charAt(j))) {
                i++; 
                continue;
            } else if (isVowel(s.charAt(i)) && isVowel(s.charAt(j))) {
                outputReverseVowel.setCharAt(i, s.charAt(j));
                outputReverseVowel.setCharAt(j, s.charAt(i));
            } 
              i++;
                j--;
          
        }
        return outputReverseVowel.toString();
    }
}