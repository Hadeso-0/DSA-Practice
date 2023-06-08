# SELECT  Email
# FROM (
  SELECT email as Email
  FROM Person
  GROUP BY email
# ) AS T
# WHERE cnt > 1;
HAVING COUNT(email) > 1;