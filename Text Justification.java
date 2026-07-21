// Leetcode Problem 68: Text Justification
// JAVA CODE
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0;
        int n = words.length;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            StringBuilder line = new StringBuilder();

            // Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line.append(words[k]);
                    if (k != j - 1) {
                        line.append(" ");
                    }
                }

                while (line.length() < maxWidth) {
                    line.append(" ");
                }
            } else {
                int totalSpaces = maxWidth - lineLength;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line.append(words[k]);

                    for (int s = 0; s < evenSpaces; s++) {
                        line.append(" ");
                    }

                    if (k - i < extraSpaces) {
                        line.append(" ");
                    }
                }

                line.append(words[j - 1]);
            }

            result.add(line.toString());
            i = j;
        }

        return result;
    }
}