"""
Table: Weather

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.

 

Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).

Return the result table in any order.
"""
# Write your MySQL query statement below
Select distinct w1.id 
from weather w1, weather w2
where DATEDIFF(w1.recordDate,w2.recordDate)=1 AND w1.temperature>w2.temperature;