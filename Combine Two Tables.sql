# LeetCode Problem 175: Combine Two Tables

# MySQL query to combine two tables, Person and Address, using a LEFT JOIN to retrieve the first name, last name, city, and state of each person along with their corresponding address information. If a person does not have an address, the city and state will return NULL.

# Write your MySQL query statement below

SELECT 
    p.firstName, 
    p.lastName, 
    a.city, 
    a.state
FROM 
    Person p
LEFT JOIN 
    Address a 
ON 
    p.personId = a.personId;