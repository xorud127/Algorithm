with recursive fuc as (
    select id, parent_id, 1 as gen
    from ECOLI_DATA
    where parent_id is null
    
    union all
    
    select a.id, a.parent_id, gen + 1 as gen
    from ECOLI_DATA a, fuc b
    where b.id = a.parent_id
)

SELECT 
    COUNT(*) AS COUNT,
    a.GEN AS GENERATION
FROM 
    fuc a LEFT JOIN fuc b ON a.ID = b.PARENT_ID
WHERE 
    b.ID IS NULL
GROUP BY 
    a.GEN
ORDER BY 
    a.GEN
