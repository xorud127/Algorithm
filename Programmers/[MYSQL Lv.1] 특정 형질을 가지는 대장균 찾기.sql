select count(*) as COUNT
from ECOLI_DATA
where (GENOTYPE & 2) = 0 and ((GENOTYPE & 4) > 0 or (GENOTYPE & 1) > 0)
