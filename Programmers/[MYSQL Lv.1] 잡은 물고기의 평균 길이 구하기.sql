select round(avg(if(LENGTH is null, 10, LENGTH)), 2) as AVERAGE_LENGTH
from FISH_INFO 
