with avg_score as (
    select EMP_NO, AVG(SCORE) AS AVG_SCORE
    from hr_grade
    group by emp_no
)

SELECT
    e.EMP_NO,
    e.EMP_NAME,
    CASE
        WHEN t.AVG_SCORE >= 96 THEN 'S'
        WHEN t.AVG_SCORE >= 90 THEN 'A'
        WHEN t.AVG_SCORE >= 80 THEN 'B'
        ELSE 'C'
        END AS GRADE,
    CASE
        WHEN t.AVG_SCORE >= 96 THEN e.SAL * 0.2
        WHEN t.AVG_SCORE >= 90 THEN e.SAL * 0.15
        WHEN t.AVG_SCORE >= 80 THEN e.SAL * 0.1
        ELSE 0
    END AS BONUS
FROM
    HR_EMPLOYEES e JOIN avg_score t ON e.EMP_NO = t.EMP_NO
GROUP BY t.EMP_NO
order by e.EMP_NO
