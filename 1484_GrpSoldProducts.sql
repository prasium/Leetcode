"""
Table Activities:

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
There is no primary key for this table, it may contain duplicates.
Each row of this table contains the product name and the date it was sold in a market.

 

Write an SQL query to find for each date the number of different products sold and their names.

The sold products names for each date should be sorted lexicographically.

Return the result table ordered by sell_date.
"""
# Write your MySQL query statement below

SELECT SELL_DATE, COUNT(DISTINCT(PRODUCT)) AS num_sold, 
    GROUP_CONCAT(DISTINCT PRODUCT order by PRODUCT SEPARATOR ',' ) AS Products
FROM ACTIVITIES
GROUP BY SELL_DATE
ORDER BY SELL_DATE;
