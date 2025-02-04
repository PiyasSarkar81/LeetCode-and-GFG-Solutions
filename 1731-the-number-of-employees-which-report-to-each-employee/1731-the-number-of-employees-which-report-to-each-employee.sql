# Write your MySQL query statement below
select m.employee_id, m.name, count(e.employee_id) as reports_count, round(avg(e.age)) as average_age
from Employees as e join Employees as m 
on m.employee_id = e.reports_to
group by employee_id
order by employee_id;