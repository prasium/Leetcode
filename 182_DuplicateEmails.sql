"""
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.

 

Write an SQL query to report all the duplicate emails.

Return the result table in any order.
"""
/* Write your T-SQL query statement below */
select email from Person
group by email
having count(*)>1