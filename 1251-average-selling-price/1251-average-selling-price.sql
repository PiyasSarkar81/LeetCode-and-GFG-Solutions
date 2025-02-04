# Write your MySQL query statement below
SELECT p1.product_id, 
       IFNULL(ROUND(SUM(p2.units * p1.price) / sum(p2.units), 2), 0) AS average_price
FROM Prices AS p1 
left JOIN UnitsSold AS p2 
ON p1.product_id = p2.product_id 
AND p2.purchase_date BETWEEN p1.start_date AND p1.end_date
GROUP BY p1.product_id
ORDER BY p1.product_id;
