"""
Table: ActorDirector

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key column for this table.

 

Write a SQL query for a report that provides the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.

Return the result table in any order.
"""
# Write your MySQL query statement below
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY Actor_id, Director_id
HAVING COUNT(*)>2;