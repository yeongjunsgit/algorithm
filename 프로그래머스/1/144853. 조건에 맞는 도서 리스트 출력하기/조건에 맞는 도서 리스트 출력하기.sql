-- 코드를 입력하세요
SELECT BOOK_ID, substr(PUBLISHED_DATE, 1, 10) as PUBLISHED_DATE
FROM BOOK
WHERE substr(PUBLISHED_DATE, 1, 4) = 2021 AND CATEGORY = '인문'
ORDER BY PUBLISHED_DATE