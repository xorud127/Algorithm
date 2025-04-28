with sec_grade as(
select fir.PARENT_ID, sec.ID
from ECOLI_DATA fir join ECOLI_DATA sec on sec.PARENT_ID = fir.id)

select sec.id
from sec_grade sec join ECOLI_DATA third on sec.parent_id = third.id
where third.parent_id is null
order by sec.id
