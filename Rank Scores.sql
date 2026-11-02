# Leetcode Problem 178: Rank Scores
# Write your MySQL query statement below
SELECT 
    score, 
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM 
    Scores;