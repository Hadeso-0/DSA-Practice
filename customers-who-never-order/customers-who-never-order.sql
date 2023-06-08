SELECT name AS Customers 
# SELECT * 
FROM Customers LEFT JOIN Orders
ON Customers.id = Orders.customerId
WHERE ISNULL(Orders.id); 