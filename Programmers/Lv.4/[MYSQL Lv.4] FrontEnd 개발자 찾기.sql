with front as (
    select CODE
    from SKILLCODES
    where CATEGORY = "Front End"
)

select id, email, first_name, last_name
from DEVELOPERS
where id in (select id
    from DEVELOPERS d join front f
    group by id having sum(SKILL_CODE & CODE) > 0)
order by id
