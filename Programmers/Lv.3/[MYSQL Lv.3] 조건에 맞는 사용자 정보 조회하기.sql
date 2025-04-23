SELECT U.USER_ID, U.NICKNAME, concat(U.CITY," ", U.STREET_ADDRESS1, " ", U.STREET_ADDRESS2) as 전체주소, concat(left(TLNO,3),'-',substr(TLNO,4,4),'-',right(TLNO,4)) as 전화번호
from USED_GOODS_BOARD B join USED_GOODS_USER U on B.WRITER_ID = U.USER_ID
group by B.WRITER_ID having count(B.CONTENTS) >= 3
order by U.USER_ID desc
