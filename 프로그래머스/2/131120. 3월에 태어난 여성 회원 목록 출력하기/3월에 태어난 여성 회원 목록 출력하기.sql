-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, substr(DATE_OF_BIRTH, 1, 10) as DATE_OF_BIRTH
FROM MEMBER_PROFILE
WHERE TLNO is not NULL
AND substr(DATE_OF_BIRTH, 6, 7) = 03
AND GENDER = 'W'
ORDER BY MEMBER_ID